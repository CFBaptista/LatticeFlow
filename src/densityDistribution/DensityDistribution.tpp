#ifndef DENSITY_DISTRIBUTION_TPP
#define DENSITY_DISTRIBUTION_TPP

;
#include "DensityDistribution.hpp"

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
DensityDistribution<Dimension, Size, Scalar>::DensityDistribution() : distribution_{0.0}
{
}

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
DensityDistribution<Dimension, Size, Scalar>::DensityDistribution(
    std::initializer_list<Scalar> distribution
)
{
    std::copy(distribution.begin(), distribution.end(), distribution_.begin());
}

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto DensityDistribution<Dimension, Size, Scalar>::operator[](std::size_t index) -> Scalar&
{
    return distribution_.at(index);
}

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto DensityDistribution<Dimension, Size, Scalar>::operator[](std::size_t index
) const -> const Scalar&
{
    return distribution_.at(index);
}

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto DensityDistribution<Dimension, Size, Scalar>::begin() -> std::array<Scalar, Size>::iterator
{
    return distribution_.begin();
}

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto DensityDistribution<Dimension, Size, Scalar>::begin() const
    -> std::array<Scalar, Size>::const_iterator
{
    return distribution_.begin();
}

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto DensityDistribution<Dimension, Size, Scalar>::end() -> std::array<Scalar, Size>::iterator
{
    return distribution_.end();
}

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto DensityDistribution<Dimension, Size, Scalar>::end() const
    -> std::array<Scalar, Size>::const_iterator
{
    return distribution_.end();
}

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto DensityDistribution<Dimension, Size, Scalar>::cbegin() const
    -> std::array<Scalar, Size>::const_iterator
{
    return distribution_.cbegin();
}

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto DensityDistribution<Dimension, Size, Scalar>::cend() const
    -> std::array<Scalar, Size>::const_iterator
{
    return distribution_.cend();
}

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
constexpr auto DensityDistribution<Dimension, Size, Scalar>::dimension() const -> std::size_t
{
    return Dimension;
}

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
constexpr auto DensityDistribution<Dimension, Size, Scalar>::size() const -> std::size_t
{
    return Size;
}

#endif // DENSITY_DISTRIBUTION_TPP
