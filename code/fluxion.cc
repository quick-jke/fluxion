#include <iostream>
#include <filesystem>
#include "moc-builder.hpp"

using quick::fluxion::MocBuilder;

int main() {

    MocBuilder moc_builder;
    moc_builder.build("user-state.yaml");
    moc_builder.info();

    return 0;
}