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
    self->field_150.field_8 = nullptr;
    self->field_150.field_0 = 0;
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

struct Unk_24bbc30_T {
    u8 _0[0x1c];
    bool field_1c;
};
extern Unk_24bbc30_T Unk_24bbc30;  // the engine's settings
extern void* Unk_24bbbb8;
extern void* Unk_24bbbc0;
extern void* Unk_24bbbd8;

void Unk_3b9500(Unk_23837d0* self, Unk_23837d0_Object* object, u32 playingId);
u32 Unk_3b9b60(Unk_23837d0* self, u32 value, const Unk_3babc0_Key& key,
               Unk_23837d0_Filter* except);
u32 Unk_3ba2a0(Unk_23837d0* self, u32 value, void* object);
struct Unk_363570_T;
struct Unk_3643f0_Action;
void Unk_34b7c0(Unk_363570_T* self, Unk_3643f0_Action* action);  // the base class's
u32 Unk_382d00(u32 id);
void Unk_382d80(u32 id);
void Unk_399200(void* self, u32 id, void* arg2);
Unk_23837d0_Node* Unk_3351b0(void* self, u32 id, u32 type);
// 0x7100339930 was named with this type for the node: a cast at the calls.
struct Unk_23837d0_Child;
void Unk_339930(void* self, Unk_23837d0_Child* node, void* object, u32 arg3);
// 0x71003baa80 has the name of a function without parameters (lib/wwise/leaf):
// the second base's object and its group are passed on to what it calls.
u64 Unk_3baa80_call();
static inline Unk_Array<u32>* Unk_23837d0_GetPrepared(void* self, u32 group, u32 type) {
    return reinterpret_cast<Unk_Array<u32>* (*)(void*, u32, u32)>(Unk_3baa80_call)(self, group,
                                                                                    type);
}
void Unk_3bab30(void* self, u32 group, u32 type);

// 0x71003b97a0: an action on the node: the playing children are paused or
// resumed with it
void Unk_3b97a0(Unk_23837d0* self, Unk_23837d0_Action* action) {
    switch (action->field_0) {
    case 0:
        Unk_3b9500(self, static_cast<Unk_23837d0_Object*>(action->field_8), 0);
        break;
    case 1: {
        void* object = action->field_8;
        for (Unk_23837d0_Cont* p = self->field_150.field_8; p != nullptr; p = p->next) {
            if (object == nullptr || p->field_20 == object) {
                if (p->field_70 != 1)
                    p->field_70 = 1;
            }
        }
        break;
    }
    case 2: {
        void* object = action->field_8;
        for (Unk_23837d0_Cont* p = self->field_150.field_8; p != nullptr; p = p->next) {
            if (object == nullptr || p->field_20 == object) {
                if (p->field_70 != 0)
                    p->field_70 = 0;
            }
        }
        break;
    }
    }
    Unk_34b7c0(reinterpret_cast<Unk_363570_T*>(self),
               reinterpret_cast<Unk_3643f0_Action*>(action));
}

// The group's value changed.
static inline void Unk_23837d0_SetSwitch(Unk_23837d0* self, u32 value, const Unk_3babc0_Key& key,
                                         Unk_23837d0_Filter* except) {
    if (!self->field_9c_29)
        return;
    self->vf2();
    Unk_3b9b60(self, value, key, except);
    self->vf3();
}

// 0x71003b9ae0
void Unk_3b9ae0(Unk_23837d0* self, u32 value, const Unk_3babc0_Key& key,
                Unk_23837d0_Filter* except) {
    Unk_23837d0_SetSwitch(self, value, key, except);
}

