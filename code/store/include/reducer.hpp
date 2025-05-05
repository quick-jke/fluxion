#ifndef STORE_REDUCER_H
#define STORE_REDUCER_H

#include <iostream>
#include <map>
#include <any>
#include <tuple>
#include <functional>
#include <utility>


namespace quick{
namespace fluxion{
namespace store{



template <typename EnumType>
class Reducer{
public:
    Reducer() = default;
    template <typename... Args>
    Reducer& add(EnumType type, std::function<void(Args...)> func) {
        reducers_[type] = [func](std::any args) {
            auto tuple = std::any_cast<std::tuple<Args...>>(args);
            std::apply(func, tuple);
        };
        return *this;
    }

    std::map<EnumType, std::function<void(std::any)>> build() {
        return reducers_;
    }

    


private:
    std::map<EnumType, std::function<void(std::any)>> reducers_;

}; 

};};};


#endif