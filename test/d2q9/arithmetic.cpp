#include "../../src/d2q9/arithmetic.hpp"
#include <gtest/gtest.h>

TEST(D2Q9DensityDistributionArithmeticTest, AddingTwoDistributionsReturnsSumOfDistribution)
{
    // Given

    const D2Q9DensityDistribution<double> distribution1{1, 2, 3, 4, 5, 6, 7, 8, 9};
    const D2Q9DensityDistribution<double> distribution2{2, 4, 6, 8, 10, 12, 14, 16, 18};
    const D2Q9DensityDistribution<double> expectedDistribution{3, 6, 9, 12, 15, 18, 21, 24, 27};

    // When

    D2Q9DensityDistribution<double> summedDistribution = distribution1 + distribution2;

    // Then

    for (size_t i = 0; i < D2Q9DensityDistribution<double>::size(); i++)
    {
        EXPECT_EQ(summedDistribution[i], expectedDistribution[i]);
    }
}
