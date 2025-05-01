#include <iostream>
#include <filesystem>
#include "moc-builder.hpp"

using quick::fluxion::MocBuilder;

int main() {
    std::cout << (std::filesystem::exists("user-state.yaml") ? "user-state exist" : " user-state not exist") << std::endl;

    MocBuilder moc_builder;
    moc_builder.build("user-state.yaml");
    

    return 0;
}