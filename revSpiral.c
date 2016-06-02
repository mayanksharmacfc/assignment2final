/**
*This function prints the values of a matrix in a reverse spiral form
*	@author Mayank Sharma
*	@date 2nd June 2016
*/
#include<stdio.h>
#include"func.h"

int revSpiral(){   

int N; ///< variable N for order
printf("Enter order of matrix:\n"); ///< input
scanf("%d",&N);
int i,k,M[N][N],check,T,D,R,L,centralIndX,centralIndY,dir,count;
printf("Give array elements manually.\n");
count = 1;
printf("Enter %d values", N*N);
	for(i = 0; i < N ; i++){
		for(k = 0; k < N ; k++){
			scanf("%d", &M[i][k]);
			printf("%d ",M[i][k]);
		}
	printf("\n");
	}
centralIndX = N/2; ///< to determine starting position
centralIndY =(N%2==0)?( N/2)-1:N/2; ///< determines the starting position of cursors moving along Y-direction
T = centralIndY, D = centralIndY+1, R = centralIndX, L = centralIndX-1, dir =(N%2==0)?2:0; ///< Initialization of limiting cursors and direction taking into consideration the order of matrix - even/odd
printf("OUTPUT:\n");
while(T>= 0 && D <= N && R < N && L >= 0 ) ///< setting the cursor limits
{
	if(dir == 0) ///< right --> left; leftwards
	{
		for(k = R; k > L; k--){
		printf("%d ",M[T][k]);
		}R++;
	dir = dir+1; 
	}
	
	if(dir == 1) ///< downwards
	{
		for(k = T ; k < D ; k++){
		printf("%d ",M[k][L]);
		}T--; 
	dir = dir+1;
	}

	if(dir == 2) ///< rightwards
	{
		for(k = L; k < R; k++){
		printf("%d ",M[D][k]);
		}L--;
	dir = dir+1;
	}
	
	if(dir == 3) ///<  upwards
	{
		for(k = D; k > T; k--){
		printf("%d ",M[k][R]);
		}D++;
	dir = dir+1;
	}
dir = dir%4; ///<  loops the direction
}
L++;
if(dir == 0) ///< handles the exception and prints out first row
{
	for(k = R; k >= L; k--)
	{
	printf("%d ",M[T][k]);
	}
}	
printf("\n");
return 0;
}

