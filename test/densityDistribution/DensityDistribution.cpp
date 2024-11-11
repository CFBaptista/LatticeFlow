#include "../../src/densityDistribution/DensityDistribution.hpp"
#include <gtest/gtest.h>

using FloatingPointTypes = ::testing::Types<float, double>;

template <typename Scalar>
class DefaultDensityDistributionTest : public ::testing::Test
{
protected:
    DefaultDensityDistributionTest() = default;

    static constexpr std::size_t dimension_{2};
    static constexpr std::size_t size_{9};

    DensityDistribution<dimension_, size_, Scalar> distribution;
};

TYPED_TEST_SUITE(DefaultDensityDistributionTest, FloatingPointTypes);

TYPED_TEST(DefaultDensityDistributionTest, DistributionEqualsUniformZero)
{
    // Given

    const TypeParam expectedValue{0.0};

    // When

    // Then

    for (std::size_t i = 0; i < this->distribution.size(); ++i)
    {
        EXPECT_EQ(this->distribution[i], expectedValue);
    }
}

TYPED_TEST(DefaultDensityDistributionTest, DensityEqualsZero)
{
    // Given

    const TypeParam expectedDensity{0.0};

    // When

    const TypeParam density{computeDensity(this->distribution)};

    // Then

    EXPECT_EQ(density, expectedDensity);
}

TYPED_TEST(DefaultDensityDistributionTest, MomentumEqualsZeroVector)
{
    // Given

    const std::array<TypeParam, 2> expectedMomentum{0.0, 0.0};

    // When

    const std::array<TypeParam, 2> momentum{computeMomentum(this->distribution)};

    // Then

    EXPECT_EQ(momentum, expectedMomentum);
}

template <typename Scalar>
class GeneralDensityDistributionTest : public ::testing::Test
{
protected:
    GeneralDensityDistributionTest()
        : distribution{1.0 / 3.0, 2.0 / 4.0, 3.0 / 5.0,  4.0 / 6.0, 5.0 / 7.0,
                       6.0 / 8.0, 7.0 / 9.0, 8.0 / 10.0, 9.0 / 11.0},
          constDistribution{1.0 / 3.0, 2.0 / 4.0, 3.0 / 5.0,  4.0 / 6.0, 5.0 / 7.0,
                            6.0 / 8.0, 7.0 / 9.0, 8.0 / 10.0, 9.0 / 11.0}
    {
    }

    DensityDistribution<2, 9, Scalar> distribution;
    DensityDistribution<2, 9, Scalar> constDistribution;
};

TYPED_TEST_SUITE(GeneralDensityDistributionTest, FloatingPointTypes);

TYPED_TEST(GeneralDensityDistributionTest, DimensionEqualsTwo)
{
    // Given

    const std::size_t expectedDimension{2};

    // When

    // Then

    EXPECT_EQ(this->distribution.dimension(), expectedDimension);
}

TYPED_TEST(GeneralDensityDistributionTest, SizeEqualsNine)
{
    // Given

    const std::size_t expectedSize{9};

    // When

    // Then

    EXPECT_EQ(this->distribution.size(), expectedSize);
}

TYPED_TEST(GeneralDensityDistributionTest, GetValueFromNonConstDistribution)
{
    // Given

    const std::size_t index{3};
    const TypeParam expectedValue{4.0 / 6.0};

    // When

    const TypeParam& value{this->distribution[index]};

    // Then

    EXPECT_EQ(value, expectedValue);
}

TYPED_TEST(GeneralDensityDistributionTest, GetValueFromConstDistribution)
{
    // Given

    const DensityDistribution<2, 9, TypeParam> distribution{3, 5, 7, 11, 13, 17, 19, 23, 29};
    const std::size_t index{3};
    const TypeParam expectedValue{11};

    // When

    const TypeParam& value{distribution[index]};

    // Then

    EXPECT_EQ(value, expectedValue);
}

TYPED_TEST(GeneralDensityDistributionTest, SetValueInNonConstDistribution)
{
    // Given

    const std::size_t index{3};
    const TypeParam expectedValue{5.0};

    // When

    this->distribution[index] = expectedValue;

    // Then

    EXPECT_EQ(this->distribution[index], expectedValue);
}

