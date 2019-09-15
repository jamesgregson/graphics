#ifndef __GRAPHICS_GRAPHICS_H
#define __GRAPHICS_GRAPHICS_H

#include "core/utils.h"
#include "core/geometry.h"
#include "core/mesh_traits.h"
#include "core/mesh.h"

#include "rasterize/rasterize.h"

#define cimg_display 0
#include "third_party/CImg.h"

template< typename T >
class image : public cimg_library::CImg<T> {
public:
    image( int w, int h, int c ) : cimg_library::CImg<T>(w,h,1,c,0.0f) {
    }
};

#endif