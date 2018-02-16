#include <stdio.h>
#include <stdlib.h>
#include "snake.h"

snakeb *insert(snakeb *c)
{
	snakeb *new_node;
	
	new_node = (snakeb *) malloc(sizeof(snakeb));
	if(new_node==NULL)
	{
		printf("%s\n","Not available memory!" );
		exit(1);
	}
	new_node->next = c;
	return new_node;
}

void insert_end()
{
	//It adds at the end of the snake a new node!
	snakeb *new_node,*tmp;

	if((new_node = (snakeb *) malloc(sizeof(snakeb)))==NULL)
	{
		printf("%s\n","Not available memory!" );
		exit(1);
	}
	tmp=head;
	while(tmp->next!=NULL)
		tmp=tmp->next;
	tmp->next=new_node;
	new_node->y=0;
	new_node->x=0;
	new_node->part='x';
	new_node->next=NULL;
}

void delTail()
{
	//It deletes the last node of the tail!
	snakeb *tmp,*ptr;

	length-=2;
	ptr=head;
	while(ptr->next->next!=NULL)
		ptr=ptr->next;
	tmp=ptr->next;
	table[tmp->y][tmp->x]='.';
	free(tmp);
	ptr->next=NULL;

}

void createSnake()
{
	//It creates the snake.It places it in a random position and with a random direction!
	snakeb *tmp;
	int i,j;

	head = insert(head);
	head = insert(head);
	head = insert(head);
	
	head->y = rand() % n;
	head->x = rand() % m;
	head->part = 'O';

	while(1)
	{
		if(head->y>=2 && head->x>=2 && head->y < n-2 && head->x<m-2)
		{
			if(table[head->y][head->x]!='#' && table[head->y][head->x]!=fruit )
			{
				if(table[head->y+2][head->x]!='#' && table[head->y+2][head->x]!=fruit && table[head->y+1][head->x]!='#' && table[head->y+1][head->x]!=fruit)
				{
					table[head->y][head->x] = head->part;
					head->next->y=head->y+1;
					head->next->x=head->x;
					head->next->part='x';
					table[head->y+1][head->x] = head->next->part ;
					head->next->next->y=head->y+2;
					head->next->next->x=head->x;
					head->next->next->part='x';
					table[head->y+2][head->x] = 'x' ;
					break;
				}
				else if(table[head->y-2][head->x]!='#' && table[head->y-2][head->x]!=fruit && table[head->y-1][head->x]!='#' && table[head->y-1][head->x]!=fruit)
				{
					table[head->y][head->x] = head->part;
					head->next->y=head->y-1;
					head->next->x=head->x;
					head->next->part='x';
					table[head->y-1][head->x] = head->next->part ;
					head->next->next->y=head->y-2;
					head->next->next->x=head->x;
					head->next->next->part='x';
					table[head->y-2][head->x] = 'x' ;
					break;
				}
				else if(table[head->y][head->x+2]!='#' && table[head->y][head->x+2]!=fruit && table[head->y][head->x+1]!='#' && table[head->y][head->x+1]!=fruit)
				{
					table[head->y][head->x] = head->part;
					head->next->y=head->y;
					head->next->x=head->x+1;
					head->next->part='x';
					table[head->y][head->x+1] = head->next->part ;
					head->next->next->y=head->y;
					head->next->next->x=head->x+2;
					head->next->next->part='x';
					table[head->y][head->x+2] = 'x' ;
					break;
				}
				else if(table[head->y][head->x-2]!='#' && table[head->y][head->x-2]!=fruit && table[head->y][head->x-1]!='#' && table[head->y][head->x-1]!=fruit)
				{
					table[head->y][head->x] = head->part;
					head->next->y=head->y;
					head->next->x=head->x-1;
					head->next->part='x';
					table[head->y][head->x-1] = head->next->part ;
					head->next->next->y=head->y;
					head->next->next->x=head->x-2;
					head->next->next->part='x';
					table[head->y][head->x-2] = 'x' ;
					break;
				}
			}
		}
		head->x = rand() % n;
		head->y = rand() % m;		
	}
}

void freeSnake()
{
	snakeb *tmp;

	while(head!=NULL){
		tmp=head;
		head=head->next;
		free(tmp);
	}
}
