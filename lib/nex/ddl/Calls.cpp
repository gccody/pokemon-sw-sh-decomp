// Scope: common
// NEX 4.6.8's protocol clients' calls (tools/nexddl.py calls): each builds a
// Message (the protocol's and the method's IDs, then the inputs), registers
// where the results go and the method's result handler, and sends it. The
// functions and their parameters are placeholders: nothing names them.
#include <nn/nex/Call.h>
#include "Streams.h"

struct Unk_158ab60;
void Unk_158ab60_write(nn::nex::ByteStream* s, const Unk_158ab60& v);
struct Unk_158c660 {
    u8 _0[0x130];
};
void Unk_158c660_write(nn::nex::ByteStream* s, const Unk_158c660& v);
struct Unk_158c660;
void Unk_158c660_write(nn::nex::ByteStream* s, const Unk_158c660& v);
struct Unk_1590930;
void Unk_1590930_write(nn::nex::ByteStream* s, const Unk_1590930& v);
struct Unk_15a2c60;
void Unk_15a2c60_write(nn::nex::ByteStream* s, const Unk_15a2c60& v);
struct Unk_15a7420;
void Unk_15a7420_write(nn::nex::ByteStream* s, const Unk_15a7420& v);
struct Unk_15a8550;
void Unk_15a8550_write(nn::nex::ByteStream* s, const Unk_15a8550& v);
struct Unk_15a8b70;
void Unk_15a8b70_write(nn::nex::ByteStream* s, const Unk_15a8b70& v);
struct Unk_15a8db0;
void Unk_15a8db0_write(nn::nex::ByteStream* s, const Unk_15a8db0& v);
struct Unk_164da60;
void Unk_164da60_write(nn::nex::ByteStream* s, const Unk_164da60& v);
struct Unk_164e020;
void Unk_164e020_write(nn::nex::ByteStream* s, const Unk_164e020& v);
void Unk_158cdc0();
void Unk_158cee0();
void Unk_158cf90_update();
void Unk_158cfa0_update();
void Unk_158cfb0();
void Unk_158d020_update();
void Unk_158d030();
void Unk_158d0a0();
void Unk_158d1f0();
void Unk_158d300();
void Unk_158d3b0_update();
void Unk_158d3c0();
void Unk_158d490();
void Unk_158d5a0();
void Unk_158d680();
void Unk_158d6f0();
void Unk_158d760();
void Unk_158d8a0_update();
void Unk_158d8b0();
void Unk_158d920();
void Unk_158d9c0();
void Unk_158da60_update();
void Unk_158da70();
void Unk_158db50();
void Unk_158dc00();
void Unk_158dd30_update();
void Unk_158dd40();
void Unk_158de20();
void Unk_158dec0();
void Unk_158df30();
void Unk_158e030_update();
void Unk_158e040_update();
void Unk_158e050();
void Unk_158e200();
void Unk_158e270();
void Unk_158e370();
void Unk_158e480_update();
void Unk_158e490_update();
void Unk_158e4a0();
void Unk_158e510();
void Unk_158e610_update();
void Unk_158e620();
void Unk_158e800();
void Unk_158e900();
void Unk_158e9d0_update();
void Unk_158e9e0_update();
void Unk_158e9f0_update();
void Unk_158ea10();
void Unk_158ead0();
void Unk_15a3a70_update();
void Unk_15a3a80_update();
void Unk_15a3a90_update();
void Unk_15a3ab0_update();
void Unk_15a3ac0();
void Unk_15a3b60_update();
void Unk_15a3b70_update();
void Unk_15a3c50();
void Unk_15a3d20();
void Unk_15a3df0_update();
void Unk_15a3e00();
void Unk_15a3e90_update();
void Unk_15a3ea0();
void Unk_15a3fc0();
void Unk_15a40e0();
void Unk_15a4200();
void Unk_15a4320_update();
void Unk_15a4400();
void Unk_15a4520();
void Unk_15a45f0();
void Unk_15a46c0();
void Unk_15a4790();
void Unk_15a4860();
void Unk_15a4930();
void Unk_15a4a80();
void Unk_15a4b50();
void Unk_15a4be0();
void Unk_15a4c70();
void Unk_15a4d00();
void Unk_15af680();
void Unk_15af720_update();
void Unk_15af730();
void Unk_15af830();
void Unk_15af8c0();
void Unk_15b3ce0(nn::nex::ByteStream* s, nn::nex::ProtocolCallContext* ctx);
void Unk_15b3d20(nn::nex::ByteStream* s, nn::nex::ProtocolCallContext* ctx);
void Unk_15b3df0_update();
void Unk_15b3fa0(nn::nex::ByteStream* s, nn::nex::ProtocolCallContext* ctx);
void Unk_164e820_update();
void Unk_164e830_update();
void Unk_164e840_update();
void Unk_164e850(nn::nex::ByteStream* s, nn::nex::ProtocolCallContext* ctx);
void Unk_164e8f0(nn::nex::ByteStream* s, nn::nex::ProtocolCallContext* ctx);
void Unk_164e990(nn::nex::ByteStream* s, nn::nex::ProtocolCallContext* ctx);
void Unk_164ea30_update();
void Unk_164ea40(nn::nex::ByteStream* s, nn::nex::ProtocolCallContext* ctx);
void Unk_164eae0(nn::nex::ByteStream* s, nn::nex::ProtocolCallContext* ctx);

