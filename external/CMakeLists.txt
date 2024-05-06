add_subdirectory (glfw-3.4)
include_directories(
	# libs/glfw-3.4/include/
	# libs/glm/
)

# Search for the header
# FIND_PATH(GLFW3_INCLUDE_DIR "GLFW/glfw3.h"
# "${CMAKE_CURRENT_SOURCE_DIR}/libs/glfw-3.4.bin.WIN64/include" )

# # Search for the library
# FIND_LIBRARY(GLFW3_LIBRARY NAMES glfw3 glfw
# "${CMAKE_CURRENT_SOURCE_DIR}/libs/glfw-3.4.bin.WIN64/lib-msvc110/lib"
# )

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GLFW3 DEFAULT_MSG
GLFW3_LIBRARY GLFW3_INCLUDE_DIR)