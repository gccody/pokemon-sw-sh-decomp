// Scope: common
// Functions of the class with the vtable 0x71023837d0 (Unk_23837d0.h): a
// node that plays the children of a switch or state group's current value.
// Placeholder names.
#include "Unk_23837d0.h"
#include "Unk_3476d0.h"

extern u64 Unk_24bbbe0;

u32 Unk_3b7900(void* self, u32 group, u32 type);
void Unk_3b78c0_call(void* self);
void Unk_379fa0_call(struct Unk_379fa0* self);
u32 Unk_385430(void* self, u8** data, u32* size, bool arg3);
void Unk_349be0_update(u64, u32, u32, u32);

// 0x71003b7a60
void Unk_3b7a60(Unk_23837d0* self) {
    Unk_3b78c0_call(self->field_d8);
    for (auto* p = self->field_100.field_0; p != nullptr; p = p->next)
        p->item.item.Term();
    self->field_100.RemoveAll();
    self->field_158 = nullptr;
    self->field_150 = 0;
    self->field_128.Term();
    self->field_100.Term();
    Unk_379fa0_call(reinterpret_cast<Unk_379fa0*>(self));
}

// 0x71003b8370
u32 Unk_3b8370(Unk_23837d0* self, Unk_Array<u32>* list, u32 id);

// 0x71003b7ed0: reads the object from a bank
// NON_MATCHING: block placement only. The original duplicates the head of the
// switch loop (the first load and test of its list search) after the list's
// preallocation; here that path branches to the shared copy (8 bytes less).
u32 Unk_3b7ed0(Unk_3476d0_Obj* object, u32* source, u32 size) {
    Unk_23837d0* self = reinterpret_cast<Unk_23837d0*>(object);
    u8*& data = reinterpret_cast<u8*&>(source);
    if (self->vf17() != 4) {
        Unk_349be0_update(Unk_24bbbe0, self->field_10, 4, self->vf17());
        return 0x5a;
    }
    data += sizeof(u32);
    u32 result = Unk_385430(self, &data, &size, false);
    if (result != 1)
        return result;

    u8 type = Unk_ReadBank<u8>(data);
    u32 group = Unk_ReadBank<u32>(data);
    u32 defaultValue = Unk_ReadBank<u32>(data);
    u8 flag = Unk_ReadBank<u8>(data);
    if (self->field_f8 != group || self->field_f4 != type) {
        self->field_f4 = type;
        self->field_f8 = group;
        result = Unk_3b7900(self->field_d8, group, type);
        if (result != 1)
            return result;
    }
    self->field_fc = defaultValue;
    self->field_9c_29 = flag != 0;

    u32 numChildren = Unk_ReadBank<u32>(data);
    if (numChildren != 0) {
        result = self->field_b8.Reserve(numChildren);
        if (result != 1)
            return result;
        for (u32 i = 0; i < numChildren; i++) {
            u32 id = Unk_ReadBank<u32>(data);
            result = self->vf11(id);
            if (result != 0xf && result != 1)
                break;
        }
    }
    if (result != 1)
        return result;

    u32 numSwitches = Unk_ReadBank<u32>(data);
    self->field_100.Init(numSwitches);
    for (u32 i = 0; i < numSwitches; i++) {
        u32 key = Unk_ReadBank<u32>(data);
        Unk_23837d0_Nodes* nodes = self->field_100.Set(key);
        if (nodes == nullptr)
            return 2;
        u32 numNodes = Unk_ReadBank<u32>(data);
        if (numNodes != 0) {
            nodes->Reserve(numNodes);
            for (u32 j = 0; result == 1 && j < numNodes; j++)
                result = Unk_3b8370(self, nodes, Unk_ReadBank<u32>(data));
            if (result != 1)
                return result;
        }
    }

    u32 numNodes = Unk_ReadBank<u32>(data);
    self->field_128.Init(numNodes);
    for (u32 i = 0; i < numNodes; i++) {
        u32 key = Unk_ReadBank<u32>(data);
        Unk_23837d0_NodeParams params;
        u8 flags = Unk_ReadBank<u8>(data);
        params.field_8_3 = flags & 1;
        params.field_8_4 = (flags >> 1) & 1;
        params.field_8_0 = Unk_ReadBank<u8>(data);
        params.field_0 = Unk_ReadBank<Unk_23837d0_NodeParams::Times>(data);
        result = self->SetNodeParams(key, params);
        if (result != 1)
            break;
    }
    return result;
}

// 0x71003b8370: adds a node to a switch value's nodes
u32 Unk_3b8370(Unk_23837d0* self, Unk_Array<u32>* list, u32 id) {
    if (list->Exists(id))
        return 0x39;
    u32* item = list->AddLastGrow();
    if (item == nullptr)
        return 2;
    *item = id;
    return 1;
}
