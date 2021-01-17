#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char* PointerMemoryAllocation();                            // Ячейка памяти под указатель
void InputWithDynamicMemoryAllocation(char*);               // Ввод текста с динамическим выделением памяти
char* AllUniqueWords(char*);                                // Вывод всех уникальных слов
void Calculations(char*, char*);                            // Вычисления
char* SearchWord(char*, char*, int);                        // Ищет одно слово
int NextWord(char*, int);                                   // Переходит на начало следуйщего слова
void SmallCase(char*);
int SpaceSkip(char*, int);                                  // Пропускает пробелы
int WordSkip(char *, int);                                  // Пропускает слово