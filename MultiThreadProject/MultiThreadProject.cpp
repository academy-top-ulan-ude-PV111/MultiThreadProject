#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int cnt{};

mutex m;

void func()
{
    for (int i = 0; i < 100; i++)
        cout << this_thread::get_id() << " " << i << "\n";
}

void counter()
{
    for (int i = 0; i < 1000; i++)
    {
        lock_guard<mutex> lg(m);
        cout << this_thread::get_id() << " " << cnt << "\n";
        cnt++;   
    }
}

int main()
{
    thread th1(counter);
    thread th2(counter);


    th1.join();
    th2.join();

    cout << cnt;
}
