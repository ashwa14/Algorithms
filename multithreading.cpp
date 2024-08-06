#include <iostream>
/* The `#include <thread>` and `#include <unistd.h>` are preprocessor directives that include the
necessary header files for using threads and the `sleep()` function in C++. */
#include <thread>
#include <unistd.h>

using namespace std;

void taskA()
{
    for (int i = 0; i < 10; i++)
    {
        sleep(1);
        cout << "Task A" << i << endl;
        /* `fflush(stdout);` is used to flush the output buffer associated with the standard output
        stream (`stdout`). */
        fflush(stdout);
    }
}

void taskB()
{
    for (int i = 0; i < 10; i++)
    {
        /* The `sleep(1);` function is causing the program to pause for 1 second before executing the
        next line of code. */
        sleep(1);
        cout << "Task B" << i << endl;
        fflush(stdout);
    }
}

int main()
{
    thread t1(taskA);
    thread t2(taskB);

    /* The `t1.join()` and `t2.join()` functions are used to wait for the completion of the threads `t1`
    and `t2` respectively.
    If we don't write the below 2 lines of code, then the program will terminate before the completion
    */
    t1.join();
    t2.join();

    return 0;
}