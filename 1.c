#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdarg.h>

int word(char);
int sizeofword(char*, int);
int word_word(char*, char*, int, int);
void find(char**, int&, int&, int&, int n);
void print(char**, int);
void fun(char*, int);
void revers(char*, ...);
void printfword(char**, int, int, int);
void revers1(char* s, ...);

//"Slava hello world" "Hello 123 slava" "Friend is Vlad" "My name is Slava" "Gher fef ef Slava"

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	int s = 0;
	char* s1 = nullptr;
	do
	{
		if (s == 1)
			system("cls");
		int maxcout = 0, line = 0, begin = 0;
		system("cls");
		printf("Âàø òåêñò: \n");
		print(argv, argc);
		find(argv, maxcout, line, begin, argc);
		printfword(argv, begin, line, maxcout);
		//revers(argv[3], argv[2], argv[4], argv[5], s1);
		revers1(argv[3], argv[2], argv[4], argv[5], s1);
		printf("\n\nÂâåäèòå 1, åñëè õîòèòå ïîâòîðèòü ïðîãðàììó: ");
		scanf_s("%d", &s);
	} while (s == 1);
	return 0;
}

void printfword(char** argv, int begin, int line, int maxcout)
{
	if (maxcout == 1)
	{
		printf("\nÂñå ñëîâà âñòðå÷àþòñÿ â òåêñòå 1 ðàç");
	}
	else
	{
		printf("\nÍàèáîëåå ÷àñòî âñòðå÷àþùååñÿ ñëîâî: ");
		for (int i = begin; (*word)(argv[line][i]); i++)
			printf("%c", argv[line][i]);
		printf("\nÊîëè÷åñòâî ïîâòðîåíèé: %d\n", maxcout);
	}
}
void revers(char* s,...)
{

	va_list p;								 // ýòî àíàëîãè÷íî îáúÿâëåíèþ áåçòèïîâîãî óêàçàòåëÿ
	va_start(p,s);							 // óêàçàòåëü ð óñòàíàâëèâàåòñÿ íà íà÷àëî ïåðåìåííîãî
											 // ñïèñêà ïàðàìåòðîâ ôóíêöèè
	fun(s, 0);
	printf("\n%s", s);						 // ïàðàìåòð, ïåðâûé (ïîñòîÿííûé),
	while (s)								 // öèêë ïîêà â ñòåêå íå nullptr
	{
		s	=	va_arg(p,char *);            // ïåðåõîä ê íîâîìó ýëåìåíòó (àäðåñó) â ñòåêå
		fun(s, 0);
		printf("\n%s",s);					 // âûâîä ñòðîê íà ýêðàí
	}
	va_end(p);
}
void fun(char* s, int i)
{
	static int j;
	char c;									// ëîêàëüíàÿ ïåðåìåííàÿ äëÿ ñîõðàíåíèÿ î÷åðåäíîãî ñèìâîëà ñòðîêè
	if (s==nullptr)
		return;
	if (*(s + i) == ' ')
		j = i + 1;							// çàïîìèíàåì ïîçèöèþ ' ' ïåðåä ñëîâîì
	if (*(s + i))							// åñëè íå äîñòèãíóò êîíåö ñòðîêè
	{
		c = *(s + i++);						// òî ÷òåíèå î÷åðåäíîãî ñèìâîëà èç ñòðîêè
		fun(s, i);							// ðåêóðñèâíûé âûçîâ fun
	}
	else return;							// ñòðîêà îêîí÷åíà

	if (*(s + j))
		*(s + j++) = c;						// ðåâåðñ ñëîâà (çàïèñü â ñòðîêó ñèìâîëîâ ñîõðàíåííûõ ïðè ðåêóðñèè)
	if (i == 1) j = 0;						// ñáðîñ â 0 èíäåêñà (äëÿ î÷åðåäíîãî âûçîâà fun) äëÿ íîâîé ñòðîêè
}
int word(char sym)
{
	if ((sym >= 'a' && sym <= 'z') || (sym >= 'A' && sym <= 'Z'))
		return 1;
	else
		return 0;
}

