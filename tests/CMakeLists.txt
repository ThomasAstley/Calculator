set(TEST_SOURCES
    test_test.cpp
)

add_executable(MyProjectTests ${TEST_SOURCES})

target_link_libraries(MyProjectTests PRIVATE gtest gtest_main Qt6::Widgets Qt6::Gui Qt6::Core MyProjectLib)

add_test(NAME MyProjectTests COMMAND MyProjectTests)