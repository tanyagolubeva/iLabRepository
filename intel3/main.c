#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int find_symbol (char* string, char q);

int main()
{
    char *s;
    s = (char*)malloc(1024);
    gets (s);
    char q;
    q = getchar();
    int result = find_symbol(s, q);
    printf ("%d", result);
    free (s);
    return 0;
}

int find_symbol (char* string, char q)
{
    assert(string != NULL);
    int size = strlen(string);
    int i;
    for (i = 0; i < size; i++)
    {
        if (string[i] == q) return 1; //find
    }
    return 0; // do not find
}
