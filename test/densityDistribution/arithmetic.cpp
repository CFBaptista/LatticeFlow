#include "../../src/densityDistribution/arithmetic.hpp"
#include <gtest/gtest.h>

using FloatingPointTypes = ::testing::Types<float, double>;

template <typename Scalar>
class DensityDistributionArithmeticTest : public ::testing::Test
{
private:
    static constexpr std::size_t dimension_{2};
    static constexpr std::size_t size_{9};
    static constexpr std::initializer_list<Scalar> distribution1_{1, 2, 3, 4, 5, 6, 7, 8, 9};
    static constexpr std::initializer_list<Scalar> distribution2_{2, 4, 6, 8, 10, 12, 14, 16, 18};

protected:
    DensityDistributionArithmeticTest() = default;

    // NOLINTBEGIN(cppcoreguidelines-non-private-member-variables-in-classes)
    DensityDistribution<dimension_, size_, Scalar> distribution1{distribution1_};
    DensityDistribution<dimension_, size_, Scalar> distribution2{distribution2_};
    // NOLINTEND(cppcoreguidelines-non-private-member-variables-in-classes)
};

TYPED_TEST_SUITE(DensityDistributionArithmeticTest, FloatingPointTypes);

TYPED_TEST(DensityDistributionArithmeticTest, AddingTwoDistributionsReturnsSumOfDistributions)
{
    // Given

    const DensityDistribution<2, 9, TypeParam> expectedDistribution{3,  6,  9,  12, 15,
                                                                    18, 21, 24, 27};

    // When

    const DensityDistribution<2, 9, TypeParam> summedDistribution = operator+(
        this->distribution1, this->distribution2
    );

    // Then

    for (std::size_t i = 0; i < expectedDistribution.size(); ++i)
    {
        EXPECT_EQ(summedDistribution[i], expectedDistribution[i]);
    }
}

TYPED_TEST(
    DensityDistributionArithmeticTest,
    SubtractingTwoDistributionsReturnsDifferenceBetweenDistributions
)
{
    // Given

    const DensityDistribution<2, 9, TypeParam> expectedDistribution{-1, -2, -3, -4, -5,
                                                                    -6, -7, -8, -9};

    // When

    const DensityDistribution<2, 9, TypeParam> summedDistribution = operator-(
        this->distribution1, this->distribution2
    );

    // Then

    for (std::size_t i = 0; i < expectedDistribution.size(); ++i)
    {
        EXPECT_EQ(summedDistribution[i], expectedDistribution[i]);
    }
}
