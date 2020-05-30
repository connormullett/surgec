# src
include_directories(${surge_SOURCE_DIR}/include)

add_library(ErrorLib ${surge_SOURCE_DIR}/src/error/error.cpp)

add_library(LexerLib ${surge_SOURCE_DIR}/src/lexer/lexer.cpp
    ${surge_SOURCE_DIR}/src/lexer/tokens.cpp)

set(LIBRARY_OUTPUT_PATH ${surge_SOURCE_DIR}/build/lib)
set(EXECUTABLE_OUTPUT_PATH ${surge_SOURCE_DIR}/build/bin)

add_executable(surge main.cpp)
target_link_libraries(surge
    ErrorLib
    LexerLib)