extern Unk_Handlers Unk_27f20d8;
extern Unk_Handlers Unk_27f2340;
extern Unk_Handlers Unk_27f25d0;
extern Unk_Handlers Unk_27f26f8;
extern Unk_Handlers Unk_27f2860;
extern Unk_Handlers Unk_27f9b68;

// 0x7101574f80
bool Unk_1574f80(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_158c300& arg2, void* arg3) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x19);
        Unk_158c300_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
        }
        Unk_27f20d8.m_handlers[24] = Unk_158dc00;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x71015751d0
bool Unk_15751d0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_158c460& arg2, void* arg3) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x1);
        Unk_158c460_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
        }
        Unk_27f20d8.m_handlers[0] = Unk_158cdc0;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x7101575430
bool Unk_1575430(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_158c300& arg2, void* arg3, void* arg4) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x21);
        Unk_158c300_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
            Unk_1630ac0(ctx, arg4);
        }
        Unk_27f20d8.m_handlers[32] = Unk_158e050;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x7101575780
bool Unk_1575780(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_158c660& arg2, void* arg3) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x18);
        Unk_158c660_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
        }
        Unk_27f20d8.m_handlers[23] = Unk_158db50;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x71015759d0
bool Unk_15759d0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_158c980& arg2, void* arg3) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x2);
        Unk_158c980_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
        }
        Unk_27f20d8.m_handlers[1] = Unk_158cee0;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x7101575be0
bool Unk_1575be0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_158a460& arg2) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x1a);
        Unk_158a460_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_27f20d8.m_handlers[25] = Unk_158dd30_update;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x7101575de0
bool Unk_1575de0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_158a540& arg2) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x3);
        Unk_158a540_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_27f20d8.m_handlers[2] = Unk_158cf90_update;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x7101575fe0
bool Unk_1575fe0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<u64>& arg2) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x25);
        WriteContainer(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_27f20d8.m_handlers[36] = Unk_158e480_update;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x7101576200
bool Unk_1576200(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_158c660& arg2, void* arg3) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x15);
        Unk_158c660_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
        }
        Unk_27f20d8.m_handlers[20] = Unk_158d9c0;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x7101576400
bool Unk_1576400(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const u64& arg2, const Unk_158c660& arg3) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x29);
        msg.Write(arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_158c660_write(&msg, arg3);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_27f20d8.m_handlers[40] = Unk_158e610_update;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x7101576640
bool Unk_1576640(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<u64>& arg2, const nn::nex::qVector<Unk_158c660>& arg3, const bool& arg4, void* arg5) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x2a);
        WriteContainer(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        WriteContainer(&msg, arg3, Unk_158c660_write);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_15c8ca0_write(&msg, arg4);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg5);
        }
        Unk_27f20d8.m_handlers[41] = Unk_158e620;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x7101576a50
bool Unk_1576a50(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_158cb70& arg2, void* arg3) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0xa);
        Unk_158cb70_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
        }
        Unk_27f20d8.m_handlers[9] = Unk_158d300;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x7101576ca0
bool Unk_1576ca0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_158a620& arg2) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0xb);
        Unk_158a620_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_27f20d8.m_handlers[10] = Unk_158d3b0_update;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x7101576ea0
