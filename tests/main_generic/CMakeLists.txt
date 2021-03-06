cmake_minimum_required (VERSION 3.2)
project(rtm_unit_tests CXX)

set(CMAKE_CXX_STANDARD 11)

include_directories("${PROJECT_SOURCE_DIR}/../../includes")
include_directories("${PROJECT_SOURCE_DIR}/../../external/catch2/single_include/catch2")

# Grab all of our test source files
file(GLOB_RECURSE ALL_TEST_SOURCE_FILES LIST_DIRECTORIES false
	${PROJECT_SOURCE_DIR}/../sources/*.h
	${PROJECT_SOURCE_DIR}/../sources/*.cpp)

create_source_groups("${ALL_TEST_SOURCE_FILES}" ${PROJECT_SOURCE_DIR}/..)

# Grab all of our main source files
file(GLOB_RECURSE ALL_MAIN_SOURCE_FILES LIST_DIRECTORIES false
	${PROJECT_SOURCE_DIR}/*.cpp)

create_source_groups("${ALL_MAIN_SOURCE_FILES}" ${PROJECT_SOURCE_DIR})

add_executable(${PROJECT_NAME} ${ALL_TEST_SOURCE_FILES} ${ALL_MAIN_SOURCE_FILES})

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/../../external/catch2/contrib")
include(CTest)
include(ParseAndAddCatchTests)
ParseAndAddCatchTests(${PROJECT_NAME})

setup_default_compiler_flags(${PROJECT_NAME})

# Throw on failure to allow us to catch them and recover
add_definitions(-DRTM_ON_ASSERT_THROW)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
