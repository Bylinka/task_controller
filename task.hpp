#pragma once
#include <functional>

class task{
    std::function <void()> functor;
public:
    task(std::function <void()> functor) : functor(functor) {};
    void operator()(){
        functor();
    }
};