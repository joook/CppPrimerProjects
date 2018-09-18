#include "plus.h"

int numplus()
{
    static int i = 0;
    i++;
    return i;
}
