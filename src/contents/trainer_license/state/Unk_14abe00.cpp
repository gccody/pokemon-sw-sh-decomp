// Scope: common
//
// The League Card views' parts (Unk_14abe00.h): what a part's slot value is
// passed to, and the second table's objects.
#include <algorithm>

#include "contents/trainer_license/state/Unk_14abe00.h"

struct Unk_67bdb0;

// Placeholders: the signatures are what the calls pass.
void Unk_130adb0(void* part, u64 arg, u64 slot, u32 arg2, u32 arg3);
void Unk_130b180_call(void* part, const Unk_67bdb0* arg, u64 slot, u32 arg2, u32 arg3);
void Unk_1311c60_call(Unk_1311c60* self, void* value, void* arg2);
void Unk_685cc0(void* layout, u8 value);

// The second table's objects: slot 14 takes a flag.
class Unk_14ac3c0_Object : public Unk_239a418 {
public:
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14(bool flag, bool arg);
};

// 0x71014abe00
void Unk_14abe00(void* self, void* key, void* arg, u32 arg2) {
    Unk_14abe00_Parts* parts = static_cast<Unk_14abe00_Parts*>(self);
    Unk_14abe00_Part* part =
        Unk_14abe00_As<Unk_27789b0>(parts->Unk_GetPart(*static_cast<const u64*>(key)));
    Unk_130adb0(part, reinterpret_cast<u64>(arg), parts->Unk_GetSlot(part), arg2, parts->field_2f8);
}

// 0x71014ac040
void Unk_14ac040(u64 self, u64 key, u64 arg, u32 arg2) {
    Unk_14abe00_Parts* parts = reinterpret_cast<Unk_14abe00_Parts*>(self);
    Unk_14abe00_Part* part =
        Unk_14abe00_As<Unk_27789b0>(parts->Unk_GetPart(*reinterpret_cast<const u64*>(key)));
    Unk_130b180_call(part, reinterpret_cast<const Unk_67bdb0*>(arg), parts->Unk_GetSlot(part), arg2,
                     parts->field_2f8);
}

// 0x71014ac280
void Unk_14ac280(Unk_14abe00_Parts* self, Unk_14abe00_Part* part, const Unk_67bdb0* arg, u32 arg2) {
    Unk_130b180_call(part, arg, self->Unk_GetSlot(part), arg2, self->field_2f8);
}

// 0x71014ac370
void Unk_14ac370(Unk_14abe00_Parts* self, u64 key, u32 arg) {
    Unk_1311c60_call(self->field_2e0, self->field_2f0, self->field_2e8);
    Unk_14ac040(reinterpret_cast<u64>(self), key, reinterpret_cast<u64>(self->field_2f0), arg);
}

// 0x71014ac3c0
void Unk_14ac3c0(u64 self, u32 flag) {
    Unk_14abe00_Parts* parts = reinterpret_cast<Unk_14abe00_Parts*>(self);
    const bool on = flag & 1;
    Unk_14aaec0_Table<Unk_14abaa0_Entry>& table = parts->field_140;
    for (Unk_14abaa0_Entry *e = table.data, *end = table.data + table.size; e != end; ++e)
        static_cast<Unk_14ac3c0_Object*>(e->object.m_ptr)->vf14(on, false);
    parts->field_2fc = on;
}

// 0x71014ac430
// NON_MATCHING: the table's data and the clamped value swap registers (x9/x10),
// and the loop's end is computed after its pointer.
void Unk_14ac430(Unk_14abe00_Parts* self, s32 value) {
    for (Unk_14abaa0_Entry e : self->field_140)
        Unk_685cc0(e.object.m_ptr, std::min(std::max(value, 0), 0xff));
}
