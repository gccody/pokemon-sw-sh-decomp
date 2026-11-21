// Scope: common
// The TU of the class with the vtable 0x7102383770: the shared subscriber of
// the nodes that follow one switch or state group, kept by group in a global
// sorted array and reference counted. Placeholder names.
#include "Unk_23837a8.h"
#include "sorted_array.h"

void operator delete(void* ptr) noexcept;

// A group: its type (0 switch, 1 state) and ID.
struct Unk_2383770_Key {
    u32 field_0;
    u32 field_4;

    Unk_2383770_Key(u32 type, u32 id) : field_0(type), field_4(id) {}
};

class Unk_2383770 : public Unk_2383770_Key, public Unk_23837a8 {
public:
    Unk_2383770(u32 type, u32 id) : Unk_2383770_Key(type, id), field_10(1) {
        Unk_3b7900(this, id, type);
    }
    ~Unk_2383770() override;
    void vf2() override;
    virtual u32 vf3();  // adds a reference
    virtual u32 vf4();  // releases one

    u32 field_10;  // reference count
};
PKMN_SIZE_ASSERT(Unk_2383770, 0x18);

struct Unk_2383770_Ptr {
    Unk_2383770* field_0;

    Unk_2383770_Ptr() : field_0(nullptr) {}
};

struct Unk_2383770_Item {
    u32 key;
    Unk_2383770_Ptr item;
};

typedef Unk_SortedKeyArray<u32, u32, Unk_KeyIsItem<u32>> Unk_2383770_Ids;
typedef Unk_SortedKeyArray<u32, Unk_2383770_Item, Unk_KeyIsMember<u32, Unk_2383770_Item>>
    Unk_2383770_Index;

// The subscribers by group ID.
extern Unk_2383770_Index Unk_24deeb8;

// 0x71003b6ee0
template u32* Unk_SortedKeyArray<u32, u32, Unk_KeyIsItem<u32>>::Set(u32);

// 0x71003b71c0: adds the group to an object's groups, with a reference to its
// subscriber
void Unk_3b71c0(Unk_2383770_Ids* self, const Unk_2383770_Key* key) {
    if (self->Exists(key->field_4) != nullptr)
        return;
    Unk_2383770* subscriber = nullptr;
    Unk_2383770_Item* item = Unk_24deeb8.Exists(key->field_4);
    if (item != nullptr) {
        subscriber = item->item.field_0;
        subscriber->vf3();
    } else {
        item = Unk_24deeb8.Set(key->field_4);
        if (item != nullptr) {
            subscriber = new (Unk_237e820) Unk_2383770(key->field_0, key->field_4);
            item->item.field_0 = subscriber;
            if (subscriber == nullptr)
                Unk_24deeb8.Unset(key->field_4);
        }
    }
    if (subscriber != nullptr)
        self->Set(key->field_4);
}

// 0x71003b74a0
template Unk_2383770_Item*
Unk_SortedKeyArray<u32, Unk_2383770_Item, Unk_KeyIsMember<u32, Unk_2383770_Item>>::Set(u32);

// 0x71003b7720, 0x71003b7760
Unk_2383770::~Unk_2383770() {
    Unk_3b78c0_call(this);
}

// 0x71003b77c0
u32 Unk_2383770::vf4() {
    u32 count = --field_10;
    if (count == 0) {
        int pool = Unk_237e820;
        this->~Unk_2383770();
        Unk_3047c0(pool, this);
    }
    return count;
}
