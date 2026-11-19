// Scope: common
// NEX 4.6.8's RefCountedObject and the small classes derived from it (RTTI:
// N2nn3nex16RefCountedObjectE, N2nn3nex7qBufferE, N2nn3nex3KeyE).
#include <nn/nex/RefCountedObject.h>
#include <nn/nex/qVector.h>

namespace nn {
namespace nex {

// 0x71015a98f0 (D2), 0x71015a9910 (D0)
RefCountedObject::~RefCountedObject() {}

// 0x71015cf3c0 (D2), 0x71015cf410 (D0)
qBuffer::~qBuffer() {
    if (m_data != nullptr) {
        Unk_15b9390(reinterpret_cast<u64>(m_data));
    }
}

class Key : public RefCountedObject {
public:
    virtual ~Key();

    qVector<u8> m_data;
};
PKMN_OFFSET_ASSERT(Key, m_data, 0x10);

// 0x71015ce560 (D2), 0x71015ce5b0 (D0)
Key::~Key() {}

}  // namespace nex
}  // namespace nn
