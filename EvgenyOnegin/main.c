#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 4096
#define IFNAME "onegin.txt"
#define OFNAME "onegin_new.txt"


int scmp(const char *p1, const char *p2)
{
    //const char *s1, *s2;
    //s1 = *(char **) p1;
    //s2 = *(char **) p2;
    return strcmp(p1, p2);
}


// Bad situations handler
void ex_handler()
{
    fprintf(stderr, "ALL IS REALLYYY BAAAAAAAAAAAAAAAAAAAAAAAD!\n");
    exit(-1);
}

int main(void)
{
    FILE *ifp, *ofp;
    char *lineptr[MAXLINE];
    char s[MAXLINE];
    int i, nl;

    ifp = fopen(IFNAME, "r");   //opens file to read
    if (ifp == NULL)
        ex_handler();
    ofp = fopen(OFNAME, "w");   //opens file to write
    if (ofp == NULL)
        ex_handler();

    for(i = 0; i < MAXLINE; ) {
        if(fgets(s, MAXLINE, ifp) == NULL)
            break;

        if(*s != '\n') {
            lineptr[i] = (char *)malloc(sizeof(char) * (strlen(s) + 1));
            strcpy(lineptr[i], s);
            i += 1;
        }
    }

    nl = i;
    qsort(lineptr, nl, sizeof(char *), scmp);

    for(i = 0; i < nl; i++) {
        fprintf(ofp, "%s", lineptr[i]);
        free(lineptr[i]);
    }

    fclose(ifp);
    fclose(ofp);
    return 0;

}