int sizeofword(char* s, int begin)
{
	int size = 0, i;
	for (i = begin; (*word)(s[i]); i++)
		size++;
	return size;
}

int word_word(int(*sizeofword)(char*, int), char* word1, char* word2, int ind1, int ind2)
{
	if ((*sizeofword)(word1, ind1) == (*sizeofword)(word2, ind2))
	{
		for (int i = ind1, j = ind2; (*word)(word1[i]) && (*word)(word2[j]); i++, j++)
			if (word1[i] != word2[j])
				return 0;
		return 1;
	}
	else return 0;
}

void find(char** text, int& maxcout, int& line, int& begin, int n)
{
	int word_word(int(*sizeofword)(char*, int), char*, char*, int, int);
	for (int i = 1; i < n; i++)													//Öèêë ïî âñåì ñòðîêàì
	{
		int j = 0;																//j - ïåðåìåííàÿ äëÿ ïðîõîäà ïî ñèìâîëàì ñòðîêè
		while (text[i][j] != '\0')												//Öèêë âûïîëíÿåòñÿ äî òåõ ïîð ïîêà íåò íîëü ñèìâîëà
		{
			while (!(*word)(text[i][j]) && text[i][j] != '\0') j++;				//Ïðîïóñê ñèìâîëîâ ïîêà íå íàéä¸ò áóêâó ñëîâà
			int cout = 0;														//Ïåðåìåííàÿ äëÿ ïîäñ÷åòà êîëè÷åñòâî ïîâòîðåíèé ñëîâà
			for (int k = 1; k < n; k++)											//Öèêë äëÿ ïðîâåðêè âñåõ îñòàëüíûõ ñëîâ â òåêñòå ñî ñëîâîì â ñòðîêå i  è ïîçèöååé ïåðâîãî ñèìâîëà j
			{
				int q = 0;
				while (text[k][q] != '\0')
				{
					while (!(*word)(text[k][q]) && text[k][q] != '\0') q++;		//Ïðîïóñê ñèìâîëîâ ïîêà íå íàéä¸ò áóêâó ñëîâà
					if (word_word(sizeofword, *(text + i), *(text + k), j, q))
						cout++;
					while ((*word)(text[k][q]) && text[k][q] != '\0') q++;		//Ïðîïóñê ñèìâîëîâ ïîêà íå íàéä¸ò íå áóêâó ñëîâà
				}
			}
			if (cout > maxcout)
			{
				maxcout = cout;
				line = i;
				begin = j;

			}
			while ((*word)(text[i][j]) && text[i][j] != '\0') j++;				//Ïðîïóñê ñèìâîëîâ ïîêà íå íàéä¸ò íå áóêâó ñëîâà
		}
	}
}

void print(char** argv, int argc)
{
	for (int i = 1; i < argc; i++)
		printf("%s \n", *(argv + i));
}


void revers1(char *s,...)
{
	void **p;
	p=(void**)&s;											// "óáèðàåì" ó óêàçàòåëÿ â ñòåêå åãî òèï (ïðèâîäÿ ê void **)
	 while(*(char**)p)										// öèêë ïîêà â ñòåêå íå nullptr
	 {
		 fun(*(char**)p, 0);
		 printf("\n%s", *(char**)p);						// ðàçûìåíîâûâàÿ p ïîëó÷àåì óêàçàòåëü (s1, s2, ...)
		 p++;												// âûâîäèì íà ýêðàí ñòðîêè, ñîîòâ. ýòèì óêàçàòåëÿì
															// ïåðåõîä ê íîâîìó ýëåìåíòó (àäðåñó) â ñòåêå
	 }														// p óâåëè÷èâàåòñÿ íà âåëè÷èíó = ðàçìåðó óêàçàòåëÿ (ïðîñòî óêàçàòåëÿ)

}
