file(GLOB STORE_SOURCES "src/*.cc")

add_library(Store STATIC ${STORE_SOURCES})

target_include_directories(Store PUBLIC include interfaces)