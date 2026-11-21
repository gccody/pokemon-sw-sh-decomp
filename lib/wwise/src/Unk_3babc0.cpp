// Scope: common
// The TU of the switch groups' manager (Unk_3babc0.h). Placeholder names.
#include "Unk_3babc0.h"

u32 Unk_3bb280(Unk_3babc0* self, Unk_23837a8* subscriber, u32 group);
Unk_3babc0_Group* Unk_3bb7d0(Unk_3babc0* self, u32 id);
void Unk_3bb940(Unk_3babc0* self, Unk_23837a8* subscriber);

extern Unk_3babc0* Unk_24bbbc8;

// 0x71003baef0
u32 Unk_3baef0(Unk_3babc0* self) {
    for (auto it = self->field_0.BeginEx(); it != self->field_0.End();) {
        Unk_3babc0_Group* group = *it;
        it = self->field_0.Erase(it);
        int pool = Unk_237e820;
        group->~Unk_3babc0_Group();
        Unk_3047c0(pool, group);
    }
    for (auto it = self->field_18.BeginEx(); it != self->field_18.End();) {
        Unk_3babc0_Entry* entry = *it;
        it = self->field_18.Erase(it);
        self->Unlink(entry);
        Unk_3047c0(Unk_237e820, entry);
    }
    self->field_0.field_0.Term();
    self->field_18.field_0.Term();
    self->field_30.Term();
    return 1;
}

// 0x71003bb230: a subscriber follows a group
u32 Unk_3bb230(u64 self_, void* subscriber_, u32 group) {
    Unk_23837a8* subscriber = static_cast<Unk_23837a8*>(subscriber_);
    Unk_3babc0* self = reinterpret_cast<Unk_3babc0*>(self_);
    if (self->field_40 > 0) {
        return self->field_30.AddLastGrow(Unk_3babc0_Action(0, subscriber, group)) != nullptr ? 1
                                                                                             : 2;
    }
    return Unk_3bb280(self, subscriber, group);
}

// 0x71003bb280
u32 Unk_3bb280(Unk_3babc0* self, Unk_23837a8* subscriber, u32 group) {
    u32 result = 0x34;
    if (subscriber != nullptr) {
        Unk_3babc0_Entry* entry = self->field_18.Exists(subscriber);
        if (entry == nullptr) {
            entry = new (Unk_237e820) Unk_3babc0_Entry;
            if (entry != nullptr) {
                entry->key = subscriber;
                entry->field_10 = group;
                self->field_18.Set(entry);
            }
        } else {
            self->Unlink(entry);
            entry->field_10 = group;
        }
        if (entry != nullptr) {
            Unk_3babc0_Group* g = Unk_3bb7d0(self, group);
            if (g != nullptr && g->field_28.Add(entry) != nullptr)
                result = 1;
        }
        if (result != 1) {
            self->field_18.Unset(subscriber);
            if (entry != nullptr) {
                self->Unlink(entry);
                Unk_3047c0(Unk_237e820, entry);
            }
        }
    }
    return result;
}

// 0x71003bb6a0
template Unk_3babc0_Action* Unk_Array<Unk_3babc0_Action>::AddLastGrow(const Unk_3babc0_Action&);

// 0x71003bb7d0: the group of an ID, created when the manager doesn't have it
Unk_3babc0_Group* Unk_3bb7d0(Unk_3babc0* self, u32 id) {
    Unk_3babc0_Group* group = self->field_0.Exists(id);
    if (group == nullptr) {
        group = new (Unk_237e820) Unk_3babc0_Group(id);
        if (group != nullptr)
            self->field_0.Set(group);
    }
    return group;
}

// 0x71003bb8e0: a subscriber stops following its group
void Unk_3bb8e0(u64 self_, void* subscriber_) {
    Unk_23837a8* subscriber = static_cast<Unk_23837a8*>(subscriber_);
    Unk_3babc0* self = reinterpret_cast<Unk_3babc0*>(self_);
    Unk_3bb940(self, subscriber);
    if (self->field_40 > 0) {
        self->field_30.AddLastGrow(Unk_3babc0_Action(1, subscriber, 0));
    }
}

// 0x71003bb940
void Unk_3bb940(Unk_3babc0* self, Unk_23837a8* subscriber) {
    Unk_3babc0_Entry* entry = self->field_18.Exists(subscriber);
    if (entry == nullptr)
        return;
    if (self->field_40 > 0) {
        entry->field_14 = false;
        return;
    }
    self->field_18.Unset(subscriber);
    self->Unlink(entry);
    Unk_3047c0(Unk_237e820, entry);
}

u32 Unk_3bbbd0(Unk_3babc0_Group* self, u32 id, u32 type, const Unk_3babc0_Point* points,
               u32 numPoints);

