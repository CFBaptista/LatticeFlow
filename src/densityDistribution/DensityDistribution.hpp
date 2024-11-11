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
    auto begin() -> std::array<Scalar, Size>::iterator;
    auto begin() const -> std::array<Scalar, Size>::const_iterator;
    auto end() -> std::array<Scalar, Size>::iterator;
    auto end() const -> std::array<Scalar, Size>::const_iterator;
    auto cbegin() const -> std::array<Scalar, Size>::const_iterator;
    auto cend() const -> std::array<Scalar, Size>::const_iterator;

    constexpr auto dimension() const -> std::size_t;
    constexpr auto size() const -> std::size_t;

    static auto weight(std::size_t index) -> const Scalar&;

private:
    static constexpr auto setWeights_() -> std::array<Scalar, Size>;

    static constexpr std::array<Scalar, Size> weight_{setWeights_()};

    std::array<Scalar, Size> distribution_;
};

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
constexpr auto defineWeights() -> std::array<Scalar, Size>;

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto computeDensity(const DensityDistribution<Dimension, Size, Scalar>& distribution) -> Scalar;

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto computeMomentum(const DensityDistribution<Dimension, Size, Scalar>& distribution
) -> std::array<Scalar, Dimension>;

#include "DensityDistribution.tpp"

#endif // DENSITY_DISTRIBUTION_HPP
