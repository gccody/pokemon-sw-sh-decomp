// Scope: common
//
// Classes whose vf3 (slot 3 of their primary vtable, slot 1 of the one at +0x48)
// destroys the instance a global of theirs holds, the way Unk_239a418::vf3
// destroys an object: the global is cleared first, then the instance's
// destructor runs (a virtual call) and its memory goes back to the allocator
// it keeps (field_8; the allocation in field_10-field_20). The function doesn't
// use `this`, so its thunk is a copy. The classes are those instances
// (0x7100007860 creates Unk_236d328's and stores it in its global). Placeholder
// names, after the vtables and the globals' addresses. Written by
// tools/familygen.py: regenerate, don't edit.
#include "gflib3/Unk_239a418.h"

// Their primary base, 0x48 bytes laid out like Unk_239a418_Base.
class Unk_7c20_Base {
public:
    virtual ~Unk_7c20_Base();
    virtual void vf2();
    virtual void vf3();

    Unk_239a418_Allocator* field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
    u64 field_28;
    u64 field_30;
    u64 field_38;
    u64 field_40;
};
static_assert(sizeof(Unk_7c20_Base) == 0x48, "Unk_7c20_Base");

// The interface at +0x48: the same two functions.
class Unk_7c20_Interface {
public:
    virtual void vf2();
    virtual void vf3();
};

// Clears `instance`, then destroys what it held.
template <class T>
void Unk_7c20_Reset(T*& instance) {
    T* p = instance;
    instance = nullptr;
    if (p != nullptr) {
        Unk_239a418_Allocator* allocator = p->field_8;
        u64 arg1 = p->field_10;
        u64 arg2 = p->field_18;
        u64 arg3 = p->field_20;
        p->~T();
        allocator->vf3(arg1, arg2, arg3);
    }
}

class Unk_236d328 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_236d328() override;
    void vf3() override;
};
extern Unk_236d328* Unk_24ba608;

// 0x7100007c20, its thunk from +0x48 0x7100007ca0
void Unk_236d328::vf3() {
    Unk_7c20_Reset(Unk_24ba608);
}

class Unk_236d418 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_236d418() override;
    void vf3() override;
};
extern Unk_236d418* Unk_24ba5a8;

// 0x7100008690, its thunk from +0x48 0x7100008710
void Unk_236d418::vf3() {
    Unk_7c20_Reset(Unk_24ba5a8);
}

class Unk_236d468 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_236d468() override;
    void vf3() override;
};
extern Unk_236d468* Unk_24ba628;

// 0x7100008cc0, its thunk from +0x48 0x7100008d40
void Unk_236d468::vf3() {
    Unk_7c20_Reset(Unk_24ba628);
}

class Unk_236d4f8 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_236d4f8() override;
    void vf3() override;
};
extern Unk_236d4f8* Unk_24ba4f0;

// 0x7100009190, its thunk from +0x48 0x7100009210
void Unk_236d4f8::vf3() {
    Unk_7c20_Reset(Unk_24ba4f0);
}

class Unk_236d548 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_236d548() override;
    void vf3() override;
};
extern Unk_236d548* Unk_24ba658;

// 0x71000094a0, its thunk from +0x48 0x7100009520
void Unk_236d548::vf3() {
    Unk_7c20_Reset(Unk_24ba658);
}

class Unk_236d598 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_236d598() override;
    void vf3() override;
};
extern Unk_236d598* Unk_24ba688;

// 0x710000a7e0, its thunk from +0x48 0x710000a860
void Unk_236d598::vf3() {
    Unk_7c20_Reset(Unk_24ba688);
}

class Unk_236d678 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_236d678() override;
    void vf3() override;
};
extern Unk_236d678* Unk_24ba6a8;

// 0x710000af30, its thunk from +0x48 0x710000afb0
void Unk_236d678::vf3() {
    Unk_7c20_Reset(Unk_24ba6a8);
}

