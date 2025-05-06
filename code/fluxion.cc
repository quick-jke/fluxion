#include <iostream>
#include <filesystem>

#include "reducer.hpp"
#include "slice.hpp"
#include "state.hpp"
#include "store.hpp"
#include "dispatch.hpp"

enum class ActionType {
    ADD,
    PRINT
};

using Reducer = quick::fluxion::store::Reducerjke<ActionType>;
using Slice = quick::fluxion::store::Slicejke<ActionType>;
using state = quick::fluxion::interface::statejke;
using Store = quick::fluxion::store::Storejke<ActionType>;
using Dispatch = quick::fluxion::store::Dispatchjke<ActionType>;



struct initialState : public state{
    bool is_auth_ = false;
    int age_ = 2;
    char class_ = 'c';
};

int main() {
    initialState state;
    
    auto reducers = Reducer().
        add(
            ActionType::ADD, 
            std::function<void(int, int)>(
                [&state](int a, int b) {
                    state.age_ = a+b;
                    std::cout << "Add result: " << state.age_ << std::endl;
                }
            )
        ).add(
            ActionType::PRINT, 
            std::function<void(const std::string&)>(
                [&state](const std::string& msg) {
                    state.is_auth_ = true;
                    std::cout << "Message: " << msg << std::endl;
                }
            )
        );
    
    auto userSlice = Slice(state, reducers);

    

    Store::getInstance().initialize({{"user", userSlice}});

    Dispatch::get().dispatch(ActionType::ADD, 5, 7);
    Dispatch::get().dispatch(ActionType::PRINT, std::string("Hello, world!"));
    

    return 0;
}