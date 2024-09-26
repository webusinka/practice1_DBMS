#pragma once

template<typename T1, typename T2>
class Pair {
public:
    Pair();
    Pair(const T1& first, const T2& second);
    ~Pair() = default;

    T1& get_first();
    T2& get_second();

private:
    T1 first;
    T2 second;
};  

template<typename T1, typename T2>
Pair<T1,T2>::Pair(){}

template<typename T1, typename T2>
Pair<T1,T2>::Pair(const T1& first, const T2& second): 
    first(first), second(second) {}

template<typename T1, typename T2>
T1& Pair<T1,T2>::get_first() {
    return first;
}

template<typename T1, typename T2>
T2& Pair<T1,T2>::get_second() {
    return second;
}