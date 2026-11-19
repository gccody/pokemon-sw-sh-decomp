// Scope: common
// Vectors of type-erased callables on Unk_2771620's allocator (game/unk_133d350,
// filled by 0x710137e4a0 and its neighbours): emplace_back's slow path, once
// per callable type. A callable is 0x80 bytes: four operations, then 0x60 bytes
// that hold the callable itself. The ones added here are empty: constructing
// one only stores its operations, which are the functions after each slow
// path (src/unsorted/leaf names them; their real signatures aren't known, so
// they're declared as leafgen wrote them and cast). Placeholder names: rename
// once the callable class is known.
#include <types.h>
#include <vector>

#include "unsorted/Unk_2771620.h"

class alignas(16) Unk_1382340_Func {
public:
    using Op = void (*)();
    using Destroy = void (*)(void* storage);
    using Move = void (*)(void* from, void* to);

    // The operations of one callable type.
    template <Op A, Op B, Op C, Op D>
    struct Ops {};

    // field_8 destroys the callable in the storage, field_18 moves it to
    // another's.
    struct Table {
        Op field_0;
        Destroy field_8;
        Op field_10;
        Move field_18;
    };

    template <Op A, Op B, Op C, Op D>
    explicit Unk_1382340_Func(Ops<A, B, C, D>&&)
        : field_0{A, reinterpret_cast<Destroy>(B), C, reinterpret_cast<Move>(D)} {}
    Unk_1382340_Func(Unk_1382340_Func&& other) : field_0() {
        if (other.field_0.field_18 != nullptr) {
            other.field_0.field_18(other.field_20, field_20);
            field_0 = other.field_0;
            other.Unk_Reset();
        }
    }
    ~Unk_1382340_Func() { Unk_Reset(); }

    // Destroys the callable, if there's one.
    void Unk_Reset() {
        if (Destroy destroy = field_0.field_8) {
            field_0.field_0 = nullptr;
            field_0.field_8 = nullptr;
            field_0.field_10 = nullptr;
            field_0.field_18 = nullptr;
            destroy(field_20);
        }
    }

    Table field_0;
    u8 field_20[0x60];
};
static_assert(sizeof(Unk_1382340_Func) == 0x80, "Unk_1382340_Func");
PKMN_OFFSET_ASSERT(Unk_1382340_Func, field_20, 0x20);

using Unk_1382340_Vector = std::vector<Unk_1382340_Func, Unk_2771620_Allocator<Unk_1382340_Func>>;

