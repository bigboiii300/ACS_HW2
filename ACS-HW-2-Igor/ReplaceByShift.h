//
// Created by Igor on 11.10.2021.
//

#ifndef __shift__
#define __shift__

#include "EncryptionText.h"
#include "utils.h"

class ReplaceByShift : public EncryptionText {
public:
    ~ReplaceByShift() override = default;

    // Ввод параметров из файла
    void In(FILE *file) override;

    // Случайный ввод параметров
    void InRnd() override;

    // Вывод параметров в форматируемый поток
    void Out(FILE *file) override;

    double Quotient() override;

private:
    const char *encrypted;
    int shift;
};
#endif //__shift__