class Unk_236d6c8 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_236d6c8() override;
    void vf3() override;
};
extern Unk_236d6c8* Unk_24ba6b8;

// 0x710000b340, its thunk from +0x48 0x710000b3c0
void Unk_236d6c8::vf3() {
    Unk_7c20_Reset(Unk_24ba6b8);
}

class Unk_236d718 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_236d718() override;
    void vf3() override;
};
extern Unk_236d718* Unk_24ba6c8;

// 0x710000b750, its thunk from +0x48 0x710000b7d0
void Unk_236d718::vf3() {
    Unk_7c20_Reset(Unk_24ba6c8);
}

class Unk_236d768 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_236d768() override;
    void vf3() override;
};
extern Unk_236d768* Unk_24ba6d8;

// 0x710000bd60, its thunk from +0x48 0x710000bde0
void Unk_236d768::vf3() {
    Unk_7c20_Reset(Unk_24ba6d8);
}

class Unk_236d7b8 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_236d7b8() override;
    void vf3() override;
};
extern Unk_236d7b8* Unk_24ba718;

// 0x710000c470, its thunk from +0x48 0x710000c4f0
void Unk_236d7b8::vf3() {
    Unk_7c20_Reset(Unk_24ba718);
}

class Unk_236d838 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_236d838() override;
    void vf3() override;
};
extern Unk_236d838* Unk_24ba100;

// 0x710000cac0, its thunk from +0x48 0x710000cb40
void Unk_236d838::vf3() {
    Unk_7c20_Reset(Unk_24ba100);
}

class Unk_23999e8 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_23999e8() override;
    void vf3() override;
};
extern Unk_23999e8* Unk_2773fd8;

// 0x71005d8220, its thunk from +0x48 0x71005d8290
void Unk_23999e8::vf3() {
    Unk_7c20_Reset(Unk_2773fd8);
}

class Unk_2399a38 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_2399a38() override;
    void vf3() override;
};
extern Unk_2399a38* Unk_2777128;

// 0x71005d8520, its thunk from +0x48 0x71005d85a0
void Unk_2399a38::vf3() {
    Unk_7c20_Reset(Unk_2777128);
}

class Unk_239a158 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_239a158() override;
    void vf3() override;
};
extern Unk_239a158* Unk_27736a8;

// 0x71005e0620, its thunk from +0x48 0x71005e06a0
void Unk_239a158::vf3() {
    Unk_7c20_Reset(Unk_27736a8);
}

class Unk_239a1a8 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_239a1a8() override;
    void vf3() override;
};
extern Unk_239a1a8* Unk_24ba500;

// 0x71005e0900, its thunk from +0x48 0x71005e0980
void Unk_239a1a8::vf3() {
    Unk_7c20_Reset(Unk_24ba500);
}

class Unk_239a528 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_239a528() override;
    void vf3() override;
};
extern Unk_239a528* Unk_24ba738;

// 0x71005e5480, its thunk from +0x48 0x71005e54f0
void Unk_239a528::vf3() {
    Unk_7c20_Reset(Unk_24ba738);
}

class Unk_239a7d0 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_239a7d0() override;
    void vf3() override;
};
extern Unk_239a7d0* Unk_24ba728;

// 0x71005eb1c0, its thunk from +0x48 0x71005eb230
void Unk_239a7d0::vf3() {
    Unk_7c20_Reset(Unk_24ba728);
}

class Unk_239a8c0 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_239a8c0() override;
    void vf3() override;
};
extern Unk_239a8c0* Unk_2773fc8;

// 0x71005ec260, its thunk from +0x48 0x71005ec2e0
void Unk_239a8c0::vf3() {
    Unk_7c20_Reset(Unk_2773fc8);
}

class Unk_239b1f8 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_239b1f8() override;
    void vf3() override;
};
extern Unk_239b1f8* Unk_24ba110;

// 0x71005f93a0, its thunk from +0x48 0x71005f9ee0
void Unk_239b1f8::vf3() {
    Unk_7c20_Reset(Unk_24ba110);
}

