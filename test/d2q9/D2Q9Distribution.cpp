#include "../../src/d2q9/D2Q9Distribution.hpp"
#include <gtest/gtest.h>

TEST(D2Q9Distribution, DimensionEquals2)
{
    // Given

    D2Q9Distribution distribution;
    const int expectedDimension{2};

    // When

    // Then

    EXPECT_EQ(distribution.dimension(), expectedDimension);
}

TEST(D2Q9Distribution, SizeEquals9)
{
    // Given

    D2Q9Distribution distribution;
    const int expectedSize{9};

    // When

    // Then

    EXPECT_EQ(distribution.size(), expectedSize);
}

TEST(D2Q9Distribution, DefaultValueEquals0)
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

TEST(D2Q9Distribution, SetValue)
{
    // Given

    D2Q9Distribution distribution;
    const int index{3};
    const double expectedValue{3.14};

    // When

    distribution[index] = expectedValue;

    // Then

    EXPECT_EQ(distribution[index], expectedValue);
}

TEST(D2Q9Distribution, DefaultDensityEquals0)
{
    // Given

    D2Q9Distribution distribution;
    const double expectedDensity{0.0};

    // When

    const double density{distribution.computeDensity()};

    // Then

    EXPECT_EQ(density, expectedDensity);
}

TEST(D2Q9Distribution, NonDefaultDensityEqualsSumOfDistribution)
{
    // Given

    const int size{9};
    const double expectedDensity{5.9602453102453108};

    D2Q9Distribution distribution;
    for (int i = 0; i < size; i++)
    {
        distribution[i] = static_cast<double>(i + 1) / (i + 3);
    }

    // When

    const double density{distribution.computeDensity()};

    // Then

    EXPECT_NEAR(density, expectedDensity, 1e-15);
}

TEST(D2Q9Distribution, DefaultMomentumEqualsZeroVector)
{
    // Given

    D2Q9Distribution distribution;
    const std::array<double, 2> expectedMomentum{0.0, 0.0};

    // When

    const std::array<double, 2> momentum{distribution.computeMomentum()};

    // Then

    EXPECT_EQ(momentum, expectedMomentum);
}

TEST(D2Q9Distribution, NonDefaultMomentumEqualsComputedMomentum)
{
    // Given

    const int size{9};
    const std::array<double, 2> expectedMomentum{-0.17626262626262612, -0.2046897546897548};

    D2Q9Distribution distribution;
    for (int i = 0; i < size; i++)
    {
        distribution[i] = static_cast<double>(i + 1) / (i + 3);
    }
    // When

    const std::array<double, 2> momentum{distribution.computeMomentum()};

    // Then

    EXPECT_NEAR(momentum[0], expectedMomentum[0], 1e-15);
    EXPECT_NEAR(momentum[1], expectedMomentum[1], 1e-15);
}

TEST(D2Q9Distribution, DefaultVelocityEqualsZeroVector)
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

TEST(D2Q9Distribution, NonDefaultVelocityEqualsComputedVelocity)
{
    // Given

    const int size{9};

    D2Q9Distribution distribution;
    for (int i = 0; i < size; i++)
    {
        distribution[i] = static_cast<double>(i + 1) / (i + 3);
    }

    const std::array<double, 2> expectedVelocity{-0.029573048941398609, -0.034342505053928767};

    // When

    const double density{distribution.computeDensity()};
    const std::array<double, 2> momentum{distribution.computeMomentum()};
    const std::array<double, 2> velocity{D2Q9Distribution::computeVelocity(density, momentum)};

    // Then

    EXPECT_NEAR(velocity[0], expectedVelocity[0], 1e-15);
    EXPECT_NEAR(velocity[1], expectedVelocity[1], 1e-15);
}
