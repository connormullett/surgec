# src
include_directories(${surge_SOURCE_DIR}/include)

add_library(ErrorLib SHARED ${surge_SOURCE_DIR}/src/error/error.cpp)

add_library(LexerLib SHARED ${surge_SOURCE_DIR}/src/lexer/lexer.cpp
    ${surge_SOURCE_DIR}/src/lexer/tokens.cpp)

set(LIBRARY_OUTPUT_PATH ${surge_SOURCE_DIR}/build/lib)
set(EXECUTABLE_OUTPUT_PATH ${surge_SOURCE_DIR}/build/bin)

add_executable(surge main.cpp)
target_link_libraries(surge
    ErrorLib
    LexerLib)

install(TARGETS surge
    DESTINATION bin)

install(DIRECTORY ${surge_SOURCE_DIR}/include
    DESTINATION include)

install(TARGETS ErrorLib
    DESTINATION lib)

install(TARGETS LexerLib
    DESTINATION lib)