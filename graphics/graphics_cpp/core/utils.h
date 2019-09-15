#ifndef __GRAPHICS_UTILS_H
#define __GRAPHICS_UTILS_H

namespace graphics {
    template< typename T >
    T clamp( const T& val, const T& lo, const T& hi ){
        return val < lo ? lo : val > hi ? hi : val;
    }
};

#endif