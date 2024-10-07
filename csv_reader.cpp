#include "data_base.hpp"
#include <fstream>
#include <sstream>

void csv_reader (Table& table) {
    std::ifstream file(table.table_name + ".csv");
    std::string line;
    Array<LinkedList<std::string>*> rows;
    int size_array = 0;
    while (std::getline(file, line)) {
        if (file.eof()){
            break;
        }
        LinkedList<std::string>* new_row = new LinkedList<std::string>;
        std::istringstream iss(line);
        std::string value;
        while(std::getline(iss, value, ',')) {
            new_row->push_back(value);
        }
        rows.push_back(new_row);
        size_array++;
    }
    table.load_data(rows, size_array);
    for(int i = 0; i < size_array; i++) {
        delete (rows[i]);
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