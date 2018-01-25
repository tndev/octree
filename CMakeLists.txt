cmake_minimum_required (VERSION 3.0.0)
set (project_name octree)
project (${project_name})

find_package(glm REQUIRED)


SET(SOURCES main.cpp)


include_directories(${project_name} "include")

add_executable(
    ${project_name}
    #${HEADERS}
    ${SOURCES}
)

