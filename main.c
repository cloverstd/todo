#include"main.h"


int main(int argc, char **argv)
{
    char *path = getenv("HOME");
    strcat(path, "/todo.list");
    strcpy(todofile, path);
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
    FILE *fp = open_list("w");

    printf("Please type your TODO:\n");
    gets(todo.item);
    fprintf(fp, "%s", todo.item);
    printf("TODO has saved.\n");

    fclose(fp);
}

void delete_item(char *todofile)
{
    FILE *fp = open_list("w");
    printf("todo list has deleted.\n");
    fclose(fp);
}

void list_item(char *todofile)
{

    FILE *fp = open_list("r");

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

FILE *open_list(char *mode)
{
    FILE *fp;
    fp = fopen(todofile, mode);
    if (fp == NULL)
    {
        fprintf(stderr, "Open file error!\n");
        return NULL;
    }
    return fp;
}
