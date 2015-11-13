#include <stdio.h>
#include <string.h>
#include <stdlib.h>
FILE *ifp, *ifp1, *ofp; 
void check( int *mas, int i, int *n);
enum cmd 
{
	cpush = 1,
	cpop = 2, 
	cadd = 3,
	csub = 4,
	cprint = 7,
	
};