class Unk_239b548 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_239b548() override;
    void vf3() override;
};
extern Unk_239b548* Unk_2773fb8;

// 0x71005fd520, its thunk from +0x48 0x71005fd5a0
void Unk_239b548::vf3() {
    Unk_7c20_Reset(Unk_2773fb8);
}

class Unk_23a10b8 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_23a10b8() override;
    void vf3() override;
};
extern Unk_23a10b8* Unk_24ba130;

// 0x7100681640, its thunk from +0x48 0x71006816c0
void Unk_23a10b8::vf3() {
    Unk_7c20_Reset(Unk_24ba130);
}

class Unk_23a21c8 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_23a21c8() override;
    void vf3() override;
};
extern Unk_23a21c8* Unk_2778af0;

// 0x710069c4c0, its thunk from +0x48 0x710069c540
void Unk_23a21c8::vf3() {
    Unk_7c20_Reset(Unk_2778af0);
}

class Unk_23a2380 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_23a2380() override;
    void vf3() override;
};
extern Unk_23a2380* Unk_24ba678;

// 0x710069e930, its thunk from +0x48 0x710069e9b0
void Unk_23a2380::vf3() {
    Unk_7c20_Reset(Unk_24ba678);
}

class Unk_23a24f0 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_23a24f0() override;
    void vf3() override;
};
extern Unk_23a24f0* Unk_24ba160;

// 0x71006a1630, its thunk from +0x48 0x71006a16b0
void Unk_23a24f0::vf3() {
    Unk_7c20_Reset(Unk_24ba160);
}

class Unk_23a2540 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_23a2540() override;
    void vf3() override;
};
extern Unk_23a2540* Unk_2778c18;

// 0x71006a2090, its thunk from +0x48 0x71006a2110
void Unk_23a2540::vf3() {
    Unk_7c20_Reset(Unk_2778c18);
}

class Unk_23a2590 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_23a2590() override;
    void vf3() override;
};
extern Unk_23a2590* Unk_2778be8;

// 0x71006a3480, its thunk from +0x48 0x71006a3500
void Unk_23a2590::vf3() {
    Unk_7c20_Reset(Unk_2778be8);
}

class Unk_23a25e0 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_23a25e0() override;
    void vf3() override;
};
extern Unk_23a25e0* Unk_2778bf8;

// 0x71006a50f0, its thunk from +0x48 0x71006a5170
void Unk_23a25e0::vf3() {
    Unk_7c20_Reset(Unk_2778bf8);
}

class Unk_23a2c48 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_23a2c48() override;
    void vf3() override;
};
extern Unk_23a2c48* Unk_24ba170;

// 0x71006af560, its thunk from +0x48 0x71006af5e0
void Unk_23a2c48::vf3() {
    Unk_7c20_Reset(Unk_24ba170);
}

class Unk_23a3a80 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_23a3a80() override;
    void vf3() override;
};
extern Unk_23a3a80* Unk_2778c08;

// 0x71006bf520, its thunk from +0x48 0x71006bf5a0
void Unk_23a3a80::vf3() {
    Unk_7c20_Reset(Unk_2778c08);
}

class Unk_23a3db8 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_23a3db8() override;
    void vf3() override;
};
extern Unk_23a3db8* Unk_27790f0;

// 0x71006c36b0, its thunk from +0x48 0x71006c3720
void Unk_23a3db8::vf3() {
    Unk_7c20_Reset(Unk_27790f0);
}

class Unk_23a7ca0 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_23a7ca0() override;
    void vf3() override;
};
extern Unk_23a7ca0* Unk_27cecf0;

// 0x71007862d0, its thunk from +0x48 0x7100786340
void Unk_23a7ca0::vf3() {
    Unk_7c20_Reset(Unk_27cecf0);
}

class Unk_23a80b0 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_23a80b0() override;
    void vf3() override;
};
extern Unk_23a80b0* Unk_27ce848;

