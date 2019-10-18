#pragma once
#include <mutex>
#include <functional>

class mutex_action{
    std::mutex _mutex;
public:
    void operator()(std::function<void()> action){
        while(_mutex.try_lock()==false);
        action();
        _mutex.unlock();
    }
};