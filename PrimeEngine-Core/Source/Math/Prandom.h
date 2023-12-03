#pragma once
#include <random>

namespace Prime::Math
{
    class Prandom
    {
    public:
        static int GetRandomIntInRange(int min, int max)
        {
            std::random_device rd;
            std::mt19937 eng(rd());
            
            std::uniform_int_distribution distr(min, max);

            return distr(eng);
        }
        
    };
}


