#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#define MAXTODO 100
#define MAXNAME 100

typedef struct TODO_ITEM {
    char item[MAXTODO];
} todo_item;

todo_item todo;
char todofile[MAXNAME];

/* add a item into TODO_ITEM struct */
void add_item(todo_item todo, char *);

/* delete a item from todo list */
void delete_item(char *);

/* list all todo item */
void list_item(char *);

/* help */
void help(char *filename);

/* open file to save todo list */
FILE *open_list(char *mode);
