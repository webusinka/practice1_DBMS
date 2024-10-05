#pragma once

#include "List.hpp"
#include "hash_map.hpp"

class Table;
class Data_base{
public:
    LinkedList<Table&> tables;
};
class Table{
    public:
    Table(std::string _name, LinkedList<std::string> _columns) : table_name(_name), 
                    columns(_columns) {}
    ~Table() = default;
    void load_data(LinkedList<int> keys,LinkedList<std::string>* rows);
    std::string table_name;
    LinkedList<std::string> columns;
    Hash_map<int, LinkedList<std::string>, 1000> table;
};