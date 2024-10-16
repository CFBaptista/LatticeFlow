#include <gtest/gtest.h>
#include "../../src/d2q9/D2Q9Distribution.hpp"

TEST(D2Q9Distribution, DefaultValueEquals0)
{
    // Given
    
    const double expectedValue{0.0};

    // When

    D2Q9Distribution distribution;

    // Then

    for (int i = 0; i < 9; i++)
    {
        EXPECT_EQ(distribution[i], expectedValue);
    }
}

TEST(D2Q9Distribution, SizeEquals9)
{
    // Given

    const int expectedSize{9};

    // When

    D2Q9Distribution distribution;

    // Then

    EXPECT_EQ(distribution.size(), expectedSize);
}
