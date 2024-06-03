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

find_program(GLSL_VALIDATOR glslangValidator HINTS 
	${Vulkan_GLSLANG_VALIDATOR_EXECUTABLE} 
	/usr/bin 
	/usr/local/bin 
	${VULKAN_SDK_PATH}/Bin
	${VULKAN_SDK_PATH}/Bin32
	$ENV{VULKAN_SDK}/Bin/ 
	$ENV{VULKAN_SDK}/Bin32/
)

set(SHADERS_SOURCE_DIR "${PROJECT_SOURCE_DIR}/assets/shaders")

file(GLOB_RECURSE VERTEX_SHADERS
	"${SHADERS_SOURCE_DIR}/*.vert"
)

file(GLOB_RECURSE FRAGMENT_SHADERS
	"${SHADERS_SOURCE_DIR}/*.frag"
)

# add_custom_target(
#     COMPILED_SHADERS
#     DEPENDS ${SPIRV_BINARY_FILES}
# )



# foreach(VERTEX_SHADER ${VERTEX_SHADERS})
# 	# get_filename_component(FILE_NAME ${SHADER} NAME)
# 	# message(STATUS ${FILE_NAME})
# 	message(STATUS ${GLSL_VALIDATOR})
# 	set(SPIRV01 "${SHADERS_SOURCE_DIR}/vert.spv")
# 	add_custom_command(
# 		OUTPUT ${SPIRV01}
# 		COMMAND ${GLSL_VALIDATOR} -V ${SHADER} -o ${SPIRV01}
# 		# WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
# 		# DEPENDS ${VERTEX_SHADER}
# 		DEPENDS
# 	)
# 	list(APPEND SPIRV_BINARY_FILES ${SPIRV01})
# endforeach(VERTEX_SHADER)

foreach(SHADER ${FRAGMENT_SHADERS})
	# get_filename_component(FILE_NAME ${SHADER} NAME)
	message(STATUS ${SHADER})
	set(SPIRV "${SHADERS_SOURCE_DIR}/frag.spv")
	message(STATUS ${SPIRV})
	add_custom_command(
		OUTPUT ${SPIRV}
		COMMAND ${GLSL_VALIDATOR} -V ${SHADER} -o ${SPIRV}
		DEPENDS ${SHADER}
	)
	list(APPEND SPIRV_BINARY_FILES ${SPIRV})
endforeach(SHADER)

foreach(SHADER ${FRAGMENT_SHADERS})
	# get_filename_component(FILE_NAME ${SHADER} NAME)
	message(STATUS ${SHADER})
	set(SPIRV "${SHADERS_SOURCE_DIR}/frag.spv")
	message(STATUS ${SPIRV})
	add_custom_command(
		OUTPUT ${SPIRV}
		COMMAND ${GLSL_VALIDATOR} -V ${SHADER} -o ${SPIRV}
		DEPENDS ${SHADER}
	)
	list(APPEND SPIRV_BINARY_FILES ${SPIRV})
endforeach(SHADER)

add_custom_target(
    default ALL
    DEPENDS ${SPIRV_BINARY_FILES}
)
# add_custom_target(T1 DEPENDS t1.txt)


# set(PUK01 "t1.txt")
# set(FRAGMENT_SHADER "../assets/shaders/shader.frag")
# add_custom_command(
#     OUTPUT ${PUK01}
#     COMMAND echo "Created at `new date`" > ${PUK01}
#     COMMENT "Creating file.."
# 	DEPENDS ${FRAGMENT_SHADER}
#     )
# list(APPEND SPIRV_BINARY_FILES ${PUK01})

# message(STATUS ${SPIRV_BINARY_FILES})
# add_custom_target(default ALL DEPENDS ${SPIRV_BINARY_FILES})
