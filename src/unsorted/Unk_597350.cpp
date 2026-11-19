// Scope: common
// rehash and __rehash of unordered_maps keyed by u64 or u32 whose memory comes
// from Unk_2771620's allocator, like Unk_23c4ef0_Map (src/unsorted/Unk_23c4ef0.h).
// Their code doesn't depend on the mapped type, which isn't known: each map gets
// a placeholder, named after its __rehash. Their users aren't decompiled yet.
#include <types.h>

#include "unsorted/Unk_2771620.h"

// The mapped type of the map whose __rehash is 0x7100597460.
struct Unk_597460 {};  // its layout isn't known (nothing here reads it)

// 0x7100597350
template void Unk_2771620_Map<u64, Unk_597460>::__table::rehash(size_t);
// 0x7100597460
template void Unk_2771620_Map<u64, Unk_597460>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x7100598130.
struct Unk_598130 {};  // its layout isn't known (nothing here reads it)

// 0x7100598020
template void Unk_2771620_Map<u64, Unk_598130>::__table::rehash(size_t);
// 0x7100598130
template void Unk_2771620_Map<u64, Unk_598130>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x71005bab50.
struct Unk_5bab50 {};  // its layout isn't known (nothing here reads it)

// 0x71005baa40
template void Unk_2771620_Map<u64, Unk_5bab50>::__table::rehash(size_t);
// 0x71005bab50
template void Unk_2771620_Map<u64, Unk_5bab50>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x71005baf20.
struct Unk_5baf20 {};  // its layout isn't known (nothing here reads it)

// 0x71005bae10
template void Unk_2771620_Map<u64, Unk_5baf20>::__table::rehash(size_t);
// 0x71005baf20
template void Unk_2771620_Map<u64, Unk_5baf20>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x71005c0670.
struct Unk_5c0670 {};  // its layout isn't known (nothing here reads it)

// 0x71005c0560
template void Unk_2771620_Map<u64, Unk_5c0670>::__table::rehash(size_t);
// 0x71005c0670
template void Unk_2771620_Map<u64, Unk_5c0670>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x71005d0780.
struct Unk_5d0780 {};  // its layout isn't known (nothing here reads it)

// 0x71005d0670
template void Unk_2771620_Map<u64, Unk_5d0780>::__table::rehash(size_t);
// 0x71005d0780
template void Unk_2771620_Map<u64, Unk_5d0780>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x71005e5d80.
struct Unk_5e5d80 {};  // its layout isn't known (nothing here reads it)

// 0x71005e5c70
template void Unk_2771620_Map<u32, Unk_5e5d80>::__table::rehash(size_t);
// 0x71005e5d80
template void Unk_2771620_Map<u32, Unk_5e5d80>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x71005fa220.
struct Unk_5fa220 {};  // its layout isn't known (nothing here reads it)

// 0x71005fa110
template void Unk_2771620_Map<u64, Unk_5fa220>::__table::rehash(size_t);
// 0x71005fa220
template void Unk_2771620_Map<u64, Unk_5fa220>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x710063ecc0.
struct Unk_63ecc0 {};  // its layout isn't known (nothing here reads it)

// 0x710063ebb0
template void Unk_2771620_Map<u32, Unk_63ecc0>::__table::rehash(size_t);
// 0x710063ecc0
template void Unk_2771620_Map<u32, Unk_63ecc0>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x7100675be0.
struct Unk_675be0 {};  // its layout isn't known (nothing here reads it)

// 0x7100675ad0
template void Unk_2771620_Map<u64, Unk_675be0>::__table::rehash(size_t);
// 0x7100675be0
template void Unk_2771620_Map<u64, Unk_675be0>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x71006769a0.
struct Unk_6769a0 {};  // its layout isn't known (nothing here reads it)

// 0x7100676890
template void Unk_2771620_Map<u32, Unk_6769a0>::__table::rehash(size_t);
// 0x71006769a0
template void Unk_2771620_Map<u32, Unk_6769a0>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x7100677330.
struct Unk_677330 {};  // its layout isn't known (nothing here reads it)

