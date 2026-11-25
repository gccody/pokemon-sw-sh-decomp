#pragma once
// NEX 4.6.8's PRUDP stream and end point templates (RTTI:
// N2nn3nex22PRUDPStreamTemplateImpE, N2nn3nex31PRUDPStreamTemplatePRUDPLiteImpE,
// their base N2nn3nex23PRUDPStreamTemplateBaseE, N2nn3nex24PRUDPEndPointTemplateImpE,
// N2nn3nex33PRUDPEndPointTemplatePRUDPLiteImpE), as lib/nex/socket/Unk_160a230.cpp
// and Unk_160a800.cpp use them. The members without a name in the executable
// are placeholders (vf<slot>, field_<offset>).
//
// Each class's RTTI lists two bases at offset 0: an interface
// (N2nn3nex28PRUDPStreamTemplateInterfaceE, N2nn3nex30PRUDPEndPointTemplateInterfaceE)
// and N2nn3nex10RootObjectE. With <nn/nex/RootObject.h>'s RootObject (which has
// the vtable), the interfaces are declared empty here, and the classes'
// virtual functions are declared in the first class that has them.
#include <nn/nex/RootObject.h>
#include <nn/nex/PseudoGlobalVariable.h>

#include "../Unk_15c64b0.h"

// 0x71006a5230: the calling thread's instance index, in a thread-local table.
u32* Unk_6a5230(void* key);
extern bool Unk_27f3838;   // more than one instance
extern void* Unk_27f3830;  // the thread-local key of the instance index

// The calling thread's instance of a pseudo-global variable (an inline
// helper; the name isn't the executable's).
template <class T>
inline T& Unk_160a230_Get(nn::nex::PseudoGlobalVariable<T>& var) {
    if (Unk_27f3838) {
        u32 index = *Unk_6a5230(Unk_27f3830);
        if (index != 0) {
            return var.m_instances[index];
        }
    }
    return var.m_value;
}

// What an end point's slot 2 gives a stream: a byte and 24 bits of flags.
struct Unk_160a350_Info {
    u32 m_value : 8;
    u32 m_flags : 24;
};
PKMN_SIZE_ASSERT(Unk_160a350_Info, 0x4);

// A PRUDP message, as the templates read it.
struct Unk_160a230_Message {
    u8 _0[0x40];
    u8 field_40;
    u8 _41;
    u8 field_42;
    u8 _43[5];
    Unk_15c6560_Digest m_signature;
    u16 field_60;  // the low 4 bits: its type
    u8 _62[0x6e];
    Unk_160a350_Info field_d0;
};
PKMN_OFFSET_ASSERT(Unk_160a230_Message, field_42, 0x42);
PKMN_OFFSET_ASSERT(Unk_160a230_Message, m_signature, 0x48);
PKMN_OFFSET_ASSERT(Unk_160a230_Message, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_160a230_Message, field_d0, 0xd0);

// What a stream's slot 7 takes.
struct Unk_160aa00_arg1 {
    u64 field_0;
};

namespace nn {
namespace nex {

// N2nn3nex15PacketEncDecInfE: the encoding of the packets (its slots 3 and 5
// are RC4PacketEncDec's two big ones).
class PacketEncDecInf : public RootObject {
public:
    ~PacketEncDecInf() override {}
    virtual void vf2();
    virtual void vf3(Unk_160a230_Message* message, u32 arg2, void* arg3, u8 arg4, u64 arg5,
                     void* arg6, u64 arg7);
    virtual void vf4();
    // the message's signature, into `digest`
    virtual u32 vf5(Unk_160a230_Message* message, u32 arg2, u64 arg3, u64 arg4, u64 arg5,
                    Unk_15c6560_Digest* digest);
};

// N2nn3nex15RC4PacketEncDecE
class RC4PacketEncDec : public PacketEncDecInf {
public:
    // 0x71015e76f0
    ~RC4PacketEncDec() override;

