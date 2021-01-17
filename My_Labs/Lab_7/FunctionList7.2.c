#include "Header.h"

char *PointerMemoryAllocation()                                                 // Ячейка памяти под указатель
{
    char *Memory;
    Memory = (char *)calloc(1, sizeof(char));
    return Memory;
}

void InputWithDynamicMemoryAllocation(char *Line)                               // Ввод текста с динамическим выделением памяти
{
    int t = 1;
    int i = 0;
    printf("Write a text: ");
    rewind(stdin);
    do
    {
        t++;
        *(Line + i++) = getchar();
        Line = (char*)realloc(Line, sizeof(char) * t);                          // Динамическое выдиление
    } while (*(Line + i - 1) != '\n');                                          // Пока не прожмешь Enter
    Line = (char*)realloc(Line, sizeof(char) * i);
    *(Line + i - 1) = '\0';                                                     // В конце ставится ноль символ
}

char* AllUniqueWords(char *Line)                                                // Вывод всех уникальных слов
{
    int i = 0;
    int t = 0;
    int ArraySize = 0;
    char *Word;
    char *AllWords;
    char *AllWords1;
    SmallCase(Line);
    do                                                                          // Находит размер массива
    {
        ArraySize++;
    } while (Line[ArraySize] != '\0');
    AllWords = (char*)calloc(ArraySize + 1, sizeof(char));                      // Создает два массива этого размера
    AllWords1 = (char*)calloc(ArraySize + 1, sizeof(char));
    do                                                                          // Копирует туда все
    {
        AllWords[i] = Line[i];
        i++;
    } while (Line[i] != '\0');
    AllWords[ArraySize] = '\0';
    i = 0;
    do                                                                          // Убирает повторяющиеся слова из массива
    {
        int temp;
        Word = SearchWord(Word, AllWords, i);
        if (!(Word))
        {
            break;
        }
        do
        {
            i++;
        } while (Word[i] >= 'a' && Word[i] <= 'z');
        temp = i;
        i = SpaceSkip(AllWords, i);
        t = i + temp;
        do
        {
            if (AllWords[t] == *Word)                                           // Смотрится первая буква слова
            {
                int k = 0;
                do                                                              // Проверка правильности слова
                {
                    if (AllWords[t] != Word[k])                                 // Если буква отличается то выход из цикла
                    {
                        break;
                    }
                    AllWords[t] = ' ';
                    t++;
                    k++;
                } while (k != temp);
            }
            else
            {
                t = WordSkip(AllWords, t);
                t = SpaceSkip(AllWords, t);
            }
        } while (AllWords[t] != '\0');
    } while (AllWords[i] != '\0');
    int x = 0;
    int k = 0;
    do                                                                          // Форматирование полученой строчки, уборка пробелов
    {
        if (AllWords[x] >= 'a' && AllWords[x] <= 'z')
        {
            AllWords1[k] = AllWords[x];
            x++; k++;
            if (AllWords[x] == ' ')
            {
                AllWords1[k] = ' ';
                k++;
            }
        }
        else
        {
            x++;
        }
    } while (AllWords[x] != '\0');
    x = 0;
    do                                                                          // Ставится ноль символ
    {
        if (AllWords1[x] == ' ' && AllWords1[x + 1] == ' ')
        {
            AllWords1[x] == '\0';
        }
        else
        {
            x++;
        }
    } while (AllWords1[x] != '\0');
    ArraySize = 0;
    do                                                                          // Изменяется размер полученой строчки без лишней памяти
    {
        ArraySize++;
    } while (AllWords1[ArraySize] != '\0');
    AllWords1 = (char*)realloc(AllWords1, sizeof(char) * ArraySize + 1);
    AllWords1[ArraySize] = '\0';
    printf("A string with all unique words: %s\n", AllWords1);
    return AllWords1;
}

void Calculations(char *Line, char *AllWords)                                   // Вычисления
{
    int i = 0;
    int Repeat = 0;
    char *Word;
    do                                                                          // Считается колво повторов слова
    {
        int k = 0;
        Word = SearchWord(Word, AllWords, i);
        if (!(Word))
        {
            break;
        }
        do
        {
            if (Line[k] == *Word)                                               // Проверка слова на правильность
            {
                int t = 0;
                int Check = 0;
                do
                {
                    if (Word[t] != Line[k])                                     // Если оно не правильное то смотрим след слово
                    {
                        int Check = 1;
                        k = NextWord(Line, k);
                        break;
                    }
                    else
                    {
                        t++; k++;
                    }
                } while (Line[k] != ' ' && Line[k] != '\0');
                if (Check == 0)                                                 // Если правильно ставим +1 к повтору
                {
                    Repeat++;
                }
            }
            else
            {
                k++;
            }
        } while (Line[k] != '\0');
        printf("The word '%s' repeated %d times\n", Word, Repeat);
        i = NextWord(AllWords, i);                                              // Переход к следуйщему слову
        Repeat = 0;
    } while (Line[i] != '\0');
}

char* SearchWord(char* Word, char* Line, int i)
{
    do
    {
        if (Line[i] >= 'a' && Line[i] <= 'z')
        {
            int t = i;
            do
            {
                t++;
            } while (Line[t] != ' ' && Line[t] != '\0');
            Word = (char*)calloc(t - i, sizeof(char));
            int k = 0;
            do
            {
            *(Word + k++) = *(Line + i++);
            } while (t != i);
            return Word;
        }
        else
        {
            i++;
        }
    } while ((Line[i] >= 'a' && Line[i] <= 'z') || Line[i] != '\0');
}

int NextWord(char *Line, int i)                                                 // Переходит на начало следуйщего слова
{
    do
    {
        if (Line[i] >= 'a' && Line[i] <= 'z')
        {
            do
            {
                i++;
            } while (Line[i] != ' ' && Line[i] != '\0');
        }
        else
        {
            i++;
        }
    } while ((Line[i] >= 'a' && Line[i] <= 'z') && Line[i] != '\0');
    return i;
}

void SmallCase(char *Line)                                                      // Переводит весь текст в прописные буквы
{
    int i = 0;
    do
    {
        if (*(Line + i) >= 'A' && *(Line + i) <= 'Z')
        {
            *(Line + i) += 32;
        }
        if(*(Line + i) == '.' || *(Line + i) == '!' || *(Line + i) == '?' || *(Line + i) == ',')
        {
            *(Line + i) = ' ';
        }
        i++;
    } while (*(Line + i) != '\0');
}

int SpaceSkip(char *Line, int i)                                                // Пропускает пробелы
{
    do
    {
        if (Line[i] == ' ')
        {
            i++;
        }
    } while (Line[i] == ' ');
    return i;
}

int WordSkip(char *Line, int i)                                                 // Пропускает слово
{
    do
    {
        if (Line[i] != ' ')
        {
            i++;
        }
    } while (Line[i] != ' ' && Line[i] != '\0');
    return i;
}