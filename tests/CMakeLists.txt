include_directories(../include)
include_directories(/usr/include/eigen3)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# add the executable
add_executable(test_basic_obj test_basic_obj.cpp)
target_link_libraries(test_basic_obj SpacePath)

add_executable(test_unit test_unit.cpp)
target_link_libraries(test_unit SpacePath ${GTEST_LIBRARIES} pthread)
