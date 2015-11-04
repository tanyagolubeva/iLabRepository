#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 4096
#define IFNAME "start.txt"
#define OFNAME "finish.txt"
#define COMMANDS_NUM 4


// Magic constants for commands
enum Commands {
    cmd_push = 0,
    cmd_pop = 1,
    cmd_add = 2,
    cmd_sub = 3
};

int scmp(const char *p1, const char *p2)
{
    return strcmp(p1, p2);
}

// Bad situations handler
void ex_handler()
{
    fprintf(stderr, "ALL IS REALLYYY BAAAAAAAAAAAAAAAAAAAAAAAD!\n");
    exit(-1);
}

typedef struct {
    int num;
    const char *name;
} cmd;

const cmd Info[] = {
    {cmd_push,  "push"},
    {cmd_pop,   "pop"},
    {cmd_add,   "add"},
    {cmd_sub,   "sub"}
};

int main(void)
{
    FILE *ifp, *ofp;
//    char *lineptr[MAXLINE];
    char s[MAXLINE];
    char buf[MAXLINE];
    int j;
    char *ptr, *str;

    ifp = fopen(IFNAME, "r");   //opens file to read
    if (ifp == NULL)
        ex_handler();

    ofp = fopen(OFNAME, "w");   //opens file to write
    if (ofp == NULL)
        ex_handler();


    for(;;) {

        if(fgets(s, MAXLINE, ifp) == NULL)
           break;
        (strchr(s, '\n') - s)[s] = '\0';
        ptr = strchr(s, ' ');

        if (ptr == NULL) {
            str = s;
        } else {
            str = buf;
            strncpy(str, s, ptr - s);
        }

        int num = 0;
        for (j = 0; j < COMMANDS_NUM; ++j) {
            if (strcmp(str, Info[j].name) == 0) {
                printf("\'%s\' and \'%s\' are equal, equialent is %d \n", str, Info[j].name, Info[j].num);
                num = Info[j].num;
                fputc(num + '0', ofp);
                if (num == cmd_push) {
                    while (*(++ptr) == ' ');
                    printf("argument is %s\n", ptr);
                    fputs(ptr, ofp);
                }
                break;
            } else {
                printf("\'%s\' and \'%s\' are NOT equal\n", str, Info[j].name);
            }
        }
        fputs("\n",ofp);



    }
    return 0;
}

