#include "fact.h"

int factorial(int val)
{
    if(val > 1)
        return factorial(val - 1) * val;
    return 1;
}
