#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "snake.h"

void set_obstacles()
{
	//This function sets the obstacles in the table
	int countObs,i,j,pi,pj;

	countObs = obstacles;
	i = rand() % n;
	j = rand() % m;
	
	while(countObs > 0)
	{
		if(i>=0 && j>=0 && i<n && j<m && table[i][j]!='#' && table[i][j]!='O' && table[i][j]!='x' && table[i][j]!='@')
		{
				table[i][j]='#';
				countObs--;
		}
		else
		{
			while(1)
			{
				pi = i + rand()% 2 - rand()% 2;
				pj = j + rand()% 2 - rand()% 2;
				if(pi>=1 && pj>=1 && pi<n-1 && pj<m-1)
				{
					if(table[pi-1][pj-1]=='#')
						break;
					else if(table[pi-1][pj]=='#' && table[i][j]!='O' && table[i][j]!='x' && table[i][j]!='@')
						break;
					else if(table[pi-1][pj+1]=='#' && table[i][j]!='O' && table[i][j]!='x' && table[i][j]!='@')
						break;
					else if(table[pi][pj-1]=='#' && table[i][j]!='O' && table[i][j]!='x' && table[i][j]!='@')
						break;
					else if(table[pi][pj+1]=='#' && table[i][j]!='O' && table[i][j]!='x' && table[i][j]!='@')
						break;
					else if(table[pi+1][pj-1]=='#' && table[i][j]!='O' && table[i][j]!='x' && table[i][j]!='@')
						break;
					else if(table[pi+1][pj]=='#' && table[i][j]!='O' && table[i][j]!='x' && table[i][j]!='@')
						break;
					else if(table[pi+1][pj+1]=='#' && table[i][j]!='O' && table[i][j]!='x' && table[i][j]!='@')
						break;
				}
			}
			i = pi;
			j = pj;
		}

	}
}

void set_fruits()
{
	//This function sets the fruit in the table
	int i,j;

	i = rand() % n;
	j = rand() % m;

	while(1)
	{
		if(i>=0 && j>=0 && i<n && j<m && table[i][j]!='#' && table[i][j]!='O' && table[i][j]!='x' && table[i][j]!='@')
		{
			table[i][j] = fruit;
			break;
		}
		else
		{
			i = i + rand()% 2 - rand()% 2;
			j = j + rand()% 2 - rand()% 2;
		}
	}
}

void set_power_ups()
{
	//This function process the display of powerUp in the table
	int i,j,set;

	set=1;

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(table[i][j]=='@')
			{
				set=0;
				printf("%s\n","A powerUp is already placed in the table!" );
				pause();
				break;
			}
		}
	}
	if(set==1)
	{
		if(powerUps>0)
		{
			i = rand() % n;	
			j = rand() % m;

			while(1)
			{
				if(i>=0 && j>=0 && i<n && j<m && table[i][j]!='#' && table[i][j]!='O' && table[i][j]!='x' && table[i][j]!=fruit)
				{
					table[i][j] = '@';
					break;
				}
				else
				{
					i = i + rand()% 2 - rand()% 2;
					j = j + rand()% 2 - rand()% 2;
				}
				powerUps--;
			}
		}
		else
		{
			printf("%s\n","Sorry,you dont have any powerUps left!" );
			pause();
		}
	}
}

void level_up()
{
	//This function continues the game to the next level!
	int i,j;
	n = n + 2;
	m = m + 2;
	if(n>N_MAX || m>M_MAX)
	{
		printf("You reached the max level.Well done!\n");
		exit(0);
	}
	else
	{	
		table =(int **) realloc(table,n*sizeof(int*));
		if(table==NULL)
		{
			printf("%s\n","Error:Not available memory!" );
			exit(1);
		}
		for(i=n-2;i<n;i++)
		{
			table[i] = (int *) malloc((m-2)*sizeof(int));
			if(table[i]==NULL)
			{
				printf("%s\n","Error:Not available memory!");
				exit(1);
			}
		}
		for(i=0;i<n;i++)
		{
			table[i] = (int *) realloc(table[i],m*sizeof(int));
			if(table[i]==NULL)
			{
				printf("%s%d\n","Error:Not available memory!",i );
				exit(1);
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=m-2;j<m;j++)
			{
				table[i][j]='.';
			}
		}
		for(i=n-2;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				table[i][j]='.';
			}
		}
		for(i=0;i<n;i++)
		{
			for (j=0;j<m;j++)
			{
				if(table[i][j]=='#')
					table[i][j] = '.';
			}
		}
		set_obstacles();
	}
}

void change_fruit()
{
	//This function changes the fruit,it sets the score and calls the function which increase the tail of the snake!
	int i;
	if(fruit=='1')
	{
		length+=2;
		score+=level * 10;
		fruit='2';
		printf("%s%d%s\n","Snake grew by ",1,"!" );
		pause();
		insert_end();
	}
	else if(fruit=='2')
	{
		length+=4;
		score+=level * 20;
		fruit='3';
		printf("%s%d%s\n","Snake grew by ",2,"!" );
		pause();
		for(i=0;i<2;i++)
			insert_end();
	}
	else if(fruit=='3')
	{
		length+=6;
		score+=level * 30;
		fruit='4';
		printf("%s%d%s\n","Snake grew by ",3,"!" );
		pause();
		for(i=0;i<3;i++)
			insert_end();
	}
	else if(fruit=='4')
	{
		length+=8;
		score+=level * 20;
		printf("%s%d%s\n","Snake grew by ",4,"!" );
		pause();
		fruit='5';
		for(i=0;i<4;i++)
			insert_end();
	}
	else
	{
		length+=10;
		score+=level * 20;
		fruit='1';
		printf("%s%d%s\n","Snake grew by ",5,"!" );
		printf("%s\n","You reached a new level!!!" );
		pause();
		level++;
		if (difficulty==5)
			powerUps=2;
		else if(difficulty==10)
			powerUps=1;
		else
			powerUps=0;
		level_up();
		for(i=0;i<5;i++)
			insert_end();
	}
}

void lucky_pick()
{
	//This function gives the random gift to the player from the powerUP!
	int i,k,j,count,rollDice;

	rollDice=rand() % 6 +1;
	count = 0;

	k= rand() % 3;
	if(k==0)
	{
		score+=100 * rollDice;
		printf("%s%d%s\n","You earned ",100*rollDice," points!!!" );
	}
	else if(k==1)
	{
	    for(i=0;i<n;i++)
	    {
		    for(j=0;j<m;j++)
		    {
		    	if(count==2)
					break;
		    	if(table[i][j]=='#')
		    	{
					table[i][j]='.';
					count++;
				}
			}
		}
		printf("%s\n","Two obstacles were removed!!" );
	}
	else
	{
		if(length==4)
			printf("%s\n","Sorry,you have the minimum size of the snake!" );
		else{
			delTail();
			delTail();
			printf("%s\n","Your tail decreased by 2 blocks!" );
		}
	}
}