#include "List.hpp"
#include "hash_map.hpp"
#include "hash_node.hpp"
#include "data_base.hpp"

#include <string>
#include <iostream>
int main(){
    LinkedList<std::string> columns;
    columns.push_back("hui");

    Table t1(std::string("table1"), columns);

    LinkedList<std::string> row1;
    row1.push_back("r1");
    row1.push_back("r1");

    LinkedList<std::string> row2;
    row2.push_back("r1");
    row2.push_back("r1");

    LinkedList<std::string>* rows[1];
    rows[0] = &row1;
   
    LinkedList<int> primary_keys;
    primary_keys.push_back(1);  

    t1.load_data(primary_keys, rows[0]);

    // t1.table.get_value(1, test_for_loading);
    // test_for_loading[0];
    //ПРОБЛЕМА В GET_VALUE: Ниже представлен код создания хэш таблицы и без get_value работает

    Hash_map<int, LinkedList<std::string>, 1> table_test;
    table_test.insert(1, *(rows[0]));

    std::cout << table_test.table[0]->_value[0] << std::endl;
    //ПРОБЛЕМА В ГЕТ ВАЛУЕ НЕ ТО ЧТО НАДО ВОЗВРАШАЕТ
    LinkedList<std::string> test_for_loading(table_test.get_value(1));
    std::cout << test_for_loading[0] << std::endl;

}
