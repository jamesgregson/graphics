#include <iostream>

#include "graphics.h"
using namespace graphics;

class shader {
public:
    shader( int w, int h ) : m_img(w,h,3) {
    }

    size_t width() const {
        return m_img.width();
    }

    size_t height() const {
        return m_img.height();
    }

    template< typename tri_t, typename vtx_t=typename tri_t::vertex_t >
    void shade( const int i, const int j, const vec3f bary, tri_t* tri, vtx_t* a, vtx_t* b, vtx_t* c ){
        float d = bary.x*a->pos.z + bary.y*b->pos.z + bary.z*c->pos.z;
        m_img(i,j,0) = d;
        m_img(i,j,1) = d;
        m_img(i,j,2) = d;
    }

    void save( const char* filename ){
        cimg_library::CImg<unsigned char> tmp = m_img.get_normalize(0,255);
        tmp.save( filename );
    }

private:
    image<float>    m_img;
};

int main( int argc, char **argv ){

    auto blah = vec2f::make(1.0f,2.0f);
    auto tmp = blah.homogeneous(1.0f);

    auto m = mesh<mesh_traits<basic_vertex_traits,basic_triangle_traits>>();
    auto a = m.add_vertex();
    auto b = m.add_vertex();
    auto c = m.add_vertex(); 
    auto d = m.add_vertex();
    auto t1 = m.add_triangle(a,b,c);
    auto t2 = m.add_triangle(a,c,d);

    a->pos = vec3f::make(10.0f,10.0f,20.0f);
    b->pos = vec3f::make(90.0f,20.0f,-10.0f);
    c->pos = vec3f::make(80.0f,90.0f,30.0f);
    d->pos = vec3f::make(20.0f,70.0f,-20.0f);

    auto shd = shader(100,100);
    rasterize_triangle( &shd, t1 );
    rasterize_triangle( &shd, t2 );
    //shd.save("dump.png");

    return 0;
}