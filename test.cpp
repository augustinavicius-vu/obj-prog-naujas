#include <gtest/gtest.h>
#include <limits>
#include "functions.h"

// Test fixture for the AtsitiktinisSkaicius function
class AtsitiktinisSkaiciusTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Set up any necessary data or objects for the tests
    }

    void TearDown() override {
        // Clean up any resources used by the tests
    }

    // Declare any member variables or helper functions needed for the tests
};

// Test case for the AtsitiktinisSkaicius function
TEST_F(AtsitiktinisSkaiciusTest, RandomNumberInRange) {
    // Define the range
    int min = 1;
    int max = 100;

    // Call the AtsitiktinisSkaicius function
    int result = AtsitiktinisSkaicius(min, max);

    // Check if the result is within the specified range
    ASSERT_GE(result, min);  // Check if result is greater than or equal to min
    ASSERT_LE(result, max);  // Check if result is less than or equal to max
}

TEST_F(AtsitiktinisSkaiciusTest, InvalidRange) {
    // Define an invalid range where min > max
    int min = 100;
    int max = 1;

    // Call the AtsitiktinisSkaicius function with invalid range
    int result = AtsitiktinisSkaicius(min, max);

    // Check if the result is the minimum value of int
    ASSERT_EQ(result, std::numeric_limits<int>::min());
}