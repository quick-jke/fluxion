#include "moc-builder.hpp"

using quick::fluxion::MocBuilder;

MocBuilder::MocBuilder(){}


void MocBuilder::build(const std::filesystem::path& path){
    try {
        YAML::Node config = YAML::LoadFile(path);

        if (const YAML::Node& user_node = config["user"]) {
            for (YAML::const_iterator it = user_node.begin(); it != user_node.end(); ++it) {
                std::string key = it->first.as<std::string>();
                YAML::Node value_node = it->second;

                if (value_node.Type() == YAML::NodeType::Scalar) {
                    std::cout << key << ": " << value_node.as<std::string>() << std::endl;
                }
            }
        } else {
            std::cerr << "Section 'user' not found in YAML file.\n";
        }
    } catch (const YAML::Exception& e) {
        std::cerr << "YAML parsing error: " << e.what() << std::endl;
    }
}