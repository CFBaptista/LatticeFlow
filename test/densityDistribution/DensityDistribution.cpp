#include "../../src/densityDistribution/DensityDistribution.hpp"
#include "gtest/gtest.h"
#include <cstddef>

TEST(DensityDistributionConstructorTest, DimensionAndSizeEqualTemplateParameters)
{
    // Given

    const std::size_t expectedDimension1{1};
    const std::size_t expectedDimension2{1};
    const std::size_t expectedDimension3{1};

    const std::size_t expectedSize3{3};
    const std::size_t expectedSize5{5};
    const std::size_t expectedSize9{9};
    const std::size_t expectedSize15{15};
    const std::size_t expectedSize19{19};
    const std::size_t expectedSize27{27};

    const DensityDistribution<expectedDimension1, expectedSize3, double> d1q3;
    const DensityDistribution<expectedDimension2, expectedSize5, double> d2q5;
    const DensityDistribution<expectedDimension2, expectedSize9, double> d2q9;
    const DensityDistribution<expectedDimension3, expectedSize15, double> d3q15;
    const DensityDistribution<expectedDimension3, expectedSize19, double> d3q19;
    const DensityDistribution<expectedDimension3, expectedSize27, double> d3q27;
    const DensityDistribution<expectedDimension1, expectedSize3, float> d1q3_f;
    const DensityDistribution<expectedDimension2, expectedSize5, float> d2q5_f;
    const DensityDistribution<expectedDimension2, expectedSize9, float> d2q9_f;
    const DensityDistribution<expectedDimension3, expectedSize15, float> d3q15_f;
    const DensityDistribution<expectedDimension3, expectedSize19, float> d3q19_f;
    const DensityDistribution<expectedDimension3, expectedSize27, float> d3q27_f;

    // When

    const std::size_t d1q3Dimension{d1q3.dimension()};
    const std::size_t d2q5Dimension{d2q5.dimension()};
    const std::size_t d2q9Dimension{d2q9.dimension()};
    const std::size_t d3q15Dimension{d3q15.dimension()};
    const std::size_t d3q19Dimension{d3q19.dimension()};
    const std::size_t d3q27Dimension{d3q27.dimension()};
    const std::size_t d1q3_fDimension{d1q3_f.dimension()};
    const std::size_t d2q5_fDimension{d2q5_f.dimension()};
    const std::size_t d2q9_fDimension{d2q9_f.dimension()};
    const std::size_t d3q15_fDimension{d3q15_f.dimension()};
    const std::size_t d3q19_fDimension{d3q19_f.dimension()};
    const std::size_t d3q27_fDimension{d3q27_f.dimension()};

    const std::size_t d1q3Size{d1q3.size()};
    const std::size_t d2q5Size{d2q5.size()};
    const std::size_t d2q9Size{d2q9.size()};
    const std::size_t d3q15Size{d3q15.size()};
    const std::size_t d3q19Size{d3q19.size()};
    const std::size_t d3q27Size{d3q27.size()};
    const std::size_t d1q3_fSize{d1q3_f.size()};
    const std::size_t d2q5_fSize{d2q5_f.size()};
    const std::size_t d2q9_fSize{d2q9_f.size()};
    const std::size_t d3q15_fSize{d3q15_f.size()};
    const std::size_t d3q19_fSize{d3q19_f.size()};
    const std::size_t d3q27_fSize{d3q27_f.size()};

    // Then

    EXPECT_EQ(d1q3Dimension, expectedDimension1);
    EXPECT_EQ(d2q5Dimension, expectedDimension2);
    EXPECT_EQ(d2q9Dimension, expectedDimension2);
    EXPECT_EQ(d3q15Dimension, expectedDimension3);
    EXPECT_EQ(d3q19Dimension, expectedDimension3);
    EXPECT_EQ(d3q27Dimension, expectedDimension3);
    EXPECT_EQ(d1q3_fDimension, expectedDimension1);
    EXPECT_EQ(d2q5_fDimension, expectedDimension2);
    EXPECT_EQ(d2q9_fDimension, expectedDimension2);
    EXPECT_EQ(d3q15_fDimension, expectedDimension3);
    EXPECT_EQ(d3q19_fDimension, expectedDimension3);
    EXPECT_EQ(d3q27_fDimension, expectedDimension3);

    EXPECT_EQ(d1q3Size, expectedSize3);
    EXPECT_EQ(d2q5Size, expectedSize5);
    EXPECT_EQ(d2q9Size, expectedSize9);
    EXPECT_EQ(d3q15Size, expectedSize15);
    EXPECT_EQ(d3q19Size, expectedSize19);
    EXPECT_EQ(d3q27Size, expectedSize27);
    EXPECT_EQ(d1q3_fSize, expectedSize3);
    EXPECT_EQ(d2q5_fSize, expectedSize5);
    EXPECT_EQ(d2q9_fSize, expectedSize9);
    EXPECT_EQ(d3q15_fSize, expectedSize15);
    EXPECT_EQ(d3q19_fSize, expectedSize19);
    EXPECT_EQ(d3q27_fSize, expectedSize27);
}

