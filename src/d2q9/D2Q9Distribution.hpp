#ifndef D2Q9_DISTRIBUTION_HPP
#define D2Q9_DISTRIBUTION_HPP

#include <array>
class D2Q9Distribution
{
public:
    D2Q9Distribution();

    auto operator[](int index) -> double&;

    constexpr auto dimension() const -> std::size_t;
    constexpr auto size() const -> std::size_t;

    auto density() const -> double;
    auto momentum() const -> std::array<double, 2>;
    auto velocity(const double& density, const std::array<double, 2>& momentum) const
        -> std::array<double, 2>;

private:
    static const std::size_t dimension_ = 2;
    static const std::size_t size_ = 9;

    std::array<double, D2Q9Distribution::size_> distribution_;
};

#include "D2Q9Distribution.tpp"

#endif // D2Q9_DISTRIBUTION_HPP
