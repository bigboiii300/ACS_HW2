//
// Created by Islombek on 11.10.2021.
//

#ifndef __replaceWithSymbols__
#define __replaceWithSymbols__

#include "EncryptionText.h"
#include "utils.h"

class ReplaceWithSymbols : public EncryptionText {
public:
    ~ReplaceWithSymbols() override = default;

    // Ввод параметров из файла
    void In(FILE *file) override;

    // Случайный ввод параметров
    void InRnd() override;

    // Вывод параметров в форматируемый поток
    void Out(FILE *file) override;

    double Quotient() override;

private:
    char *key;
    char *value;
};

#endif //__replaceWithSymbols__
