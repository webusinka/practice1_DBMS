#include "data_base.hpp"
#include "Array.hpp"
#include <fstream>

void Table::load_data (Array<LinkedList<std::string>*> rows, int size) {
    int i;
    for (i = 0; i < size; i++) {
        table.insert(std::to_string(i), *rows[i]);         //смещение указателя на размер типа указателя и разыменование
    }
    // Создать и открыть файл, если он уже есть, перезаписать его
    std::ofstream file("pk_sequence.txt");
    if (file.is_open()) {
        file << i;
        file.close();
    } else {
        std::cout << "Unable to open file";
    }
}

/*void Table::add_row(LinkedList<std::string> row) { //добавление строчки
    

    table.insert(key, row);
}*/

void Table::delete_row(std::string primary_key){
    table.remove(primary_key);
}