// 0x71003b9b60: for the key's game object, or for every game object with a
// playing child that isn't in `except`
u32 Unk_3b9b60(Unk_23837d0* self, u32 value, const Unk_3babc0_Key& key,
               Unk_23837d0_Filter* except) {
    void* object = key.field_0;
    if (object != nullptr) {
        Unk_3ba2a0(self, value, object);
    } else if (self->field_150.field_0 != 0) {
        u32 size = self->field_150.field_0 * sizeof(void*);
        void** objects = static_cast<void**>(Unk_3045e0(Unk_237e820, size));
        if (objects == nullptr)
            return 2;
        u32 count = 0;
        for (Unk_23837d0_Cont* p = self->field_150.field_8; p != nullptr; p = p->next) {
            if (except == nullptr || !except->vf0(Unk_3babc0_Key(p->field_20)))
                objects[count++] = p->field_20;
        }
        for (u32 i = 0; i < count; i++)
            Unk_3ba2a0(self, value, objects[i]);
        Unk_3047c0(Unk_237e820, objects);
    } else {
        Unk_399200(Unk_24bbbd8, self->field_10, nullptr);
    }
    return 1;
}

// 0x71003b9cc0: the same through the subscriber base
void Unk_3b9cc0(u8* self, u32 value, const Unk_3babc0_Key& key, Unk_23837d0_Filter* except) {
    Unk_23837d0_SetSwitch(reinterpret_cast<Unk_23837d0*>(self - 0xd8), value, key, except);
}

// Prepares or unprepares the data of the nodes of one switch value.
static inline u32 Unk_23837d0_PrepareSwitch(Unk_23837d0* self, u32 value, bool prepare) {
    u32 result = 1;
    if (self->field_f0 != 0) {
        Unk_23837d0_Nodes* nodes = self->field_100.Exists(value);
        if (nodes != nullptr) {
            if (prepare) {
                for (auto it = nodes->Begin(); it != nodes->End(); ++it) {
                    result = Unk_382d00(*it);
                    if (result != 1) {
                        for (auto undo = nodes->Begin(); undo != it; ++undo)
                            Unk_382d80(*undo);
                        break;
                    }
                }
            } else {
                for (auto it = nodes->Begin(); it != nodes->End(); ++it)
                    Unk_382d80(*it);
            }
        }
    }
    return result;
}

// 0x71003b9d40
// NON_MATCHING: the original loads the list's items in each branch, after
// the test of its length; here that load is hoisted above the test of
// `prepare` with the length's (4 bytes less).
u32 Unk_3b9d40(Unk_23837d0* self, u32 value, bool prepare) {
    return Unk_23837d0_PrepareSwitch(self, value, prepare);
}

// 0x71003b9e20: the same through the second base
// NON_MATCHING: as Unk_3b9d40.
u32 Unk_3b9e20(u8* self, u32 value, bool prepare) {
    return Unk_23837d0_PrepareSwitch(reinterpret_cast<Unk_23837d0*>(self - 0xe0), value, prepare);
}

u32 Unk_3baab0(void* self, u32 group, u32 type);

// 0x71003b9f00: the data is needed: the children's, or the nodes' of the
// switch values that are prepared
u32 Unk_3b9f00(Unk_23837d0* self) {
    u32 result = 1;
    if (Unk_24bbc30.field_1c) {
        if (self->field_f0 != 0) {
            self->field_f0++;
        } else {
            Unk_Array<u32>* prepared =
                Unk_23837d0_GetPrepared(self->field_e0, self->field_f8, self->field_f4);
            if (prepared != nullptr) {
                for (auto* p = self->field_100.field_0; p != nullptr; p = p->next) {
                    if (prepared->FindEx(p->item.key) != prepared->End()) {
                        Unk_23837d0_Nodes& nodes = p->item.item;
                        for (auto it = nodes.Begin(); it != nodes.End(); ++it) {
                            result = Unk_382d00(*it);
                            if (result != 1) {
                                for (auto undo = nodes.Begin(); undo != it; ++undo)
                                    Unk_382d80(*undo);
                                break;
                            }
                        }
                        if (result != 1) {
                            for (auto* q = self->field_100.field_0; q != p; q = q->next) {
                                if (prepared->FindEx(q->item.key) != prepared->End()) {
                                    for (auto it = q->item.item.Begin(); it != q->item.item.End();
                                         ++it)
                                        Unk_382d80(*it);
                                }
                            }
                            break;
                        }
                    }
                }
                if (result == 1) {
                    self->field_f0++;
                    result = Unk_3baab0(self->field_e0, self->field_f8, self->field_f4);
                    if (result != 1)
                        self->vf40();
                }
            } else {
                result = 0x34;
            }
        }
    } else {
        for (auto it = self->field_b8.Begin(); it != self->field_b8.End(); ++it) {
            result = (*it)->vf39();
            if (result != 1) {
                for (auto undo = self->field_b8.Begin(); undo != it; ++undo)
                    (*undo)->vf40();
                break;
            }
        }
    }
    return result;
}

