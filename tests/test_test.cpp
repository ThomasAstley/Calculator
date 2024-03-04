#include "../src/mainwindow.h"
#include "../lib/googletest/googletest/include/gtest/gtest.h"

TEST(BasicOperators, Add) {
    QString display_expression = "1+2";
    QString previous_answer = "0";
    QString expected_answer = "3";
    ASSERT_EQ(shuntingYard(display_expression, previous_answer), expected_answer);
    ASSERT_EQ(shuntingYard("1+1", previous_answer), "2");
}

int main(int argc, char **argv) {
    // Initialize Google Test framework
    ::testing::InitGoogleTest(&argc, argv);

    // Run all tests
    return RUN_ALL_TESTS();
}