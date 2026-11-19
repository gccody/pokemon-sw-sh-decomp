// Scope: common
// Members of vectors on Unk_2771620's allocator that Game Freak's code (game,
// gflib3, gflnet3) instantiates out of line, for elements that are trivially
// copyable: the code depends only on the element's size and alignment. Each
// element type is a placeholder of that size and alignment, named after the
// function (the vectors' users aren't decompiled, so which of them share an
// element type isn't known).
#include <types.h>
#include <vector>

#include "unsorted/Unk_2771620.h"

template <class T>
using Unk_2771620_Vector = std::vector<T, Unk_2771620_Allocator<T>>;

struct alignas(2) Unk_5a1660 {
    u8 _0[0x2];
};
struct alignas(8) Unk_5a1ae0 {
    u8 _0[0x8];
};
struct alignas(8) Unk_5a8c10 {
    u8 _0[0x10];
};
struct alignas(4) Unk_5ab480 {
    u8 _0[0xc];
};
struct alignas(16) Unk_5ab6d0 {
    u8 _0[0x20];
};
struct alignas(16) Unk_5acb00 {
    u8 _0[0xf0];
};
struct alignas(8) Unk_5bc5b0 {
    u8 _0[0x8];
};
struct alignas(16) Unk_5c21f0 {
    u8 _0[0x50];
};
struct alignas(8) Unk_5c3e00 {
    u8 _0[0x8];
};
struct alignas(8) Unk_5c4d70 {
    u8 _0[0x8];
};
struct alignas(4) Unk_5cf3d0 {
    u8 _0[0xc];
};
struct alignas(2) Unk_5cf620 {
    u8 _0[0x2];
};
struct alignas(8) Unk_5d4700 {
    u8 _0[0x8];
};
struct alignas(8) Unk_5d4f50 {
    u8 _0[0x8];
};
struct alignas(4) Unk_5e1f80 {
    u8 _0[0x14];
};
struct alignas(8) Unk_5ff400 {
    u8 _0[0x18];
};
struct alignas(16) Unk_612d50 {
    u8 _0[0x130];
};
struct alignas(4) Unk_615370 {
    u8 _0[0x4];
};
struct alignas(16) Unk_615690 {
    u8 _0[0x10];
};
struct alignas(16) Unk_6157f0 {
    u8 _0[0x10];
};
struct alignas(4) Unk_615ec0 {
    u8 _0[0x4];
};
struct alignas(4) Unk_619d00 {
    u8 _0[0x14];
};
struct alignas(8) Unk_629860 {
    u8 _0[0x8];
};
struct alignas(4) Unk_631620 {
    u8 _0[0x8];
};
struct alignas(16) Unk_652640 {
    u8 _0[0x40];
};
struct alignas(16) Unk_653bf0 {
    u8 _0[0x40];
};
struct alignas(16) Unk_656010 {
    u8 _0[0x40];
};
struct alignas(8) Unk_696620 {
    u8 _0[0x8];
};
struct alignas(8) Unk_6b87e0 {
    u8 _0[0x20];
};
struct alignas(8) Unk_a704f0 {
    u8 _0[0x80];
};
struct alignas(8) Unk_c260c0 {
    u8 _0[0x140];
};
struct alignas(8) Unk_c66cc0 {
    u8 _0[0x8];
};
struct alignas(8) Unk_c6a170 {
    u8 _0[0x8];
};
struct alignas(8) Unk_c71f10 {
    u8 _0[0x18];
};
struct alignas(16) Unk_c8f560 {
    u8 _0[0x20];
};
struct alignas(8) Unk_cb7cc0 {
    u8 _0[0x8];
};
struct alignas(8) Unk_d28bc0 {
    u8 _0[0x8];
};
struct alignas(4) Unk_d5c500 {
    u8 _0[0x8];
};
struct alignas(16) Unk_d68980 {
    u8 _0[0x30];
};
struct alignas(16) Unk_d6a8a0 {
    u8 _0[0x30];
};
struct alignas(8) Unk_dd24c0 {
    u8 _0[0x8];
};
struct alignas(8) Unk_dd26e0 {
    u8 _0[0x8];
};
struct alignas(8) Unk_ddaaa0 {
    u8 _0[0x8];
};
struct alignas(16) Unk_e4bb70 {
    u8 _0[0x30];
};
struct alignas(8) Unk_e53300 {
    u8 _0[0x28];
};
struct alignas(16) Unk_e56440 {
    u8 _0[0x30];
};
struct alignas(4) Unk_ee06d0 {
    u8 _0[0x8];
};
struct alignas(8) Unk_f17920 {
    u8 _0[0x8];
};
struct alignas(8) Unk_f6eea0 {
    u8 _0[0x68];
};
struct alignas(8) Unk_fefa30 {
    u8 _0[0x28];
};
struct alignas(8) Unk_1020db0 {
    u8 _0[0x28];
};
struct alignas(8) Unk_1021170 {
    u8 _0[0x160];
};
struct alignas(8) Unk_1046520 {
    u8 _0[0x80];
};
struct alignas(8) Unk_10471d0 {
    u8 _0[0x80];
};
struct alignas(8) Unk_10473b0 {
    u8 _0[0x80];
};
struct alignas(8) Unk_106b1d0 {
    u8 _0[0x40];
};
struct alignas(8) Unk_106b350 {
    u8 _0[0x28];
};
struct alignas(4) Unk_1115d40 {
    u8 _0[0xc];
};
struct alignas(2) Unk_1115fa0 {
    u8 _0[0x2];
};
struct alignas(4) Unk_1117e20 {
    u8 _0[0xc];
};
struct alignas(2) Unk_1118010 {
    u8 _0[0x2];
};
struct alignas(8) Unk_1131490 {
    u8 _0[0x10];
};
struct alignas(8) Unk_1133f40 {
    u8 _0[0x8];
};
struct alignas(8) Unk_11600b0 {
    u8 _0[0x10];
};
struct alignas(8) Unk_1160210 {
    u8 _0[0x8];
};
struct alignas(16) Unk_11691e0 {
    u8 _0[0x30];
};
struct alignas(16) Unk_1169ff0 {
    u8 _0[0x30];
};
struct alignas(16) Unk_11736c0 {
    u8 _0[0x20];
};
struct alignas(16) Unk_1173fa0 {
    u8 _0[0x20];
};
struct alignas(8) Unk_139a410 {
    u8 _0[0x20];
};
struct alignas(16) Unk_13ccaa0 {
    u8 _0[0x10];
};
struct alignas(8) Unk_13fbae0 {
    u8 _0[0x28];
};
struct alignas(8) Unk_14f7ad0 {
    u8 _0[0x18];
};