// 0x7100677220
template void Unk_2771620_Map<u32, Unk_677330>::__table::rehash(size_t);
// 0x7100677330
template void Unk_2771620_Map<u32, Unk_677330>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x71006788f0.
struct Unk_6788f0 {};  // its layout isn't known (nothing here reads it)

// 0x71006787e0
template void Unk_2771620_Map<u32, Unk_6788f0>::__table::rehash(size_t);
// 0x71006788f0
template void Unk_2771620_Map<u32, Unk_6788f0>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x7100683330.
struct Unk_683330 {};  // its layout isn't known (nothing here reads it)

// 0x7100683220
template void Unk_2771620_Map<u64, Unk_683330>::__table::rehash(size_t);
// 0x7100683330
template void Unk_2771620_Map<u64, Unk_683330>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x710068cd70.
struct Unk_68cd70 {};  // its layout isn't known (nothing here reads it)

// 0x710068cc60
template void Unk_2771620_Map<u64, Unk_68cd70>::__table::rehash(size_t);
// 0x710068cd70
template void Unk_2771620_Map<u64, Unk_68cd70>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x7100697430.
struct Unk_697430 {};  // its layout isn't known (nothing here reads it)

// 0x7100697320
template void Unk_2771620_Map<u64, Unk_697430>::__table::rehash(size_t);
// 0x7100697430
template void Unk_2771620_Map<u64, Unk_697430>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x7100697800.
struct Unk_697800 {};  // its layout isn't known (nothing here reads it)

// 0x71006976f0
template void Unk_2771620_Map<u64, Unk_697800>::__table::rehash(size_t);
// 0x7100697800
template void Unk_2771620_Map<u64, Unk_697800>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x7100697e60.
struct Unk_697e60 {};  // its layout isn't known (nothing here reads it)

// 0x7100697d50
template void Unk_2771620_Map<u64, Unk_697e60>::__table::rehash(size_t);
// 0x7100697e60
template void Unk_2771620_Map<u64, Unk_697e60>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x710069c6c0.
struct Unk_69c6c0 {};  // its layout isn't known (nothing here reads it)

// 0x710069c5b0
template void Unk_2771620_Map<u32, Unk_69c6c0>::__table::rehash(size_t);
// 0x710069c6c0
template void Unk_2771620_Map<u32, Unk_69c6c0>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x710069ca90.
struct Unk_69ca90 {};  // its layout isn't known (nothing here reads it)

// 0x710069c980
template void Unk_2771620_Map<u32, Unk_69ca90>::__table::rehash(size_t);
// 0x710069ca90
template void Unk_2771620_Map<u32, Unk_69ca90>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x7100792b60.
struct Unk_792b60 {};  // its layout isn't known (nothing here reads it)

// 0x7100792a50
template void Unk_2771620_Map<u64, Unk_792b60>::__table::rehash(size_t);
// 0x7100792b60
template void Unk_2771620_Map<u64, Unk_792b60>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x7100792f30.
struct Unk_792f30 {};  // its layout isn't known (nothing here reads it)

// 0x7100792e20
template void Unk_2771620_Map<u64, Unk_792f30>::__table::rehash(size_t);
// 0x7100792f30
template void Unk_2771620_Map<u64, Unk_792f30>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x71007c1e50.
struct Unk_7c1e50 {};  // its layout isn't known (nothing here reads it)

// 0x71007c1d40
template void Unk_2771620_Map<u64, Unk_7c1e50>::__table::rehash(size_t);
// 0x71007c1e50
template void Unk_2771620_Map<u64, Unk_7c1e50>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x7100967ff0.
struct Unk_967ff0 {};  // its layout isn't known (nothing here reads it)

// 0x7100967ee0
template void Unk_2771620_Map<u32, Unk_967ff0>::__table::rehash(size_t);
// 0x7100967ff0
template void Unk_2771620_Map<u32, Unk_967ff0>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x7100968e40.
struct Unk_968e40 {};  // its layout isn't known (nothing here reads it)

