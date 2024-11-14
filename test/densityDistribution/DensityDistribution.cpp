#include "../../src/densityDistribution/DensityDistribution.hpp"
#include <gtest/gtest.h>

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
