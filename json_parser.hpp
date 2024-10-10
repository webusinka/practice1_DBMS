#pragma once

#include <create.hpp>
#include <iostream>
#include "data_base.hpp"
#include "json.hpp"

using namespace nlohmann;

void json_parser(const std::string& filePath){
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл: " << filePath << std::endl;
        return;
    }

    nlohmann::json json_data;
    file >> json_data;

    std::string schema_name = json_data["name"];
    Data_base schema;       //создание класса таблиц
    CreateDir(schema_name);

    int tuples_limit = json_data["tuples_limit"];

    json schema_structure = json_data["structure"];
    for (auto& [key, value] : schema_structure.items()) {
        CreateDir(schema_name + "/" + key);

        LinkedList<std::string> column;
        for (auto columns: value) {
            column.push_back(columns);
        }

        Table table(key, value);
        schema.tables.push_back(table);

        CreateFile(schema_name + "/" + key, "1.csv", colNames, true);
        CreateFile (schema_name + "/" + key, key + "lock.txt", "@", false);
        CreateFile(schema_name + "/" + key, key + "_pk_sequence.txt", "0", false);

    }
}