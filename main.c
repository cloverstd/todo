#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXTODO 100
#define MAXNAME 100

typedef struct TODO_ITEM {
    char item[MAXTODO];
} todo_item;

todo_item todo;

/* add a item into TODO_ITEM struct */
void add_item(todo_item todo, char *);

/* delete a item from todo list */
void delete_item(char *);

/* list all todo item */
void list_item(char *);

/* help */
void help(char *filename);

/* open file to save todo list */


int main(int argc, char **argv)
{
    char *path = getenv("HOME");
    char *todofile = "/todo.list";
    strcat(path, todofile);
    char filename[MAXNAME];
    strcpy(filename, *argv);
    if (argc == 1)
    {
        help(filename);
        exit(1);
    }
    while (--argc > 0)
    {
        ++argv;
        if ((*argv)[0] == '-')
        {
            switch((*argv)[1])
            {
                case 'a': 
                    add_item(todo, path);
                    break;
                case 'd':
                    delete_item(path);
                    break;
                case 'l':
                    list_item(path);
                    break;
                default:
                    help(filename);
                    exit(1);
                }
        }
        else 
        {
            help(filename);
            exit(1);
        }
    }
    return 0;
}

void help(char *filename)
{
    printf("Usage: %s -[adl]\n", filename);
}

void add_item(todo_item todo, char *todofile)
{
    FILE *fp = fopen(todofile, "w");
    if (fp == NULL)
    {
        printf("Open file error!\n");
        exit(2);
    }

    printf("Please type your TODO:\n");
    gets(todo.item);
    fprintf(fp, "%s", todo.item);
    printf("TODO has saved.\n");

    fclose(fp);
}

void delete_item(char *todofile)
{
    FILE *fp = fopen(todofile, "w");
    if (fp == NULL)
    {
        printf("Open file error!\n");
        exit(2);
    }
    fclose(fp);
}

void list_item(char *todofile)
{

    FILE *fp = fopen(todofile, "r");
    if (fp == NULL)
    {
        printf("Open file error!\n");
        exit(2);
    }
    fgets(todo.item, MAXTODO, fp);
    
    if (strlen(todo.item) == 0)
    {
        printf("TODO item is empty.\n");
    }
    else
    {
        printf("\nTODO item:\n");
        puts(todo.item);
        putchar('\n');
    }
    fclose(fp);
}
