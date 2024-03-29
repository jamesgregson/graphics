#ifndef __GRAPHICS_MESH_TRAITS_H
#define __GRAPHICS_MESH_TRAITS_H

#include "geometry.h"

namespace graphics {

    struct basic_vertex_traits {
        int     id;
        vec3f   pos;
        vec3f   nor;
    };

    struct basic_triangle_traits {
        int     id;
        vec2f   uv[3];
    };

};

#endif