cmake_minimum_required(VERSION 3.16)
project(SkipLists VERSION 1.0.0 LANGUAGES C CXX)

# executable name
set(EXECUTABLE_NAME skiplist)

# enable virtual folders for projects if supported by the build system/IDE
set_property(GLOBAL PROPERTY USE_FOLDERS ON) 

# set output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/static)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# configure C11
set(CMAKE_C_STANDARD 11)          # request C11
set(CMAKE_C_STANDARD_REQUIRED ON) # enforce requested standard
set(CMAKE_C_EXTENSIONS OFF)       # disable compiler specific extensions

# configure C++20
set(CMAKE_CXX_STANDARD 20)          # request C++20
set(CMAKE_CXX_STANDARD_REQUIRED ON) # enforce requested standard
set(CMAKE_CXX_EXTENSIONS OFF)       # disable compiler specific extensions

# executable
add_executable(${EXECUTABLE_NAME} 
 skiplist/main.cpp
        skiplist/Skipset.h
        # add your files
)

# compilersettings
if(MSVC)
    target_compile_options(${EXECUTABLE_NAME} PRIVATE /W4 /permissive- /JMC /MP)
else(MSVC)
    target_compile_options(${EXECUTABLE_NAME} PRIVATE -Wall -Wextra -Wpedantic -Wconversion -Werror=vla)
endif(MSVC)
