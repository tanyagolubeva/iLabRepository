#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <string.h>
#include <windows.h>

int main()
{
boolean exit;
exit = FALSE;
FILE *fp;

fp = fopen("ar.txt", "r");
if(fp == NULL)
  {
  printf("Error: ar.txt does not found. Press Enter.");
  getchar();
  return 5;
  }
int const countAllQuestions = 100;
char tmp[countAllQuestions];// ��� ������ �����
int countRealQuestions = 0;
if(fgets(tmp, countAllQuestions, fp) == NULL)
  {
  printf("Error 1. Press Enter.");
  getchar();
  return 1;
  }
char *pch = strtok(tmp," ");// ������� � tmp �� ���� ���� �� ��������� �����������(������)
while (pch != NULL) //���� �� �������� ������
  {
  pch = strtok(NULL, " ");
  countRealQuestions++;
  }
int countRealObject = 1;
while(fgets(tmp, countAllQuestions, fp) != NULL)
  {
  countRealObject++;
  }

fseek(fp, 0, SEEK_SET);   //������� �� ������ �����
int **ar;
ar = malloc(sizeof(int*[countRealObject]));  //�������� ������ ��� ������(������ ����������)
int i, k;
for(i=0; i<countRealObject; i++)
  ar[i] = malloc(sizeof(int[countRealQuestions])); //�������� ������ ��� �������
i = 0;
while(fgets(tmp, countAllQuestions, fp) != NULL)  //��������� ���������� ����� �� ����� ���� �� ��������� ��� ������
  {
  k = 0;
  pch = strtok(tmp," ");  // ������� � tmp �� ���� ���� �� ��������� �����������(������)
  ar[i][k] = atoi(pch);  //��������� ��������� ����� ������ � ����� � ��������� � �������
  while ((pch = strtok(NULL, " ")) != NULL) //���� �� �������� � �������� ��� ������
    {
    k++;
    ar[i][k] = atoi(pch);
    }
  i++;
  }
fclose(fp);

char **q = malloc(sizeof(char*[countRealQuestions]));  //������ ��� ������ ���������� �� �������
FILE *fp2;
fp2 = fopen("questions.txt", "r");
if(fp == NULL)
  {
  printf("Error: question.txt does not found. Press Enter.");
  getchar();
  return 6;
  }
i = 0;
while(fgets(tmp, countAllQuestions, fp2) != NULL)
  {
  q[i] = malloc(sizeof(char[strlen(tmp)]));  //������ ��� ������
  strcpy(q[i], tmp);
  i++;
  if(i > countRealQuestions)  //16 �������� ��� �������� �� ������ ��� �������� � ar.txt
    {
    printf("Error 2");
    break;
//    return 2;
    }
  }
fclose(fp2);

char **obj = malloc(sizeof(char*[countRealObject]));
FILE *fp3;
fp3 = fopen("objects.txt", "r");
if(fp == NULL)
  {
  printf("Error: object.txt does not found. Press Enter.");
  getchar();
  return 7;
  }
i = 0;
while(fgets(tmp, countAllQuestions, fp3) != NULL)
  {
  obj[i] = malloc(sizeof(char[strlen(tmp)]));
  strcpy(obj[i], tmp);
  i++;
  if(i > countRealObject)   //9  �������� ��� �������� �� ������ ��� ����� � ar.txt
    {
    printf("Error 3");
    break;
//    return 3;
    }
  }
fclose(fp3);
int *countNull = malloc(sizeof(int[countRealQuestions]));   //������ ��� ���������� �����, ������ � ����� ������ �� �������� � ar.txt
int *countOne = malloc(sizeof(int[countRealQuestions]));
int *countMinus = malloc(sizeof(int[countRealQuestions]));

int rezInd;
int countString;
countString = countRealObject;
int *numbersStrings = malloc(sizeof(int[countString]));   //������ ��� ������ ����� ��������� � �������� ���������(������������) �����
for(i=0; i<countRealObject; i++)   //when program is staring all numbers are here
  numbersStrings[i] = i;
char c2[2];
int rezVal;
int m;

do
{
while(countString > 1)
{
//printf("\ncountstring %d\n", countString);   //number of strings
for(k=0; k<countRealQuestions; k++)   //��������� ���������� 0, 1 � -1 � ��������
  {
  countNull[k] = countOne[k] = countMinus[k] = 0;
  for(i=0; i<countString; i++)   //countRealObject
    {
    if(ar[numbersStrings[i]][k] == 0)
      countNull[k]++;
      else if(ar[numbersStrings[i]][k] == 1)
        countOne[k]++;
        else countMinus[k]++;
    }
  }
rezInd = -1;
i = countString/2;   //numberr which is desireble
m = 0;
while(i >= 1)
  {
  for(k=0; k<countRealQuestions; k++)
    {
    if(i > 1)
      {
      if(((countOne[k] + countMinus[k]) == i) || ((countOne[k] + countMinus[k]) == (i + 1 + 2*m)))   //countRealObject
        {
        rezInd = k;  //if the question is divides list of question in two,remember it
        break;
        }
      }
      else  //for last way
        {
        if((countOne[k] + countMinus[k]) == i)   //countRealObject
          {
          rezInd = k;
          break;
          }
        }
    }
  i--;
  m++;
  if(rezInd != -1) break;
  }

if(rezInd == -1)
  {
  printf("Error 4(index)");
  return 4;
  }
printf("Question: %s\n", q[rezInd]);
printf("write an answer 1(Yes) or 0(No): ");
gets(c2);  //read an answer from cansol
if(c2[0] == '1')
  {
  printf("Your answer: Yes");
  rezVal = 1;
  }
  else
    {
    printf("Your answer: No");
    rezVal = 0;
    }
k = 0;
for(i=0; i<countString; i++)   //countRealObject
  {
  if(ar[numbersStrings[i]][rezInd] == rezVal || ar[i][rezInd] == -1)  //��������� ������ � ������������� ������� 0 ��� 1 � ��� � -1
    {
    numbersStrings[k] = numbersStrings[i];
    printf("\nIndex %d", numbersStrings[i]);
    k++;
    }
  }
countString = k;
}
printf("Your animal is : %s\n", obj[numbersStrings[0]]);
printf("Pause. Press Enter.\n");
getchar();
printf("Would you like to play again?  Write an answer 1(Yes) or 0(No): ");
gets(c2);
if(c2[0] == '0')
  exit = TRUE;
  else
    {
    countString = countRealObject;
    for(i=0; i<countRealObject; i++)
      numbersStrings[i] = i;
    }
}while(!exit);
free(numbersStrings);
free(countNull);
free(countOne);
free(countMinus);
free(obj);
free(q);
free(ar);

    return 0;
}