// 0x71003ba170: the data isn't needed any more
void Unk_3ba170(Unk_23837d0* self) {
    if (Unk_24bbc30.field_1c) {
        if (self->field_f0 != 0) {
            if (--self->field_f0 == 0) {
                Unk_Array<u32>* prepared =
                    Unk_23837d0_GetPrepared(self->field_e0, self->field_f8, self->field_f4);
                if (prepared != nullptr) {
                    for (auto* p = self->field_100.field_0; p != nullptr; p = p->next) {
                        if (prepared->FindEx(p->item.key) != prepared->End()) {
                            for (auto it = p->item.item.Begin(); it != p->item.item.End(); ++it)
                                Unk_382d80(*it);
                        }
                    }
                }
                Unk_3bab30(self->field_e0, self->field_f8, self->field_f4);
            }
        }
    } else {
        for (auto it = self->field_b8.Begin(); it != self->field_b8.End(); ++it)
            (*it)->vf40();
    }
}

u32 Unk_3ba520(Unk_23837d0* self, Unk_23837d0_Nodes* old, Unk_23837d0_Nodes* now, void* object);
u32 Unk_3ba6a0(Unk_23837d0* self, u32 id, Unk_23837d0_Cont* cont);
u32 Unk_3ba930(Unk_23837d0* self, u32 id, const Unk_23837d0_NodeParams* params, void* object);
Unk_23837d0_History Unk_398e20(void* self, void* object, u32 id);
void Unk_398ec0(void* self, void* object, u32 id, Unk_23837d0_History* history);

// 0x71003ba2a0: the group's value changed for a game object: stops what the
// old value played and plays the nodes of the new one
u32 Unk_3ba2a0(Unk_23837d0* self, u32 value, void* object) {
    Unk_23837d0_History history = Unk_398e20(Unk_24bbbd8, object, self->field_10);
    if (history.field_0 == value)
        return 1;
    Unk_23837d0_Nodes* old = self->field_100.Exists(history.field_0);
    Unk_23837d0_Nodes* now = self->field_100.Exists(value);
    if (now == nullptr) {
        value = self->field_fc;
        now = self->field_100.Exists(value);
    }
    Unk_3ba520(self, old, now, object);
    Unk_399200(Unk_24bbbd8, self->field_10, object);
    history.field_0 = 0;
    history.field_4 = 0;
    u32 result = 1;
    for (Unk_23837d0_Cont* p = self->field_150.field_8; p != nullptr; p = p->next) {
        if (p->field_20 == object) {
            history.Increment(value);
            if (now != nullptr) {
                for (auto it = now->Begin(); it != now->End(); ++it) {
                    Unk_23837d0_NodeParams params;
                    self->GetNodeParams(*it, params);
                    if (old != nullptr && params.field_8_4 && old->Has(*it))
                        continue;
                    result = Unk_3ba6a0(self, *it, p);
                }
            }
        }
    }
    Unk_398ec0(Unk_24bbbd8, object, self->field_10, &history);
    return result;
}

// 0x71003ba520: stops the nodes of the old value, except those that go on
// with the new one
u32 Unk_3ba520(Unk_23837d0* self, Unk_23837d0_Nodes* old, Unk_23837d0_Nodes* now, void* object) {
    if (old != nullptr) {
        for (auto it = old->Begin(); it != old->End(); ++it) {
            u32 id = *it;
            Unk_23837d0_NodeParams params;
            self->GetNodeParams(id, params);
            if (now != nullptr && self->field_9c_29 && params.field_8_4 && now->Has(id))
                continue;
            Unk_3ba930(self, id, &params, object);
        }
    }
    return 1;
}

