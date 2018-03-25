cmake_minimum_required(VERSION 3.12.2)

set(CMAKE_CXX_FLAGS "-std=c++1z -Werror -Wall -DDEBUG")
set(ANTLR_BINARY_LIB /usr/local/lib)
set(ANTLR_INCLUDE_LIB /usr/local/include/antlr4)
set(ANTLR4 java -jar /usr/local/lib/antlr-4.7.1-complete.jar -Dlanguage=Cpp)

project(Calculation)

# specify include and link path
link_directories(${ANTLR_BINARY_LIB})
include_directories(
  ${ANTLR_INCLUDE_LIB}
  ${ANTLR_INCLUDE_LIB}/misc
  ${ANTLR_INCLUDE_LIB}/atn
  ${ANTLR_INCLUDE_LIB}/dfa
  ${ANTLR_INCLUDE_LIB}/tree
  ${ANTLR_INCLUDE_LIB}/support
  ${ANTLR_INCLUDE_LIB}/antlr4-runtime
)

#mark these files as GENERATED to bypass the file existence checking
set(CALCULATION_GENERATED_SRC
  ${PROJECT_SOURCE_DIR}/antlr4-runtime/calculationLexer.cpp
  ${PROJECT_SOURCE_DIR}/antlr4-runtime/calculationParser.cpp
)

foreach(src_file ${CALCULATION_GENERATED_SRC})
set_source_files_properties(${src_file}
  PROPERTIES 
  GENERATED TRUE
)
endforeach()

#download and build the antlr4 cpp runtime lib
include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)

ExternalProject_Add(Antlr4-cpp
  GIT_REPOSITORY https://github.com/antlr/antlr4.git
  SOURCE_DIR antlr4-cpp
  SOURCE_SUBDIR runtime/Cpp 
)

add_executable(calc main.cpp ${CALCULATION_GENERATED_SRC})

if(APPLE)
target_link_libraries(calc ${ANTLR_BINARY_LIB}/libantlr4-runtime.dylib)
elseif(UNIX)
target_link_libraries(calc ${ANTLR_BINARY_LIB}/libantlr4-runtime.so)
endif()

#generate antlr4 files
if(NOT EXISTS ${PROJECT_SOURCE_DIR}/antlr4-runtime)
message("--------------------------")
add_custom_target(antlr4-runtime ALL 
  COMMAND ${ANTLR4} -Dlanguage=Cpp -o ${PROJECT_SOURCE_DIR}/antlr4-runtime ${PROJECT_SOURCE_DIR}/Calculation.g4
  VERBATIM
)
endif()

install(TARGETS calc DESTINATION debug)

