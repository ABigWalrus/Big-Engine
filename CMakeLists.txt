include(./.env.cmake OPTIONAL RESULT_VARIABLE LOCAL_ENV)
message(STATUS "Local .env.cmake: ${LOCAL_ENV}")

cmake_minimum_required (VERSION 3.16)
project (VulkanTutorial)
set(CMAKE_CXX_STANDARD 17)
find_package(Vulkan REQUIRED)

# set(GLFW_PATH ${PROJECT_SOURCE_DIR}/external/glfw-3.4.bin.WIN64)
set(GLFW_LIB "${GLFW_PATH}/lib-mingw-w64/libglfw3.a")
set(GLFW_INCLUDE_DIRS "${GLFW_PATH}/include")

set(VULKAN_INCLUDE_DIRS "${VULKAN_SDK_PATH}/Include")

set(PROJECT_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/src")


file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable(
	${PROJECT_NAME}
	${SOURCES}
)

add_subdirectory("external")

target_include_directories(${PROJECT_NAME} PUBLIC
	${PROJECT_INCLUDE_DIRS}
	${GLFW_INCLUDE_DIRS}
	${VULKAN_INCLUDE_DIRS}
)
# target_link_directories(${PROJECT_NAME} PUBLIC
# ${Vulkan_LIBRARIES}
# ${GLFW_LIB}
# )
target_link_libraries(${PROJECT_NAME} ${GLFW_LIB} ${Vulkan_LIBRARIES})
# target_link_libraries(VulkanTutorial ${Vulkan_LIBRARIES} glfw)