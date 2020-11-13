int** AllocateMemory(int** mas, int row, int col)
{
	mas = (int**)malloc(row * sizeof(int*));
	for (int i = 0; i < col; i++)
	{
		*(mas + i) = (int*)malloc(col * sizeof(int));
	}
	return mas;
}

void Input(int** mas, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("Write a number: ");
			scanf_s("%d", *(mas + i) + j);
		}
	}
}

void Output(int** mas, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%-4d\t", *(*(mas + i) + j));
		}
		printf("\n");
	}
	printf("\n");
}
void Calculations(int **mas, int row, int col)
{
    int t;
    for (int i = 0; i < row; i++)
    {
        for (int k = 0; k < col; k++)
        {
            for (int j = 1 + k; j < col; j++)
            {
                if (*(*(mas + i) + k) < 0)
                {
                    do
                    {
                        k += 1;
                        j += 1;
                    } while (*(*(mas + i) + k) < 0);
                }
                if (*(*(mas + i) + k) < *(*(mas + i) + j))
                {
                    t = *(*(mas + i) + k);
                    *(*(mas + i) + k) = *(*(mas + i) + j);
                    *(*(mas + i) + j) = t;
                }
            }
        }
    }
}