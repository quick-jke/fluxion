#ifndef MOC_BUILDER_H
#define MOC_BUILDER_H

#include <iostream>
#include <filesystem>
#include <map>
#include <string>
#include <set>
#include <yaml-cpp/yaml.h>
#include <vector>



namespace quick{
namespace fluxion{




class MocBuilder{
public:
    MocBuilder();
    void build(const std::filesystem::path& path);

    void info();


private:
    void createType(const std::string& key, const std::string& value);
    std::string moc_name_;
    std::vector<std::string> private_fields_;
    std::vector<std::string> setters_getters_;
};

};};

#endif