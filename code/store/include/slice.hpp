#ifndef STORE_SLICE_H
#define STORE_SLICE_H

#include "reducer.hpp"
#include "state.hpp"
#include <string>

namespace quick {
namespace fluxion {
namespace store {

template <typename EnumType>
class Slicejke {
public:
    Slicejke(quick::fluxion::interface::statejke& state, Reducerjke<EnumType>& reducer)
        : state_(state), reducer_(reducer) {}

    // Добавлен метод для безопасного получения редюсера
    const Reducerjke<EnumType>& getReducer() const {
        return reducer_;
    }

private:
    quick::fluxion::interface::statejke& state_;
    Reducerjke<EnumType> reducer_;
};

} // namespace store
} // namespace fluxion
} // namespace quick

#endif // STORE_SLICE_H