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

void Calculations(char *Line)                                                   // Вычисления
{
    int i = 0;
    int temp;
    char *Word;
    Word = (char*)calloc(1, sizeof(char));
    SmallCase(Line);
    do
    {
        if (*(Line + i) >= 'a' && *(Line + i) <= 'z')                           // Ищется слово
        {
            int t = i;
            do
            {
                t++;
            } while (*(Line + t) != ' ' && *(Line + t) != '\0');
            Word = (char*)realloc(Word, sizeof(char) * t - i);                  // Создается массив для слова
            temp = t - i;
            int k = 0;
            do                                                                  // Записываем слово
            {
                *(Word + k++) = *(Line + i++);
            } while (t != i);
        }
        else
        {
            i++;
        }
        if (*(Line + i) != ' ')                                                 // Ищется кол-во повторов
        {
            int t = i;
            int Repeat = 1;
            do
            {
                int check = 1;                                                  // Проверка правильности слова
                t = SpaceSkip(Line, t);                                         // Пропуск пробелов
                if (*(Line + t) == *(Word))                                     // Смотрится первая буква слова
                {
                    int k = 0;
                    do                                                          // Проверка правильности слова
                    {
                        if (*(Line + t) != *(Word + k))                         // Если буква отличается то check становится 0
                        {
                            check = 0;
                            break;
                        }
                        *(Line + t) = ' ';
                        t++;
                        k++;
                    } while (k != temp);
                    if(check == 1)                                              // Если слово правильное то добавляется повторение слова
                    {
                        Repeat++;
                    }
                }
                else                                                            // Если нет тогда пропускается до следуйщего слова
                {
                    do
                    {
                        t++;
                    } while (*(Line + t) != ' ' && *(Line + t) != '\0');
                }
                if (check == 0)                                                 // Если слово было неправильным то пропуск до следуйщего пробела
                {
                    do
                    {
                        t++;
                    } while (*(Line + t) != ' ' && *(Line + t) != '\0');
                }
            } while (*(Line + t) != '\0');
            printf("Word '%s' repeated %d times\n", Word, Repeat);              // Вывод как часто повторилось слово
        }
    } while (*(Line + i) != '\0');

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
        if (*(Line + i) == ' ')
        {
            i++;
        }
    } while (*(Line + i) == ' ');
    return i;
}