// 0x7100792960, its thunk from +0x48 0x71007929e0
void Unk_23a80b0::vf3() {
    Unk_7c20_Reset(Unk_27ce848);
}

class Unk_23aa3c8 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_23aa3c8() override;
    void vf3() override;
};
extern Unk_23aa3c8* Unk_24ba5e8;

// 0x71007c1b20, its thunk from +0x48 0x71007c1ba0
void Unk_23aa3c8::vf3() {
    Unk_7c20_Reset(Unk_24ba5e8);
}

class Unk_23aa4b8 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_23aa4b8() override;
    void vf3() override;
};
extern Unk_23aa4b8* Unk_24ba5d8;

// 0x71007c2c10, its thunk from +0x48 0x71007c2c90
void Unk_23aa4b8::vf3() {
    Unk_7c20_Reset(Unk_24ba5d8);
}

class Unk_23db550 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_23db550() override;
    void vf3() override;
};
extern Unk_23db550* Unk_24ba638;

// 0x7100c447c0, its thunk from +0x48 0x7100c44840
void Unk_23db550::vf3() {
    Unk_7c20_Reset(Unk_24ba638);
}

class Unk_23f48d0 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_23f48d0() override;
    void vf3() override;
};
extern Unk_23f48d0* Unk_24ba6f8;

// 0x7100e892f0, its thunk from +0x48 0x7100e89370
void Unk_23f48d0::vf3() {
    Unk_7c20_Reset(Unk_24ba6f8);
}

class Unk_23f4a18 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_23f4a18() override;
    void vf3() override;
};
extern Unk_23f4a18* Unk_24ba320;

// 0x7100e92fc0, its thunk from +0x48 0x7100e93040
void Unk_23f4a18::vf3() {
    Unk_7c20_Reset(Unk_24ba320);
}

class Unk_23f4a68 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_23f4a68() override;
    void vf3() override;
};
extern Unk_23f4a68* Unk_27d92f8;

// 0x7100e93590, its thunk from +0x48 0x7100e93610
void Unk_23f4a68::vf3() {
    Unk_7c20_Reset(Unk_27d92f8);
}

class Unk_23f5bf8 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_23f5bf8() override;
    void vf3() override;
};
extern Unk_23f5bf8* Unk_24ba618;

// 0x7100eaa6f0, its thunk from +0x48 0x7100eaa770
void Unk_23f5bf8::vf3() {
    Unk_7c20_Reset(Unk_24ba618);
}

class Unk_23f5cb0 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_23f5cb0() override;
    void vf3() override;
};
extern Unk_23f5cb0* Unk_24ba5f8;

// 0x7100eacd90, its thunk from +0x48 0x7100eace10
void Unk_23f5cb0::vf3() {
    Unk_7c20_Reset(Unk_24ba5f8);
}

class Unk_23f5d70 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_23f5d70() override;
    void vf3() override;
};
extern Unk_23f5d70* Unk_24ba588;

// 0x7100eadd20, its thunk from +0x48 0x7100eadda0
void Unk_23f5d70::vf3() {
    Unk_7c20_Reset(Unk_24ba588);
}

class Unk_23f5dc0 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_23f5dc0() override;
    void vf3() override;
};
extern Unk_23f5dc0* Unk_24ba6e8;

// 0x7100eaf270, its thunk from +0x48 0x7100eaf2f0
void Unk_23f5dc0::vf3() {
    Unk_7c20_Reset(Unk_24ba6e8);
}

class Unk_23fb7f0 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_23fb7f0() override;
    void vf3() override;
};
extern Unk_23fb7f0* Unk_24ba708;

// 0x7100f1a860, its thunk from +0x48 0x7100f1a8e0
void Unk_23fb7f0::vf3() {
    Unk_7c20_Reset(Unk_24ba708);
}

class Unk_240b028 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_240b028() override;
    void vf3() override;
};
extern Unk_240b028* Unk_27d92e8;

