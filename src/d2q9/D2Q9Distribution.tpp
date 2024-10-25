#ifndef D2Q9_DISTRIBUTION_TPP
#define D2Q9_DISTRIBUTION_TPP

;
#include "D2Q9Distribution.hpp"
#include <limits>
#include <numeric>

template <typename Scalar>
D2Q9Distribution<Scalar>::D2Q9Distribution() : distribution_{0.0}
{
}

template <typename Scalar>
auto D2Q9Distribution<Scalar>::operator[](int index) -> Scalar&
{
    return distribution_.at(index);
}

template <typename Scalar>
constexpr auto D2Q9Distribution<Scalar>::dimension() -> std::size_t
{
    return D2Q9Distribution::dimension_;
}

template <typename Scalar>
constexpr auto D2Q9Distribution<Scalar>::size() -> std::size_t
{
    return D2Q9Distribution::size_;
}

template <typename Scalar>
auto D2Q9Distribution<Scalar>::computeDensity() const -> Scalar
{
    Scalar density{std::reduce(distribution_.begin(), distribution_.end())};
    return density;
}

template <typename Scalar>
auto D2Q9Distribution<Scalar>::computeMomentum() const -> std::array<Scalar, 2>
{
    const Scalar momentumX =
        (distribution_[D2Q9Distribution::right] + distribution_[D2Q9Distribution::topRight] +
         distribution_[D2Q9Distribution::bottomRight]) -
        (distribution_[D2Q9Distribution::left] + distribution_[D2Q9Distribution::topLeft] +
         distribution_[D2Q9Distribution::bottomLeft]);
    const Scalar momentumY =
        (distribution_[D2Q9Distribution::top] + distribution_[D2Q9Distribution::topRight] +
         distribution_[D2Q9Distribution::topLeft]) -
        (distribution_[D2Q9Distribution::bottom] + distribution_[D2Q9Distribution::bottomLeft] +
         distribution_[D2Q9Distribution::bottomRight]);
    std::array<Scalar, 2> momentum{momentumX, momentumY};

    return momentum;
}

template <typename Scalar>
auto D2Q9Distribution<Scalar>::computeVelocity(
    const Scalar& density,
    const std::array<Scalar, 2>& momentum
) -> std::array<Scalar, 2>
{
    const Scalar densityEpsilon = density + std::numeric_limits<Scalar>::epsilon();
    std::array<Scalar, 2> velocity{momentum[0] / densityEpsilon, momentum[1] / densityEpsilon};

    return velocity;
}

#endif // D2Q9_DISTRIBUTION_TPP
