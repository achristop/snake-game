#include <stdio.h>
#include <stdlib.h>
#include "snake.h"

void save_score(char name[])
{
	FILE *f = fopen("score.txt","a");
	if (f == NULL)
	{
		printf("%s\n","Error while opening the file!" );
		exit(1);
	}
	fprintf(f, "%s%s %s%d\n", "Name:", name, "Score:", score, "Difficulty:", difficulty);
	fclose(f);
}

void load_score()
{
	FILE *f = fopen("score.txt", "r");
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	if (f == NULL)
	{
		printf("%s\n","No records from other matches!" );
	}
	else
	{
		printf("%s\n","Scoreboard:" );
		while((read = getline(&line, &len, f)) != -1 )
		{
			printf("%s",line );
		}
		free(line);
		fclose(f);
	}
	printf("\n");
}
