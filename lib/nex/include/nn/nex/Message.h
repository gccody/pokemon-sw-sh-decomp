#pragma once
#include <nn/nex/ByteStream.h>

namespace nn {
namespace nex {

// N2nn3nex7MessageE: a protocol message (a ByteStream).
class Message : public ByteStream {
public:
    Message();
    virtual ~Message();

    // 0x7101630b10, 0x7101630a90: the protocol's and the method's IDs.
    void Unk_1630b10(u16 protocolId, u32 request);
    void Unk_1630a90(u32 methodId);

    u8 _70[0x0];
};

}  // namespace nex
}  // namespace nn