bool Unk_1576ea0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_158a880& arg2) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x4);
        Unk_158a880_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_27f20d8.m_handlers[3] = Unk_158cfa0_update;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x7101577110
bool Unk_1577110(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<Unk_158a880>& arg2, const bool& arg3, void* arg4) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x5);
        WriteContainer(&msg, arg2, Unk_158a880_write);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_15c8ca0_write(&msg, arg3);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg4);
        }
        Unk_27f20d8.m_handlers[4] = Unk_158cfb0;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x71015774d0
bool Unk_15774d0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_158a0f0& arg2) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x26);
        Unk_158a0f0_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_27f20d8.m_handlers[37] = Unk_158e490_update;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x71015776d0
bool Unk_15776d0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_158a2d0& arg2) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x6);
        Unk_158a2d0_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_27f20d8.m_handlers[5] = Unk_158d020_update;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x7101577970
bool Unk_1577970(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<u64>& arg2, const nn::nex::qVector<Unk_158a0f0>& arg3, const bool& arg4, void* arg5) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x27);
        WriteContainer(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        WriteContainer(&msg, arg3, Unk_158a0f0_write);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_15c8ca0_write(&msg, arg4);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg5);
        }
        Unk_27f20d8.m_handlers[38] = Unk_158e4a0;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x7101577d20
bool Unk_1577d20(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<u64>& arg2, const nn::nex::qVector<Unk_158a2d0>& arg3, const bool& arg4, void* arg5) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x7);
        WriteContainer(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        WriteContainer(&msg, arg3, Unk_158a2d0_write);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_15c8ca0_write(&msg, arg4);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg5);
        }
        Unk_27f20d8.m_handlers[6] = Unk_158d030;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x71015780c0
bool Unk_15780c0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_158a970& arg2, void* arg3) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x8);
        Unk_158a970_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
        }
        Unk_27f20d8.m_handlers[7] = Unk_158d0a0;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x71015782d0
bool Unk_15782d0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<u64>& arg2, const Unk_158a970& arg3, void* arg4, void* arg5) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x9);
        WriteContainer(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_158a970_write(&msg, arg3);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg4);
            Unk_1630ac0(ctx, arg5);
        }
        Unk_27f20d8.m_handlers[8] = Unk_158d1f0;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x7101578570
bool Unk_1578570(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<Unk_158a970>& arg2, void* arg3, void* arg4) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x24);
        WriteContainer(&msg, arg2, Unk_158a970_write);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
            Unk_1630ac0(ctx, arg4);
        }
        Unk_27f20d8.m_handlers[35] = Unk_158e370;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x71015787e0
bool Unk_15787e0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_1590930& arg2, void* arg3) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0xc);
        Unk_1590930_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
        }
        Unk_27f20d8.m_handlers[11] = Unk_158d3c0;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x71015789f0
bool Unk_15789f0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_1590930& arg2, void* arg3) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x2e);
        Unk_1590930_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
        }
        Unk_27f20d8.m_handlers[45] = Unk_158e900;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x7101578c00
bool Unk_1578c00(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_158ab60& arg2, void* arg3) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0xd);
        Unk_158ab60_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
        }
        Unk_27f20d8.m_handlers[12] = Unk_158d490;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x7101578e10
bool Unk_1578e10(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_158aa70& arg2, void* arg3, void* arg4) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x1b);
        Unk_158aa70_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
            Unk_1630ac0(ctx, arg4);
        }
        Unk_27f20d8.m_handlers[26] = Unk_158dd40;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x7101579030
bool Unk_1579030(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_158aa70& arg2, void* arg3, void* arg4) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0xe);
        Unk_158aa70_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
            Unk_1630ac0(ctx, arg4);
        }
        Unk_27f20d8.m_handlers[13] = Unk_158d5a0;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x7101579280
bool Unk_1579280(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_158f560& arg2, const Unk_158ec60& arg3, const bool& arg4, void* arg5) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0xf);
        Unk_158f560_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_158ec60_write(&msg, arg3);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_15c8ca0_write(&msg, arg4);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg5);
        }
        Unk_27f20d8.m_handlers[14] = Unk_158d680;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x7101579610
