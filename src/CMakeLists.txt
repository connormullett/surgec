# src
include_directories(${surge_SOURCE_DIR}/include)

# libraries
add_library(ErrorLib SHARED ${surge_SOURCE_DIR}/src/error/error.cpp)
add_library(LexerLib SHARED ${surge_SOURCE_DIR}/src/lexer/lexer.cpp
    ${surge_SOURCE_DIR}/src/lexer/tokens.cpp)
add_library(ParserLib SHARED ${surge_SOURCE_DIR}/src/parser/parser.cpp
    ${surge_SOURCE_DIR}/src/parser/nodes.cpp)

# variables
set(LIBRARY_OUTPUT_PATH ${surge_SOURCE_DIR}/build/lib)
set(EXECUTABLE_OUTPUT_PATH ${surge_SOURCE_DIR}/build/bin)

# main executable
add_executable(surge main.cpp)
target_link_libraries(surge
    ErrorLib
    LexerLib
    ParserLib)


# install executable
install(TARGETS surge
    DESTINATION bin)

# install libs
install(DIRECTORY ${surge_SOURCE_DIR}/include/lexer
    ${surge_SOURCE_DIR}/include/error
    ${surge_SOURCE_DIR}/include/parser
    DESTINATION include)

install(TARGETS ErrorLib
    DESTINATION lib)

install(TARGETS LexerLib
    DESTINATION lib)

install(TARGETS ParserLib
    DESTINATION lib)
