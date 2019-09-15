#ifndef __GRAPHICS_RASTERIZE_H
#define __GRAPHICS_RASTERIZE_H

#include <cmath>
#include <tuple>
#include <iostream>
#include <algorithm>

#include "../core/utils.h"
#include "../core/mesh.h"
#include "../core/geometry.h"

namespace graphics {

    template< typename shader_t, typename triangle_t >
    void rasterize_triangle( shader_t* shd, triangle_t *tri ){
        typedef typename triangle_t::vertex_t vertex_t;

        // width and height of output
        const int w = shd->width();
        const int h = shd->height();

        // get pointers to vertices and sort vertically
        const vec3f a=(*tri)[0]->pos;
        const vec3f b=(*tri)[1]->pos;
        const vec3f c=(*tri)[2]->pos;

        // get triangle bounds
        const int minx = std::min( a.x, std::min( b.x, c.x ) )-1;
        const int maxx = std::max( a.x, std::max( b.x, c.x ) )+1;
        const int miny = std::min( a.y, std::min( b.y, c.y ) )-1;
        const int maxy = std::max( a.y, std::max( b.y, c.y ) )+1;

        // bounds check, discard fast if triangle does not intersect
        if( miny >= h || maxy < 0 || minx >= w || maxx < 0 )
            return;

        // build the system to go from x,y coordinates
        // back to barycentric...
        vec3f bary;
        float A,B,C,D,det,x,y;
        A = b.x-a.x; B = c.x-a.x;
        C = b.y-a.y; D = c.y-a.y;
        det = A*D - B*C;
        if( fabs(det) < 1e-5f )
            return;
        A /= det; B /= det;
        C /= det; D /= det;

        // loop over the bounding box.
        // TODO: do proper scan-conversion
        for( auto j=miny; j<=maxy; ++j ){
            y = j+0.1f-a.y;
            for( auto i=minx; i<=maxx; ++i ){
                x = i+0.1f-a.x;
                bary.y =  D*x - B*y;
                bary.z = -C*x + A*y;
                bary.x = 1.0f-bary.y-bary.z;
                if( bary.x >= 0.0 && bary.y >= 0.0f & bary.z >= 0.0f )
                    shd->shade( i, j, bary, tri, (*tri)[0], (*tri)[1], (*tri)[2] );
            }
        }
    }

};

#endif