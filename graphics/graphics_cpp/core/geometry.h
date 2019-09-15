#ifndef __GRAPHICS_GEOMETRY_H
#define __GRAPHICS_GEOMETRY_H

#include <cstddef>

namespace graphics {

    template< typename T >
    class vec2;

    template< typename T >
    class vec3;

    template< typename T >
    class vec4;

    template< typename T >
    class vec2 {
        union {
            struct {
                T x,y;
            };
            T xy[2];
        };

        inline size_t size() const {
            return 2;
        }

        static vec2<T> make( const T& x, const T& y ){
            return {x,y};
        }
    };



    template< typename T >
    class vec3 {
    public:
        union {
            struct {
                T x,y,z;
            };
            T xyz[3];
        };

        inline size_t size() const {
            return 3;
        } 

        static vec3<T> make( const T& x, const T& y, const T& z ){
            return {x,y,z};
        }   
    };

    template< typename T >
    class vec4 {
    public:
        union {
            struct {
                T x,y,z,w;
            };
            T xyzw[4];
        };
        
        inline size_t size() const {
            return 4;
        }

        static vec4<T> make( const T& x, const T& y, const T& z, const T& w ){
            return {x,y,z,w};
        }
    };

    typedef vec2<int>    vec2i;
    typedef vec2<float>  vec2f;
    typedef vec2<double> vec2d;

    typedef vec3<int>    vec3i;
    typedef vec3<float>  vec3f;
    typedef vec3<double> vec3d;

    typedef vec4<int>    vec4i;
    typedef vec4<float>  vec4f;
    typedef vec4<double> vec4d;

};

#endif