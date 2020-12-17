#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

static int StringLength(int);                          // Ввод длинны строки
static char* MemoryAllocation(int);                    // Выделение памяти под строчку
static void Input(char*, int);                         // Ввод сиволов в строку
static char* GetString(char*, int);                    // Получение строчки
static char* Calculations(char*, char*, int);          // Вычисления
static void Output(char*);                             // Вывод линии