// The operations, in src/unsorted/leaf (and one here).
void Unk_13825d0_call();
void Unk_13825e0_update();
void Unk_13825f0_update();
void Unk_1382600_update();
void Unk_13828a0_update();
void Unk_13828b0_update();
void Unk_13828c0_update();
void Unk_13828d0_update();
void Unk_1382b70_update();
void Unk_1382b80_update();
void Unk_1382b90_update();
void Unk_1382ba0_update();
void Unk_1382e40_call();
void Unk_1382e50_update();
void Unk_1382e60_update();
void Unk_1382e70_update();
void Unk_1383110_update();
void Unk_1383120_update();
void Unk_1383130_update();
void Unk_1383140_update();
void Unk_13833e0_update();
void Unk_13833f0_update();
void Unk_1383400_update();
void Unk_1383410_update();
void Unk_13836b0_call();
void Unk_13836c0_update();
void Unk_13836d0_update();
void Unk_13836e0_update();
void Unk_1383980_update();
void Unk_1383990_update();
void Unk_13839a0_update();
void Unk_13839b0_update();
void Unk_1383c50_update();
void Unk_1383c60_update();
void Unk_1383c70_update();
void Unk_1383c80_update();
void Unk_1383f20_call();
void Unk_1383f30_update();
void Unk_1383f40_update();
void Unk_1383f50_update();
void Unk_13841f0_update();
void Unk_1384200_update();
void Unk_1384210_update();
void Unk_1384220_update();
void Unk_13844c0_update();
void Unk_13844d0_update();
void Unk_13844e0_update();
void Unk_13844f0_update();
void Unk_1384790_call();
void Unk_13847a0_update();
void Unk_13847b0_update();
void Unk_13847c0_update();
void Unk_1384a60_update();
void Unk_1384a70_update();
void Unk_1384a80_update();
void Unk_1384a90_update();
void Unk_1384d30_update();
void Unk_1384d40_update();
void Unk_1384d50_update();
void Unk_1384d60_update();
void Unk_1385000_call();
void Unk_1385010_update();
void Unk_1385020_update();
void Unk_1385030_update();
void Unk_13852d0_update();
void Unk_13852e0_update();
void Unk_13852f0_update();
void Unk_1385300_update();
void Unk_13855a0_call();
void Unk_13855b0_update();
void Unk_13855c0_update();
void Unk_13855d0_update();
void Unk_1385880_update();
void Unk_1385890_update();
void Unk_13858a0_update();
void Unk_1385b40_update();
void Unk_1385b50_update();
void Unk_1385b60_update();
void Unk_1385b70_update();
void Unk_1385e10_update();
void Unk_1385e20_update();
void Unk_1385e30_update();
void Unk_1385e40_update();
void Unk_13860e0_call();
void Unk_13860f0_update();
void Unk_1386100_update();
void Unk_1386110_update();
void Unk_13863b0_update();
void Unk_13863c0_update();
void Unk_13863d0_update();
void Unk_13863e0_update();
void Unk_1386680_update();
void Unk_1386690_update();
void Unk_13866a0_update();
void Unk_13866b0_update();
void Unk_136d000_call();

// 0x7101385870
void Unk_1385870_call() {
    Unk_136d000_call();
}

// 0x7101382340
template void Unk_1382340_Vector::__emplace_back_slow_path<
    Unk_1382340_Func::
        Ops<Unk_13825d0_call, Unk_13825e0_update, Unk_13825f0_update, Unk_1382600_update>>(
    Unk_1382340_Func::
        Ops<Unk_13825d0_call, Unk_13825e0_update, Unk_13825f0_update, Unk_1382600_update>&&);
// 0x7101382610
template void Unk_1382340_Vector::__emplace_back_slow_path<
    Unk_1382340_Func::
        Ops<Unk_13828a0_update, Unk_13828b0_update, Unk_13828c0_update, Unk_13828d0_update>>(
    Unk_1382340_Func::
        Ops<Unk_13828a0_update, Unk_13828b0_update, Unk_13828c0_update, Unk_13828d0_update>&&);
// 0x71013828e0
template void Unk_1382340_Vector::__emplace_back_slow_path<
    Unk_1382340_Func::
        Ops<Unk_1382b70_update, Unk_1382b80_update, Unk_1382b90_update, Unk_1382ba0_update>>(
    Unk_1382340_Func::
        Ops<Unk_1382b70_update, Unk_1382b80_update, Unk_1382b90_update, Unk_1382ba0_update>&&);
// 0x7101382bb0
template void Unk_1382340_Vector::__emplace_back_slow_path<
    Unk_1382340_Func::
        Ops<Unk_1382e40_call, Unk_1382e50_update, Unk_1382e60_update, Unk_1382e70_update>>(
    Unk_1382340_Func::
        Ops<Unk_1382e40_call, Unk_1382e50_update, Unk_1382e60_update, Unk_1382e70_update>&&);
// 0x7101382e80
template void Unk_1382340_Vector::__emplace_back_slow_path<
    Unk_1382340_Func::
        Ops<Unk_1383110_update, Unk_1383120_update, Unk_1383130_update, Unk_1383140_update>>(
    Unk_1382340_Func::
        Ops<Unk_1383110_update, Unk_1383120_update, Unk_1383130_update, Unk_1383140_update>&&);
