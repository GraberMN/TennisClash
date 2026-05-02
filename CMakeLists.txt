# CMakeList.txt : CMake project for TennisClash, include source and define
# project specific logic here.
#
find_package(SFML 2.5.1 REQUIRED COMPONENTS graphics audio)

# Add source to this project's executable.
add_executable (TennisClash "TennisClash.cpp" "TennisClash.h" "TextureManager.cpp" "TextureManager.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET TennisClash PROPERTY CXX_STANDARD 20)
endif()
set_property(TARGET TennisClash PROPERTY DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

# TODO: Add tests and install targets if needed.
target_link_libraries(TennisClash PRIVATE sfml-graphics sfml-audio)
target_include_directories(TennisClash PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/images)