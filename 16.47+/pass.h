#ifndef _PASS_H_
#define _PASS_H_

#include <utility>

// correct pass template
template <typename F, typename T>
void pass(F func, T&& arg)
{
    func(std::forward<T>(arg));
}

// using this pass template, 
// you cannot calculate in the right way, if the func() requires a ref-of-lvalue parameter, 
// you cannot compile, if the func requires a (const-/non-const-)ref-of-rvalue parameter
template <typename F, typename T>
void passWithFlaw1(F func, T arg)
{
    func(arg);
}

// using this pass template, 
// you cannot compile, if the func() requires a (const-/non-const-)ref-of-rvalue parameter, 
// or if the func() requires a ref-of-lvalue parameter while the argument is a const-ref-of-lvalue
template <typename F, typename T>
void passWithFlaw2(F func, T& arg)
{
    func(arg);
}

// using this pass template, 
// you cannot compile, if the func() requires a (const-/non-const-)ref-of-rvalue parameter, 
// or if the func() requires a ref-of-lvalue parameter while the argument is a const-ref-of-lvalue
template <typename F, typename T>
void passWithFlaw3(F func, T&& arg)
{
    func(arg);
}

#endif