// 0x71003bbb10: a group takes its value from a game parameter, through a curve
u32 Unk_3bbb10(Unk_3babc0* self, u32 groupId, u32 id, u32 type, const Unk_3babc0_Point* points,
               u32 numPoints) {
    Unk_3babc0_Group* group = Unk_3bb7d0(self, groupId);
    if (group == nullptr)
        return 0x34;
    group->UnsetCurve();
    if (numPoints == 0)
        return 1;
    return Unk_3bbbd0(group, id, type, points, numPoints);
}

// 0x71003bbbd0
u32 Unk_3bbbd0(Unk_3babc0_Group* self, u32 id, u32 type, const Unk_3babc0_Point* points,
               u32 numPoints) {
    u32 result = self->field_10.Reserve(numPoints);
    if (result == 1) {
        self->field_20 = id;
        self->field_24 = type;
        Unk_3babc0_CurvePoint* curve = static_cast<Unk_3babc0_CurvePoint*>(
            Unk_3045e0(Unk_237e820, sizeof(Unk_3babc0_CurvePoint) * numPoints));
        if (curve != nullptr) {
            for (u32 i = 0; i < numPoints; i++) {
                curve[i].field_0 = points[i].field_0;
                curve[i].field_4 = static_cast<f32>(i);
                curve[i].field_8 = points[i].field_8;
                self->field_10.AddLastGrow(points[i].field_4);
            }
            result = Unk_39b840(Unk_24bbbf8, self, id, type, curve, numPoints);
            Unk_3047c0(Unk_237e820, curve);
        } else {
            result = 0x34;
        }
    }
    if (result != 1)
        self->ClearCurve();
    return result;
}

// 0x71003bbe70: a group's value for a key
u32 Unk_3bbe70(u64 self_, u32 groupId, u64 key_) {
    Unk_3babc0* self = reinterpret_cast<Unk_3babc0*>(self_);
    Unk_3babc0_Group* group = self->field_0.Exists(groupId);
    if (group == nullptr)
        return 0;
    Unk_3babc0_Key key = *reinterpret_cast<const Unk_3babc0_Key*>(key_);
    if (group->field_20 != 0) {
        u32 index = static_cast<u32>(Unk_39d550(Unk_24bbbf8, group, &key));
        if (index < group->field_10.Length())
            return group->field_10.field_0[index];
        return 0;
    }
    u32* item = Unk_3657c0(&group->field_38, &key);
    if (item != nullptr)
        return *item;
    return 0;
}

// 0x71003bbf80: forgets a game object's values in every group
void Unk_3bbf80(Unk_3babc0* self, void* object) {
    if (object == nullptr)
        return;
    for (auto it = self->field_0.Begin(); it != self->field_0.End(); ++it)
        (*it)->RemoveValues(object);
}

// 0x71003bc040
Unk_3babc0_Group::~Unk_3babc0_Group() {
    RemoveValues(nullptr);
    UnsetCurve();
    field_38.Term();
    field_28.Term();
}

// 0x71003bc190: sets a group's value for a game object and tells the group's
// subscribers
bool Unk_3bc190(Unk_3babc0_Group* self, u32 value, void* object) {
    u32* item = self->SetValue(object);
    if (item != nullptr)
        *item = value;
    if (self->field_20 == 0)
        Unk_3babc0::Notify(self, value, object, nullptr);
    return item != nullptr;
}

// 0x71003bc280: tells a group's subscribers the value at an index of its list
void Unk_3bc280(Unk_3babc0_Group* self, const Unk_3babc0_Key* key, u32 index, void* arg3) {
    if (index < self->field_10.Length()) {
        for (auto it = self->field_28.Begin(); it != self->field_28.End(); ++it) {
            Unk_3babc0_Entry* entry = *it;
            if (entry->field_14 && entry->key != nullptr)
                entry->key->vf2(self->field_10.field_0[index], Unk_3babc0_Key(key->field_0), arg3);
        }
    }
}

// 0x71003bc350: locks the manager: what its subscribers ask for is queued
void Unk_3bc350() {
    Unk_24bbbc8->field_40++;
}

// 0x71003bc370: unlocks the manager and does what was queued
void Unk_3bc370() {
    Unk_3babc0* self = Unk_24bbbc8;
    if (--self->field_40 == 0) {
        for (auto it = self->field_30.Begin(); it != self->field_30.End(); ++it) {
            switch ((*it).field_0) {
            case 0:
                Unk_3bb280(self, (*it).field_8, (*it).field_10);
                break;
            case 1:
                Unk_3bb940(self, (*it).field_8);
                break;
            }
        }
        self->field_30.RemoveAll();
    }
}

// 0x71003bc420
template u32 Unk_HashListBare<Unk_3babc0_Entry, Unk_3babc0_EntryPolicy>::Reserve(u32);

// 0x71003bc7c0
template Unk_3babc0_Entry** Unk_3babc0_Entries::AddNoSetKey(Unk_3babc0_Entry*);

// 0x71003bcaa0
template u32 Unk_HashListBare<Unk_3babc0_Group, Unk_3babc0_GroupPolicy>::Reserve(u32);
