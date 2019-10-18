#include <iostream>
#include <functional>
#include <string>
#include "task_list.h"
#include "logger.hpp"
#include "mutex_action.hpp"

using namespace std;

int c = 0;
mutex_action m;
void inc(){
    m([]{
        ++c;
    });
}
int get(){
    int o;
    m([&o]{
        o=c;
    });
    return o;
}
task_list t;

int main(){
    function <void()> first = [](){
        inc();
        logger("first: %i\n",get());
    };
    function <void()> second = [](){
        inc();
        logger("second: %i\n",get());
    };
    

   t.add(first)
    .add(first)
    .add(first)
    .add(second)
    .add(second)
    .add(first)
    .add(first)
    .add(second)
    .add(second);
   t.add(first)
    .add(first)
    .add(first)
    .add(second)
    .add(second)
    .add(first)
    .add(first)
    .add(second)
    .add(second);
   t.add(first)
    .add(first)
    .add(first)
    .add(second)
    .add(second)
    .add(first)
    .add(first)
    .add(second)
    .add(second);
    this_thread::sleep_for(std::chrono::seconds(1));
    return 0;
}