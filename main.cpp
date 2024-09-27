#include "vector.hpp"
#include "pair.hpp"
#include "hash_map.hpp"

#include <string>
#include <iostream>
int main(){

    Vector<Pair<int,int>> v;
    Pair<int, int> p1(1, 1);
    Pair<int, int> p2(2, 2);
    Pair<int, int> p3(3, 3); 
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    std::cout << v.getSize() << std::endl;
    std::cout << v[2].get_second() << std::endl;
    Hash_map<int, int, 1> aboba;

    aboba.insert(1, 1);
    int val = 1239;
    aboba.get_value(1, val);
    std::cout << val  << std::endl;

    int key = 1;
    aboba.remove(key);

    val = 2229;
    aboba.get_value(1, val);
    std::cout << val  << std::endl;
}