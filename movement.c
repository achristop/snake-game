#include <stdio.h>
#include <stdlib.h>
#include "snake.h"

void check(int dir)
{
	//This function checks the next move of the head and it act accordingly !
	if(dir==1)
	{
		if(head->y==0)
		{
			if(table[n-1][head->x]=='#')
			{
				printf("%s\n","You hit an obstacle!Be caureful!" );
				pause();
				lifes-=1;
				obstacles-=1;
			}
		}
		else if(table[head->y-1][head->x]=='#')
		{
			printf("%s\n","You hit an obstacle!Be caureful!" );
			pause();
			lifes-=1;
			obstacles-=1;
		}

		if(head->y==0)
		{
			if(table[n-1][head->x]=='x')
			{
				printf("%s\n","You killed yourself!Game Over!!!");
				pause();
				died=1;
			}
		}
		else if(table[head->y-1][head->x]=='x')
		{
			printf("%s\n","You killed yourself!Game Over!!!");
			pause();
			died=1;
		}

		if(head->y==0)
		{
			if(table[n-1][head->x]=='@')
			{
				printf("%s\n","You eat a power up!" );
				lucky_pick();
				pause();
			}
		}
		else if(table[head->y-1][head->x]=='@')
		{
			printf("%s\n","You eat a power up!" );
			lucky_pick();
			pause();
		}

		if(head->y==0)
		{
			if(table[n-1][head->x]==fruit)
			{
				change_fruit();
				set_fruits();
			}
		}
		else if(table[head->y-1][head->x]==fruit)
		{
			change_fruit();
			set_fruits();
		}
	}
	else if(dir==2)
	{
		if(head->y==n-1)
		{
			if(table[0][head->x]=='#')
			{
				printf("%s\n","You hit an obstacle!Be caureful!" );
				pause();
				lifes-=1;
				obstacles-=1;
			}
		}
		else if(table[head->y+1][head->x]=='#')
		{
			printf("%s\n","You hit an obstacle!Be caureful!" );
			pause();
			lifes-=1;
			obstacles-=1;
		}

		if(head->y==n-1)
		{
			if(table[0][head->x]=='x')
			{
				printf("%s\n","You killed yourself!Game Over!!!");
				pause();
				died=1;
			}
		}
		else if(table[head->y+1][head->x]=='x')
		{
			printf("%s\n","You killed yourself!Game Over!!!");
			pause();
			died=1;
		}

		if(head->y==n-1)
		{
			if(table[0][head->x]=='@')
			{
				printf("%s\n","You eat a power up!" );
				lucky_pick();
				pause();
			}
		}
		else if(table[head->y+1][head->x]=='@')
		{
			printf("%s\n","You eat a power up!" );
			lucky_pick();
			pause();
		}
		
		if(head->y==n-1)
		{
			if(table[0][head->x]==fruit)
			{
				change_fruit();
				set_fruits();
			}
		}
		else if(table[head->y+1][head->x]==fruit)
		{
			change_fruit();
			set_fruits();
		}
	}
	else if(dir==3)
	{
		if(head->x==0)
		{
			if(table[head->y][m-1]=='#')
			{
				printf("%s\n","You hit an obstacle!Be caureful!" );
				pause();
				lifes-=1;
				obstacles-=1;
			}
		}
		else if(table[head->y][head->x-1]=='#')
		{
			printf("%s\n","You hit an obstacle!Be caureful!" );
			pause();
			lifes-=1;
			obstacles-=1;
		}

		if(head->x==0)
		{
			if(table[head->y][m-1]=='x')
			{
				printf("%s\n","You killed yourself!Game Over!!!");
				pause();
				died=1;
			}
		}
		else if(table[head->y][head->x-1]=='x')
		{
			printf("%s\n","You killed yourself!Game Over!!!");
			pause();
			died=1;
		}

		if(head->x==0)
		{
			if(table[head->y][m-1]=='@')
			{
				printf("%s\n","You eat a power up!" );
				lucky_pick();
				pause();
			}
		}
		else if(table[head->y][head->x-1]=='@')
		{
			printf("%s\n","You eat a power up!" );
			lucky_pick();
			pause();
		}

		if(head->x==0)
		{
			if(table[head->y][m-1]==fruit)
			{
				change_fruit();
				set_fruits();
			}
		}
		else if(table[head->y][head->x-1]==fruit)
		{
			change_fruit();
			set_fruits();
		}
	}
	else if(dir==4)
	{
		if(head->x==m-1)
		{
			if(table[head->y][0]=='#')
			{
				printf("%s\n","You hit an obstacle!Be caureful!" );
				pause();
				lifes-=1;
				obstacles-=1;
			}
		}
		else if(table[head->y][head->x+1]=='#')
		{
			printf("%s\n","You hit an obstacle!Be caureful!" );
			pause();
			lifes-=1;
			obstacles-=1;
		}

		if(head->x==m-1)
		{
			if(table[head->y][0]=='x')
			{
				printf("%s\n","You killed yourself!Game Over!!!");
				pause();
				died=1;
			}
		}
		else if(table[head->y][head->x+1]=='x')
		{
			printf("%s\n","You killed yourself!Game Over!!!");
			pause();
			died=1;
		}

		if(head->x==m-1)
		{
			if(table[head->y][0]=='@')
			{
				printf("%s\n","You eat a power up!" );
				lucky_pick();
				pause();
			}
		}
		else if(table[head->y][head->x+1]=='@')
		{
			printf("%s\n","You eat a power up!" );
			lucky_pick();
			pause();
		}

		if(head->x==m-1)
		{
			if(table[head->y][0]==fruit)
			{
				change_fruit();
				set_fruits();
			}
		}
		else if(table[head->y][head->x+1]==fruit)
		{
			change_fruit();
			set_fruits();
		}
	}
}

