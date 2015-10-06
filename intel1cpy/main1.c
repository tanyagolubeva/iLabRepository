#include <stdio.h>
#include <assert.h>

void copystr( char *string1, char *string2 ) {
    assert (string1 != NULL || string2 != NULL);
    while((*string2++=*string1++)!=0){}
}
int main() {
    int i = 0;
    char string1[50] = {};
    char string2[50] = {};
    char c = NULL;
    gets ( string1 );
    copystr( string1, string2 );
    i = 0;
    while (string2[i] != 0) {
        printf ("%c", string2[i]);
        i++;
    }
    return 0;
}
