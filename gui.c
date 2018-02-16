/* A simple user friendly interface. */
#include <stdio.h>
#include <stdlib.h>
#include "snake.h"

void clear_the_screen()
{
	//A function for cleaning the terminal/command line.

	//UNIX
	#ifdef linux
	system("clear");
	#endif

	//WINDOWS
	#ifdef _WIN32
	system("cls");
	#endif
}

void print_the_title()
{
	//Prints the title.
	const char title[] = {"Snake - The Classic Game"};
	printf("%s\n","--------------------------" );
	printf("|%s|\n",title);
	printf("%s\n","--------------------------" );
}

void pause()
{
	printf("%s\n","Press any key to continue . . ." );
	getchar();
	getchar();
}

void set_title()
{
	//Windows title 
	#ifdef _WIN32
	system("title Snake - The Classic Game ");
	#endif

	//Unix title
	#ifdef linux
	system("PS1='Snake - The Classic Game'"); 
	#endif
}
