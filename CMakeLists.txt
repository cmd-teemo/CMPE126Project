cmake_minimum_required(VERSION 3.10)

project(SFMLProject VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find the SFML package
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Add the executable
add_executable(SFMLProject main.cpp
        tree.h)

# Link SFML libraries
target_link_libraries(SFMLProject sfml-graphics sfml-window sfml-system)

# Set the output directory for the built executable
set_target_properties(SFMLProject PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# Optional: Add compiler flags if needed
if(APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -stdlib=libc++")
endif()