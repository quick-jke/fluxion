#ifndef DISPATCHER_HPP
#define DISPATCHER_HPP

#include <tuple>
#include <any>
#include "store.hpp"

namespace quick {
namespace fluxion {
namespace store {

template <typename EnumType>
class Dispatchjke {
public:
    static Dispatchjke& get() {
        static Dispatchjke instance;
        return instance;
    }

    template <typename... Args>
    void dispatch(EnumType actionType, Args&&... args) {
        auto payload = std::make_any<std::tuple<std::decay_t<Args>...>>(std::forward<Args>(args)...);
        Storejke<EnumType>::getInstance().dispatch(actionType, payload);
    }

private:
    Dispatchjke() = default;

    Dispatchjke(const Dispatchjke&) = delete;
    Dispatchjke& operator=(const Dispatchjke&) = delete;
};

} // namespace store
} // namespace fluxion
} // namespace quick

#endif // DISPATCHER_HPP