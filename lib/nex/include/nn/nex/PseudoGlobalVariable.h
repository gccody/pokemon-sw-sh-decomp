#pragma once
#include <nn/nex/RootObject.h>

void Unk_15b9390(u64 p);

namespace nn {
namespace nex {

class PseudoGlobalVariableRoot;

}  // namespace nex
}  // namespace nn

// 0x710244fbf0: how many instances each pseudo-global variable has (one per
// context; the name isn't known).
extern size_t Unk_244fbf0;
// 0x71027f3828: the list of the pseudo-global variables.
extern u8 Unk_27f3828[];
// 0x71015ceec0: takes a variable off the list.
void Unk_15ceec0(void* list, nn::nex::PseudoGlobalVariableRoot* var);

namespace nn {
namespace nex {

// N2nn3nex24PseudoGlobalVariableRootE: a variable with one instance per
// context, in a list (slots 5 and 6 get and set the next one).
class PseudoGlobalVariableRoot : public RootObject {
public:
    virtual ~PseudoGlobalVariableRoot();
    virtual void vf2() = 0;
    virtual void vf3() = 0;
    virtual void vf4(u32 index) = 0;
    virtual u64 vf5() = 0;
    virtual void vf6(u64 value) = 0;

    u64 field_8;  // the next variable
};
PKMN_SIZE_ASSERT(PseudoGlobalVariableRoot, 0x10);

// N2nn3nex20PseudoGlobalVariableIbEE ...: the instances, the current value and
// the default one. vf2 (which allocates the instances) isn't written.
template <class T>
class PseudoGlobalVariable : public PseudoGlobalVariableRoot {
public:
    ~PseudoGlobalVariable() override {
        Unk_15ceec0(Unk_27f3828, this);
        vf3();
    }
    void vf2() override;
    // Destroys the instances.
    void vf3() override {
        if (m_instances != nullptr) {
            for (u32 i = 0; i < Unk_244fbf0; i++) {
                m_instances[i].~T();
            }
            Unk_15b9390(reinterpret_cast<u64>(m_instances));
            m_instances = nullptr;
        }
    }
    // Resets an instance to the default.
    void vf4(u32 index) override { m_instances[index] = m_default; }
    u64 vf5() override { return field_8; }
    void vf6(u64 value) override { field_8 = value; }
    // Resets the value and every instance to the default.
    virtual void vf7() {
        m_value = m_default;
        if (Unk_244fbf0 != 0 && m_instances != nullptr) {
            for (u32 i = 0; i < Unk_244fbf0; i++) {
                m_instances[i] = m_default;
            }
        }
    }

    T* m_instances;
    T m_value;
    T m_default;
};

}  // namespace nex
}  // namespace nn
