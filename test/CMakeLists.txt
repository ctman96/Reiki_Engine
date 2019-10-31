include(${PROJECT_SOURCE_DIR}/cmake/Modules/googletest.cmake)

fetch_googletest(
        ${PROJECT_SOURCE_DIR}/cmake/Modules
        ${PROJECT_BINARY_DIR}/googletest
)

enable_testing()

set(SOURCE_FILES
        main.cpp
        exampleTest.cpp
        math/vec2Test.cpp
        math/vec3Test.cpp
        math/vec4Test.cpp
)

add_executable(
        unit_tests
        ${SOURCE_FILES}
)

# Include src
target_include_directories(unit_tests PRIVATE ${PROJECT_SOURCE_DIR}/src)

target_link_libraries(
        unit_tests
        gtest_main
        REIKI_CORE
)

add_test(
        NAME
        unit
        COMMAND
        ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests
)