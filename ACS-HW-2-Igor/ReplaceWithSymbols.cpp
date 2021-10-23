//
// Created by Islombek on 11.10.2021.
//

#include "ReplaceWithSymbols.h"


void ReplaceWithSymbols::In(FILE *file) {
    value = Utils::readString(file);
    key = Utils::readString(file);
}

void ReplaceWithSymbols::InRnd() {
    key = Utils::randString(15);
    value = Utils::randString(15);
}

void ReplaceWithSymbols::Out(FILE *file) {
    fprintf(
            file,
            "Replace with Symbols: source value = %s, \nencoded =  ",
            value
    );
    for (int i = 0; i < std::strlen(key); ++i) {
        fprintf(file, "%c-", value[i]);
    }
    fprintf(file, "\n");
    fprintf(file, "sum / strlen(value) = %lf.\n", Quotient());
    for (int i = 0; i < std::strlen(key) * 2 + 27; ++i) {
        fprintf(file, "%c", '=');
    }
    fprintf(file, "\n");
}

//------------------------------------------------------------------------------
// Вычисление
double ReplaceWithSymbols::Quotient() {
    int sum = 0;
    for (int i = 0; i < strlen(key); i++) {
        sum += key[i] - '0';
    }
    return static_cast<double>(sum) / static_cast<double>(strlen(key));
}