#pragma once
#include <cstring>
#include <type_traits>
template <class To, class From>
typename std::enable_if_t<(sizeof(To) == sizeof(From)) 
                        && std::is_trivially_copyable_v<From> 
                        && std::is_trivially_copyable_v<To>,
                        To> bit_cast(const From &src) {
    static_assert(std::is_trivially_constructible_v<To>, "require constructible.");
    To dst;
    std::memcpy(&dst, &src, sizeof(To));
    return dst;
}