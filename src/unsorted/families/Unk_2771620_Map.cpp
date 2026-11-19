// Scope: common
// Members of maps on Unk_2771620's allocator that game code instantiates out of
// line, for keys and values that are trivially copyable: operator[]'s
// __emplace_unique_key_args, whose code depends only on the key's type and the
// value's size (it value-initialises a new one). Each value type is a
// placeholder of that size, named after the function (the maps' users aren't
// decompiled, so which of them share a value type isn't known).
#include <types.h>
#include <map>
#include <tuple>

#include "unsorted/Unk_2771620.h"

template <class K, class T>
using Unk_2771620_OrderedMap =
    std::map<K, T, std::less<K>, Unk_2771620_Allocator<std::pair<const K, T>>>;

struct Unk_dd1d70 {
    u64 _0[4];
};
struct Unk_dd1f00 {
    u64 _0[4];
};
struct Unk_dd2090 {
    u64 _0[4];
};
struct Unk_dd2330 {
    u64 _0[4];
};

// 0x7100dd1d70
template std::pair<Unk_2771620_OrderedMap<u64, Unk_dd1d70>::__base::iterator, bool>
Unk_2771620_OrderedMap<u64, Unk_dd1d70>::__base::__emplace_unique_key_args<
    u64,
    const std::piecewise_construct_t&,
    std::tuple<const u64&>,
    std::tuple<>>(const u64&,
                  const std::piecewise_construct_t&,
                  std::tuple<const u64&>&&,
                  std::tuple<>&&);
// 0x7100dd1f00
template std::pair<Unk_2771620_OrderedMap<u64, Unk_dd1f00>::__base::iterator, bool>
Unk_2771620_OrderedMap<u64, Unk_dd1f00>::__base::__emplace_unique_key_args<
    u64,
    const std::piecewise_construct_t&,
    std::tuple<const u64&>,
    std::tuple<>>(const u64&,
                  const std::piecewise_construct_t&,
                  std::tuple<const u64&>&&,
                  std::tuple<>&&);
// 0x7100dd2090
template std::pair<Unk_2771620_OrderedMap<u32, Unk_dd2090>::__base::iterator, bool>
Unk_2771620_OrderedMap<u32, Unk_dd2090>::__base::__emplace_unique_key_args<
    u32,
    const std::piecewise_construct_t&,
    std::tuple<const u32&>,
    std::tuple<>>(const u32&,
                  const std::piecewise_construct_t&,
                  std::tuple<const u32&>&&,
                  std::tuple<>&&);
// 0x7100dd2330
template std::pair<Unk_2771620_OrderedMap<u64, Unk_dd2330>::__base::iterator, bool>
Unk_2771620_OrderedMap<u64, Unk_dd2330>::__base::__emplace_unique_key_args<
    u64,
    const std::piecewise_construct_t&,
    std::tuple<const u64&>,
    std::tuple<>>(const u64&,
                  const std::piecewise_construct_t&,
                  std::tuple<const u64&>&&,
                  std::tuple<>&&);
