cmake_minimum_required (VERSION 3.16)
project (VulkanTutorial)
# set(ENV{VULKAN_SDK} C:/VulkanSDK/1.2.198.1)
# set(ENV{VULKAN_SDK} "C:/VulkanSDK/1.3.280.0")
set(CMAKE_CXX_STANDARD 17)
find_package(Vulkan REQUIRED)

# set(CMAKE_CXX_STANDARD 17)
add_subdirectory(libs)
include_directories(
	libs/glfw-3.4/include/
	libs/glm/
	C:/VulkanSDK/1.3.280.0/Include
)
# target_include_directories(target PUBLIC )
add_executable(VulkanTutorial src/main.cpp)
target_link_libraries(VulkanTutorial ${Vulkan_LIBRARIES} glfw)