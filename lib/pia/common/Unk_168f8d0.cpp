// Scope: common
// local::LocalMatchDestroySessionJob's destructors. lib/pia/common/Unk_168f910.h
// declares the class without one, so this TU declares only what they need: the
// class and its base (session::DestroySessionJob, placeholder Unk_245f368 after
// its vtable).
#include <types.h>

class Unk_245f368 {
public:
    Unk_245f368();
    virtual ~Unk_245f368();
};

namespace nn {
namespace pia {
namespace local {

class LocalMatchDestroySessionJob : public Unk_245f368 {
public:
    ~LocalMatchDestroySessionJob() override;
};

// 0x710168f8d0 (and 0x710168f8e0, deleting)
LocalMatchDestroySessionJob::~LocalMatchDestroySessionJob() {}

}  // namespace local
}  // namespace pia
}  // namespace nn
