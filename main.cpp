#include "List.hpp"
#include "hash_map.hpp"
#include "hash_node.hpp"
#include "data_base.hpp"
#include "Array.hpp"

#include <string>
#include <iostream>

int main(){
    LinkedList<std::string> columns; //создаем список названия колонок
    columns.push_back("hui"); //добавляем новую колонку

    Table t1(std::string("table1"), columns); //создаем таблицу с названием "table1" и храню названия колонок

    LinkedList<std::string> row1; //список названий колонок ОН ПУСТОЙ
    row1.push_back("r1"); //добавляем колонку
    row1.push_back("r1");

    LinkedList<std::string> row2;
    row2.push_back("r1");
    row2.push_back("r1");

    Array<LinkedList<std::string>*> rows; //массив указателей типа лист
    rows[0] = &row1; //первый элемент массива это адрес на первый элемент списка row1
    std::cout << rows[0] << std::endl; 
    rows[1] = &row2;
    std::cout << rows[1] << std::endl;
    rows[2] = &row2;
    std::cout << rows[2] << std::endl;


    t1.load_data(rows, 3); //формирование хэш-тбалицы

    //Hash_map<std::string, LinkedList<std::string>, 1> table_test;
    //table_test.insert("1", *(rows[0]));
    
    //std::cout << table_test.table[0]->_value[0] << std::endl;
    //t1.delete_row("1");

    //std::cout << table_test.table[0]->_value[0] << std::endl;
    //ПРОБЛЕМА В ГЕТ ВАЛУЕ НЕ ТО ЧТО НАДО ВОЗВРАШАЕТ
    //LinkedList<std::string> test_for_loading(table_test.get_value(1));
    //::cout << test_for_loading[0] << std::endl;

}
