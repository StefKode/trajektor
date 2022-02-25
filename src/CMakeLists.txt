include_directories(../include)
include_directories(/usr/include/eigen3)

set(SOURCE_FILES "") 
set(SOURCE_FILES ${SOURCE_FILES} Body.cpp)
set(SOURCE_FILES ${SOURCE_FILES} Force.cpp)
set(SOURCE_FILES ${SOURCE_FILES} Movement.cpp)
set(SOURCE_FILES ${SOURCE_FILES} Position.cpp)
set(SOURCE_FILES ${SOURCE_FILES} SpaceObject.cpp)
set(SOURCE_FILES ${SOURCE_FILES} SpaceSystem.cpp)

# add the executable
add_library(SpacePath ${SOURCE_FILES})

