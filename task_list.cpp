#include "mutex_action.hpp"
#include "task_list.h"

void task_list::loop(){
    do{      
        mutex_queue([this]{
            task_queue.front()();
            task_queue.pop();
        });
    }while(!task_queue.empty());

    mutex_thread([this]{
        task_thread.release();
    });
}

task_list& task_list::add(std::function <void()> functor){
    mutex_queue([this,functor]{
        task_queue.push(task(functor));
    });

    if(!task_thread){
        mutex_thread([this]{
            task_thread.reset(new std::thread(&task_list::loop,this));
        });
    }
    return *this;
}
