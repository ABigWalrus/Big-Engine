cmake_minimum_required (VERSION 3.16)
project (VulkanTutorial)
# set(ENV{VULKAN_SDK} C:/VulkanSDK/1.2.198.1)
# set(ENV{VULKAN_SDK} "C:/VulkanSDK/1.3.280.0")
set(CMAKE_CXX_STANDARD 17)
find_package(Vulkan REQUIRED)

# set(CMAKE_CXX_STANDARD 17)
add_subdirectory("external")
include_directories(
	"src/app.hpp"
	"src/render.hpp"
	"external/glfw-3.4/include/"
	"external/glm/"
	"C:/VulkanSDK/1.3.280.0/Include"
	"external/stb-master"
	"external/tinyobjloader-release"
)
# target_include_directories(target PUBLIC )
add_executable(
	VulkanTutorial
	src/main.cpp
	src/render.cpp
	src/app.cpp
)
target_link_libraries(VulkanTutorial ${Vulkan_LIBRARIES} glfw)