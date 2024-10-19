cmake_minimum_required(VERSION 3.10)


set(project_name rendermath)
project(${project_name} VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

message(STATUS "Project source dir: ${PROJECT_SOURCE_DIR}")
message(STATUS "Building project: ${PROJECT_NAME} ___ ${project_name}")

if(MSVC)
    add_compile_options(/W4 /WX /Zi)
else()
    add_compile_options(-fdiagnostics-color=always -Wall -Wextra -Werror -std=c++17 -pedantic -g)
endif()

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

# Including directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# message(STATUS "Building Lib: VMA")
# add_subdirectory(${PROJECT_SOURCE_DIR}/third_party/VulkanMemoryAllocator)
# message(STATUS "Building Lib: GLM")
# add_subdirectory(${PROJECT_SOURCE_DIR}/third_party/glm)
# message(STATUS "Building Lib: TinyOBJLoader")
# add_subdirectory(${PROJECT_SOURCE_DIR}/third_party/tinyobjloader)
# message(STATUS "Building Lib: VkBootstrap")
# set_directory_properties(PROPERTIES DIRECTORY ${PROJECT_SOURCE_DIR}/third_party/vk-bootstrap
#                        COMPILE_OPTIONS "-w")
# add_subdirectory(${PROJECT_SOURCE_DIR}/third_party/vk-bootstrap)
# message(STATUS "Building Lib: fastGLTF")
# add_subdirectory(${PROJECT_SOURCE_DIR}/third_party/fastgltf)
#include_directories(${SDL2_INCLUDE_DIRS} ${Vulkan_INCLUDE_DIRS})
#find_package(SDL2 REQUIRED)
#find_package(Vulkan REQUIRED)


file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.hpp" "include/*.h")
add_library(${project_name} STATIC ${SOURCES} ${HEADERS})
target_include_directories(${project_name} PUBLIC include)

add_executable(run_tests test/main.cpp)
target_link_libraries(run_tests PRIVATE ${project_name})

enable_testing()
add_test(TEST1 UnitTests COMMAND run_tests)

