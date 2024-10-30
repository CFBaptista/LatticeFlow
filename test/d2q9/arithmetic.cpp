#include "../../src/d2q9/arithmetic.hpp"
#include <gtest/gtest.h>

TEST(D2Q9DensityDistributionArithmeticTest, AddingTwoDistributionsReturnsSumOfDistribution)
{
    // Given

    D2Q9DensityDistribution<double> distribution1;
    D2Q9DensityDistribution<double> distribution2;
    D2Q9DensityDistribution<double> expectedDistribution;

    for (int i = 0; i < static_cast<int>(D2Q9DensityDistribution<double>::size()); i++)
    {
        distribution1[i] = i;
        distribution2[i] = 2 * i;
        expectedDistribution[i] = 3 * i;
    }

    // When

    D2Q9DensityDistribution<double> summedDistribution = distribution1 + distribution2;

    // Then

    for (size_t i = 0; i < D2Q9DensityDistribution<double>::size(); i++)
    {
        EXPECT_EQ(summedDistribution[i], expectedDistribution[i]);
    }
}