// 0x7100a67dc0
template void Unk_2771620_Map<u32, Unk_968e40>::__table::rehash(size_t);
// 0x7100968e40
template void Unk_2771620_Map<u32, Unk_968e40>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x7100969100.
struct Unk_969100 {};  // its layout isn't known (nothing here reads it)

// 0x7100a66b70
template void Unk_2771620_Map<u32, Unk_969100>::__table::rehash(size_t);
// 0x7100969100
template void Unk_2771620_Map<u32, Unk_969100>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x71009698a0.
struct Unk_9698a0 {};  // its layout isn't known (nothing here reads it)

// 0x7100969790
template void Unk_2771620_Map<u32, Unk_9698a0>::__table::rehash(size_t);
// 0x71009698a0
template void Unk_2771620_Map<u32, Unk_9698a0>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x710096b680.
struct Unk_96b680 {};  // its layout isn't known (nothing here reads it)

// 0x710096b570
template void Unk_2771620_Map<u64, Unk_96b680>::__table::rehash(size_t);
// 0x710096b680
template void Unk_2771620_Map<u64, Unk_96b680>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x7100bc6eb0.
struct Unk_bc6eb0 {};  // its layout isn't known (nothing here reads it)

// 0x7100bc6da0
template void Unk_2771620_Map<u32, Unk_bc6eb0>::__table::rehash(size_t);
// 0x7100bc6eb0
template void Unk_2771620_Map<u32, Unk_bc6eb0>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x7100bc7280.
struct Unk_bc7280 {};  // its layout isn't known (nothing here reads it)

// 0x7100bc7170
template void Unk_2771620_Map<u32, Unk_bc7280>::__table::rehash(size_t);
// 0x7100bc7280
template void Unk_2771620_Map<u32, Unk_bc7280>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x7100c111c0.
struct Unk_c111c0 {};  // its layout isn't known (nothing here reads it)

// 0x7100c110b0
template void Unk_2771620_Map<u32, Unk_c111c0>::__table::rehash(size_t);
// 0x7100c111c0
template void Unk_2771620_Map<u32, Unk_c111c0>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x7100c51280.
struct Unk_c51280 {};  // its layout isn't known (nothing here reads it)

// 0x7100c51170
template void Unk_2771620_Map<u64, Unk_c51280>::__table::rehash(size_t);
// 0x7100c51280
template void Unk_2771620_Map<u64, Unk_c51280>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x7100c80e40.
struct Unk_c80e40 {};  // its layout isn't known (nothing here reads it)

// 0x7100c80d30
template void Unk_2771620_Map<u64, Unk_c80e40>::__table::rehash(size_t);
// 0x7100c80e40
template void Unk_2771620_Map<u64, Unk_c80e40>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x7100d48c60.
struct Unk_d48c60 {};  // its layout isn't known (nothing here reads it)

// 0x7100d48b50
template void Unk_2771620_Map<u64, Unk_d48c60>::__table::rehash(size_t);
// 0x7100d48c60
template void Unk_2771620_Map<u64, Unk_d48c60>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x7100de49c0.
struct Unk_de49c0 {};  // its layout isn't known (nothing here reads it)

// 0x7100de48b0
template void Unk_2771620_Map<u64, Unk_de49c0>::__table::rehash(size_t);
// 0x7100de49c0
template void Unk_2771620_Map<u64, Unk_de49c0>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x7100de8710.
struct Unk_de8710 {};  // its layout isn't known (nothing here reads it)

// 0x7100de8600
template void Unk_2771620_Map<u64, Unk_de8710>::__table::rehash(size_t);
// 0x7100de8710
template void Unk_2771620_Map<u64, Unk_de8710>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x7100de9dd0.
struct Unk_de9dd0 {};  // its layout isn't known (nothing here reads it)

// 0x7100de9cc0
template void Unk_2771620_Map<u64, Unk_de9dd0>::__table::rehash(size_t);
// 0x7100de9dd0
template void Unk_2771620_Map<u64, Unk_de9dd0>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x7100deb6b0.
struct Unk_deb6b0 {};  // its layout isn't known (nothing here reads it)

