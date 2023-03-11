#include <iostream>
#include <list>
#include <thread>
#include <mutex>
#include <Windows.h>
#include <future>

std::list<int> g_Data;
std::mutex g_Mutex;

void Download(const std::string& file)
{
    std::cout << "[Downloader] started download" << file << std::endl;
    for (int i = 0; i < 100000; ++i)
    {
        std::lock_guard<std::mutex> mtx(g_Mutex);
        g_Data.push_back(i);
    }
    std::cout << "[Download]Finsihed download" << std::endl;
}

void Download1(const std::string& file)
{
    std::cout << "[Downloader] started download" << file << std::endl;
    for (int i = 0; i < 100000; ++i)
    {
        std::lock_guard<std::mutex> mtx(g_Mutex);
        g_Data.push_back(i);
    }
    std::cout << "[Download]Finsihed download" << std::endl;
}

void Detach()
{
    std::string file{ "cppcast.mp4" };
    std::cout << "[main] User started an operation" << std::endl;
    std::thread thDownloader(Download, std::cref(file));
    thDownloader.detach();

    std::cout << "[main] User started another operation" << std::endl;

    if (thDownloader.joinable())
    {
        thDownloader.join();
    }
}

void Mutex()
{
    std::string file{ "cppcast.mp4" };
    std::thread thDownloader(Download, std::cref(file));
    std::thread thDownloader2(Download1, std::cref(file));

    thDownloader.join();
    thDownloader2.join();

    std::cout << g_Data.size() << std::endl;
}

void Process()
{
    std::cout << std::this_thread::get_id() << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << i << " ";
    }
}

void ThreadFunction()
{
    std::thread t1(Process);
    auto id = t1.get_id();
    std::cout << id << std::endl;
    HANDLE handle = t1.native_handle();
    SetThreadDescription(handle, L"MyThread");

    int cores = std::thread::hardware_concurrency();
    std::cout << "Cores:" << cores << std::endl;
    t1.join();
}

void Downloader1()
{
    using namespace std::chrono_literals;
    for (int i = 0; i < 10; ++i)
    {
        std::cout << '.';
        std::this_thread::sleep_for(300ms);
    }
}

void TaskBasedConcurrency()
{
    std::future<void> result = std::async(Downloader1);
    std::cout << "main() threading continues execution...\n";
    result.get();
}

int Operation(int count)
{
    using namespace std::chrono_literals;
    int sum{};
    for (int i = 0; i < count; ++i)
    {
        sum += 1;
        std::cout << '.';
        std::this_thread::sleep_for(300ms);
    }
    return sum;
}

void LaunchPolicies()
{
    using namespace std::chrono_literals;
    std::future<int> result = std::async(std::launch::async,
        Operation, 10);
    std::this_thread::sleep_for(1s);
    std::cout << "main() thread cntinues exectuion..." << std::endl;;
    if (result.valid())
    {
        auto timepoint = std::chrono::system_clock::now();
        timepoint += 1s;
        auto status = result.wait_until(timepoint);
        status = result.wait_for(1s);
        switch (status)
        {
        case std::future_status::ready:
            break;
        case std::future_status::timeout:
            break;
        case std::future_status::deferred:
            break;
        default:
            break;
        }
        result.wait();
        auto sum = result.get();
        std::cout << sum << std::endl;
    }
}

int Operation1(std::promise<int>& data)
{
    try
    {
        auto f = data.get_future();
        auto count = f.get();
        std::cout << count << std::endl;
        return count;
    }
    catch (std::exception& ex)
    {
        std::cout << "[Task] Exception:" << ex.what() << std::endl;
        return 0;
    }
}

void Promise()
{
    using namespace std::chrono_literals;
    std::promise<int> data;
    std::future<int> result = std::async(std::launch::async, Operation1, std::ref(data));
    std::cout << "[main] setting";
    std::this_thread::sleep_for(1s);
    try {
        throw std::runtime_error("Data not available");
        data.set_value(10);
    }
    catch (std::exception& ex)
    {
        data.set_exception(std::make_exception_ptr(ex));
    }
}

int main()
{
    Promise();
}