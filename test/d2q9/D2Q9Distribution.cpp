#include "../../src/d2q9/D2Q9Distribution.hpp"
#include <gtest/gtest.h>

class D2Q9DistributionTest : public ::testing::Test
{
public:
    D2Q9Distribution distribution;

protected:
    D2Q9DistributionTest()
    {
        const int size{9};

        for (int i = 0; i < size; i++)
        {
            distribution[i] = static_cast<double>(i + 1) / (i + 3);
        }
    }
};

TEST(DefaultD2Q9DistributionTest, DimensionEqualsTwo)
{
    // Given

    D2Q9Distribution distribution;
    const int expectedDimension{2};

    // When

    // Then

    EXPECT_EQ(distribution.dimension(), expectedDimension);
}

TEST(DefaultD2Q9DistributionTest, SizeEqualsNine)
{
    // Given

    D2Q9Distribution distribution;
    const int expectedSize{9};

    // When

    // Then

    EXPECT_EQ(distribution.size(), expectedSize);
}

TEST(DefaultD2Q9DistributionTest, DefaultDistributionEqualsUniformZero)
{
    // Given

    D2Q9Distribution distribution;
    const int size{9};
    const double expectedValue{0.0};

    // When

    // Then

    for (int i = 0; i < size; i++)
    {
        EXPECT_EQ(distribution[i], expectedValue);
    }
}

TEST(DefaultD2Q9DistributionTest, DefaultDensityEqualsZero)
{
    // Given

    D2Q9Distribution distribution;
    const double expectedDensity{0.0};

    // When

    const double density{distribution.computeDensity()};

    // Then

    EXPECT_EQ(density, expectedDensity);
}

TEST(DefaultD2Q9DistributionTest, DefaultMomentumEqualsZeroVector)
{
    // Given

    D2Q9Distribution distribution;
    const std::array<double, 2> expectedMomentum{0.0, 0.0};

    // When

    const std::array<double, 2> momentum{distribution.computeMomentum()};

    // Then

    EXPECT_EQ(momentum, expectedMomentum);
}

TEST(DefaultD2Q9DistributionTest, DefaultVelocityEqualsZeroVector)
{
    // Given

    D2Q9Distribution distribution;
    const std::array<double, 2> expectedVelocity{0.0, 0.0};

    // When

    const double density{distribution.computeDensity()};
    const std::array<double, 2> momentum{distribution.computeMomentum()};
    const std::array<double, 2> velocity{D2Q9Distribution::computeVelocity(density, momentum)};

    // Then

    EXPECT_EQ(velocity, expectedVelocity);
}

TEST_F(D2Q9DistributionTest, NonUniformDistributionEqualsSetValues)
{
    // Given

    const int size{9};
    const std::array<double, size> expectedValue{1.0 / 3.0, 2.0 / 4.0,  3.0 / 5.0,
                                                 4.0 / 6.0, 5.0 / 7.0,  6.0 / 8.0,
                                                 7.0 / 9.0, 8.0 / 10.0, 9.0 / 11.0};

    // When

    // Then

    for (int i = 0; i < size; i++)
    {
        EXPECT_EQ(distribution[i], expectedValue.at(i));
    }
}

TEST_F(D2Q9DistributionTest, NonDefaultDensityEqualsDistributionZerothMoment)
{
    // Given

    const double expectedDensity{5.9602453102453108};

    // When

    const double density{distribution.computeDensity()};

    // Then

    EXPECT_NEAR(density, expectedDensity, 1e-15);
}

TEST_F(D2Q9DistributionTest, NonDefaultMomentumEqualsDistributionFirstMoment)
{
    // Given

    const std::array<double, 2> expectedMomentum{-0.17626262626262612, -0.2046897546897548};

    // When

    const std::array<double, 2> momentum{distribution.computeMomentum()};

    // Then

    EXPECT_NEAR(momentum[0], expectedMomentum[0], 1e-15);
    EXPECT_NEAR(momentum[1], expectedMomentum[1], 1e-15);
}

TEST_F(D2Q9DistributionTest, NonDefaultVelocityEqualsDistributionFirstMomentDividedbyZerothMoment)
{
    // Given

    const double density{distribution.computeDensity()};
    const std::array<double, 2> momentum{distribution.computeMomentum()};
    const std::array<double, 2> expectedVelocity{-0.029573048941398609, -0.034342505053928767};

    // When

    const std::array<double, 2> velocity{D2Q9Distribution::computeVelocity(density, momentum)};

    // Then

    EXPECT_NEAR(velocity[0], expectedVelocity[0], 1e-15);
    EXPECT_NEAR(velocity[1], expectedVelocity[1], 1e-15);
}