// 0x71003ba930: stops a node for a game object, or lets it go on
u32 Unk_3ba930(Unk_23837d0* self, u32 id, const Unk_23837d0_NodeParams* params, void* object) {
    Unk_23837d0_Node* node = Unk_3351b0(Unk_24bbbb8, id, 0);
    if (node != nullptr) {
        Unk_339930(Unk_24bbbc0, reinterpret_cast<Unk_23837d0_Child*>(node), object, 0);
        if (params->field_8_0 == 1) {
            Unk_23837d0_Action action;
            action.field_14.field_4 = 4;
            action.field_0 = 0;
            action.field_8 = object;
            action.field_10 = 0;
            action.field_14.field_0 = params->field_0.field_0;
            action.field_21 = false;
            node->vf19(&action);
            Unk_339930(Unk_24bbbc0, reinterpret_cast<Unk_23837d0_Child*>(node), object,
                       action.field_10);
        } else {
            node->vf22(object, self, 0);
        }
        node->vf3();
    }
    return 1;
}

extern void* Unk_24bbc08;
void Unk_38fcb0(void* self, u32 playingId);
// 0x71003b79c0 has a generated name (lib/wwise/leaf): the group's value for a key.
u32 Unk_3b79c0_call(void* self, u64 key, u32 group, u32 type);

// Asks the nodes of every switch value; the ones of `nodes` are told that
// theirs is the current one.
static inline void Unk_23837d0_AskNodes(Unk_23837d0* self, void* arg1, void* arg2,
                                        Unk_Array<Unk_23837d0_Group>* groups, bool current,
                                        Unk_23837d0_Nodes* nodes, void* object, u32 group,
                                        u32 value) {
    for (auto p = self->field_100.Begin(); p != self->field_100.End(); ++p) {
        Unk_23837d0_Nodes& list = (*p).item;
        bool isCurrent = current && &list == nodes;
        for (auto it = list.Begin(); it != list.End(); ++it) {
            Unk_23837d0_Node* node = Unk_3351b0(Unk_24bbbb8, *it, 0);
            if (node != nullptr) {
                node->vf16(arg1, arg2, groups, isCurrent, object, group, value);
                node->vf3();
            }
        }
    }
}

// 0x71003b8500: asks the nodes of every switch value; the ones of the
// current value are told so
void Unk_3b8500(Unk_23837d0* self, void* arg1, void* arg2, Unk_Array<Unk_23837d0_Group>* groups,
                bool current, void* object, u32 group, u32 value) {
    if (self->field_100.field_24 == 0)
        return;
    if (self->field_f4 == 1) {
        if (current) {
            Unk_23837d0_Group item;
            item.field_4 = self->field_f8;
            groups->AddLastGrowValue(item);
        }
        u32 now = value;
        if (self->field_f8 != group) {
            Unk_3babc0_Key key;
            key.field_0 = object;
            key.field_8 = 0;
            now = Unk_3b79c0_call(self->field_d8, reinterpret_cast<u64>(&key), self->field_f8,
                                  self->field_f4);
        }
        Unk_23837d0_Nodes* nodes = self->field_100.Exists(now);
        if (nodes == nullptr)
            nodes = self->field_100.Exists(self->field_fc);
        Unk_23837d0_AskNodes(self, arg1, arg2, groups, current, nodes, object, group, value);
    } else {
        for (auto p = self->field_100.Begin(); p != self->field_100.End(); ++p) {
            Unk_23837d0_Nodes& list = (*p).item;
            for (auto it = list.Begin(); it != list.End(); ++it) {
                Unk_23837d0_Node* node = Unk_3351b0(Unk_24bbbb8, *it, 0);
                if (node != nullptr) {
                    node->vf16(arg1, arg2, groups, current, object, group, value);
                    node->vf3();
                }
            }
        }
    }
}

// Where the playing children's records come from: this TU's (reached without
// the GOT).
extern Unk_BlockPool<Unk_23837d0_Cont, 128> Unk_24deec8 __attribute__((visibility("hidden")));

u64 Unk_382e00(void* arg0, void* arg1, void* arg2, bool arg3);

// 0x71003b8810
u64 Unk_3b8810(void* arg0, void* arg1, void* arg2, bool arg3) {
    return Unk_382e00(arg0, arg1, arg2, arg3);
}

void Unk_3b8850(Unk_23837d0* self);
void Unk_3b3970(void* self);

