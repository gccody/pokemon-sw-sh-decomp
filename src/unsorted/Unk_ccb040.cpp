// Scope: common
// Unk_23e14a8's virtual functions, slots 16 to 25 (src/unsorted/Unk_ccac00.h;
// its key function and what's inline are in Unk_ccac00.cpp). Placeholder
// names.
#include <limits>

#include "unsorted/Unk_ccac00.h"

// 0x7100ccb030
void Unk_23e14a8::vf16(bool value) {
    field_24 = value;
}

// 0x7100ccb050
void Unk_23e14a8::vf18(bool value) {
    field_25 = value;
}

// 0x7100ccb070
void Unk_23e14a8::vf20(const Unk_Table& table) {
    field_30.Unk_c83e50(table.GetPointer<Unk_Table>(4));
}

// 0x7100ccb0c0: the squared distance from a position to where it is: the
// table field_30 gives, else the nearest of field_28's points, else vf10's.
f32 Unk_23e14a8::vf22(const float32x4_t& position) {
    if (const Unk_Table* table = field_30.Unk_c840d0()) {
        const Unk_Table* point = table->GetPointer<Unk_Table>(4);
        f32 x = point->Get<f32>(4, 0);
        f32 y = point->Get<f32>(6, 0);
        f32 z = point->Get<f32>(8, 0);
        return Unk_ccac00_LengthSq(float32x4_t{x, y, z, 0} - position);
    }
    if (field_28 == nullptr)
        return Unk_ccac00_LengthSq(vf10() - position);
    const Unk_ccac00_Tables* points = Unk_ccac00_GetRequired<Unk_ccac00_Tables>(field_28, 0xe);
    f32 nearest = std::numeric_limits<f32>::max();
    for (const Unk_Table* point : *points) {
        f32 x = point->Get<f32>(4, 0);
        f32 y = point->Get<f32>(6, 0);
        f32 z = point->Get<f32>(8, 0);
        f32 distance = Unk_ccac00_LengthSq(float32x4_t{x, y, z, 0} - position);
        nearest = distance < nearest ? distance : nearest;
    }
    return nearest;
}

// 0x7100ccb320
void Unk_23e14a8::vf24(bool value) {
    field_78 = value;
}

// 0x7100ccb330: field_28's hash at field 0x16 (FNV-1a's offset basis, the
// hash of nothing, when there's no table).
u64 Unk_23e14a8::vf25() {
    if (field_28 == nullptr)
        return 0xcbf29ce484222645;
    return field_28->GetPointer<Unk_Table>(4)->Get<u64>(0x16, 0);
}