// 0x71005a1660
template void Unk_2771620_Vector<Unk_5a1660>::__append(size_t);
// 0x71005a1ae0
template void Unk_2771620_Vector<Unk_5a1ae0>::__append(size_t);
// 0x71005a8c10
template void Unk_2771620_Vector<Unk_5a8c10>::reserve(size_t);
// 0x71005ab480
template void Unk_2771620_Vector<Unk_5ab480>::__append(size_t);
// 0x71005ab6d0
template void Unk_2771620_Vector<Unk_5ab6d0>::__append(size_t);
// 0x71005acb00
template void Unk_2771620_Vector<Unk_5acb00>::reserve(size_t);
// 0x71005bc5b0
template void Unk_2771620_Vector<Unk_5bc5b0>::reserve(size_t);
// 0x71005c21f0
template void Unk_2771620_Vector<Unk_5c21f0>::reserve(size_t);
// 0x71005c3e00
template void Unk_2771620_Vector<Unk_5c3e00>::reserve(size_t);
// 0x71005c4d70
template void Unk_2771620_Vector<Unk_5c4d70>::__append(size_t);
// 0x71005cf3d0
template void Unk_2771620_Vector<Unk_5cf3d0>::__append(size_t);
// 0x71005cf620
template void Unk_2771620_Vector<Unk_5cf620>::__append(size_t);
// 0x71005d4700
template void Unk_2771620_Vector<Unk_5d4700>::reserve(size_t);
// 0x71005d4f50
template Unk_5d4f50* Unk_2771620_Vector<Unk_5d4f50>::__swap_out_circular_buffer(
    std::__split_buffer<Unk_5d4f50, Unk_2771620_Allocator<Unk_5d4f50>&>&,
    Unk_5d4f50*);
// 0x71005e1f80
template void Unk_2771620_Vector<Unk_5e1f80>::__push_back_slow_path<const Unk_5e1f80&>(
    const Unk_5e1f80&);
