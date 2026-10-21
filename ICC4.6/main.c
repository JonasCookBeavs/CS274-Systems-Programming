#include <stdio.h>
#include <stdlib.h>

void read_file(char *filename)
{
    char s[1024];  // Big enough for any line this program will encounter
    int linecount = 0;

    if(!fopen(filename, "r")) return;
    FILE* fp = fopen(filename, "r");

    while (fgets(s, sizeof s, fp) != NULL) 
        printf("%d: %s", ++linecount, s);

    printf("\n");
    fclose(fp);
}

void write_file(char *filename, char *data)
{
    if(!fopen(filename, "w")) return;
    FILE* fp = fopen(filename, "w");
    fputs("------ BEGIN ------\n", fp);
    fputs("Data: ", fp);
    fputs(data, fp);
    fputs("\n", fp);
    fputs("------ END ------", fp);

    fclose(fp);
}

void usage(char *cmd)
{
    fprintf(stderr, "usage: %s r filename | w filename \"data\"\n", cmd);
    exit(1);
}

int main(int argc, char *argv[])
{
    if (argc == 1) usage(argv[0]);

    switch (argv[1][0]) {
    case 'r':
        if (argc != 3) usage(argv[0]);
        read_file(argv[2]);
        break;

    case 'w':
        if (argc != 4) usage(argv[0]);
        write_file(argv[2], argv[3]);
        break;

    default: usage(argv[0]);
    }
}