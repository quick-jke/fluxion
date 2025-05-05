#include <iostream>
#include <filesystem>

#include "reducer.hpp"
#include "slice.hpp"
#include "state.hpp"

using quick::fluxion::store::Reducer;
using quick::fluxion::store::Slice;
using quick::fluxion::interface::statejke;

enum class ActionType {
    ADD,
    PRINT
};

struct initialState : public statejke{
    bool is_auth_ = false;
    int age_ = 2;
    char class_ = 'c';
};

int main() {
    initialState state;
    
    auto reducers = Reducer<ActionType>().
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
                    std::cout << "Message: " << msg << state.is_auth_ << std::endl;
                }
            )
        );
    
    auto userSlice = Slice<ActionType>(state, reducers);

    return 0;
}