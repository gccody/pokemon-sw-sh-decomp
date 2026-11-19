#pragma once
#include <list>
#include <nn/nex/qVector.h>

namespace nn {
namespace nex {

// nn::nex::qList<T> (RTTI N2nn3nex5qListINS0_8URLProbeEEE, with the base
// std::__1::list<nn::nex::URLProbe, nn::nex::MemAllocator<nn::nex::URLProbe>>).
template <class T>
class qList : public std::list<T, MemAllocator<T>> {};

}  // namespace nex
}  // namespace nn
