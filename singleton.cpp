#include "singleton.h"
#include <iostream>
#include <mutex>

template <typename T>
std::shared_ptr<T> Singleton<T>::GetInstance() {
    static std::once_flag s_flag;
    std::call_once(s_flag, [&]() {
        _instance = shared_ptr<T>(new T);
    });

    return _instance;
}

template <typename T>
void Singleton<T>::PrintAddress() {
    std::cout << _instance.get() << endl;
}
template <typename T>
Singleton<T>::~Singleton() {
    std::cout << "this is singleton destruct" << std::endl;
}

template <typename T>
std::shared_ptr<T> Singleton<T>::_instance = nullptr;
