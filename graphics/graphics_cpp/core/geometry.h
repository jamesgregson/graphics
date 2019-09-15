#ifndef __GRAPHICS_GEOMETRY_H
#define __GRAPHICS_GEOMETRY_H

#include <cstddef>

#include "sfinae.h"

namespace graphics {

    template< typename T >
    class vec2;

    template< typename T >
    class vec3;

    template< typename T >
    class vec4;

    template< typename T >
    class vec2 {
    public:
        typedef vec2<T> this_t;

        union {
            struct {
                T x,y;
            };
            T xy[2];
        };

        inline size_t size() const {
            return 2;
        }

        template< typename V >
        ensure_arithmetic_t<V,vec2<V>> as() const {
            return {V(x),V(y)};
        }

        this_t operator-() const {
            return {-x,-y};
        }

        this_t operator+( const this_t& in ) const {
            return {x+in.x,y+in.y};
        }

        this_t operator-( const this_t& in ) const {
            return {x-in.x,y-in.y};
        }

        template< typename S >
        ensure_arithmetic_t<S,this_t> operator*( const S& in ) const {
            return {x*in,y*in};
        }

        template< typename S >
        ensure_arithmetic_t<S,this_t> operator/( const S& in ) const {
            return {x/in,y/in};
        }

        inline vec3<T> homogeneous( const T& w=T(1) );

        static vec2<T> make( const T& x, const T& y ){
            return {x,y};
        }
    };

    template< typename T >
    class vec3 {
    public:
        typedef vec3<T> this_t;
        union {
            struct {
                T x,y,z;
            };
            T xyz[3];
        };

        inline size_t size() const {
            return 3;
        } 

        template< typename V >
        ensure_arithmetic_t<V,vec3<V>> as() const {
            return {V(x),V(y),V(z)};
        }

        this_t operator-() const {
            return {-x,-y,-z};
        }

        this_t operator+( const this_t& in ) const {
            return {x+in.x,y+in.y,z+in.z};
        }

        this_t operator-( const this_t& in ) const {
            return {x-in.x,y-in.y,z-in.z};
        }

        template< typename S >
        ensure_arithmetic_t<S,this_t> operator*( const S& in ) const {
            return {x*in,y*in};
        }

        template< typename S >
        ensure_arithmetic_t<S,this_t> operator/( const S& in ) const {
            return {x/in,y/in};
        }


        inline vec4<T> homogeneous( const T& w=T(1) );

        inline vec2<T> xy() const {
            return {x,y};
        }

        static vec3<T> make( const T& x, const T& y, const T& z ){
            return {x,y,z};
        }   
    };

    template< typename T >
    class vec4 {
    public:
        typedef vec4<T> this_t;
        union {
            struct {
                T x,y,z,w;
            };
            T xyzw[4];
        };
        
        inline size_t size() const {
            return 4;
        }

        template< typename V >
        vec4<V> as() const {
            return {V(x),V(y),V(z),V(w)};
        }

        this_t operator-() const {
            return {-x,-y,-z,-w};
        }

        this_t operator+( const this_t& in ) const {
            return {x+in.x,y+in.y,z+in.z,w+in.w};
        }

        this_t operator-( const this_t& in ) const {
            return {x-in.x,y-in.y,z-in.z,w-in.w};
        }

        template< typename S >
        ensure_arithmetic_t<S,this_t> operator*( const S& in ) const {
            return {x*in,y*in,z*in,w*in};
        }

        template< typename S >
        ensure_arithmetic_t<S,this_t> operator/( const S& in ) const {
            return {x/in,y/in,z/in,w/in};
        }

        inline vec3<T> xyz() const {
            return {x,y,z};
        }

        static vec4<T> make( const T& x, const T& y, const T& z, const T& w ){
            return {x,y,z,w};
        }
    };

    template< typename T >
    vec3<T> vec2<T>::homogeneous( const T& w ){
        return {x,y,w};
    }

    template< typename T >
    vec4<T> vec3<T>::homogeneous( const T& w ){
        return {x,y,z,w};
    }


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