// 0x71005ff400
template void Unk_2771620_Vector<Unk_5ff400>::__push_back_slow_path<const Unk_5ff400&>(
    const Unk_5ff400&);
// 0x7100612d50
template void Unk_2771620_Vector<Unk_612d50>::reserve(size_t);
// 0x7100615370
template void Unk_2771620_Vector<Unk_615370>::reserve(size_t);
// 0x7100615690
template void Unk_2771620_Vector<Unk_615690>::reserve(size_t);
// 0x71006157f0
template void Unk_2771620_Vector<Unk_6157f0>::__push_back_slow_path<const Unk_6157f0&>(
    const Unk_6157f0&);
// 0x7100615ec0
template void Unk_2771620_Vector<Unk_615ec0>::__append(size_t);
// 0x7100619d00
template void Unk_2771620_Vector<Unk_619d00>::__push_back_slow_path<const Unk_619d00&>(
    const Unk_619d00&);
// 0x7100629860
template void Unk_2771620_Vector<Unk_629860>::reserve(size_t);
// 0x7100631620
template void Unk_2771620_Vector<Unk_631620>::__append(size_t);
// 0x7100652640
template void Unk_2771620_Vector<Unk_652640>::reserve(size_t);
// 0x7100653bf0
template void Unk_2771620_Vector<Unk_653bf0>::__push_back_slow_path<const Unk_653bf0&>(
    const Unk_653bf0&);
// 0x7100656010
template void Unk_2771620_Vector<Unk_656010>::__push_back_slow_path<const Unk_656010&>(
    const Unk_656010&);
// 0x7100696620
template void Unk_2771620_Vector<Unk_696620>::__append(size_t);
// 0x71006b87e0
template void Unk_2771620_Vector<Unk_6b87e0>::__push_back_slow_path<const Unk_6b87e0&>(
    const Unk_6b87e0&);
// 0x7100a704f0
template void Unk_2771620_Vector<Unk_a704f0>::assign<Unk_a704f0*>(Unk_a704f0*, Unk_a704f0*);
// 0x7100c260c0
template void Unk_2771620_Vector<Unk_c260c0>::__push_back_slow_path<const Unk_c260c0&>(
    const Unk_c260c0&);
// 0x7100c66cc0
template void Unk_2771620_Vector<Unk_c66cc0>::reserve(size_t);
// 0x7100c6a170
template void Unk_2771620_Vector<Unk_c6a170>::reserve(size_t);
// 0x7100c71f10
template void Unk_2771620_Vector<Unk_c71f10>::__push_back_slow_path<const Unk_c71f10&>(
    const Unk_c71f10&);
// 0x7100c8f560
template void Unk_2771620_Vector<Unk_c8f560>::__push_back_slow_path<const Unk_c8f560&>(
    const Unk_c8f560&);
// 0x7100cb7cc0
template void Unk_2771620_Vector<Unk_cb7cc0>::reserve(size_t);
// 0x7100d28bc0
template void Unk_2771620_Vector<Unk_d28bc0>::reserve(size_t);
// 0x7100d5c500
template void Unk_2771620_Vector<Unk_d5c500>::__push_back_slow_path<const Unk_d5c500&>(
    const Unk_d5c500&);
// 0x7100d68980
template void Unk_2771620_Vector<Unk_d68980>::reserve(size_t);
// 0x7100d6a8a0
template Unk_d6a8a0* Unk_2771620_Vector<Unk_d6a8a0>::__swap_out_circular_buffer(
    std::__split_buffer<Unk_d6a8a0, Unk_2771620_Allocator<Unk_d6a8a0>&>&,
    Unk_d6a8a0*);
// 0x7100dd24c0
template void Unk_2771620_Vector<Unk_dd24c0>::__append(size_t);
// 0x7100dd26e0
template void Unk_2771620_Vector<Unk_dd26e0>::__append(size_t);
// 0x7100ddaaa0
template void Unk_2771620_Vector<Unk_ddaaa0>::__append(size_t);
// 0x7100e4bb70
template void Unk_2771620_Vector<Unk_e4bb70>::reserve(size_t);
// 0x7100e53300
template void Unk_2771620_Vector<Unk_e53300>::__push_back_slow_path<const Unk_e53300&>(
    const Unk_e53300&);
