file(GLOB MOC_BUILDER_SOURCES "src/*.cc")

find_package(yaml-cpp REQUIRED)

add_library(MocBuilder STATIC ${MOC_BUILDER_SOURCES})

target_include_directories(MocBuilder PUBLIC include)

target_link_libraries(MocBuilder PRIVATE yaml-cpp::yaml-cpp)