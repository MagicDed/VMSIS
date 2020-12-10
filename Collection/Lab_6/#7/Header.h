#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int StringLength(int);                          // Ввод длинны строки
char* MemoryAllocation(int);                    // Выделение памяти под строчку
void Input(char*, int);                         // Ввод сиволов в строку
char* GetString(char*, int);                    // Получение строчки
char* Calculations(char*, char*, int);          // Вычисления
void Output(char*);                             // Вывод линии