    u8 _8[0xb0];
};

// N2nn3nex28PRUDPStreamTemplateInterfaceE (see the top of the file)
class PRUDPStreamTemplateInterface {};

// N2nn3nex23PRUDPStreamTemplateBaseE: a stream's packets, encoded by m_encDec.
class PRUDPStreamTemplateBase : public PRUDPStreamTemplateInterface, public RootObject {
public:
    PRUDPStreamTemplateBase(u32 arg, PacketEncDecInf* encDec) : field_8(arg), m_encDec(encDec) {}
    virtual u32 vf2();
    virtual bool vf3(const Unk_160a230_Message* message, Unk_160a230_Message* out);
    virtual bool vf4(Unk_160a230_Message* message, u64 arg2, u64 arg3, u64 arg4);
    virtual u32 vf5(u64 arg1, u64 arg2, u64 arg3, Unk_160a230_Message* message, u64 arg5,
                    u64 arg6, u64 arg7, u32 arg8);
    virtual bool vf6(Unk_160a230_Message* message, u64 arg2, u64 arg3, u64 arg4);
    virtual void vf7(const Unk_160aa00_arg1* value);
    virtual u32 vf8();
    virtual void vf9(u32 value);

    u32 field_8;
    PacketEncDecInf* m_encDec;
    u32 field_18;
};
PKMN_OFFSET_ASSERT(PRUDPStreamTemplateBase, m_encDec, 0x10);
PKMN_SIZE_ASSERT(PRUDPStreamTemplateBase, 0x20);

// N2nn3nex22PRUDPStreamTemplateImpE
class PRUDPStreamTemplateImp : public PRUDPStreamTemplateBase {
public:
    PRUDPStreamTemplateImp(u32 arg, PacketEncDecInf* encDec)
        : PRUDPStreamTemplateBase(arg, encDec) {}
    // 0x7101609f60 (D2), 0x7101609f70 (D0)
    ~PRUDPStreamTemplateImp() override;
    u32 vf5(u64 arg1, u64 arg2, u64 arg3, Unk_160a230_Message* message, u64 arg5, u64 arg6,
            u64 arg7, u32 arg8) override;
};
PKMN_SIZE_ASSERT(PRUDPStreamTemplateImp, 0x20);

// N2nn3nex31PRUDPStreamTemplatePRUDPLiteImpE
class PRUDPStreamTemplatePRUDPLiteImp : public PRUDPStreamTemplateBase {
public:
    PRUDPStreamTemplatePRUDPLiteImp(u32 arg, PacketEncDecInf* encDec)
        : PRUDPStreamTemplateBase(arg, encDec) {}
    ~PRUDPStreamTemplatePRUDPLiteImp() override;
    u32 vf2() override;
    bool vf3(const Unk_160a230_Message* message, Unk_160a230_Message* out) override;
    bool vf4(Unk_160a230_Message* message, u64 arg2, u64 arg3, u64 arg4) override;
    u32 vf5(u64 arg1, u64 arg2, u64 arg3, Unk_160a230_Message* message, u64 arg5, u64 arg6,
            u64 arg7, u32 arg8) override;
    bool vf6(Unk_160a230_Message* message, u64 arg2, u64 arg3, u64 arg4) override;
};
PKMN_SIZE_ASSERT(PRUDPStreamTemplatePRUDPLiteImp, 0x20);

// N2nn3nex30PRUDPEndPointTemplateInterfaceE (see the top of the file)
class PRUDPEndPointTemplateInterface {};

// N2nn3nex24PRUDPEndPointTemplateImpE
class PRUDPEndPointTemplateImp : public PRUDPEndPointTemplateInterface, public RootObject {
public:
    ~PRUDPEndPointTemplateImp() override;
    virtual void vf2(Unk_160a350_Info* info, u16* arg2);
    virtual u64 vf3(u8 enabled, u32 info);
    virtual PacketEncDecInf* vf4();

    u32 field_8;
    RC4PacketEncDec m_encDec;
};
PKMN_OFFSET_ASSERT(PRUDPEndPointTemplateImp, m_encDec, 0x10);

// N2nn3nex33PRUDPEndPointTemplatePRUDPLiteImpE
class PRUDPEndPointTemplatePRUDPLiteImp : public PRUDPEndPointTemplateInterface,
                                          public RootObject {
public:
    ~PRUDPEndPointTemplatePRUDPLiteImp() override;
    virtual void vf2(Unk_160a350_Info* info, u16* arg2);
    virtual u64 vf3(u8 enabled, u32 info);
    virtual PacketEncDecInf* vf4();
};

}  // namespace nex
}  // namespace nn
