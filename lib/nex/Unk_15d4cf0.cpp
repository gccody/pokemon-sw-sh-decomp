// Scope: common
// NEX 4.6.8: the scheduler's worker thread's slot 4, SecurityContext's
// destructors (RTTI N2nn3nex15SecurityContextE), slots of
// MethodCallJob<CallContextRegister, int, PeriodicJob> (RTTI
// N2nn3nex13MethodCallJobINS0_19CallContextRegisterEiNS0_11PeriodicJobEEE,
// declared by lib/nx_middleware/class: written here as free functions over its
// layout), and the destroy function of a tree.
#include <nn/nex/qVector.h>

#include "Unk_15d48b0.h"

// 0x71015d0da0
void Unk_15d0da0(void* self, u32 arg1, u32 arg2);

namespace nn {
namespace nex {

// 0x71015d4cf0
void Scheduler::SchedulerWorkerThread::vf4() {
    Unk_15d0da0(m_scheduler, field_14c, field_148);
    m_pacer.vf2();
}

}  // namespace nex
}  // namespace nn

// The node of a std::map-style tree of trivially destroyed values (libc++'s
// __tree_node); the tree isn't known.
struct Unk_15d4d20_Node {
    Unk_15d4d20_Node* m_left;
    Unk_15d4d20_Node* m_right;
};

// 0x71015d4d20: frees a subtree with NEX's allocator.
void Unk_15d4d20(void* tree, Unk_15d4d20_Node* node) {
    if (node != nullptr) {
        Unk_15d4d20(tree, node->m_left);
        Unk_15d4d20(tree, node->m_right);
        Unk_15b9390(reinterpret_cast<u64>(node));
    }
}

namespace nn {
namespace nex {

// N2nn3nex15SecurityContextE
class SecurityContext : public RootObject {
public:
    ~SecurityContext() override;
};

// 0x71015d4d60 (D0; its D2 is a `ret` shared with other classes)
SecurityContext::~SecurityContext() {}

class CallContextRegister;

}  // namespace nex
}  // namespace nn

// MethodCallJob<CallContextRegister, int, PeriodicJob>: a job that calls a
// member function of an object with an int.
struct Unk_15d4f00 {
    u8 _0[0x68];
    void (nn::nex::CallContextRegister::*m_method)(int);
    nn::nex::CallContextRegister* m_object;
    int m_arg;
};
PKMN_OFFSET_ASSERT(Unk_15d4f00, m_method, 0x68);
PKMN_OFFSET_ASSERT(Unk_15d4f00, m_object, 0x78);
PKMN_OFFSET_ASSERT(Unk_15d4f00, m_arg, 0x80);

// 0x71015d4f00: its slot 3, the call.
void Unk_15d4f00(Unk_15d4f00* self) {
    (self->m_object->*self->m_method)(self->m_arg);
}
