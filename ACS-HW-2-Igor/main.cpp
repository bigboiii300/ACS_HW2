//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию,
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#include <cstdlib> // для функций rand() и srand()
#include <ctime>   // для функции time()
#include <cstring>
#include "container.h"

void firstErr() {
    printf("incorrect command line!\n"
           "  Waited:\n"
           "     command -f infile outfile01 outfile02\n"
           "  Or:\n"
           "     command -n number outfile01 outfile02\n");
}

void secondErr(int size) {
    printf("incorrect number of texts = %d. Set 0 < number <= 10000\n", size);
}

void thirdErr() {
    printf("incorrect qualifier value!\n"
           "  Waited:\n"
           "     command -f infile outfile01 outfile02\n"
           "  Or:\n"
           "     command -n number outfile01 outfile02\n");
}

//------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
    if (argc != 5) {
        firstErr();
        return 1;
    }
    printf("Start\n");
    Container container;
    if (!strcmp(argv[1], "-f")) {
        FILE *input = fopen(argv[2], "r");
        // Проверка
        if (!input) {
            printf("File not exist!");
            return 1;
        }
        container.In(input);
        fclose(input);
    } else if (!strcmp(argv[1], "-n")) {
        auto size = atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            secondErr(size);
            return 3;
        }
        // системные часы в качестве инициализатора
        srand(static_cast<unsigned int>(time(0)));
        // Заполнение контейнера генератором случайных чисел
        container.InRnd(size);
    } else {
        thirdErr();
        return 2;
    }
    FILE *first_output = fopen(argv[3], "w");
    fprintf(first_output, "Filled container:\n");
    container.Out(first_output);
    FILE *second_output = fopen(argv[4], "w");
    fprintf(second_output, "Sorted container:\n");
    container.StraightInsertion();
    container.Out(second_output);
    printf("Stop\n");
    fclose(first_output);
    fclose(second_output);
    return 0;
}