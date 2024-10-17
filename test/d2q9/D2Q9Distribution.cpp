#include <gtest/gtest.h>
#include "../../src/d2q9/D2Q9Distribution.hpp"

TEST(D2Q9Distribution, DimensionEquals2)
{
    // Given

    D2Q9Distribution distribution;
    const int expectedDimension{2};

    // When

    // Then

    EXPECT_EQ(distribution.dimension(), expectedDimension);
}

TEST(D2Q9Distribution, SizeEquals9)
{
    // Given

    D2Q9Distribution distribution;
    const int expectedSize{9};

    // When

    // Then

    EXPECT_EQ(distribution.size(), expectedSize);
}

TEST(D2Q9Distribution, DefaultValueEquals0)
{
    // Given
    
    D2Q9Distribution distribution;
    const double expectedValue{0.0};

    // When

    // Then

    for (int i = 0; i < 9; i++)
    {
        EXPECT_EQ(distribution[i], expectedValue);
    }
}

TEST(D2Q9Distribution, SetValue)
{
    // Given

    D2Q9Distribution distribution;
    const int index{3};
    const double expectedValue{3.14};

    // When

    distribution[index] = expectedValue;

    // Then

    EXPECT_EQ(distribution[index], expectedValue);
}
