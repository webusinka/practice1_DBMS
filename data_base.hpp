#pragma once

#include "Array.hpp"
#include "List.hpp"
#include "hash_map.hpp"

class Table;
class Data_base {
public:
    LinkedList<Table&> tables; //все таблицы с колонками
};
//чтение csv
void csv_reader (std::string table_name, Array<LinkedList<std::string>*>& rows, int& size);
//запись в csv
void csv_writer (Table& table);

class Table{ 
    public:
    Table(std::string _name, LinkedList<std::string> _columns) : table_name(_name), 
                    columns(_columns) {}
    ~Table() = default;

    std::string table_name;        //название таблицы "таблица1":
    LinkedList<std::string> columns; //названия столбцов ["колонка1", "колонка2", "колонка3", "колонка4"]
    Hash_map<std::string, LinkedList<std::string>, 1> table; //хэш таблица - ключ, названия колонок, количество строк
    
    //загрузка данных
    void load_data(Array<LinkedList<std::string>*>& rows, int size);
    //удаление строки через primary_key
    void delete_row(std::string primary_key);
    //добавление строчки типа лист
    void add_row(LinkedList<std::string> row);
};