// Scope: common
// Members of vectors of owned objects (unique_ptrs with gflib3's deleter) on
// Unk_2771620's allocator that game code instantiates out of line. Their code
// doesn't depend on the objects' class, only that it has a virtual destructor
// (the deleter calls it, then gives the memory back): each gets a placeholder
// class, named after the function.
#include <types.h>
#include <memory>
#include <vector>

#include "unsorted/Unk_23f4660.h"
#include "unsorted/Unk_2771620.h"

template <class T>
using Unk_2771620_OwnerVector =
    std::vector<std::unique_ptr<T, Unk_23f4660_Deleter>,
                Unk_2771620_Allocator<std::unique_ptr<T, Unk_23f4660_Deleter>>>;

class Unk_c7e480 {
public:
    virtual ~Unk_c7e480();
};
class Unk_c86a50 {
public:
    virtual ~Unk_c86a50();
};
class Unk_cb7910 {
public:
    virtual ~Unk_cb7910();
};
class Unk_ccbe70 {
public:
    virtual ~Unk_ccbe70();
};
class Unk_e931f0 {
public:
    virtual ~Unk_e931f0();
};
class Unk_10fa750 {
public:
    virtual ~Unk_10fa750();
};
class Unk_10fe660 {
public:
    virtual ~Unk_10fe660();
};

// 0x7100c7e480
template void Unk_2771620_OwnerVector<Unk_c7e480>::__push_back_slow_path<
    std::unique_ptr<Unk_c7e480, Unk_23f4660_Deleter>>(
    std::unique_ptr<Unk_c7e480, Unk_23f4660_Deleter>&&);
// 0x7100c86a50
template void Unk_2771620_OwnerVector<Unk_c86a50>::__push_back_slow_path<
    std::unique_ptr<Unk_c86a50, Unk_23f4660_Deleter>>(
    std::unique_ptr<Unk_c86a50, Unk_23f4660_Deleter>&&);
// 0x7100cb7910
template void Unk_2771620_OwnerVector<Unk_cb7910>::reserve(size_t);
// 0x7100ccbe70
template void Unk_2771620_OwnerVector<Unk_ccbe70>::__push_back_slow_path<
    std::unique_ptr<Unk_ccbe70, Unk_23f4660_Deleter>>(
    std::unique_ptr<Unk_ccbe70, Unk_23f4660_Deleter>&&);
// 0x7100e931f0
template void Unk_2771620_OwnerVector<Unk_e931f0>::reserve(size_t);
// 0x71010fa750
template void Unk_2771620_OwnerVector<Unk_10fa750>::reserve(size_t);
// 0x71010fe660
template void Unk_2771620_OwnerVector<Unk_10fe660>::__push_back_slow_path<
    std::unique_ptr<Unk_10fe660, Unk_23f4660_Deleter>>(
    std::unique_ptr<Unk_10fe660, Unk_23f4660_Deleter>&&);