// 0x7101049e70, its thunk from +0x48 0x7101049ef0
void Unk_240b028::vf3() {
    Unk_7c20_Reset(Unk_27d92e8);
}

class Unk_240b318 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_240b318() override;
    void vf3() override;
};
extern Unk_240b318* Unk_24ba598;

// 0x710104e2c0, its thunk from +0x48 0x710104e340
void Unk_240b318::vf3() {
    Unk_7c20_Reset(Unk_24ba598);
}

class Unk_240b460 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_240b460() override;
    void vf3() override;
    virtual void vf4();
    virtual void vf5();
};
extern Unk_240b460* Unk_27f0358;

// 0x7101053600, its thunk from +0x48 0x7101053680
void Unk_240b460::vf3() {
    Unk_7c20_Reset(Unk_27f0358);
}

class Unk_240bfb8 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_240bfb8() override;
    void vf3() override;
};
extern Unk_240bfb8* Unk_24ba668;

// 0x710105c3f0, its thunk from +0x48 0x710105c470
void Unk_240bfb8::vf3() {
    Unk_7c20_Reset(Unk_24ba668);
}

class Unk_240c658 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_240c658() override;
    void vf3() override;
};
extern Unk_240c658* Unk_24ba150;

// 0x710105e450, its thunk from +0x48 0x710105e4d0
void Unk_240c658::vf3() {
    Unk_7c20_Reset(Unk_24ba150);
}

class Unk_240c9d8 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_240c9d8() override;
    void vf3() override;
};
extern Unk_240c9d8* Unk_27d1048;

// 0x7101061b00, its thunk from +0x48 0x7101061b80
void Unk_240c9d8::vf3() {
    Unk_7c20_Reset(Unk_27d1048);
}

class Unk_240ca28 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_240ca28() override;
    void vf3() override;
};
extern Unk_240ca28* Unk_24ba5b8;

// 0x7101065100, its thunk from +0x48 0x7101065170
void Unk_240ca28::vf3() {
    Unk_7c20_Reset(Unk_24ba5b8);
}

class Unk_2417bd8 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_2417bd8() override;
    void vf3() override;
};
extern Unk_2417bd8* Unk_27e1870;

// 0x71010f7e70, its thunk from +0x48 0x71010f7ef0
void Unk_2417bd8::vf3() {
    Unk_7c20_Reset(Unk_27e1870);
}

class Unk_2417dc8 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_2417dc8() override;
    void vf3() override;
};
extern Unk_2417dc8* Unk_27e4f70;

// 0x71010fdce0, its thunk from +0x48 0x71010fdd60
void Unk_2417dc8::vf3() {
    Unk_7c20_Reset(Unk_27e4f70);
}

class Unk_2418910 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_2418910() override;
    void vf3() override;
};
extern Unk_2418910* Unk_24ba648;

// 0x7101105d00, its thunk from +0x48 0x7101105d80
void Unk_2418910::vf3() {
    Unk_7c20_Reset(Unk_24ba648);
}

class Unk_242f448 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_242f448() override;
    void vf3() override;
};
extern Unk_242f448* Unk_24ba698;

// 0x71013079b0, its thunk from +0x48 0x7101307a30
void Unk_242f448::vf3() {
    Unk_7c20_Reset(Unk_24ba698);
}

class Unk_242f710 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_242f710() override;
    void vf3() override;
};
extern Unk_242f710* Unk_24ba5c8;

// 0x710130f640, its thunk from +0x48 0x710130f6c0
void Unk_242f710::vf3() {
    Unk_7c20_Reset(Unk_24ba5c8);
}

class Unk_2432d40 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_2432d40() override;
    void vf3() override;
};
extern Unk_2432d40* Unk_24ba4e0;

// 0x7101380230, its thunk from +0x48 0x71013802a0
void Unk_2432d40::vf3() {
    Unk_7c20_Reset(Unk_24ba4e0);
}