// 0x7101383150
template void Unk_1382340_Vector::__emplace_back_slow_path<
    Unk_1382340_Func::
        Ops<Unk_13833e0_update, Unk_13833f0_update, Unk_1383400_update, Unk_1383410_update>>(
    Unk_1382340_Func::
        Ops<Unk_13833e0_update, Unk_13833f0_update, Unk_1383400_update, Unk_1383410_update>&&);
// 0x7101383420
template void Unk_1382340_Vector::__emplace_back_slow_path<
    Unk_1382340_Func::
        Ops<Unk_13836b0_call, Unk_13836c0_update, Unk_13836d0_update, Unk_13836e0_update>>(
    Unk_1382340_Func::
        Ops<Unk_13836b0_call, Unk_13836c0_update, Unk_13836d0_update, Unk_13836e0_update>&&);
// 0x71013836f0
template void Unk_1382340_Vector::__emplace_back_slow_path<
    Unk_1382340_Func::
        Ops<Unk_1383980_update, Unk_1383990_update, Unk_13839a0_update, Unk_13839b0_update>>(
    Unk_1382340_Func::
        Ops<Unk_1383980_update, Unk_1383990_update, Unk_13839a0_update, Unk_13839b0_update>&&);
// 0x71013839c0
template void Unk_1382340_Vector::__emplace_back_slow_path<
    Unk_1382340_Func::
        Ops<Unk_1383c50_update, Unk_1383c60_update, Unk_1383c70_update, Unk_1383c80_update>>(
    Unk_1382340_Func::
        Ops<Unk_1383c50_update, Unk_1383c60_update, Unk_1383c70_update, Unk_1383c80_update>&&);
// 0x7101383c90
template void Unk_1382340_Vector::__emplace_back_slow_path<
    Unk_1382340_Func::
        Ops<Unk_1383f20_call, Unk_1383f30_update, Unk_1383f40_update, Unk_1383f50_update>>(
    Unk_1382340_Func::
        Ops<Unk_1383f20_call, Unk_1383f30_update, Unk_1383f40_update, Unk_1383f50_update>&&);
// 0x7101383f60
template void Unk_1382340_Vector::__emplace_back_slow_path<
    Unk_1382340_Func::
        Ops<Unk_13841f0_update, Unk_1384200_update, Unk_1384210_update, Unk_1384220_update>>(
    Unk_1382340_Func::
        Ops<Unk_13841f0_update, Unk_1384200_update, Unk_1384210_update, Unk_1384220_update>&&);
// 0x7101384230
template void Unk_1382340_Vector::__emplace_back_slow_path<
    Unk_1382340_Func::
        Ops<Unk_13844c0_update, Unk_13844d0_update, Unk_13844e0_update, Unk_13844f0_update>>(
    Unk_1382340_Func::
        Ops<Unk_13844c0_update, Unk_13844d0_update, Unk_13844e0_update, Unk_13844f0_update>&&);
// 0x7101384500
template void Unk_1382340_Vector::__emplace_back_slow_path<
    Unk_1382340_Func::
        Ops<Unk_1384790_call, Unk_13847a0_update, Unk_13847b0_update, Unk_13847c0_update>>(
    Unk_1382340_Func::
        Ops<Unk_1384790_call, Unk_13847a0_update, Unk_13847b0_update, Unk_13847c0_update>&&);
// 0x71013847d0
template void Unk_1382340_Vector::__emplace_back_slow_path<
    Unk_1382340_Func::
        Ops<Unk_1384a60_update, Unk_1384a70_update, Unk_1384a80_update, Unk_1384a90_update>>(
    Unk_1382340_Func::
        Ops<Unk_1384a60_update, Unk_1384a70_update, Unk_1384a80_update, Unk_1384a90_update>&&);
// 0x7101384aa0
template void Unk_1382340_Vector::__emplace_back_slow_path<
    Unk_1382340_Func::
        Ops<Unk_1384d30_update, Unk_1384d40_update, Unk_1384d50_update, Unk_1384d60_update>>(
    Unk_1382340_Func::
        Ops<Unk_1384d30_update, Unk_1384d40_update, Unk_1384d50_update, Unk_1384d60_update>&&);
