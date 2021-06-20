#ifndef _ADD_H_
#define _ADD_H_

template <typename T>
T add_without_expand(const T& num1, const T& num2)
{
    return (num1 + num2);
}

template <typename T, typename U>
auto add_with_expand(const T& num1, const U& num2) -> decltype(num1 + num2)
{
    return (num1 + num2);
}

#endif
