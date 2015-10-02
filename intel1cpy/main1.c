

#include <stdio.h>
void copystr( char *string1,char *string2 ){
while((*string2++=*string1++)!=0){}
}
int main(){
int i;
char string1[10];
char string2[10]={};
for( i = 0 ; i < 10 ; i++){
scanf("%c",&string1[i]);
}
copystr( string1,string2 );
for( i = 0 ; i < 10 ; i++){
printf("%c",string2[i]);
}
return 0;
}


