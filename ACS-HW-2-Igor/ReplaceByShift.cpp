//
// Created by Igor on 11.10.2021.
//

#include "ReplaceByShift.h"

void ReplaceByShift::In(FILE *file) {
    encrypted = Utils::readString(file);
    shift = Utils::readInt(file);
}

void ReplaceByShift::InRnd() {
    encrypted = Utils::randString(15);
    shift = Utils::randInt(1, 10);
}

void ReplaceByShift::Out(FILE *file) {
    shift = shift % strlen(encrypted);
    fprintf(
            file,
            "Replace by Shift: shift = %i, \nencrypted = ",
            shift);
    for (int i = 0; i < strlen(encrypted); ++i) {
        fprintf(file, "%c-", encrypted[(i + shift) % std::strlen(encrypted)]);
    }
    fprintf(file, "\n");
    fprintf(file, "sum / strlen(value) = %lf.\n", Quotient());
    for (int i = 0; i < std::strlen(encrypted) * 2 + 27; ++i) {
        fprintf(file, "%c", '=');
    }
    fprintf(file, "\n");
}

//------------------------------------------------------------------------------
// Вычисление
double ReplaceByShift::Quotient() {
    int sum = 0;
    for (int i = 0; i < strlen(encrypted); i++) {
        sum += encrypted[i] - '0';
    }
    return static_cast<double>(sum) / static_cast<double>(strlen(encrypted));
}