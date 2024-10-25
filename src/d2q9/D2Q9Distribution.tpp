#ifndef D2Q9_DISTRIBUTION_TPP
#define D2Q9_DISTRIBUTION_TPP

;
#include "D2Q9Distribution.hpp"
#include <limits>
#include <numeric>

D2Q9Distribution::D2Q9Distribution() : distribution_{0.0} {}

auto D2Q9Distribution::operator[](int index) -> double&
{
    return distribution_.at(index);
}

constexpr auto D2Q9Distribution::dimension() -> std::size_t
{
    return D2Q9Distribution::dimension_;
}

constexpr auto D2Q9Distribution::size() -> std::size_t
{
    return D2Q9Distribution::size_;
}

auto D2Q9Distribution::computeDensity() const -> double
{
    double density{std::reduce(distribution_.begin(), distribution_.end())};
    return density;
}

auto D2Q9Distribution::computeMomentum() const -> std::array<double, 2>
{
    std::array<double, 2> momentum{
        (distribution_[D2Q9Distribution::right] + distribution_[D2Q9Distribution::topRight] +
         distribution_[D2Q9Distribution::bottomRight]) -
            (distribution_[D2Q9Distribution::left] + distribution_[D2Q9Distribution::topLeft] +
             distribution_[D2Q9Distribution::bottomLeft]),
        (distribution_[D2Q9Distribution::top] + distribution_[D2Q9Distribution::topRight] +
         distribution_[D2Q9Distribution::topLeft]) -
            (distribution_[D2Q9Distribution::bottom] + distribution_[D2Q9Distribution::bottomLeft] +
             distribution_[D2Q9Distribution::bottomRight])
    };

    return momentum;
}

auto D2Q9Distribution::computeVelocity(const double& density, const std::array<double, 2>& momentum)
    -> std::array<double, 2>
{
    std::array<double, 2> velocity{
        momentum[0] / (density + std::numeric_limits<double>::epsilon()),
        momentum[1] / (density + std::numeric_limits<double>::epsilon())
    };

    return velocity;
}

#endif // D2Q9_DISTRIBUTION_TPP
