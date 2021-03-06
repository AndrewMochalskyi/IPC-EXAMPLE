#include <iostream>
#include <chrono>
#include <thread>
#include <string>

#include <sys/ipc.h>
#include <sys/shm.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

void increment(int *number, const int period);

int main(int argc, char *argv[])
{
    if(argc < 3)
        return -1;

    std::cout << "Hello from child" << std::endl;
    const std::string str_key = argv[1];
    const std::string str_period = argv[2];
    const int period = std::stoi(str_period);
    const key_t key = std::stoi(str_key);
    if(key == -1)
        return -1;

    const int shmid = shmget(key, sizeof(int), 0666|IPC_CREAT);
    if(shmid == -1)
        return -1;

    int *counter = (int*) shmat(shmid,(void*)0,0);
    if (counter == (int *) -1)
		    return -1;
            
    std::thread increment_thread(increment, counter, period);

    while(1)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "Counter = " << (*counter) << std::endl;
    }

    increment_thread.detach();
    return 0;
}

void increment(int *number, const int period)
{   
    for(;;)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(period));
        (*number)++;
    }
}
