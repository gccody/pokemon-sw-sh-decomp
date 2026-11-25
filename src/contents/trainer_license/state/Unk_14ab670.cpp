// Scope: common
//
// The League Card views' parts and their objects (Unk_14aae90.h): attaching
// parts, adding entries to the tables and getting their objects.
#include "contents/trainer_license/state/Unk_14aae90.h"

// Placeholders: the signatures are what the calls pass.
void Unk_17ab080(void* part, void* other);
void Unk_17ab0c0(void* part, void* other);
void Unk_17ab100(void* part, void* other);
void Unk_602930(void* target, void* object);
void Unk_687770(void* object);

// What 0x7100687a20 returns: slot 6 says whether it's the one looked for.
class Unk_687a20_Result {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual bool vf6();
};

Unk_687a20_Result* Unk_687a20(void* object, u64 arg);

// 0x71014ab670
void Unk_14ab670(const Unk_14aaec0_Parts* self, const u64& key, const u64& other) {
    Unk_17ab080(self->Unk_GetPart(key), self->Unk_GetPart(other));
}

// 0x71014ab740
void Unk_14ab740(const Unk_14aaec0_Parts* self, const u64& key, const u64& other) {
    Unk_17ab0c0(self->Unk_GetPart(key), self->Unk_GetPart(other));
}

// 0x71014ab810
void Unk_14ab810(const Unk_14aaec0_Parts* self, const u64& key, const u64& other) {
    Unk_17ab100(self->Unk_GetPart(key), self->Unk_GetPart(other));
}

// 0x71014ab8e0
void Unk_14ab8e0(const Unk_14aaec0_Parts* self, const u64& key) {
    Unk_14aaec0_Part* part = self->Unk_GetPart(key);
    Unk_17ab100(part->field_18, part);
}

// 0x71014ab920
Unk_239a418_Ref2<Unk_239a418> Unk_14ab920(const Unk_14aaec0_Parts* self, const u64& key) {
    Unk_14aaec0_Iter<Unk_14abaf0_Entry> it =
        Unk_FindIf(self->field_a0.begin(), self->field_a0.end(),
                   [key](const Unk_14abaf0_Entry& e) { return e.key == key; });
    return it == self->field_a0.end() ? Unk_239a418_Ref2<Unk_239a418>(nullptr) : it->object;
}

// 0x71014ab9a0: keeps the parts' u64 placeholder signature (see
// Unk_14aae90.cpp).
void Unk_14ab9a0(u64 self, u64 key, u64 arg) {
    Unk_14aaec0_Parts* parts = reinterpret_cast<Unk_14aaec0_Parts*>(self);
    Unk_14aaec0_Part* part = parts->Unk_GetPart(*reinterpret_cast<const u64*>(key));
    Unk_14aaec0_Table<Unk_14abaf0_Entry>& table = parts->field_a0;
    for (Unk_14abaf0_Entry *e = table.data, *end = table.data + table.size; e != end; ++e) {
        Unk_687a20_Result* result = Unk_687a20(e->object.m_ptr, arg);
        if (result->vf6()) {
            part->vf11(0)->field_18->field_8 = result;
            return;
        }
    }
}

// 0x71014abaa0
void Unk_14abaa0(Unk_14aaec0_Parts* self, const u64& key, Unk_239a418_Ref2<Unk_239a418> object) {
    Unk_14acbd0(&self->field_140, {key, static_cast<Unk_239a418_Ref2<Unk_239a418>&&>(object)});
}

// 0x71014abaf0
void Unk_14abaf0(Unk_14aaec0_Parts* self,
                 const u64& key,
                 Unk_239a418_Ref2<Unk_239a418> object,
                 bool flag) {
    Unk_14acf30(&self->field_a0, {key, static_cast<Unk_239a418_Ref2<Unk_239a418>&&>(object), flag});
}

// 0x71014abb50
void Unk_14abb50(Unk_14aaec0_Parts* self, const u64& key, const Unk_14ab180_Anim& anim) {
    Unk_14ad2d0(&self->field_280, {key, anim});
}

// 0x71014abbc0
void Unk_14abbc0(Unk_14aaec0_Parts* self, const u64& key, Unk_14aaec0_Part* part) {
    Unk_14aaec0_Entry entry = {key, part};
    self->field_1e0.Unk_PushBack(entry);
}

// 0x71014abd30
void Unk_14abd30(void* self, void* target) {
    if (target == nullptr)
        return;
    Unk_14aaec0_Table<Unk_14abaa0_Entry>& table = static_cast<Unk_14aaec0_Parts*>(self)->field_140;
    for (Unk_14abaa0_Entry *e = table.data, *end = table.data + table.size; e != end; ++e)
        Unk_602930(target, e->object.m_ptr);
}

// 0x71014abc90
void Unk_14abc90(Unk_14aaec0_Parts* self, void* target) {
    Unk_14aaec0_Table<Unk_14abaf0_Entry>& table = self->field_a0;
    for (Unk_14abaf0_Entry *e = table.data, *end = table.data + table.size; e != end; ++e) {
        if (!e->flag)
            Unk_687770(e->object.m_ptr);
    }
    Unk_14abd30(self, target);
}

// 0x71014abd80
Unk_239a418_Ref2<Unk_239a418> Unk_14abd80(const Unk_14aaec0_Parts* self, const u64& key) {
    Unk_14aaec0_Iter<Unk_14abaa0_Entry> it =
        Unk_FindIf(self->field_140.begin(), self->field_140.end(),
                   [key](const Unk_14abaa0_Entry& e) { return e.key == key; });
    return it == self->field_140.end() ? Unk_239a418_Ref2<Unk_239a418>(nullptr) : it->object;
}
