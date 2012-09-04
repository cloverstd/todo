#include"main.h"


int main(int argc, char **argv)
{
    int opt;
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

    while((opt = getopt(argc, argv, ":a:dl")) != -1)
    {
        switch(opt)
        {
            case 'a':
                optind--;
                while (argv[optind])
                {
                    strcat(todo.item, argv[optind++]);
                    strcat(todo.item, " ");
                }
                add_item(todo, path);
                break;
            case 'd':
                delete_item(path);
                break;
            case 'l':
                list_item(path);
                break;
            case ':':
                help(filename);
                break;
            case '?':
                help(filename);
                break;
        }
    }
    return 0;
}

void help(char *filename)
{
    printf("Usage: %s -[[a todo list]dl]\n", filename);
}

void add_item(todo_item todo, char *todofile)
{
    FILE *fp = open_list("w");

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
