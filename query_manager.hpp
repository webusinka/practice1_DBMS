#include <iostream>
#include "json_parser.hpp"

void query_manager(const std::string& SQLquery, const std::string& file_directory, const std::string& schema_name,
const int tuples_limit, const Hash_map<std::string, DymanicArray<string>*> JSON_schema) {
    DymanicArray<string>* ws = Split(SQLquery, ' ');
    if (ws->data[0] == "SELECT") {
        try{
            parse_select(*ws, file_directory, schema_name, JSON_schema);
        } catch (const exception& Error) {
            cerr << Error.what() << endl;
            return;
        }

    } else if(ws->data[0] == "INSERT" && ws->data[1] == "INTO") {
        try{
            parse_insert(*ws, file_directory, schema_name, JSON_schema);
        } catch (const exception& Error) {
            cerr << Error.what() << endl;
            return;
        }

    } else if(ws->data[0] == "DELETE" && ws->data[1] == "FROM") {
        try{
            parse_delete(*ws, file_directory, schema_name, JSON_schema);
        } catch (const exception& Error) {
            cerr << Error.what() << endl;
            return;
        }

    } else {
        std::cerr << "Bad news: invalid SQL query" << std::endl;
    }

}