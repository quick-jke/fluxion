#include "moc-builder.hpp"

using quick::fluxion::MocBuilder;

MocBuilder::MocBuilder(){std::cout << "moc created";}

std::set<std::string> permitted_types = {"char", "signed char", "unsigned char",
    "short", "unsigned short","int","unsigned int","long","unsigned long","long long",
    "unsigned long long","float","double","long double","string", "std::string","bool"};


void MocBuilder::createType(const std::string& key, const std::string& value){
    // std::cout << "createType" << std::endl;
    if(permitted_types.count(value)){ 
        private_fields_.push_back(value + std::string(" ") + key + std::string("_;"));

        std::string result;
        result.reserve(key.size());
        result += static_cast<char>(
            std::toupper(static_cast<unsigned char>(key[0]))
        );
        result += key.substr(1);

        setters_getters_.push_back(value + std::string(" get") + result + std::string("();"));
        setters_getters_.push_back(std::string("void set") + result + std::string("(") + std::string(value) + std::string(" ") + key + std::string(");"));

        

        // std::cout << value + std::string(" get") + result + std::string("();") << std::endl;
        // std::cout << std::string("void set") + result + std::string("(") + std::string(value) + std::string(" ") + key + std::string(");") << std::endl;
    }
}

void MocBuilder::build(const std::filesystem::path& path){
    try {
        YAML::Node config = YAML::LoadFile(path.string());

        if (config && config.IsMap()) {
            for (auto section_it = config.begin(); section_it != config.end(); ++section_it) {
                moc_name_ = section_it->first.as<std::string>();
                std::cout << moc_name_ << std::endl;
                const YAML::Node& section_content = section_it->second;

                if (section_content && section_content.IsMap()) {
                    for (auto field_it = section_content.begin(); field_it != section_content.end(); ++field_it) {
                        std::string key = field_it->first.as<std::string>();
                        YAML::Node value_node = field_it->second;

                        if (value_node && value_node.IsScalar()) {
                            std::string value = value_node.as<std::string>();
                            std::string result;
                            result.reserve(key.size());
                            result += static_cast<char>(
                                std::toupper(static_cast<unsigned char>(key[0]))
                            );
                            result += key.substr(1);
                            setters_getters_.push_back(value + std::string(" get") + result + std::string("();"));
                            setters_getters_.push_back(std::string("void set") + result + std::string("(") + std::string(value) + std::string(" ") + key + std::string(");"));
                            createType(key, value);
                        }
                    }
                }
            }

            std::cout << setters_getters_.size() << std::endl;
        } else {
            std::cerr << "Invalid YAML structure: expected a map at the root level." << std::endl;
        }
    } catch (const YAML::Exception& e) {
        std::cerr << "YAML parsing error: " << e.what() << std::endl;
    }
    std::cerr << "[DEBUG] After build:\n";
    for (const auto& el : setters_getters_) {
        std::cerr << "  " << el << "\n";
    }

}


void MocBuilder::info(){
    std::cout << "name: " << moc_name_  << std::endl << "elements:" << std::endl;
    for(auto el : setters_getters_){
        std::cout << el << std::endl;
    }

    for(auto el : private_fields_){
        std::cout << el << std::endl;
    }
}


