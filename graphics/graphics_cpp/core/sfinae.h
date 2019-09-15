#ifndef __GRAPHICS_SFINAE_H
#define __GRAPHICS_SFINAE_H

#include <type_traits>

namespace graphics {

    template< typename S1, typename S2, typename T >
    using ensure_same_t = typename std::enable_if< std::is_same<S1,S2>::value, T >::type; 

    template< typename S, typename T >
    using ensure_floating_point_t = typename std::enable_if< std::is_floating_point<S>::value, T >::type;

    template< typename S, typename T >
    using ensure_integral_t = typename std::enable_if< std::is_integral<S>::value, T >::type;

    template< typename S, typename T >
    using ensure_arithmetic_t = typename std::enable_if< std::is_arithmetic<S>::value, T >::type;

    // template <typename T, typename = int>
    // struct HasX : std::false_type { };

    // template <typename T>
    // struct HasX <T, decltype((void) T::x, 0)> : std::true_type { };
};

#endif