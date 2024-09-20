cmake_minimum_required(
    VERSION
    3.5.0
)

project(
    tictactoe
    VERSION
    0.1
)

add_executable(
    ${PROJECT_NAME}
    main.c
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

# $ `sudo make install`
install(
    TARGETS
    ${PROJECT_NAME}
    DESTINATION
    bin
)

include(
    CPack
)

set(
    CPACK_RESOURCE_FILE_LICENSE
    "${CMAKE_CURRENT_SOURCE_DIR}/UNLICENSE"
)
set(
    CPACK_PACKAGE_VERSION_MAJOR
    "${PROJECT_VERSION_MAJOR}"
)
set(
    CPACK_PACKAGE_VERSION_MINOR
    "${PROJECT_VERSION_MINOR}"
)
set(
    CPACK_PACKAGE_DESCRIPTION_SUMMARY
    "This is a terminal app."
)
set(
    CPACK_PACKAGE_VENDOR
    "Christmas_Missionary"
)
set(
    CPACK_PACKAGE_DESCRIPTION_FILE
    "${CMAKE_CURRENT_SOURCE_DIR}/README.md"
)
