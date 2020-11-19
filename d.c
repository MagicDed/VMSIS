for (int i = 0; i < n; i++)
{
    if (!(i == ' '))
    {
        a = i;
        for (int j = i; j < n - i; j++)
        {
            if (j == ' ')
            {
                b = j;
                if (WordSize < b - a)
                {
                    WordSize = b - a;
                }
                break;
            }
        }
    }
}
printf("The lognest word has %d characters", WordSize)
