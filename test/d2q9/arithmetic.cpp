#include "../../src/d2q9/arithmetic.hpp"
#include <gtest/gtest.h>

using FloatingPointTypes = ::testing::Types<float, double>;

template <typename Scalar>
class D2Q9DensityDistributionArithmeticTest : public ::testing::Test
{
protected:
    D2Q9DensityDistributionArithmeticTest() = default;

    D2Q9DensityDistribution<Scalar> distribution1{1, 2, 3, 4, 5, 6, 7, 8, 9};
    D2Q9DensityDistribution<Scalar> distribution2{2, 4, 6, 8, 10, 12, 14, 16, 18};
};

TYPED_TEST_SUITE(D2Q9DensityDistributionArithmeticTest, FloatingPointTypes);

TYPED_TEST(D2Q9DensityDistributionArithmeticTest, AddingTwoDistributionsReturnsSumOfDistributions)
{
    // Given

    const D2Q9DensityDistribution<TypeParam> expectedDistribution{3, 6, 9, 12, 15, 18, 21, 24, 27};

    // When

    D2Q9DensityDistribution<TypeParam> summedDistribution =
        this->distribution1 + this->distribution2;

    // Then

    for (std::size_t i = 0; i < D2Q9DensityDistribution<TypeParam>::size(); ++i)
    {
        EXPECT_EQ(summedDistribution[i], expectedDistribution[i]);
    }
}

TYPED_TEST(
    D2Q9DensityDistributionArithmeticTest,
    SubtractingTwoDistributionsReturnsDifferenceBetweenDistributions
)
{
    // Given

    const D2Q9DensityDistribution<TypeParam> expectedDistribution{-1, -2, -3, -4, -5,
                                                                  -6, -7, -8, -9};

    // When

    D2Q9DensityDistribution<TypeParam> summedDistribution =
        this->distribution1 - this->distribution2;

    // Then

    for (std::size_t i = 0; i < D2Q9DensityDistribution<TypeParam>::size(); ++i)
    {
        EXPECT_EQ(summedDistribution[i], expectedDistribution[i]);
    }
}
