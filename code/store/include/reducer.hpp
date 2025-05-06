#ifndef STORE_REDUCER_H
#define STORE_REDUCER_H

#include <iostream>
#include <map>
#include <any>
#include <tuple>
#include <functional>
#include <utility>
#include <typeinfo>

namespace quick {
namespace fluxion {
namespace store {

template <typename EnumType>
class Reducerjke {
public:
    Reducerjke() = default;

    template <typename... Args>
    Reducerjke& add(EnumType type, std::function<void(Args...)> func) {
        using CleanArgs = std::tuple<std::decay_t<Args>...>;
        reducers_[type] = [func](std::any args) {
            if (args.type() != typeid(CleanArgs)) {
                std::cerr << "Type mismatch! Expected: " 
                          << typeid(CleanArgs).name() << ", got: " 
                          << args.type().name() << std::endl;
                return;
            }
            auto tuple = std::any_cast<CleanArgs>(args);
            std::apply(
                [&](auto&&... unpacked) {
                    std::invoke(func, std::forward<decltype(unpacked)>(unpacked)...);
                },
                tuple
            );
        };
        return *this;
    }

    // Теперь метод build() const
    std::map<EnumType, std::function<void(std::any)>> build() const {
        return reducers_;
    }

private:
    std::map<EnumType, std::function<void(std::any)>> reducers_;
};

} // namespace store
} // namespace fluxion
} // namespace quick

#endif // STORE_REDUCER_H