void up()
{
	snakeb *tmp;
	int i;

	check(1);
	tmp=head;
	if(head->y==0)
		table[n-1][head->x]=head->part;
	else
		table[head->y-1][head->x]=head->part;

	while(tmp->next!=NULL)
		tmp=tmp->next;
	tmp->next=head->next;
	head->next=tmp;
	table[tmp->y][tmp->x]='.';
	table[head->y][head->x]=tmp->part;
	tmp->y=head->y;
	tmp->x=head->x;
	tmp=head;
	printf("%d\n",length );
	for(i=0;i<length;i++)
		tmp=tmp->next;
	tmp->next=NULL;
	if(head->y==0)
		head->y=n-1;
	else
		head->y--;
}

void down()
{
	snakeb *tmp;
	int i;

	check(2);
	tmp=head;
	if(head->y==n-1)
		table[0][head->x]=head->part;
	else
		table[head->y+1][head->x]=head->part;

	while(tmp->next!=NULL)
		tmp=tmp->next;
	tmp->next=head->next;
	head->next=tmp;
	table[tmp->y][tmp->x]='.';
	table[head->y][head->x]=tmp->part;
	tmp->y=head->y;
	tmp->x=head->x;
	tmp=head;
	for(i=0;i<length;i++)
		tmp=tmp->next;
	tmp->next=NULL;
	if(head->y==n-1)
		head->y=0;
	else
		head->y++;
}

void left()
{
	snakeb *tmp;
	int i;

	check(3);
	tmp=head;
	if(head->x==0)
		table[head->y][m-1]=head->part;
	else
		table[head->y][head->x-1]=head->part;
	while(tmp->next!=NULL)
		tmp=tmp->next;
	tmp->next=head->next;
	head->next=tmp;
	table[tmp->y][tmp->x]='.';
	table[head->y][head->x]=tmp->part;
	tmp->y=head->y;
	tmp->x=head->x;
	tmp=head;
	for(i=0;i<length;i++)
		tmp=tmp->next;	
	tmp->next=NULL;
	if(head->x==0)
		head->x=m-1;
	else
		head->x--;
}

void right()
{
	snakeb *tmp;
	int i;

	check(4);
	tmp=head;
	if(head->x==m-1)
		table[head->y][0]=head->part;
	else
		table[head->y][head->x+1]=head->part;
	while(tmp->next!=NULL)
		tmp=tmp->next;
	tmp->next=head->next;
	head->next=tmp;
	table[tmp->y][tmp->x]='.';
	table[head->y][head->x]=tmp->part;
	tmp->y=head->y;
	tmp->x=head->x;
	tmp=head;
	for(i=0;i<length;i++)
		tmp=tmp->next;	
	tmp->next=NULL;
	if(head->x==m-1)
		head->x=0;
	else
		head->x++;
}	