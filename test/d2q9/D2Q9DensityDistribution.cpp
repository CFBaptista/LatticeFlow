#include "../../src/d2q9/D2Q9DensityDistribution.hpp"
#include <gtest/gtest.h>

using FloatingPointTypes = ::testing::Types<float, double>;

template <typename Scalar>
class DefaultD2Q9DensityDistributionTest : public ::testing::Test
{
public:
    D2Q9DensityDistribution<Scalar> distribution;

protected:
    DefaultD2Q9DensityDistributionTest() = default;
};

TYPED_TEST_SUITE(DefaultD2Q9DensityDistributionTest, FloatingPointTypes);

TYPED_TEST(DefaultD2Q9DensityDistributionTest, DimensionEqualsTwo)
{
    // Given

    D2Q9DensityDistribution<TypeParam> distribution;
    const int expectedDimension{2};

    // When

    // Then

    EXPECT_EQ(distribution.dimension(), expectedDimension);
}

TYPED_TEST(DefaultD2Q9DensityDistributionTest, SizeEqualsNine)
{
    // Given

    D2Q9DensityDistribution<TypeParam> distribution;
    const int expectedSize{9};

    // When

    // Then

    EXPECT_EQ(distribution.size(), expectedSize);
}

TYPED_TEST(DefaultD2Q9DensityDistributionTest, DistributionEqualsUniformZero)
{
    // Given

    D2Q9DensityDistribution<TypeParam> distribution;
    const int size{9};
    const TypeParam expectedValue{0.0};

    // When

    // Then

    for (int i = 0; i < size; i++)
    {
        EXPECT_EQ(distribution[i], expectedValue);
    }
}

TYPED_TEST(DefaultD2Q9DensityDistributionTest, DensityEqualsZero)
{
    // Given

    D2Q9DensityDistribution<TypeParam> distribution;
    const TypeParam expectedDensity{0.0};

    // When

    const TypeParam density{distribution.computeDensity()};

    // Then

    EXPECT_EQ(density, expectedDensity);
}

TYPED_TEST(DefaultD2Q9DensityDistributionTest, MomentumEqualsZeroVector)
{
    // Given

    D2Q9DensityDistribution<TypeParam> distribution;
    const std::array<TypeParam, 2> expectedMomentum{0.0, 0.0};

    // When

    const std::array<TypeParam, 2> momentum{distribution.computeMomentum()};

    // Then

    EXPECT_EQ(momentum, expectedMomentum);
}

TYPED_TEST(DefaultD2Q9DensityDistributionTest, VelocityEqualsZeroVector)
{
    // Given

    D2Q9DensityDistribution<TypeParam> distribution;
    const std::array<TypeParam, 2> expectedVelocity{0.0, 0.0};

    // When

    const TypeParam density{distribution.computeDensity()};
    const std::array<TypeParam, 2> momentum{distribution.computeMomentum()};
    const std::array<TypeParam, 2> velocity{
        D2Q9DensityDistribution<TypeParam>::computeVelocity(density, momentum)
    };

    // Then

    EXPECT_EQ(velocity, expectedVelocity);
}

template <typename Scalar>
class GeneralD2Q9DensityDistributionTest : public ::testing::Test
{
public:
    D2Q9DensityDistribution<Scalar> distribution;

protected:
    GeneralD2Q9DensityDistributionTest()
    {
        const int size{9};

        for (int i = 0; i < size; i++)
        {
            distribution[i] = static_cast<Scalar>(i + 1) / (i + 3);
        }
    }
};

TYPED_TEST_SUITE(GeneralD2Q9DensityDistributionTest, FloatingPointTypes);

TYPED_TEST(GeneralD2Q9DensityDistributionTest, DistributionEqualsSetValues)
{
    // Given

    const int size{9};
    const std::array<TypeParam, size> expectedValue{1.0 / 3.0, 2.0 / 4.0,  3.0 / 5.0,
                                                    4.0 / 6.0, 5.0 / 7.0,  6.0 / 8.0,
                                                    7.0 / 9.0, 8.0 / 10.0, 9.0 / 11.0};

    // When

    // Then

    for (int i = 0; i < size; i++)
    {
        EXPECT_EQ(this->distribution[i], expectedValue.at(i));
    }
}

TYPED_TEST(GeneralD2Q9DensityDistributionTest, DensityEqualsDistributionZerothMoment)
{
    // Given

    const TypeParam expectedDensity{5.9602453102453108};
    const double tolerance{10 * std::numeric_limits<TypeParam>::epsilon()};

    // When

    const TypeParam density{this->distribution.computeDensity()};

    // Then

    EXPECT_NEAR(density, expectedDensity, tolerance);
}

TYPED_TEST(GeneralD2Q9DensityDistributionTest, MomentumEqualsDistributionFirstMoment)
{
    // Given

    const std::array<TypeParam, 2> expectedMomentum{-0.17626262626262612, -0.2046897546897548};
    const TypeParam tolerance{10 * std::numeric_limits<TypeParam>::epsilon()};

    // When

    const std::array<TypeParam, 2> momentum{this->distribution.computeMomentum()};

    // Then

    EXPECT_NEAR(momentum[0], expectedMomentum[0], tolerance);
    EXPECT_NEAR(momentum[1], expectedMomentum[1], tolerance);
}

TYPED_TEST(
    GeneralD2Q9DensityDistributionTest,
    VelocityEqualsDistributionFirstMomentDividedbyZerothMoment
)
{
    // Given

    const TypeParam density{this->distribution.computeDensity()};
    const std::array<TypeParam, 2> momentum{this->distribution.computeMomentum()};
    const std::array<TypeParam, 2> expectedVelocity{-0.029573048941398609, -0.034342505053928767};
    const TypeParam tolerance{10 * std::numeric_limits<TypeParam>::epsilon()};

    // When

    const std::array<TypeParam, 2> velocity{
        D2Q9DensityDistribution<TypeParam>::computeVelocity(density, momentum)
    };

    // Then

    EXPECT_NEAR(velocity[0], expectedVelocity[0], tolerance);
    EXPECT_NEAR(velocity[1], expectedVelocity[1], tolerance);
}
