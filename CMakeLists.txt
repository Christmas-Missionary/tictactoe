cmake_minimum_required(
    VERSION
    3.5.0
)

project(
    tictactoe
    VERSION
    1.0
)

add_subdirectory(
    src
)

set(
    CMAKE_C_STANDARD
    11
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    ${PROJECT_BINARY_DIR}
)
