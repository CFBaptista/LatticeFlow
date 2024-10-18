#include <gtest/gtest.h>
#include "../../src/d2q9/D2Q9Distribution.hpp"

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
    const double expectedValue{0.0};

    // When

    // Then

    for (int i = 0; i < 9; i++)
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

    const double density{distribution.density()};

    // Then

    EXPECT_EQ(density, expectedDensity);
}

TEST(D2Q9Distribution, NonDefaultDensityEqualsSumOfDistribution)
{
    // Given

    D2Q9Distribution distribution;
    distribution[0] = 1.0 / 3.0;
    distribution[1] = 2.0 / 4.0;
    distribution[2] = 3.0 / 5.0;
    distribution[3] = 4.0 / 6.0;
    distribution[4] = 5.0 / 7.0;
    distribution[5] = 6.0 / 8.0;
    distribution[6] = 7.0 / 9.0;
    distribution[7] = 8.0 / 10.0;
    distribution[8] = 9.0 / 11.0;
    const double expectedDensity{5.9602453102453108};
    
    // When

    const double density{distribution.density()};

    // Then

    EXPECT_NEAR(density, expectedDensity, 1e-15);
}

TEST(D2Q9Distribution, DefaultMomentumEqualsZeroVector)
{
    // Given

    D2Q9Distribution distribution;
    const std::array<double, 2> expectedMomentum{0.0, 0.0};

    // When

    const std::array<double, 2> momentum{distribution.momentum()};

    // Then

    EXPECT_EQ(momentum, expectedMomentum);
}

TEST(D2Q9Distribution, NonDefaultMomentumEqualsComputedMomentum)
{
    // Given

    D2Q9Distribution distribution;
    distribution[0] = 1.0 / 3.0;
    distribution[1] = 2.0 / 4.0;
    distribution[2] = 3.0 / 5.0;
    distribution[3] = 4.0 / 6.0;
    distribution[4] = 5.0 / 7.0;
    distribution[5] = 6.0 / 8.0;
    distribution[6] = 7.0 / 9.0;
    distribution[7] = 8.0 / 10.0;
    distribution[8] = 9.0 / 11.0;

    const std::array<double, 2> expectedMomentum{-0.17626262626262612, -0.2046897546897548};

    // When

    const std::array<double, 2> momentum{distribution.momentum()};

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

    const double density{distribution.density()};
    const std::array<double, 2> momentum{distribution.momentum()};
    const std::array<double, 2> velocity{distribution.velocity(density, momentum)};

    // Then

    EXPECT_EQ(velocity, expectedVelocity);
}

TEST(D2Q9Distribution, NonDefaultVelocityEqualsComputedVelocity)
{
    // Given

    D2Q9Distribution distribution;
    distribution[0] = 1.0 / 3.0;
    distribution[1] = 2.0 / 4.0;
    distribution[2] = 3.0 / 5.0;
    distribution[3] = 4.0 / 6.0;
    distribution[4] = 5.0 / 7.0;
    distribution[5] = 6.0 / 8.0;
    distribution[6] = 7.0 / 9.0;
    distribution[7] = 8.0 / 10.0;
    distribution[8] = 9.0 / 11.0;

    const std::array<double, 2> expectedVelocity{-0.029573048941398609, -0.034342505053928767};

    // When

    const double density{distribution.density()};
    const std::array<double, 2> momentum{distribution.momentum()};
    const std::array<double, 2> velocity{distribution.velocity(density, momentum)};

    // Then

    EXPECT_NEAR(velocity[0], expectedVelocity[0], 1e-15);
    EXPECT_NEAR(velocity[1], expectedVelocity[1], 1e-15);
}
