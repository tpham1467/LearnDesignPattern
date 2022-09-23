#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
class Example
{
public:
    string name;
    Example(string name)
    {
        this->name = name;
    }

private:
    static Example *Instance;
    static std::mutex mutex_;

public:
    static Example *GetSingleton(string name)
    {
        std::lock_guard<std::mutex> lock(mutex_);
        if (Instance == nullptr)
        {
            Instance = new Example(name);
        }
        return Instance;
    }
    void Show()
    {
        cout << name;
    }
    Example(Example &other) = delete;
    void operator=(const Example &) = delete;
};
mutex Example::mutex_;
Example *Example::Instance = nullptr;

void ThreadFoo()
{
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Example::GetSingleton("A")->Show();
}

void ThreadBar()
{
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Example::GetSingleton("B")->Show();
}
int main()
{
    thread t1(ThreadFoo);
    thread t2(ThreadBar);
    t1.join();
    t2.join();
}