TYPED_TEST(GeneralDensityDistributionTest, GetFirstNonConstValueWithBegin)
{
    // Given

    const TypeParam expectedValue{1.0 / 3.0};

    // When

    // Then

    EXPECT_EQ(*this->distribution.begin(), expectedValue);
}

TYPED_TEST(GeneralDensityDistributionTest, GetFirstConstValueWithBegin)
{
    // Given

    const TypeParam expectedValue{1.0 / 3.0};

    // When

    // Then

    EXPECT_EQ(*this->constDistribution.begin(), expectedValue);
}

TYPED_TEST(GeneralDensityDistributionTest, GetLastNonConstValueWithEnd)
{
    // Given

    const TypeParam expectedValue{9.0 / 11.0};

    // When

    // Then

    EXPECT_EQ(*(this->distribution.end() - 1), expectedValue);
}

TYPED_TEST(GeneralDensityDistributionTest, GetLastConstValueWithEnd)
{
    // Given

    const TypeParam expectedValue{9.0 / 11.0};

    // When

    // Then

    EXPECT_EQ(*(this->constDistribution.end() - 1), expectedValue);
}

TYPED_TEST(GeneralDensityDistributionTest, GetFirstConstValueWithCBegin)
{
    // Given

    const TypeParam expectedValue{1.0 / 3.0};

    // When

    // Then

    EXPECT_EQ(*this->constDistribution.cbegin(), expectedValue);
}

TYPED_TEST(GeneralDensityDistributionTest, GetLastConstValueWithCEnd)
{
    // Given

    const TypeParam expectedValue{9.0 / 11.0};

    // When

    // Then

    EXPECT_EQ(*(this->constDistribution.cend() - 1), expectedValue);
}

TYPED_TEST(GeneralDensityDistributionTest, DistributionEqualsSetValues)
{
    // Given

    const std::size_t size{9};
    const std::array<TypeParam, size> expectedValue{1.0 / 3.0, 2.0 / 4.0,  3.0 / 5.0,
                                                    4.0 / 6.0, 5.0 / 7.0,  6.0 / 8.0,
                                                    7.0 / 9.0, 8.0 / 10.0, 9.0 / 11.0};

    // When

    // Then

    for (std::size_t i = 0; i < size; ++i)
    {
        EXPECT_EQ(this->distribution[i], expectedValue.at(i));
    }
}

TYPED_TEST(GeneralDensityDistributionTest, DensityEqualsDistributionZerothMoment)
{
    // Given

    const TypeParam expectedDensity{5.9602453102453108};
    const double tolerance{10 * std::numeric_limits<TypeParam>::epsilon()};

    // When

    const TypeParam density{computeDensity(this->distribution)};

    // Then

    EXPECT_NEAR(density, expectedDensity, tolerance);
}

TYPED_TEST(GeneralDensityDistributionTest, MomentumEqualsDistributionFirstMoment)
{
    // Given

    const std::array<TypeParam, 2> expectedMomentum{-0.17626262626262612, -0.2046897546897548};
    const TypeParam tolerance{10 * std::numeric_limits<TypeParam>::epsilon()};

    // When

    const std::array<TypeParam, 2> momentum{computeMomentum(this->distribution)};

    // Then

    EXPECT_NEAR(momentum[0], expectedMomentum[0], tolerance);
    EXPECT_NEAR(momentum[1], expectedMomentum[1], tolerance);
}

TYPED_TEST(GeneralDensityDistributionTest, WeightsEqualLiteratureValues)
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

    // Then

    using Type = DensityDistribution<2, 9, TypeParam>;

    EXPECT_EQ(Type::weight(0), expectedWeightCenter);
    EXPECT_EQ(Type::weight(1), expectedWeightRight);
    EXPECT_EQ(Type::weight(2), expectedWeightTop);
    EXPECT_EQ(Type::weight(3), expectedWeightLeft);
    EXPECT_EQ(Type::weight(4), expectedWeightBottom);
    EXPECT_EQ(Type::weight(5), expectedWeightTopRight);
    EXPECT_EQ(Type::weight(6), expectedWeightTopLeft);
    EXPECT_EQ(Type::weight(7), expectedWeightBottomLeft);
    EXPECT_EQ(Type::weight(8), expectedWeightBottomRight);
}
