#ifndef __encryption__
#define __encryption__

#include <cstdio>
#include "EncryptionText.h"
#include "utils.h"

//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся текстовые операции
class EncryptionText {
public:
    virtual ~EncryptionText() = default;

    // Ввод обобщенной текстовой операции
    static EncryptionText *StaticIn(FILE *file);

    // Ввод обобщенной текстовой операции
    virtual void In(FILE *file) = 0;

    // Случайный ввод обобщенной текстовой операции
    static EncryptionText *StaticInRnd();

    // Виртуальный метод ввода случайного текстового оператора
    virtual void InRnd() = 0;

    // Вывод обобщенной текстовой операции
    virtual void Out(FILE *file) = 0;

    // Вычисление периметра обобщенной текстовой операции
    virtual double Quotient() = 0;
};

#endif //__encryption__