bool Unk_1579610(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<Unk_158f560>& arg2, const nn::nex::qVector<Unk_158ec60>& arg3, const bool& arg4, const bool& arg5, void* arg6, void* arg7) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x28);
        WriteContainer(&msg, arg2, Unk_158f560_write);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        WriteContainer(&msg, arg3, Unk_158ec60_write);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_15c8ca0_write(&msg, arg4);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_15c8ca0_write(&msg, arg5);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg6);
            Unk_1630ac0(ctx, arg7);
        }
        Unk_27f20d8.m_handlers[39] = Unk_158e510;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710157a2c0
bool Unk_157a2c0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_158f560& arg2, void* arg3, const u64& arg4) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x10);
        Unk_158f560_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        msg.Write(arg4);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
        }
        Unk_27f20d8.m_handlers[15] = Unk_158d6f0;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710157a520
bool Unk_157a520(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<u64>& arg2, void* arg3, void* arg4, const u64& arg5) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x11);
        WriteContainer(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        msg.Write(arg5);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
            Unk_1630ac0(ctx, arg4);
        }
        Unk_27f20d8.m_handlers[16] = Unk_158d760;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710157a800
bool Unk_157a800(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_158f560& arg2, const u64& arg3) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x12);
        Unk_158f560_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        msg.Write(arg3);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_27f20d8.m_handlers[17] = Unk_158d8a0_update;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710157aad0
bool Unk_157aad0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<u64>& arg2, const bool& arg3, void* arg4) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x13);
        WriteContainer(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_15c8ca0_write(&msg, arg3);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg4);
        }
        Unk_27f20d8.m_handlers[18] = Unk_158d8b0;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710157ae40
bool Unk_157ae40(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_158ac40& arg2, void* arg3) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x1c);
        Unk_158ac40_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
        }
        Unk_27f20d8.m_handlers[27] = Unk_158de20;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710157b050
bool Unk_157b050(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_158ad60& arg2, void* arg3) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x14);
        Unk_158ad60_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
        }
        Unk_27f20d8.m_handlers[19] = Unk_158d920;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710157b260
bool Unk_157b260(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_1591630& arg2) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x16);
        Unk_1591630_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_27f20d8.m_handlers[21] = Unk_158da60_update;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710157b450
bool Unk_157b450(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_158f560& arg2, void* arg3, void* arg4, const u64& arg5) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x17);
        Unk_158f560_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        msg.Write(arg5);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
            Unk_1630ac0(ctx, arg4);
        }
        Unk_27f20d8.m_handlers[22] = Unk_158da70;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710157b710
bool Unk_157b710(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const u64& arg2, const u16& arg3, void* arg4) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x1d);
        msg.Write(arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        msg.Write(arg3);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg4);
        }
        Unk_27f20d8.m_handlers[28] = Unk_158dec0;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710157b9b0
bool Unk_157b9b0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const u64& arg2, const nn::nex::qVector<u16>& arg3, void* arg4, void* arg5) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x1e);
        msg.Write(arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        WriteContainer(&msg, arg3);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg4);
            Unk_1630ac0(ctx, arg5);
        }
        Unk_27f20d8.m_handlers[29] = Unk_158df30;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710157bca0
bool Unk_157bca0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const u16& arg2, const u64& arg3, const bool& arg4) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x1f);
        msg.Write(arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        msg.Write(arg3);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_15c8ca0_write(&msg, arg4);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_27f20d8.m_handlers[30] = Unk_158e030_update;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710157bf80
bool Unk_157bf80(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const u16& arg2, const bool& arg3) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x20);
        msg.Write(arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_15c8ca0_write(&msg, arg3);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_27f20d8.m_handlers[31] = Unk_158e040_update;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710157c200
bool Unk_157c200(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const u64& arg2, void* arg3) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x22);
        msg.Write(arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
        }
        Unk_27f20d8.m_handlers[33] = Unk_158e200;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710157c430
bool Unk_157c430(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<u64>& arg2, void* arg3, void* arg4) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x23);
        WriteContainer(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
            Unk_1630ac0(ctx, arg4);
        }
        Unk_27f20d8.m_handlers[34] = Unk_158e270;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710157c690
bool Unk_157c690(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<u64>& arg2, void* arg3, void* arg4) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x2d);
        WriteContainer(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
            Unk_1630ac0(ctx, arg4);
        }
        Unk_27f20d8.m_handlers[44] = Unk_158e800;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710157c8f0
bool Unk_157c8f0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_1591a00& arg2) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x2f);
        Unk_1591a00_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_27f20d8.m_handlers[46] = Unk_158e9d0_update;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710157cae0
