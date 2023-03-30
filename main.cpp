#include <iostream>
#include "Backstage_task.h"

void cs()
{
    std::cout << "\n运行一次\n";
}


int main(int argc, const char** argv)
{
    int _pid = fork();

    if (_pid > 0)
    {
        Backstage_task::get()->set_run_sleep(1);
        Backstage_task::get()->set_run_func(&cs);
        Backstage_task::get()->set_local_path("/tmp/Backstage_task");
        Backstage_task::get()->start();
        std::this_thread::sleep_for(std::chrono::seconds(15));
    }
    else 
    {
        std::this_thread::sleep_for(std::chrono::seconds(10));
        //Backstage_task::get()->set_run_sleep(1);
        //Backstage_task::get()->set_run_func(&cs);
        Backstage_task::get()->set_local_path("/tmp/Backstage_task");
        Backstage_task::get()->stop();
    }


    sleep(5);
    return 0;
}




