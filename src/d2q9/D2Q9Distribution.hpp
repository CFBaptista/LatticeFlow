#include <array>

class D2Q9Distribution
{
    public:
        D2Q9Distribution() :
            distribution{0.0}
        {
        }

        double& operator[](int index)
        {
            return distribution[index];
        }


        constexpr std::size_t dimension() const
        {
            return D2Q9Distribution::dimension_;
        }

        constexpr std::size_t size() const
        {
            return D2Q9Distribution::size_;
        }

    private:
        static const std::size_t dimension_ = 2;
        static const std::size_t size_ = 9;
        
        std::array<double, 9> distribution;
};