template <typename Scalar>
class DensityDistributionTest : public ::testing::Test
{
private:
    static constexpr std::size_t dimension_{2};
    static constexpr std::size_t size_{9};
    static constexpr std::initializer_list<Scalar> distribution_{1.0 / 3.0, 2.0 / 4.0,  3.0 / 5.0,
                                                                 4.0 / 6.0, 5.0 / 7.0,  6.0 / 8.0,
                                                                 7.0 / 9.0, 8.0 / 10.0, 9.0 / 11.0};

protected:
    DensityDistributionTest()
        : nonConstNonDefaultDistribution{distribution_}, constNonDefaultDistribution{distribution_}
    {
    }

    // NOLINTBEGIN(cppcoreguidelines-non-private-member-variables-in-classes)
    DensityDistribution<dimension_, size_, Scalar> nonConstDefaultDistribution;
    DensityDistribution<dimension_, size_, Scalar> nonConstNonDefaultDistribution;
    // NOLINTNEXTLINE(cppcoreguidelines-avoid-const-or-ref-data-members)
    const DensityDistribution<dimension_, size_, Scalar> constNonDefaultDistribution;
    // NOLINTEND(cppcoreguidelines-non-private-member-variables-in-classes)
};

using FloatingPointTypes = ::testing::Types<float, double>;
TYPED_TEST_SUITE(DensityDistributionTest, FloatingPointTypes);

TYPED_TEST(DensityDistributionTest, DefaultDistributionEqualsUniformZero)
{
    // Given

    const TypeParam expectedValue{0.0};

    // When

    // Then

    for (std::size_t i = 0; i < this->nonConstDefaultDistribution.size(); ++i)
    {
        EXPECT_EQ(this->nonConstDefaultDistribution[i], expectedValue);
    }
}

TYPED_TEST(DensityDistributionTest, DimensionEqualsTwo)
{
    // Given

    const std::size_t expectedDimension{2};

    // When

    // Then

    EXPECT_EQ(this->nonConstNonDefaultDistribution.dimension(), expectedDimension);
}

TYPED_TEST(DensityDistributionTest, SizeEqualsNine)
{
    // Given

    const std::size_t expectedSize{9};

    // When

    // Then

    EXPECT_EQ(this->nonConstNonDefaultDistribution.size(), expectedSize);
}

TYPED_TEST(DensityDistributionTest, GetValueFromNonConstDistribution)
{
    // Given

    const std::size_t index{3};
    const TypeParam expectedValue{4.0 / 6.0};

    // When

    const TypeParam& value{this->nonConstNonDefaultDistribution[index]};

    // Then

    EXPECT_EQ(value, expectedValue);
}

TYPED_TEST(DensityDistributionTest, GetValueFromConstDistribution)
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

TYPED_TEST(DensityDistributionTest, SetValueInNonConstDistribution)
{
    // Given

    const std::size_t index{3};
    const TypeParam expectedValue{5.0};

    // When

    this->nonConstNonDefaultDistribution[index] = expectedValue;

    // Then

    EXPECT_EQ(this->nonConstNonDefaultDistribution[index], expectedValue);
}

TYPED_TEST(DensityDistributionTest, GetFirstNonConstValueWithBegin)
{
    // Given

    const TypeParam expectedValue{1.0 / 3.0};

    // When

    // Then

    EXPECT_EQ(*this->nonConstNonDefaultDistribution.begin(), expectedValue);
}

TYPED_TEST(DensityDistributionTest, GetFirstConstValueWithBegin)
{
    // Given

    const TypeParam expectedValue{1.0 / 3.0};

    // When

    // Then

    EXPECT_EQ(*this->constNonDefaultDistribution.begin(), expectedValue);
}

TYPED_TEST(DensityDistributionTest, GetLastNonConstValueWithEnd)
{
    // Given

    const TypeParam expectedValue{9.0 / 11.0};

    // When

    // Then

    EXPECT_EQ(*(this->nonConstNonDefaultDistribution.end() - 1), expectedValue);
}

TYPED_TEST(DensityDistributionTest, GetLastConstValueWithEnd)
{
    // Given

    const TypeParam expectedValue{9.0 / 11.0};

    // When

    // Then

    EXPECT_EQ(*(this->constNonDefaultDistribution.end() - 1), expectedValue);
}

TYPED_TEST(DensityDistributionTest, GetFirstConstValueWithCBegin)
{
    // Given

    const TypeParam expectedValue{1.0 / 3.0};

    // When

    // Then

    EXPECT_EQ(*this->constNonDefaultDistribution.cbegin(), expectedValue);
}

TYPED_TEST(DensityDistributionTest, GetLastConstValueWithCEnd)
{
    // Given

    const TypeParam expectedValue{9.0 / 11.0};

    // When

    // Then

    EXPECT_EQ(*(this->constNonDefaultDistribution.cend() - 1), expectedValue);
}

TYPED_TEST(DensityDistributionTest, DistributionEqualsSetValues)
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
        EXPECT_EQ(this->nonConstNonDefaultDistribution[i], expectedValue.at(i));
    }
}
