#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
int compare (char* string1, char* string2);


int main()
{
    char *s;
    s = (char*)malloc(1024);
    gets (s);
    char *q;
    q = (char*)malloc(1024);
    gets (q);
    int result = compare (s, q);
    printf ("%d", result);
    free (s);
    free (q);
    return 0;
}

int compare (char* string1, char* string2)
{assert( string1 != NULL || string2 != NULL);{
    int size = strlen(string1);
    int i;
    for (i = 0; i < size; i++)
    {
        if (string1[i] != string2[i]) return 0;

    }
}
    return 1;
}