// 0x7101384d70
template void Unk_1382340_Vector::__emplace_back_slow_path<
    Unk_1382340_Func::
        Ops<Unk_1385000_call, Unk_1385010_update, Unk_1385020_update, Unk_1385030_update>>(
    Unk_1382340_Func::
        Ops<Unk_1385000_call, Unk_1385010_update, Unk_1385020_update, Unk_1385030_update>&&);
// 0x7101385040
template void Unk_1382340_Vector::__emplace_back_slow_path<
    Unk_1382340_Func::
        Ops<Unk_13852d0_update, Unk_13852e0_update, Unk_13852f0_update, Unk_1385300_update>>(
    Unk_1382340_Func::
        Ops<Unk_13852d0_update, Unk_13852e0_update, Unk_13852f0_update, Unk_1385300_update>&&);
// 0x7101385310
template void Unk_1382340_Vector::__emplace_back_slow_path<
    Unk_1382340_Func::
        Ops<Unk_13855a0_call, Unk_13855b0_update, Unk_13855c0_update, Unk_13855d0_update>>(
    Unk_1382340_Func::
        Ops<Unk_13855a0_call, Unk_13855b0_update, Unk_13855c0_update, Unk_13855d0_update>&&);
// 0x71013855e0
template void Unk_1382340_Vector::__emplace_back_slow_path<
    Unk_1382340_Func::
        Ops<Unk_1385870_call, Unk_1385880_update, Unk_1385890_update, Unk_13858a0_update>>(
    Unk_1382340_Func::
        Ops<Unk_1385870_call, Unk_1385880_update, Unk_1385890_update, Unk_13858a0_update>&&);
// 0x71013858b0
template void Unk_1382340_Vector::__emplace_back_slow_path<
    Unk_1382340_Func::
        Ops<Unk_1385b40_update, Unk_1385b50_update, Unk_1385b60_update, Unk_1385b70_update>>(
    Unk_1382340_Func::
        Ops<Unk_1385b40_update, Unk_1385b50_update, Unk_1385b60_update, Unk_1385b70_update>&&);
// 0x7101385b80
template void Unk_1382340_Vector::__emplace_back_slow_path<
    Unk_1382340_Func::
        Ops<Unk_1385e10_update, Unk_1385e20_update, Unk_1385e30_update, Unk_1385e40_update>>(
    Unk_1382340_Func::
        Ops<Unk_1385e10_update, Unk_1385e20_update, Unk_1385e30_update, Unk_1385e40_update>&&);
// 0x7101385e50
template void Unk_1382340_Vector::__emplace_back_slow_path<
    Unk_1382340_Func::
        Ops<Unk_13860e0_call, Unk_13860f0_update, Unk_1386100_update, Unk_1386110_update>>(
    Unk_1382340_Func::
        Ops<Unk_13860e0_call, Unk_13860f0_update, Unk_1386100_update, Unk_1386110_update>&&);
// 0x7101386120
template void Unk_1382340_Vector::__emplace_back_slow_path<
    Unk_1382340_Func::
        Ops<Unk_13863b0_update, Unk_13863c0_update, Unk_13863d0_update, Unk_13863e0_update>>(
    Unk_1382340_Func::
        Ops<Unk_13863b0_update, Unk_13863c0_update, Unk_13863d0_update, Unk_13863e0_update>&&);
// 0x71013863f0
template void Unk_1382340_Vector::__emplace_back_slow_path<
    Unk_1382340_Func::
        Ops<Unk_1386680_update, Unk_1386690_update, Unk_13866a0_update, Unk_13866b0_update>>(
    Unk_1382340_Func::
        Ops<Unk_1386680_update, Unk_1386690_update, Unk_13866a0_update, Unk_13866b0_update>&&);
