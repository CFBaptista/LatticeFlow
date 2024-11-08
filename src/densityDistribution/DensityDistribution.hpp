#ifndef DENSITY_DISTRIBUTION_HPP
#define DENSITY_DISTRIBUTION_HPP

#include <array>
#include <concepts>

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
class DensityDistribution
{
public:
    DensityDistribution();
    DensityDistribution(std::initializer_list<Scalar> distribution);

    auto operator[](std::size_t index) -> Scalar&;
    auto operator[](std::size_t index) const -> const Scalar&;

    constexpr auto dimension() const -> std::size_t;
    constexpr auto size() const -> std::size_t;
    static auto weight(std::size_t index) -> const Scalar&;

    static auto
    computeVelocity(const Scalar& density, const std::array<Scalar, Dimension>& momentum)
        -> std::array<Scalar, Dimension>;

    auto computeDensity() const -> Scalar;
    auto computeMomentum() const -> std::array<Scalar, Dimension>;

private:
    static constexpr auto setWeights_() -> std::array<Scalar, Size>;

    static constexpr std::size_t center_{0};
    static constexpr std::size_t right_{1};
    static constexpr std::size_t top_{2};
    static constexpr std::size_t left_{3};
    static constexpr std::size_t bottom_{4};
    static constexpr std::size_t topRight_{5};
    static constexpr std::size_t topLeft_{6};
    static constexpr std::size_t bottomLeft_{7};
    static constexpr std::size_t bottomRight_{8};

    static constexpr std::array<Scalar, Size> weight_{setWeights_()};

    std::array<Scalar, Size> distribution_;
};

#include "DensityDistribution.tpp"

#endif // DENSITY_DISTRIBUTION_HPP