bool Unk_157cae0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<Unk_1591a00>& arg2) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x30);
        WriteContainer(&msg, arg2, Unk_1591a00_write);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_27f20d8.m_handlers[47] = Unk_158e9e0_update;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710157cd30
bool Unk_157cd30(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const u8& arg2) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x31);
        msg.Write(arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_27f20d8.m_handlers[48] = Unk_158e9f0_update;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710157d130
bool Unk_157d130(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_1591910& arg2, void* arg3) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x33);
        Unk_1591910_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
        }
        Unk_27f20d8.m_handlers[50] = Unk_158ea10;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710157d330
bool Unk_157d330(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<Unk_1591910>& arg2, void* arg3, void* arg4) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x34);
        WriteContainer(&msg, arg2, Unk_1591910_write);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
            Unk_1630ac0(ctx, arg4);
        }
        Unk_27f20d8.m_handlers[51] = Unk_158ead0;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710159d3b0
bool Unk_159d3b0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_15a1f30& arg2, void* arg3) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x28);
        Unk_15a1f30_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
        }
        Unk_27f2340.m_handlers[39] = Unk_15a40e0;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710159d5b0
bool Unk_159d5b0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_15a3220& arg2, void* arg3) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x26);
        Unk_15a3220_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
        }
        Unk_27f2340.m_handlers[37] = Unk_15a3ea0;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710159d7b0
bool Unk_159d7b0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_15a3640& arg2, void* arg3) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x27);
        Unk_15a3640_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
        }
        Unk_27f2340.m_handlers[38] = Unk_15a3fc0;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710159d9d0
bool Unk_159d9d0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const u32& arg2) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x1);
        msg.Write(arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_27f2340.m_handlers[0] = Unk_15a3a70_update;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710159dbe0
bool Unk_159dbe0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const u32& arg2) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x2);
        msg.Write(arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_27f2340.m_handlers[1] = Unk_15a3a80_update;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710159de00
bool Unk_159de00(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const u32& arg2, const u32& arg3, const u32& arg4) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x8);
        msg.Write(arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        msg.Write(arg3);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        msg.Write(arg4);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_27f2340.m_handlers[7] = Unk_15a3a90_update;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710159e270
bool Unk_159e270(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const u32& arg2, const nn::nex::qVector<u32>& arg3) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0xc);
        msg.Write(arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        WriteContainer(&msg, arg3);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_27f2340.m_handlers[11] = Unk_15a3ab0_update;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710159e5c0
bool Unk_159e5c0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const u32& arg2, const u8& arg3) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x22);
        msg.Write(arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        msg.Write(arg3);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_27f2340.m_handlers[33] = Unk_15a3df0_update;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710159e860
bool Unk_159e860(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_15a8b70& arg2) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x2c);
        Unk_15a8b70_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_27f2340.m_handlers[43] = Unk_15a4320_update;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710159ecb0
bool Unk_159ecb0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const u32& arg2, void* arg3) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x29);
        msg.Write(arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
        }
        Unk_27f2340.m_handlers[40] = Unk_15a4200;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710159f100
bool Unk_159f100(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const u32& arg2, void* arg3) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x31);
        msg.Write(arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
        }
        Unk_27f2340.m_handlers[48] = Unk_15a4400;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710159f320
bool Unk_159f320(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const u64& arg2, const Unk_16345b0& arg3, void* arg4) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x32);
        msg.Write(arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_16345b0_write(&msg, arg3);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg4);
        }
        Unk_27f2340.m_handlers[49] = Unk_15a4520;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710159f560
bool Unk_159f560(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_15a3380& arg2, void* arg3) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x33);
        Unk_15a3380_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
        }
        Unk_27f2340.m_handlers[50] = Unk_15a45f0;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710159f760
bool Unk_159f760(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_15a6e50& arg2, void* arg3) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x34);
        Unk_15a6e50_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
        }
        Unk_27f2340.m_handlers[51] = Unk_15a46c0;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710159f960
bool Unk_159f960(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_15a7420& arg2, void* arg3, const nn::nex::String& arg4) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x11);
        Unk_15a7420_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_162cec0_write(&msg, arg4);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
        }
        Unk_27f2340.m_handlers[16] = Unk_15a3ac0;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710159fbc0
