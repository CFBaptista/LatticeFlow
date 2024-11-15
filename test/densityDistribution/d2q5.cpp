#include "../../src/densityDistribution/d2q5.hpp"
#include <gtest/gtest.h>

template <typename Scalar>
class D2Q5Test : public ::testing::Test
{
private:
    static constexpr std::size_t dimension_{2};
    static constexpr std::size_t size_{5};
    static constexpr std::initializer_list<Scalar> distribution_{
        1.0 / 3.0, 2.0 / 4.0, 3.0 / 5.0, 4.0 / 6.0, 5.0 / 7.0
    };

protected:
    D2Q5Test() : nonDefaultDistribution{distribution_} {}

    // NOLINTBEGIN(cppcoreguidelines-non-private-member-variables-in-classes)
    DensityDistribution<dimension_, size_, Scalar> defaultDistribution;
    DensityDistribution<dimension_, size_, Scalar> nonDefaultDistribution;
    // NOLINTEND(cppcoreguidelines-non-private-member-variables-in-classes)
};

using FloatingPointTypes = ::testing::Types<float, double>;
TYPED_TEST_SUITE(D2Q5Test, FloatingPointTypes);

TYPED_TEST(D2Q5Test, DefaultDensityEqualsZero)
{
    // Given

    const TypeParam expectedDensity{0.0};

    // When

    const TypeParam density{computeDensity(this->defaultDistribution)};

    // Then

    EXPECT_EQ(density, expectedDensity);
}

TYPED_TEST(D2Q5Test, DefaultMomentumEqualsZeroVector)
{
    // Given

    const std::array<TypeParam, 2> expectedMomentum{0.0, 0.0};

    // When

    const std::array<TypeParam, 2> momentum{computeMomentum(this->defaultDistribution)};

    // Then

    EXPECT_EQ(momentum, expectedMomentum);
}

TYPED_TEST(D2Q5Test, DensityEqualsDistributionZerothMoment)
{
    // Given

    const TypeParam expectedDensity{2.814285714285714};
    const double tolerance{10 * std::numeric_limits<TypeParam>::epsilon()};

    // When

    const TypeParam density{computeDensity(this->nonDefaultDistribution)};

    // Then

    EXPECT_NEAR(density, expectedDensity, tolerance);
}

TYPED_TEST(D2Q5Test, MomentumEqualsDistributionFirstMoment)
{
    // Given

    const std::array<TypeParam, 2> expectedMomentum{-0.16666666666666663, -0.11428571428571432};
    const TypeParam tolerance{10 * std::numeric_limits<TypeParam>::epsilon()};

    // When

    const std::array<TypeParam, 2> momentum{computeMomentum(this->nonDefaultDistribution)};

    // Then

    EXPECT_NEAR(momentum[0], expectedMomentum[0], tolerance);
    EXPECT_NEAR(momentum[1], expectedMomentum[1], tolerance);
}

TYPED_TEST(D2Q5Test, WeightsEqualLiteratureValues)
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

    const TypeParam expectedWeightCenter{1.0 / 3.0};
    const TypeParam expectedWeightRight{1.0 / 6.0};
    const TypeParam expectedWeightTop{1.0 / 6.0};
    const TypeParam expectedWeightLeft{1.0 / 6.0};
    const TypeParam expectedWeightBottom{1.0 / 6.0};

    // When

    const std::array<TypeParam, 5> weight{latticeWeights(this->nonDefaultDistribution)};

    // Then

    EXPECT_EQ(weight[0], expectedWeightCenter);
    EXPECT_EQ(weight[1], expectedWeightRight);
    EXPECT_EQ(weight[2], expectedWeightTop);
    EXPECT_EQ(weight[3], expectedWeightLeft);
    EXPECT_EQ(weight[4], expectedWeightBottom);
}
