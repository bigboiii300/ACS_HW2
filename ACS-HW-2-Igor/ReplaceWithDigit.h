//
// Created by Igor on 11.10.2021.
//

#ifndef __replaceToDigits__
#define __replaceToDigits__

#include "EncryptionText.h"
#include "utils.h"

class ReplaceWithDigit : public EncryptionText {
public:
    ~ReplaceWithDigit() override = default;

    // Ввод параметров из файла
    void In(FILE *file) override;

    // Случайный ввод параметров
    void InRnd() override;

    // Вывод параметров в форматируемый поток
    void Out(FILE *file) override;

    double Quotient() override;

private:
    const char *key;
    char *temp;
    int digit;
};
#endif //__replaceToDigits__
