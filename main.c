#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "snake.h"

int main(void)
{
	char name[30];

	srand((unsigned)time(NULL));
	set_title();
	clear_the_screen();
	print_the_title();
	printf("\n%s","Please enter your name:" );
	gets(name);
	display_menu(name);
	printf("\n");
	return 0;
}








