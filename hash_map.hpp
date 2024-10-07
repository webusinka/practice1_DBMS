#pragma once

#include "hash_node.hpp"
#include "hash_function.hpp"
#include <cstddef>
#include <iostream>

template <typename Key, typename Value, unsigned long table_size,typename Hash_func = Hash_function<Key>>
class Hash_map
{
public:
    Hash_map(){
        for (int i = 0; i < table_size; i++) {
            table[i] = nullptr;
        }    
    }

    ~Hash_map()
    {
        for (unsigned long i = 0; i < table_size; i++) {
            Hash_node<Key, Value> *entry = table[i];
            while (entry != nullptr) {
                Hash_node<Key, Value> *prev = entry;
                entry = entry->get_next();
                delete prev;

            }
        }
    }

    Value get_value(const Key &key) {
        unsigned long hash_value = hash(key, table_size);
        Hash_node<Key, Value>* entry = table[hash_value];

        while (entry != nullptr) {
            if (entry->get_key() == key) {
                return entry->get_value();
            }
            entry = entry->get_next();
        }
        return Value();
    }

    void insert(const Key &key, const Value &value)
    {
        unsigned long hash_value = hash(key, table_size);
        Hash_node<Key, Value> *prev = nullptr;
        Hash_node<Key, Value> *entry = table[hash_value];

        while (entry != nullptr) {
            if(entry->get_key() != key){
                continue;
            }
            prev = entry;
            entry = entry->get_next();  
        }

        if (entry == nullptr) {
            entry = new Hash_node<Key, Value>(key, value);
            capacity_size++;
            if (prev == nullptr) {
                table[hash_value] = entry;

            } else {
                prev->set_next(entry);
            }
        }
    }

    void remove(const Key &key)
    {
        unsigned long hash_value = hash(key, table_size);
        Hash_node<Key, Value> *prev = nullptr;
        Hash_node<Key, Value> *entry = table[hash_value];

        while (entry != nullptr && entry->get_key() != key) {
            prev = entry;
            entry = entry->get_next();
        }

        if (entry == nullptr) {
            return;

        } else {
            if (prev == nullptr) {
                table[hash_value] = entry->get_next();

            } else {
                prev->set_next(entry->get_next());
            }

            capacity_size--;
            delete entry;
        }
    }
    Hash_node<Key, Value>* table[table_size];
    Hash_func hash;
    int capacity_size = 0;
};