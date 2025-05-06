#ifndef STORE_HPP
#define STORE_HPP

#include <map>
#include <string>
#include <initializer_list>
#include <utility>
#include <any>
#include "slice.hpp"

namespace quick {
namespace fluxion {
namespace store {

template <typename EnumType>
class Storejke {
public:
    static Storejke& getInstance() {
        static Storejke instance;
        return instance;
    }

    void initialize(std::initializer_list<std::pair<const std::string, Slicejke<EnumType>>> list) {
        for (const auto& [key, slice] : list) {
            reducers_.insert({key, slice.getReducer().build()});
        }
    }

    void dispatch(EnumType actionType, std::any payload) {
        for (const auto& [sliceName, reducerMap] : reducers_) {
            auto it = reducerMap.find(actionType);
            if (it != reducerMap.end()) {
                it->second(payload);
            }
        }
    }

private:
    explicit Storejke() = default;

    Storejke(const Storejke&) = delete;
    Storejke& operator=(const Storejke&) = delete;

    std::map<std::string, std::map<EnumType, std::function<void(std::any)>>> reducers_;
};

} // namespace store
} // namespace fluxion
} // namespace quick

#endif // STORE_HPP