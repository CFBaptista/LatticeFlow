#include "../../src/densityDistribution/d2q9.hpp"
#include <gtest/gtest.h>

template <typename Scalar>
class D2Q9Test : public ::testing::Test
{
protected:
    D2Q9Test()
        : nonDefaultDistribution{1.0 / 3.0, 2.0 / 4.0, 3.0 / 5.0,  4.0 / 6.0, 5.0 / 7.0,
                                 6.0 / 8.0, 7.0 / 9.0, 8.0 / 10.0, 9.0 / 11.0}
    {
    }

    DensityDistribution<2, 9, Scalar> defaultDistribution;
    DensityDistribution<2, 9, Scalar> nonDefaultDistribution;
};

using FloatingPointTypes = ::testing::Types<float, double>;
TYPED_TEST_SUITE(D2Q9Test, FloatingPointTypes);

TYPED_TEST(D2Q9Test, DefaultDensityEqualsZero)
{
    // Given

    const TypeParam expectedDensity{0.0};

    // When

    const TypeParam density{computeDensity(this->defaultDistribution)};

    // Then

    EXPECT_EQ(density, expectedDensity);
}

TYPED_TEST(D2Q9Test, DefaultMomentumEqualsZeroVector)
{
    // Given

    const std::array<TypeParam, 2> expectedMomentum{0.0, 0.0};

    // When

    const std::array<TypeParam, 2> momentum{computeMomentum(this->defaultDistribution)};

    // Then

    EXPECT_EQ(momentum, expectedMomentum);
}

TYPED_TEST(D2Q9Test, DensityEqualsDistributionZerothMoment)
{
    // Given

    const TypeParam expectedDensity{5.9602453102453108};
    const double tolerance{10 * std::numeric_limits<TypeParam>::epsilon()};

    // When

    const TypeParam density{computeDensity(this->nonDefaultDistribution)};

    // Then

    EXPECT_NEAR(density, expectedDensity, tolerance);
}

TYPED_TEST(D2Q9Test, MomentumEqualsDistributionFirstMoment)
{
    // Given

    const std::array<TypeParam, 2> expectedMomentum{-0.17626262626262612, -0.2046897546897548};
    const TypeParam tolerance{10 * std::numeric_limits<TypeParam>::epsilon()};

    // When

    const std::array<TypeParam, 2> momentum{computeMomentum(this->nonDefaultDistribution)};

    // Then

    EXPECT_NEAR(momentum[0], expectedMomentum[0], tolerance);
    EXPECT_NEAR(momentum[1], expectedMomentum[1], tolerance);
}

TYPED_TEST(D2Q9Test, WeightsEqualLiteratureValues)
{
    // Reference:

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

    const std::array<TypeParam, 9> weight{latticeWeights(this->nonDefaultDistribution)};

    // Then

    EXPECT_EQ(weight[0], expectedWeightCenter);
    EXPECT_EQ(weight[1], expectedWeightRight);
    EXPECT_EQ(weight[2], expectedWeightTop);
    EXPECT_EQ(weight[3], expectedWeightLeft);
    EXPECT_EQ(weight[4], expectedWeightBottom);
    EXPECT_EQ(weight[5], expectedWeightTopRight);
    EXPECT_EQ(weight[6], expectedWeightTopLeft);
    EXPECT_EQ(weight[7], expectedWeightBottomLeft);
    EXPECT_EQ(weight[8], expectedWeightBottomRight);
}