bool Unk_159fbc0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const u32& arg2, const nn::nex::String& arg3, const nn::nex::String& arg4) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x13);
        msg.Write(arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_162cec0_write(&msg, arg3);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_162cec0_write(&msg, arg4);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_27f2340.m_handlers[18] = Unk_15a3b70_update;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x71015a0080
bool Unk_15a0080(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, void* arg2, const bool& arg3, const Unk_16345b0& arg4) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x15);
        Unk_15c8ca0_write(&msg, arg3);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_16345b0_write(&msg, arg4);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg2);
        }
        Unk_27f2340.m_handlers[20] = Unk_15a3c50;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x71015a02f0
bool Unk_15a02f0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, void* arg2, const u64& arg3, const Unk_16345b0& arg4) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x16);
        msg.Write(arg3);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_16345b0_write(&msg, arg4);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg2);
        }
        Unk_27f2340.m_handlers[21] = Unk_15a3d20;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x71015a0560
bool Unk_15a0560(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, void* arg2, const u64& arg3, const Unk_16345b0& arg4) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x36);
        msg.Write(arg3);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_16345b0_write(&msg, arg4);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg2);
        }
        Unk_27f2340.m_handlers[53] = Unk_15a4790;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x71015a07a0
bool Unk_15a07a0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_15a7420& arg2) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x12);
        Unk_15a7420_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_27f2340.m_handlers[17] = Unk_15a3b60_update;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x71015a09b0
bool Unk_15a09b0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const u32& arg2, void* arg3) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x24);
        msg.Write(arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
        }
        Unk_27f2340.m_handlers[35] = Unk_15a3e00;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x71015a0bd0
bool Unk_15a0bd0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const u32& arg2) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x25);
        msg.Write(arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_27f2340.m_handlers[36] = Unk_15a3e90_update;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x71015a1090
bool Unk_15a1090(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_15a8550& arg2, void* arg3) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x37);
        Unk_15a8550_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
        }
        Unk_27f2340.m_handlers[54] = Unk_15a4860;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x71015a12c0
bool Unk_15a12c0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const u32& arg2, const u32& arg3, void* arg4) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x39);
        msg.Write(arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        msg.Write(arg3);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg4);
        }
        Unk_27f2340.m_handlers[56] = Unk_15a4930;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x71015a1500
bool Unk_15a1500(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_15a2c60& arg2, void* arg3) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x3c);
        Unk_15a2c60_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
        }
        Unk_27f2340.m_handlers[59] = Unk_15a4a80;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x71015a1720
bool Unk_15a1720(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const u32& arg2, void* arg3) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x3d);
        msg.Write(arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
        }
        Unk_27f2340.m_handlers[60] = Unk_15a4b50;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x71015a1920
bool Unk_15a1920(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_15a8db0& arg2, void* arg3) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x3e);
        Unk_15a8db0_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
        }
        Unk_27f2340.m_handlers[61] = Unk_15a4be0;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x71015a1b40
bool Unk_15a1b40(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const u32& arg2, void* arg3) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x3f);
        msg.Write(arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
        }
        Unk_27f2340.m_handlers[62] = Unk_15a4c70;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x71015a1d40
bool Unk_15a1d40(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_15a2850& arg2, void* arg3) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x45);
        Unk_15a2850_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
        }
        Unk_27f2340.m_handlers[68] = Unk_15a4d00;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x71015ae5a0
bool Unk_15ae5a0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_15af9d0& arg2, void* arg3) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x1);
        Unk_15af9d0_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
        }
        Unk_27f25d0.m_handlers[0] = Unk_15af680;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x71015ae7a0
bool Unk_15ae7a0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_15af2e0& arg2) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x3);
        Unk_15af2e0_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_27f25d0.m_handlers[2] = Unk_15af720_update;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x71015ae990
bool Unk_15ae990(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<Unk_15b05c0>& arg2, void* arg3, void* arg4) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x9);
        WriteContainer(&msg, arg2, Unk_15b05c0_write);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
            Unk_1630ac0(ctx, arg4);
        }
        Unk_27f25d0.m_handlers[8] = Unk_15af730;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x71015aebe0
bool Unk_15aebe0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_15b04b0& arg2, void* arg3) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0xc);
        Unk_15b04b0_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
        }
        Unk_27f25d0.m_handlers[11] = Unk_15af830;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x71015aede0
