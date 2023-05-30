#include <gtest/gtest.h>
#include <limits>
#include "functions.h"

class AtsitiktinisSkaiciusTest : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}
};

TEST_F(AtsitiktinisSkaiciusTest, RandomNumberInRange) {
    int min = 1;
    int max = 100;

    int result = AtsitiktinisSkaicius(min, max);

    ASSERT_GE(result, min);
    ASSERT_LE(result, max);
}

TEST_F(AtsitiktinisSkaiciusTest, InvalidRange) {
    int min = 100;
    int max = 1;

    int result = AtsitiktinisSkaicius(min, max);

    ASSERT_EQ(result, std::numeric_limits<int>::min());
}