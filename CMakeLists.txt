include(./.env.cmake OPTIONAL RESULT_VARIABLE LOCAL_ENV)
message(STATUS "Local .env.cmake: ${LOCAL_ENV}")
message(STATUS "blavlab")



cmake_minimum_required (VERSION 3.16)
project (VulkanTutorial)
# set(ENV{VULKAN_SDK} C:/VulkanSDK/1.2.198.1)
# set(ENV{VULKAN_SDK} "C:/VulkanSDK/1.3.280.0")
set(CMAKE_CXX_STANDARD 17)
find_package(Vulkan REQUIRED)

set(GLFW_PATH ${PROJECT_SOURCE_DIR}/external/glfw-3.4.bin.WIN64)
set(GLFW_LIB "${GLFW_PATH}/lib-mingw-w64")
set(GLFW_INCLUDE_DIRS "${GLFW_PATH}/include")
message(STATUS "nana")

# set(CMAKE_CXX_STANDARD 17)
add_subdirectory("external")
include_directories(
	"src/app.hpp"
	"src/render.hpp"
	"src/window.hpp"
	"external/glm/"
	"C:/VulkanSDK/1.3.280.0/Include"
	"external/stb-master"
	"external/tinyobjloader-release"
)

# external/glfw-3.4.bin.WIN64
# target_include_directories(target PUBLIC )
add_executable(
	VulkanTutorial
	src/main.cpp
	src/render.cpp
	src/app.cpp
	src/window.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
${GLFW_INCLUDE_DIRS}
)
# target_link_directories(${PROJECT_NAME} PUBLIC
# ${Vulkan_LIBRARIES}
# ${GLFW_LIB}
# )
target_link_libraries(${PROJECT_NAME} ${GLFW_LIB}/libglfw3.a ${Vulkan_LIBRARIES})
# target_link_libraries(VulkanTutorial ${Vulkan_LIBRARIES} glfw)