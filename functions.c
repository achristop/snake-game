#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "snake.h"

int convert_char_to_int(char arr[])
{
	//Converts a char to an integer
	if(arr[1]=='1') return 1;
	else if(arr[1]=='2') return 2;
	else if(arr[1]=='3') return 3;
	else if(arr[1]=='4') return 4;
	else if(arr[1]=='5') return 5;
	else if(arr[1]=='6') return 6;
	else if(arr[1]=='7') return 7;
	else if(arr[1]=='8') return 8;
	else if(arr[1]=='9') return 9;
	else return 0;
}

void display_instructions()
{
	//It displays instructions for the game
	clear_the_screen();
	print_the_title();
	printf("\n%s\n","Instructions");
	printf("%s\n\n","------------" );
	printf("%s\n","Valid commands are: U/u,D/d,R,r,L/l,X/x,P/p ." );
	printf("%s\n","The commands U/u,D/d,R/r,L/l can work in combination with a integer number(Max:9)." );
	printf("%s\n","U/u:It moves the Snake upwards.Etc 'Jim enter your move:U5'." );
	printf("%s\n","D/d:It moves the Snake downwards.Etc 'Jim enter your move:D8'." );
	printf("%s\n","R/r:It moves the Snake rightward.Etc 'Jim enter your move:R2'." );
	printf("%s\n","L/l:It moves the Snake leftward.Etc 'Jim enter your move:L3'." );
	printf("%s\n","X/x:It cancels the game and returns to the menu." );
	printf("%s\n","P/p:It gives help to the player with random gifts.");
	printf("%s\n","That's it have fun!" );
	pause();
}

int set_difficulty()
{
	//It sets the difficulty of the game
	int n;
	do{
		clear_the_screen();
		print_the_title();
		printf("\nMenu\n");
		printf("%s\n","----------------------" );
		printf("%s\n","1.Eazy 2.Medium 3.Hard" );
		printf("%s\n","----------------------" );
		printf("\n%s","Set difficulty:" );
		scanf("%d",&n);
	}while(n!=1 && n!=2 && n!= 3);
	if(n==1)
		n=5;
	else if(n==2)
		n=10;
	else
		n=15;
	return n;
}

void display_dev_info()
{
	//It shows information about the dev.
	clear_the_screen();
	print_the_title();
	printf("%s%.1f\n\n","Version:",VERSION);
	printf("%s\n\n","Created for fun by:" );
	printf("%s\n\n","Name: Adreas Christopoulos Email: zrn6770@gmail.com" );
	pause();
}

void display_stats(char name[])
{
	//It displays the stats of the game
	clear_the_screen();
	print_the_title();
	printf("%s%s\n\n","Name:",name );
	printf("%s%d\n\n","Score:",score );
	if(difficulty==5)
		printf("%s\n\n","Difficulty:Eazy");
	else if(difficulty==10)
		printf("%s\n\n","Difficulty:Medium");
	else
		printf("%s\n\n","Difficulty:Hard");
	load_score();
	pause();
}

void play(char name[])
{
	//This function starts and controls the game
	int i,j,times;
	char moves[3],ans;

	table=NULL;
	head=NULL;
	level=1;
	lifes = 3;
	score = 0;
	died = 0;
	fruit='1';
	length=4;
	clear_the_screen();
	print_the_title();
	do
	{ 
		printf("%s enter the dimensions NxM(MIN N=%d,M=%d , MAX N=%d,M=%d) seperated by space:",name,N_MIN,M_MIN,N_MAX,M_MAX);
		scanf("%d%d",&n,&m);
	}while((n<N_MIN || n>N_MAX) || ( m<M_MIN || m >M_MAX));
	getchar();
	
	if (difficulty==5)
		powerUps=2;
	else if(difficulty==10)
		powerUps=1;
	else
		powerUps=0;
	
	obstacles =(int) ((n * m * difficulty)/100);
	createTable();
	set_obstacles();
	set_fruits();
	createSnake();
	
	while(1)
	{
		if(lifes<=0)
		{
			printf("%s\n","Game over!" );
			pause();
			break;
		}
		if(died==1)
			break;
		do
		{
			clear_the_screen();
			print_the_title();
			showTable();
			printf("\n%s%s",name," enter your next move:" );
			gets(moves);
		}while(((moves[0]!='l' || moves[0]!='L' || moves[0]!='r' || moves[0]!='R' || moves[0]!='u' || moves[0]!='U' || moves[0]!='D' || moves[0]!='d') && (moves[1]>=1 && moves[1] <=9 )) && (moves[0]!='x' || moves[0]!='X' || moves[0]!='p' || moves[0]!='P'));
		
		times = convert_char_to_int(moves);
		
		if(moves[0]=='u' || moves[0]=='U')
		{
			for(i=0;i<times;i++)
			{
				up();
			}
		}
		else if(moves[0]=='d'|| moves[0]=='D')
		{
			for(i=0;i<times;i++)
			{
				down();
			}
		}
		else if( moves[0]=='l' || moves[0]=='L')
		{
			for(i=0;i<times;i++)
			{
				left();
			}
		}
		else if(moves[0]=='r'|| moves[0]=='R')
		{
			for(i=0;i<times;i++)
			{
				right();
			}
		}
		else if(moves[0]=='x' || moves[0]=='X')
		{
			printf("%s%s%d\n",name," your score is ",score );
			pause();
			died=1;
		}
		else if(moves[0]=='p' || moves[0]=='P')
		{
				set_power_ups();
		}
		else
		{
			printf("%s\n","Something gone wrong! Sorry :(" );
			pause();
		}
	}
	do
	{
		printf("Do you want to save your score?(y/n): ");
		ans = getchar();
	}while(ans != 'y' && ans != 'n');
	
	if (ans == 'y')
		save_score(name);
	freeTable();
	freeSnake();
}

void display_menu(char name[])
{
	int sel;
	difficulty=10;
	while(1)
	{
			clear_the_screen();
			print_the_title();
			printf("\n%s\n","Menu" );
			printf("%s\n","---------------------------------------------------------------------" );
			printf("%s\n","1.Play 2.Set difficulty 3.Statistics 4.Instructions 5.Creators 6.Exit");
			printf("%s\n","---------------------------------------------------------------------" );
			printf("\n%s","Choose an option:");
			scanf("%d",&sel);

			switch(sel)	{
				case 1:
						play(name);	
				break;

				case 2:
						difficulty = set_difficulty();
				break;

				case 3:
						display_stats(name);
				break;

				case 4:
						display_instructions();

				break;

				case 5:
						display_dev_info();
				break;

				case 6:
						printf("Thank you for playing Snake!\n");
						pause();
						exit(0);
				break;

				default:
						printf("Wrong choice!Please try again!\n");
						pause();
				break;
			}
		}
}

