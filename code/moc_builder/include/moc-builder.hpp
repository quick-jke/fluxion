#ifndef MOC_BUILDER_H
#define MOC_BUILDER_H

#include <iostream>
#include <filesystem>
#include <map>
#include <string>
#include <yaml-cpp/yaml.h>

namespace quick{
namespace fluxion{


class MocBuilder{
public:
    MocBuilder();
    void build(const std::filesystem::path& path);

private:
    
};

};};

#endif