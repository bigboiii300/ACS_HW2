//
// Created by Igor on 11.10.2021.
//

#include "ReplaceWithDigit.h"

void ReplaceWithDigit::In(FILE *file) {
    key = Utils::readString(file);
    digit = Utils::readInt(file);
}

void ReplaceWithDigit::InRnd() {
    key = Utils::randString(15);
    digit = Utils::randInt(1, 100);
}

void ReplaceWithDigit::Out(FILE *file) {
    fprintf(
            file,
            "Replace with Digit: source key = %s, shift = %i, \nencoded = ",
            key,
            digit);
    for (int i = 0; i < std::strlen(key) * 2 + 27; ++i) {
        fprintf(file, "%d-", digit);
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
double ReplaceWithDigit::Quotient() {
    int sum = 0;
    for (int i = 0; i < strlen(key); i++) {
        sum += key[i] - '0';
    }
    return static_cast<double>(sum) / static_cast<double>(strlen(key));
}