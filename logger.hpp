#pragma once
#include "mutex_action.hpp"
#include "task_list.h"
#include <iostream>

 template<class... Args>
 void logger(Args... args){
    static mutex_action log_mutex;
    static task_list log_queue;
    log_mutex([&log_queue, args...]{
        log_queue.add([args...] { printf(args...); });
    });
}
