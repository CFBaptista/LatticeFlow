#ifndef D2Q9_DISTRIBUTION_HPP
#define D2Q9_DISTRIBUTION_HPP

#include <array>
#include <numeric>
#include <limits>

class D2Q9Distribution
{
    public:
        D2Q9Distribution();

        double& operator[](int index);

        constexpr std::size_t dimension() const;
        constexpr std::size_t size() const;

        double density() const;
        std::array<double, 2> momentum() const;
        std::array<double, 2> velocity(const double& density, const std::array<double, 2>& momentum) const;

    private:
        static const std::size_t dimension_ = 2;
        static const std::size_t size_ = 9;
        
        std::array<double, 9> distribution_;
};

#include "D2Q9Distribution.tpp"

#endif // D2Q9_DISTRIBUTION_HPP