// 0x71003b8820: forgets the playing children, then what the second base does
void Unk_3b8820(Unk_23837d0* self) {
    Unk_3b8850(self);
    Unk_3b3970(reinterpret_cast<u8*>(self) + 0x18);
}

// 0x71003b8850: forgets the playing children
void Unk_3b8850(Unk_23837d0* self) {
    while (self->field_150.field_8 != nullptr) {
        Unk_23837d0_Cont* cont = self->field_150.field_8;
        self->field_150.RemoveFirst();
        Unk_38fcb0(Unk_24bbc08, cont->field_1c);
        self->vf38(1);
        cont->field_20->Release();
        Unk_24deec8.Delete(cont);
    }
}

// 0x71003b98a0: a child goes away
void Unk_3b98a0(Unk_23837d0* self, Unk_23837d0_Node* child) {
    Unk_23837d0_Node* parent = child->field_78;
    u32 id = child->field_10;
    if (parent == self) {
        child->vf7(nullptr);
        self->field_b8.Unset(id);
    }
    self->field_128.Unset(id);
    if (parent == self)
        self->vf3();
}

static inline bool Unk_23837d0_Matches(Unk_23837d0_Cont* cont, void* object, u32 playingId) {
    return (cont->field_20 == object || object == nullptr) &&
           (cont->field_1c == playingId || playingId == 0);
}

// 0x71003b92b0: an action on the node and on its children
void Unk_3b92b0(Unk_23837d0* self, Unk_23837d0_Action* action) {
    switch (action->field_0) {
    case 0:
    case 3:
        Unk_3b9500(self, static_cast<Unk_23837d0_Object*>(action->field_8), action->field_10);
        break;
    case 1: {
        void* object = action->field_8;
        u32 playingId = action->field_10;
        for (Unk_23837d0_Cont* p = self->field_150.field_8; p != nullptr; p = p->next) {
            if (Unk_23837d0_Matches(p, object, playingId)) {
                if (p->field_70 != 1)
                    p->field_70 = 1;
            }
        }
        break;
    }
    case 2: {
        void* object = action->field_8;
        u32 playingId = action->field_10;
        for (Unk_23837d0_Cont* p = self->field_150.field_8; p != nullptr; p = p->next) {
            if (Unk_23837d0_Matches(p, object, playingId)) {
                if (p->field_70 != 0)
                    p->field_70 = 0;
            }
        }
        break;
    }
    }
    if (self->field_70 != nullptr && (self->field_70->field_90 > 0 || self->field_70->field_94 > 0)) {
        for (u32 i = self->field_b8.field_8; i > 0; i--) {
            Unk_23837d0_Node* child = self->field_b8.field_0[i - 1].field_0;
            if (!action->field_20 || child->field_80 == nullptr)
                child->vf19(action);
        }
    }
}

// 0x71003b9500: forgets the playing children of a game object (all if null)
// and of a playing ID (all if 0)
void Unk_3b9500(Unk_23837d0* self, Unk_23837d0_Object* object, u32 playingId) {
    bool found = false;
    auto it = self->field_150.BeginEx();
    while (it != self->field_150.End()) {
        Unk_23837d0_Cont* cont = *it;
        if ((object == nullptr || cont->field_20 == object) &&
            (playingId == 0 || cont->field_1c == playingId)) {
            Unk_23837d0_Object* other;
            if (object == nullptr) {
                other = cont->field_20;
            } else {
                other = nullptr;
                found = true;
            }
            it = self->field_150.Erase(it);
            Unk_38fcb0(Unk_24bbc08, cont->field_1c);
            self->vf38(1);
            cont->field_20->Release();
            Unk_24deec8.Delete(cont);
            if (other != nullptr)
                Unk_399200(Unk_24bbbd8, self->field_10, other);
        } else {
            ++it;
        }
    }
    if (found)
        Unk_399200(Unk_24bbbd8, self->field_10, object);
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

u32 Unk_388140(Unk_23837d0* self);

// 0x71003baa40
u32 Unk_3baa40(Unk_23837d0* self) {
    if (self->field_9c_29)
        return 1;
    return Unk_388140(self);
}
