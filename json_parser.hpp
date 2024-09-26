#pragma once

#include <stdio.h>

class Json_parser{
    public:
        Json_parser();
        ~Json_parser();
        void parse();
    private:
        char* buffer;
};