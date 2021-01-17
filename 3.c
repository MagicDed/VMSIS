#include <stdlib.h>
#include <stdio.h>

int main()
{
	char *String;
	int Length, i;
	int Big = 0;
	char Common;
	printf("What's size of the string?: ");
	scanf_s("%d", &Length);
	String = (char*)calloc(Length + 1, sizeof(char));
	rewind(stdin);
	do
	{
		scanf_s("%c", &String[i++]);
	} while (String[i - 1] != '\n');
	int k = 0;
	do
	{
		int t = 0;
		int Amount = 0;
		do
		{
			if (String[k] == String[t])
			{
				Amount++;
				t++;
			}
			else
			{
				t++;
			}
		} while (String[t] != '\n');
		if (Amount > Big)
			{
				Common = String[k];
			}
		k++;
	} while (String[k] != '\n');
	printf("Most common: %c", Common);
}