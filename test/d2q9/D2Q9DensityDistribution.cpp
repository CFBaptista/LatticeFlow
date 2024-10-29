#include "../../src/d2q9/D2Q9DensityDistribution.hpp"
#include "../../src/d2q9/arithmetic.hpp"
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

TYPED_TEST(DefaultD2Q9DensityDistributionTest, DistributionEqualsUniformZero)
{
    // Given

    const TypeParam expectedValue{0.0};

    // When

    // Then

    for (size_t i = 0; i < this->distribution.size(); i++)
    {
        EXPECT_EQ(this->distribution[i], expectedValue);
    }
}

TYPED_TEST(DefaultD2Q9DensityDistributionTest, VelocityEqualsZeroVector)
{
    // Given

    const std::array<TypeParam, 2> expectedVelocity{0.0, 0.0};

    // When

    const TypeParam density{this->distribution.computeDensity()};
    const std::array<TypeParam, 2> momentum{this->distribution.computeMomentum()};
    const std::array<TypeParam, 2> velocity{
        D2Q9DensityDistribution<TypeParam>::computeVelocity(density, momentum)
    };

    // Then

    EXPECT_EQ(velocity, expectedVelocity);
}

TYPED_TEST(DefaultD2Q9DensityDistributionTest, DensityEqualsZero)
{
    // Given

    const TypeParam expectedDensity{0.0};

    // When

    const TypeParam density{this->distribution.computeDensity()};

    // Then

    EXPECT_EQ(density, expectedDensity);
}

TYPED_TEST(DefaultD2Q9DensityDistributionTest, MomentumEqualsZeroVector)
{
    // Given

    const std::array<TypeParam, 2> expectedMomentum{0.0, 0.0};

    // When

    const std::array<TypeParam, 2> momentum{this->distribution.computeMomentum()};

    // Then

    EXPECT_EQ(momentum, expectedMomentum);
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

TYPED_TEST(GeneralD2Q9DensityDistributionTest, DimensionEqualsTwo)
{
    // Given

    const int expectedDimension{2};

    // When

    // Then

    EXPECT_EQ(this->distribution.dimension(), expectedDimension);
}

TYPED_TEST(GeneralD2Q9DensityDistributionTest, SizeEqualsNine)
{
    // Given

    const int expectedSize{9};

    // When

    // Then

    EXPECT_EQ(this->distribution.size(), expectedSize);
}

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

TYPED_TEST(GeneralD2Q9DensityDistributionTest, WeightsEqualLiteratureValues)
{
    //  @book{
    //      author = {Krüger, Timm and Kusumaatmaja, Halim and Kuzmin, Alexandr and Shardt, Orest
    //      and Silva, Goncalo and Viggen, Erlend Magnus},
    //      title = {The Lattice Boltzmann Method},
    //      year = {2017},
    //      publisher = {Springer},
    //      isbn = {978-3-319-83103-9},
    //      doi = {10.1007/978-3-319-44649-3}
    //  }

    // Given

    const TypeParam expectedWeightCenter{4.0 / 9.0};
    const TypeParam expectedWeightRight{1.0 / 9.0};
    const TypeParam expectedWeightTop{1.0 / 9.0};
    const TypeParam expectedWeightLeft{1.0 / 9.0};
    const TypeParam expectedWeightBottom{1.0 / 9.0};
    const TypeParam expectedWeightTopRight{1.0 / 36.0};
    const TypeParam expectedWeightTopLeft{1.0 / 36.0};
    const TypeParam expectedWeightBottomLeft{1.0 / 36.0};
    const TypeParam expectedWeightBottomRight{1.0 / 36.0};

    // When

    // Then

    EXPECT_EQ(D2Q9DensityDistribution<TypeParam>::weight(0), expectedWeightCenter);
    EXPECT_EQ(D2Q9DensityDistribution<TypeParam>::weight(1), expectedWeightRight);
    EXPECT_EQ(D2Q9DensityDistribution<TypeParam>::weight(2), expectedWeightTop);
    EXPECT_EQ(D2Q9DensityDistribution<TypeParam>::weight(3), expectedWeightLeft);
    EXPECT_EQ(D2Q9DensityDistribution<TypeParam>::weight(4), expectedWeightBottom);
    EXPECT_EQ(D2Q9DensityDistribution<TypeParam>::weight(5), expectedWeightTopRight);
    EXPECT_EQ(D2Q9DensityDistribution<TypeParam>::weight(6), expectedWeightTopLeft);
    EXPECT_EQ(D2Q9DensityDistribution<TypeParam>::weight(7), expectedWeightBottomLeft);
    EXPECT_EQ(D2Q9DensityDistribution<TypeParam>::weight(8), expectedWeightBottomRight);
}

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