// 0x7100e56440
template Unk_e56440* Unk_2771620_Vector<Unk_e56440>::__swap_out_circular_buffer(
    std::__split_buffer<Unk_e56440, Unk_2771620_Allocator<Unk_e56440>&>&,
    Unk_e56440*);
// 0x7100ee06d0
template void Unk_2771620_Vector<Unk_ee06d0>::__push_back_slow_path<const Unk_ee06d0&>(
    const Unk_ee06d0&);
// 0x7100f17920
template void Unk_2771620_Vector<Unk_f17920>::reserve(size_t);
// 0x7100f6eea0
template void Unk_2771620_Vector<Unk_f6eea0>::__push_back_slow_path<const Unk_f6eea0&>(
    const Unk_f6eea0&);
// 0x7100fefa30
template void Unk_2771620_Vector<Unk_fefa30>::__push_back_slow_path<const Unk_fefa30&>(
    const Unk_fefa30&);
// 0x7101020db0
template void Unk_2771620_Vector<Unk_1020db0>::__push_back_slow_path<const Unk_1020db0&>(
    const Unk_1020db0&);
// 0x7101021170
template void Unk_2771620_Vector<Unk_1021170>::__push_back_slow_path<const Unk_1021170&>(
    const Unk_1021170&);
// 0x7101046520
template void Unk_2771620_Vector<Unk_1046520>::reserve(size_t);
// 0x71010471d0
template Unk_10471d0* Unk_2771620_Vector<Unk_10471d0>::__swap_out_circular_buffer(
    std::__split_buffer<Unk_10471d0, Unk_2771620_Allocator<Unk_10471d0>&>&,
    Unk_10471d0*);
// 0x71010473b0
template void Unk_2771620_Vector<Unk_10473b0>::__push_back_slow_path<const Unk_10473b0&>(
    const Unk_10473b0&);
// 0x710106b1d0
template void Unk_2771620_Vector<Unk_106b1d0>::reserve(size_t);
// 0x710106b350
template void Unk_2771620_Vector<Unk_106b350>::reserve(size_t);
// 0x7101115d40
template void Unk_2771620_Vector<Unk_1115d40>::assign<Unk_1115d40*>(Unk_1115d40*, Unk_1115d40*);
// 0x7101115fa0
template void Unk_2771620_Vector<Unk_1115fa0>::assign<Unk_1115fa0*>(Unk_1115fa0*, Unk_1115fa0*);
// 0x7101117e20
template void Unk_2771620_Vector<Unk_1117e20>::__push_back_slow_path<const Unk_1117e20&>(
    const Unk_1117e20&);
// 0x7101118010
template void Unk_2771620_Vector<Unk_1118010>::__push_back_slow_path<const Unk_1118010&>(
    const Unk_1118010&);
// 0x7101131490
template void Unk_2771620_Vector<Unk_1131490>::reserve(size_t);
// 0x7101133f40
template void Unk_2771620_Vector<Unk_1133f40>::reserve(size_t);
// 0x71011600b0
template void Unk_2771620_Vector<Unk_11600b0>::reserve(size_t);
// 0x7101160210
template void Unk_2771620_Vector<Unk_1160210>::reserve(size_t);
// 0x71011691e0
template void Unk_2771620_Vector<Unk_11691e0>::reserve(size_t);
// 0x7101169ff0
template void Unk_2771620_Vector<Unk_1169ff0>::__push_back_slow_path<const Unk_1169ff0&>(
    const Unk_1169ff0&);
// 0x71011736c0
template void Unk_2771620_Vector<Unk_11736c0>::reserve(size_t);
// 0x7101173fa0
template void Unk_2771620_Vector<Unk_1173fa0>::__push_back_slow_path<const Unk_1173fa0&>(
    const Unk_1173fa0&);
// 0x710139a410
template void Unk_2771620_Vector<Unk_139a410>::reserve(size_t);
// 0x71013ccaa0
template void Unk_2771620_Vector<Unk_13ccaa0>::__push_back_slow_path<const Unk_13ccaa0&>(
    const Unk_13ccaa0&);
// 0x71013fbae0
template void Unk_2771620_Vector<Unk_13fbae0>::__push_back_slow_path<const Unk_13fbae0&>(
    const Unk_13fbae0&);
// 0x71014f7ad0
template void Unk_2771620_Vector<Unk_14f7ad0>::__push_back_slow_path<const Unk_14f7ad0&>(
    const Unk_14f7ad0&);
