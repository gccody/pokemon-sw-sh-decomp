// Scope: common
// NEX 4.6.8's SharedPtr destructors (RTTI: N2nn3nex9SharedPtrINS0_6TicketEEE ...),
// one instantiation per pointee the executable has, and the counters of the
// objects deleted through their virtual destructors.
#include <nn/nex/SharedPtr.h>
#include <nn/nex/qVector.h>

namespace nn {
namespace nex {

class AuthenticationClient : public RootObject {
public:
    ~AuthenticationClient() override;
};
class ConnectionOrientedSocketManager;
class Ticket : public RootObject {
public:
    ~Ticket() override;
};
class SocketDriver {
public:
    class Socket;
    class PollInfo;
};
template <class T>
class qReservedQueue;

template class SharedPtr<qReservedQueue<u8>>;
template class SharedPtr<SocketDriver::Socket>;
template class SharedPtr<ConnectionOrientedSocketManager>;
template class SharedPtr<qReservedQueue<SharedPtr<SocketDriver::Socket>>>;
template class SharedPtr<qVector<SocketDriver::PollInfo>>;
template class SharedPtr<qVector<SharedPtr<SocketDriver::Socket>>>;
template class SharedPtr<Ticket>;
template class SharedPtr<AuthenticationClient>;

template class SharedCounter<Ticket, Ticket, SharedPtrDefaultDeleter<Ticket>>;
template class SharedCounter<AuthenticationClient, AuthenticationClient, SharedPtrDefaultDeleter<AuthenticationClient>>;

}  // namespace nex
}  // namespace nn
