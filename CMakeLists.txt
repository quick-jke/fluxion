cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)

project(qfluxion 
    VERSION 0.0.1
    LANGUAGES CXX
)   

add_subdirectory(code/moc_builder)


file(COPY "${CMAKE_SOURCE_DIR}/user-state.yaml" DESTINATION ${CMAKE_BINARY_DIR})

add_executable(qfluxion code/fluxion.cc)

target_link_libraries(qfluxion PRIVATE MocBuilder)