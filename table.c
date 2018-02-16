#include <stdio.h>
#include <stdlib.h>
#include "snake.h"

void createTable()
{
	int i,j;

	table = (int **) malloc(n*sizeof(int*));
	if(table==NULL)
	{
		printf("%s\n","Error:Not available memory!" );
		exit(1);
	}
	for(i=0;i<n;i++)
	{
		table[i] = (int *) malloc(m*sizeof(int));
		if(table[i]==NULL)
		{
			printf("%s\n","Error:Not available memory!" );
			exit(1);
		}
	}
	for(i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
			table[i][j] = '.';
	}
}

void freeTable()
{
	int i;

	for(i=0;i<n;i++)
		free(table[i]);
	free(table);
}

void showTable()
{
	//It displays the table of the game
	int i,j;

	for(i=0;i<3*m+4;i++)
		printf("%c",'*');
	printf("\n");
	printf("%s%d%s%d%s%d%s%d\n","Level:",level," Score:",score," Lifes:",lifes," PowerUps:",powerUps);
	for(i=0;i<3*m+4;i++)
		printf("%c",'*');
	printf("\n    ");
	for(i=0;i<m;i++)
		printf("%3d",i+1);
	printf("\n   ");
	for(i=0;i<3*m+1;i++)
		printf("%c",'-');
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%2d |",i+1);
		for (j=0;j<m;j++)
		{
			printf("  %c",table[i][j] );
		}
		printf("\n");
	}
	for(i=0;i<3*m+4;i++)
		printf("%c",'*');
}