bool Unk_15aede0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_15aefd0& arg2, void* arg3) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0xe);
        Unk_15aefd0_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
        }
        Unk_27f25d0.m_handlers[13] = Unk_15af8c0;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x71015b1cf0
bool Unk_15b1cf0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, void* arg2, const u32& arg3) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x2);
        msg.Write(arg3);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg2);
        }
        Unk_27f26f8.m_handlers[1] = reinterpret_cast<void (*)()>(Unk_15b3ce0);
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x71015b1f10
bool Unk_15b1f10(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, void* arg2, const u32& arg3, const nn::nex::String& arg4) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x1);
        msg.Write(arg3);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_162cec0_write(&msg, arg4);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg2);
        }
        Unk_27f2860.m_handlers[0] = reinterpret_cast<void (*)()>(Unk_15b3fa0);
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x71015b2500
bool Unk_15b2500(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const u32& arg2, const bool& arg3) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x2a);
        msg.Write(arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_15c8ca0_write(&msg, arg3);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_27f26f8.m_handlers[41] = Unk_15b3df0_update;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x71015b2740
bool Unk_15b2740(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const u32& arg2, void* arg3) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x29);
        msg.Write(arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
        }
        Unk_27f26f8.m_handlers[40] = reinterpret_cast<void (*)()>(Unk_15b3d20);
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710164c530
bool Unk_164c530(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const u32& arg2, const Unk_164da60& arg3, const bool& arg4) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x1);
        msg.Write(arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_164da60_write(&msg, arg3);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_15c8ca0_write(&msg, arg4);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_27f9b68.m_handlers[0] = Unk_164e820_update;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710164c7c0
bool Unk_164c7c0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const u32& arg2, const Unk_164da60& arg3) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x3);
        msg.Write(arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_164da60_write(&msg, arg3);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_27f9b68.m_handlers[2] = Unk_164e840_update;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710164c9d0
bool Unk_164c9d0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const u32& arg2, const Unk_164da60& arg3) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x2);
        msg.Write(arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_164da60_write(&msg, arg3);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_27f9b68.m_handlers[1] = Unk_164e830_update;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710164cc50
bool Unk_164cc50(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, void* arg2) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x8);
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg2);
        }
        Unk_27f9b68.m_handlers[7] = reinterpret_cast<void (*)()>(Unk_164e850);
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710164ce30
bool Unk_164ce30(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const u32& arg2, const u32& arg3, const u32& arg4, void* arg5) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0xa);
        msg.Write(arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        msg.Write(arg3);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        msg.Write(arg4);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg5);
        }
        Unk_27f9b68.m_handlers[9] = reinterpret_cast<void (*)()>(Unk_164e8f0);
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710164d0c0
bool Unk_164d0c0(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<u64>& arg2, void* arg3) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0xb);
        WriteContainer(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
        }
        Unk_27f9b68.m_handlers[10] = reinterpret_cast<void (*)()>(Unk_164e990);
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710164d300
bool Unk_164d300(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_164e020& arg2) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0xf);
        Unk_164e020_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        Unk_27f9b68.m_handlers[14] = Unk_164ea30_update;
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710164d510
bool Unk_164d510(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const Unk_164e020& arg2, const u32& arg3, void* arg4) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x10);
        Unk_164e020_write(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        msg.Write(arg3);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg4);
        }
        Unk_27f9b68.m_handlers[15] = reinterpret_cast<void (*)()>(Unk_164ea40);
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}

// 0x710164d750
bool Unk_164d750(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, const nn::nex::qVector<u64>& arg2, void* arg3) {
    nn::nex::Message msg;
    {
        Unk_ScopedCoreLock lock;
        msg.Unk_1630b10(self->m_protocolId, true);
        if (!Unk_1630a20(&msg, ctx)) {
            return false;
        }
        msg.Unk_1630a90(0x11);
        WriteContainer(&msg, arg2);
        if (msg.m_error) {
            Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));
            return true;
        }
        if (ctx != nullptr) {
            Unk_1630ac0(ctx, arg3);
        }
        Unk_27f9b68.m_handlers[16] = reinterpret_cast<void (*)()>(Unk_164eae0);
        if (!self->m_canDefer || !Unk_1630b90(self, 0x10)) {
            return Unk_162f1a0(self, ctx, &msg);
        }
    }
    return Unk_162f1a0(self, ctx, &msg);
}
