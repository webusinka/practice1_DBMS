#include "data_base.hpp"
#include "Array.hpp"
#include <fstream>

void Table::load_data (Array<LinkedList<std::string>*>& rows, int size) {
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

void Table::add_row(LinkedList<std::string> row) { //добавление строчки
    std::ifstream file("pk_sequence.txt");
    int key;
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            key = std::stoi(line) + 1;
        }
        file.close();
    } else{
        key = 1;
    }
    std::string primary_key = std::to_string(key);
    table.insert(primary_key, row);

    std::ofstream new_file("pk_sequence.txt", std::ios_base::trunc);
    if (new_file.is_open()) {
        new_file << key;
        new_file.close();
    }
}

//достать ключ из хэш-таблицы для удаления 


void Table::delete_row(std::string primary_key) {
    table.remove(primary_key);
}