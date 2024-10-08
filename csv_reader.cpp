#include "data_base.hpp"
#include <fstream>
#include <sstream>

void csv_reader (std::string table_name, Array<LinkedList<std::string>*>& rows, int& size) {
    std::ifstream file(table_name + ".csv");
    std::string line;
    while (std::getline(file, line)) {
        LinkedList<std::string>* new_row = new LinkedList<std::string>;
        std::istringstream iss(line);
        std::string value;
        while(std::getline(iss, value, ',')) {
            new_row->push_back(value);
            std::cout << value << std::endl;
        }
        rows.push_back(new_row);
        size++;
    }
    file.close();
}

void csv_writer (Table& table) {
    std::ofstream file(table.table_name + ".csv");
    for (int i = 0; i < table.table.capacity_size; i++) {
        LinkedList<std::string> row = table.table.get_value(std::to_string(i));
        for (int j = 0; j < row.size(); j++) {
            if (j == row.size() - 1) {
                file << row[j];
            } else {
                file << row[j] << ",";
            }
        }
        file << std::endl;
    }
    file.close();
}