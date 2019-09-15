#ifndef __GRAPHICS_SFINAE_H
#define __GRAPHICS_SFINAE_H

#include <type_traits>

namespace graphics {
    template <typename T, typename = int>
    struct HasX : std::false_type { };

    template <typename T>
    struct HasX <T, decltype((void) T::x, 0)> : std::true_type { };
};

#endif