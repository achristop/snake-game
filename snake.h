#define VERSION 1.0
#define AUTHOR "Andreas Christopoulos"
#define MAIL "zrn6770@gmail.com"
#define N_MAX 36
#define M_MAX 36
#define N_MIN 8
#define M_MIN 8

//The structure of snake
typedef struct SnakeBody{
	int x;
	int y;
	char part;
	struct SnakeBody *next;
}snakeb;

//Declaration of functions.
void clear_the_screen();
void print_the_title();
void pause();
void set_title();
void display_instructions();
void display_dev_info();
void display_stats(char name[]);
void display_menu(char name[]);
void set_obstacles();
void createTable();
void set_fruits();
void showTable();
void createSnake();
void freeTable();
void freeSnake();
void set_power_ups();
void lucky_pick();
void display_menu(char name[]);
void play(char name[]);
void up();
void down();
void left();
void right();
void check(int dir);
void change_fruit();
void level_up();
void insert_end();
void delTail();
void save_score(char name[]);
void load_score();
int set_difficulty();
int convert_char_to_int(char arr[]);
snakeb *insert(snakeb *c);

//Global variables
snakeb *head;
int **table;
int score;
int hightest_score;
int difficulty;
int length;
int obstacles;
int lifes;
int powerUps;
int died;
int fruit;
int level;
int n;
int m;