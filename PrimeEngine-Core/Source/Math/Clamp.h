#pragma once

namespace Prime::Math
{
    class Clamp
    {
    public:
        static int ClampValue(int value, int max, int min)
        {
            if(value >= max)
            {
                return max;
            }

            if(value <= min)
            {
                return min;
            }

            else
            {
                return value;
            }
        }
    };
}


