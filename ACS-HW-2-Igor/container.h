#ifndef __container__
#define __container__

//------------------------------------------------------------------------------
// container.h - содержит тип данных,
// представляющий простейший контейнер
//------------------------------------------------------------------------------

#include <cstdio>
#include "EncryptionText.h"

//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива
class Container {
public:
    Container();

    ~Container();

    // Ввод содержимого контейнера из указанного потока
    void In(FILE *file);

    // Случайный ввод содержимого контейнера
    void InRnd(int size);

    // Вывод содержимого контейнера в указанный поток
    void Out(FILE *file);

    // Сортировка по убыванию
    void StraightInsertion();

private:
    void Clear();    // Очистка контейнера от данных
    int len; // текущая длина
    EncryptionText *cont[10000]{};
};

#endif