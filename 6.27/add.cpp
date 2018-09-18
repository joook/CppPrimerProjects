#include "add.h"

float add(std::initializer_list<float> nums)
{
    float sum;
    for(auto it = nums.begin(); it != nums.end(); it++)
    {
        sum += *it;
    }
    return sum;
}
