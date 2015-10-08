#include <stdio.h>
#include<stdlib.h>
#define compare(A, B) { int t = A; A = B; B = t; }

void bubblesort(int *a, int n);

int main(void)
{int i, j;
  const int N=3;

   int matrix[N][N];
   for( i=0; i<3; i++){
   for(
       j=0; j<3; j++){
        matrix[i][j] = rand()%100;
        printf("%d ",matrix[i][j]);}
   printf("\n");}


    bubblesort(matrix[0], 3);
    bubblesort(matrix[1], 3);
    bubblesort(matrix[2], 3);
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf ("%d ", matrix[i][j]);
        }
        printf ("\n");
    }
    return 0;
}

void bubblesort(int *a, int n)
{
  int i, j;

  for (i = n - 1; i >= 0; i--)
  {
    for (j = 0; j < i; j++)
    {
      if (a[j] > a[j + 1])
        compare( a[j], a[j + 1] );
    }
  }
}