// 0x7100deb5a0
template void Unk_2771620_Map<u64, Unk_deb6b0>::__table::rehash(size_t);
// 0x7100deb6b0
template void Unk_2771620_Map<u64, Unk_deb6b0>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x7100e9ac70.
struct Unk_e9ac70 {};  // its layout isn't known (nothing here reads it)

// 0x7100e9ab60
template void Unk_2771620_Map<u64, Unk_e9ac70>::__table::rehash(size_t);
// 0x7100e9ac70
template void Unk_2771620_Map<u64, Unk_e9ac70>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x7100edf790.
struct Unk_edf790 {};  // its layout isn't known (nothing here reads it)

// 0x7100edf680
template void Unk_2771620_Map<u64, Unk_edf790>::__table::rehash(size_t);
// 0x7100edf790
template void Unk_2771620_Map<u64, Unk_edf790>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x7100edfb60.
struct Unk_edfb60 {};  // its layout isn't known (nothing here reads it)

// 0x7100edfa50
template void Unk_2771620_Map<u64, Unk_edfb60>::__table::rehash(size_t);
// 0x7100edfb60
template void Unk_2771620_Map<u64, Unk_edfb60>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x7100ef8ea0.
struct Unk_ef8ea0 {};  // its layout isn't known (nothing here reads it)

// 0x7100ef8d90
template void Unk_2771620_Map<u64, Unk_ef8ea0>::__table::rehash(size_t);
// 0x7100ef8ea0
template void Unk_2771620_Map<u64, Unk_ef8ea0>::__table::__rehash(size_t);

// The maps of Unk_112dd40 and Unk_112e110 (0x710112dc30-0x710112e110) are
// instantiated by their users, in src/contents/pokecamp/source/Unk_112a570.cpp.

// The mapped type of the map whose __rehash is 0x71012f8ff0.
struct Unk_12f8ff0 {};  // its layout isn't known (nothing here reads it)

// 0x71012f8ee0
template void Unk_2771620_Map<u64, Unk_12f8ff0>::__table::rehash(size_t);
// 0x71012f8ff0
template void Unk_2771620_Map<u64, Unk_12f8ff0>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x710135cce0.
struct Unk_135cce0 {};  // its layout isn't known (nothing here reads it)

// 0x710135cbd0
template void Unk_2771620_Map<u64, Unk_135cce0>::__table::rehash(size_t);
// 0x710135cce0
template void Unk_2771620_Map<u64, Unk_135cce0>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x710135db30.
struct Unk_135db30 {};  // its layout isn't known (nothing here reads it)

// 0x710135da20
template void Unk_2771620_Map<u64, Unk_135db30>::__table::rehash(size_t);
// 0x710135db30
template void Unk_2771620_Map<u64, Unk_135db30>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x71013a2bb0.
struct Unk_13a2bb0 {};  // its layout isn't known (nothing here reads it)

// 0x71013a2aa0
template void Unk_2771620_Map<u64, Unk_13a2bb0>::__table::rehash(size_t);
// 0x71013a2bb0
template void Unk_2771620_Map<u64, Unk_13a2bb0>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x71013e58a0.
struct Unk_13e58a0 {};  // its layout isn't known (nothing here reads it)

// 0x71013e5790
template void Unk_2771620_Map<u64, Unk_13e58a0>::__table::rehash(size_t);
// 0x71013e58a0
template void Unk_2771620_Map<u64, Unk_13e58a0>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x71013faf90.
struct Unk_13faf90 {};  // its layout isn't known (nothing here reads it)

// 0x71013fae80
template void Unk_2771620_Map<u64, Unk_13faf90>::__table::rehash(size_t);
// 0x71013faf90
template void Unk_2771620_Map<u64, Unk_13faf90>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x710140c4d0.
struct Unk_140c4d0 {};  // its layout isn't known (nothing here reads it)

// 0x710140c3c0
template void Unk_2771620_Map<u64, Unk_140c4d0>::__table::rehash(size_t);
// 0x710140c4d0
template void Unk_2771620_Map<u64, Unk_140c4d0>::__table::__rehash(size_t);
