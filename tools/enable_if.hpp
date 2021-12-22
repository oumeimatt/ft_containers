#pragma once

#include <iostream>

std::is_integral<int>;
namespace ft {

    template<bool Cond, class T = void> struct enable_if{};
    template<class T> struct enable_if<true, T> { typedef T type; };

    template<typename> struct is_integral{};

    template<> struct is_integral<bool>{};
    template<> struct is_integral<int>{};
    template<> struct is_integral<short>{};
}