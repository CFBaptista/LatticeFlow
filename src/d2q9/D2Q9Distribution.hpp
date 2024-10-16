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

        int size() const
        {
            return distribution.size();
        }

    private:
        std::array<double, 9> distribution;
};
