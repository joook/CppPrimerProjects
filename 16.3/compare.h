#ifndef _COMPARE_H_
#define _COMPARE_H_

template <typename T>
bool compare(const T& a, const T& b)
{
    if (a < b)
    {
        return false;
    }
    else if (b < a)
    {
        return false;
    }
    else
    {
        return true;
    }
}

#endif
