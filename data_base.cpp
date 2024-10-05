#include "data_base.hpp"

void Table::load_data(LinkedList<int> keys, LinkedList<std::string>* rows) {
    for (int i = 0; i < keys.size(); i++) {
        table.insert(keys[i], rows[i]);
    }
}