#ifndef __GRAPHICS_MESH_HEADER_H
#define __GRAPHICS_MESH_HEADER_H

#include <set>
#include <array>
#include <vector>
#include <memory>
#include <cassert>
#include <algorithm>
#include <exception>

namespace graphics {

    template< typename traits >
    class mesh;

    template<typename traits>
    class vertex : public traits::vertex_traits_t {
    public:
        typedef traits                      traits_t;
        typedef typename traits::vertex_t   vertex_t;
        typedef typename traits::triangle_t triangle_t;

        friend mesh<traits>;
        friend triangle_t;
    private:

        vertex(){}
        ~vertex(){
            if( !m_triangles.empty() ){
                assert( false );
            }
        }

        size_t size() const {
            return m_triangles.size();
        }

        triangle_t* operator[]( const int id ){
            assert( id >= 0 && id < size() );
            return m_triangles[id];
        }

    private:
        void add_triangle( triangle_t *t ){
            if( std::find(m_triangles.begin(),m_triangles.end(),t) != m_triangles.end() ){
                assert( false );
            }
            m_triangles.push_back( t );
        }

        void remove_triangle( triangle_t* t ){
            auto it = std::find( m_triangles.begin(), m_triangles.end(), t );
            if( it != m_triangles.end() ){
                m_triangles.erase(it);
            } else {
                assert( false );
            }
        }

        std::vector<triangle_t*>   m_triangles;
    };

    template<typename traits>
    class triangle : public traits::triangle_traits_t {
    public:
        typedef traits                      traits_t;
        typedef typename traits::vertex_t   vertex_t;
        typedef typename traits::triangle_t triangle_t;

        friend mesh<traits>;
        friend vertex_t;

        vertex_t* operator[]( const int id ){
            assert( id >= 0 && id < 3 );
            return m_vertices[id];
        }

        const vertex_t* operator[]( const int id ) const {
            assert( id >= 0 && id < 3 );
            return m_vertices[id];
        }

    private:
        triangle( vertex_t* a, vertex_t *b, vertex_t *c ) : m_vertices{a,b,c} {
            a->add_triangle( this );
            b->add_triangle( this );
            c->add_triangle( this );
        }

        ~triangle(){
            m_vertices[0]->remove_triangle( this );
            m_vertices[1]->remove_triangle( this );
            m_vertices[2]->remove_triangle( this );
        }

    private:
        const std::array<vertex_t*,3> m_vertices;
    };

    template< typename v_traits, typename t_traits >
    struct mesh_traits {
        typedef mesh_traits<v_traits,t_traits>  this_t;
        typedef v_traits                        vertex_traits_t;
        typedef t_traits                        triangle_traits_t;

        typedef vertex<this_t>                  vertex_t;
        typedef triangle<this_t>                triangle_t;

    };

    template< typename traits >
    class mesh {
    public:
        typedef mesh<traits>                this_t;
        typedef typename traits::vertex_t   vertex_t;
        typedef typename traits::triangle_t triangle_t;

        mesh(){}

        virtual ~mesh(){
            for( auto t : m_triangles ){
                delete t;
            }
            for( auto v : m_vertices ){
                delete v;
            }
        }

        vertex_t* add_vertex(){
            auto v = new vertex_t();
            m_vertices.insert(v);
            return v;
        }

        void remove_vertex( vertex_t* v ){
            m_vertices.erase(v);
            delete v;
        }

        triangle_t* add_triangle( vertex_t *a, vertex_t *b, vertex_t *c ){
            auto t = new triangle_t(a,b,c);
            m_triangles.insert(t);
            return t;
        }

        void remove_triangle( triangle_t* t ){
            m_triangles.erase(t);
            delete t;
        }

    private:
        std::set<vertex_t*>      m_vertices;
        std::set<triangle_t*>    m_triangles;
    };

};

#endif