#ifndef SINGLETON_H
#define SINGLETON_H

#include <memory>

using namespace std;
template <typename T>
class Singleton {
protected:
    Singleton() = default;
    Singleton(const Singleton<T>&) = delete;
    Singleton& operator=(const Singleton<T>& st) = delete;

    static std::shared_ptr<T> _instance;
public:
    static std::shared_ptr<T> GetInstance();
    void PrintAddress();
    ~Singleton();
};

#endif // SINGLETON_H
