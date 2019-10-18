#pragma once
#include <memory>
#include <queue>
#include <thread>
#include <functional>
#include "task.hpp"
#include "mutex_action.hpp"

class task_list{
    mutex_action mutex_thread;
    mutex_action mutex_queue;
    std::unique_ptr<std::thread> task_thread;
    std::queue<task> task_queue;
    void loop();
public:
    task_list& add(std::function <void()> functor);
 }; 