#include "main.h"


int main(int argc, char **argv)
{
    struct option longopts[] = {
        {"add", 1, NULL, 'a'},
        {"dellete", 0, NULL, 'd'},
        {"list", 0, NULL, 'l'},
        {"help", 0, NULL, 'h'},
        {0, 0, 0, 0}};
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

    while((opt = getopt_long(argc, argv, ":a:dlh", longopts, NULL)) != -1)
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
            case 'h':
                help(filename);
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
    printf("Usage: %s [option] [todo list]...\n", filename);
    printf("  -a, --add                 add a todo list\n");
    printf("  -d, --delete              delete todo list\n");
    printf("  -l, --list                list todo list\n");
    printf("  -h, --help                display this help and exit\n");
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
