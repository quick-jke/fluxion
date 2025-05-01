file (GLOB INTERFACES_SOURCES "src/*.cc")

add_library(Intefaces STATIC ${INTERFACES_SOURCES})

target_include_directories(Intefaces PUBLIC include)


