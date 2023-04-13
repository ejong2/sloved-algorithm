#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>
#include <cmath>

std::mutex countMutex;
unsigned long long primeCount = 0;

bool isPrime(unsigned long long number)
{
    if (number <= 1) return false;
    if (number == 2 || number == 3) return true;
    if (number % 2 == 0) return false;

    unsigned long long sqrtNumber = static_cast<unsigned long long>(std::sqrt(number));
    for (unsigned long long i = 3; i <= sqrtNumber; i += 2)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}

void findPrimes(unsigned long long start, unsigned long long end)
{
    for (unsigned long long i = start; i <= end; ++i)
    {
        if (isPrime(i))
        {
            // 소수를 찾으면 뮤텍스로 보호된 공유 변수 primeCount를 증가시킵니다.
            std::unique_lock<std::mutex> lock(countMutex);
            primeCount++;
        }
    }
}

int main()
{
    unsigned long long maxNumber = 10000000; // 찾고자 하는 소수의 최대 범위
    int numThreads = std::thread::hardware_concurrency(); // 사용할 스레드 개수

    // 멀티 스레드 사용
    std::vector<std::thread> threads;
    unsigned long long range = maxNumber / numThreads;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numThreads; ++i)
    {
        unsigned long long start = (range * i) + 1;
        unsigned long long end = (i == numThreads - 1) ? maxNumber : range * (i + 1);
        threads.push_back(std::thread(findPrimes, start, end));
    }
    for (auto& thread : threads)
    {
        thread.join();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "멀티 스레드를 사용한 경우 소수 개수: " << primeCount << ", 경과 시간: " << duration << "ms" << std::endl;

    // 멀티 스레드 사용하지 않음
    primeCount = 0;
    start = std::chrono::high_resolution_clock::now();
    findPrimes(1, maxNumber);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "멀티 스레드를 사용하지 않은 경우 소수 개수: " << primeCount << ", 경과 시간: " << duration << "ms" << std::endl;

    return 0;
}