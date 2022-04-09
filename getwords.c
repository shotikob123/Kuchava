#include <stdio.h>
#include <stdbool.h>

bool get_word(char word[], int limit);

int main(void)
{

    int min1 = 100;
    int min2 = 100;
    char word[100];
    bool wordlen = get_word(word, 100);

    while (wordlen == true)
    {
        int i;
        for (i = 0; i < 100; i++)
            if (word[i] == '\0' || word[i] == EOF)
                break;
        if (i < 1) break;
        else if (i == 1)
        {
            min2 = 1;
            break;
        }
        if (min2 > i)
        {
            if (min1 > i)
            {
                min2 = min1;
                min1 = i;
            }
            else
            {
                min2 = i;
            }
        }
        wordlen = get_word(word, 100);
    }

    printf("%d\n", min2);
    return 0;
}


bool get_word(char word[], int limit)
{
    char c;

    c = getchar();
    for (int i = 0; i < limit - 2; i++)
    {
        if (c == '\n' || c == ' ' || c == '\t')
        {
            word[i] = '\0';
            return true;
        }
        else if (c == EOF || c == '\0')
        {
            word[i] = '\0';
            return false;
        }
        word[i] = c;
        c = getchar();
    }
    return true;

}