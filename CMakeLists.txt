cmake_minimum_required(VERSION 3.10)
project(mar)

#Specify version of c++
set(CMAKE_CXX_STANDARD 17)

# If we ommit it, then the test
# will not be able to find header files
include_directories(src)

#Add subdirectories
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib/googletest)