#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_OF_STARSHIP (sizeof(char[128]) + sizeof(int) + sizeof(float) + sizeof(char[128]))

/**
 * Information about each starship
 */
struct starship {
    char name[128];
    int passengers;
    float speed; // 1.0 = speed of light
    char destination[128];
};

/**
 * Read a given record number into the struct.
 */
void record_read(FILE *fp, int record_num, struct starship *s)
{
    fseek(fp, record_num * sizeof(struct starship), SEEK_SET);
    fread(s, sizeof *s, 1, fp);
    printf("Record %d:\n\n", record_num);
    printf("    Name:        %s\n", s->name);
    printf("    Passengers:  %d\n", s->passengers);
    printf("    Speed:       %f\n", s->speed);
    printf("    Destination: %s\n\n", s->destination);
}

/**
 * Write a given struct to the record number.
 */
void record_write(FILE *fp, int record_num, struct starship *s)
{
    fseek(fp, record_num*SIZE_OF_STARSHIP, SEEK_SET);
    fwrite(s, sizeof *s, 1, fp);
}

void usage(char *cmd)
{
    fprintf(stderr, "usage: %s r rec | w rec name passengers speed dest\n", cmd);
    exit(1);
}

int main(int argc, char *argv[])
{
    if (argc == 1) usage(argv[0]);
    
    char *file_name = "database.dat";
    FILE* fp;
    if(fopen(file_name, "r+b"))
    {
        fp = fopen(file_name, "r+b");
    }
    else {
        fp = fopen(file_name, "w+b");
    }

    if(strcmp(argv[1], "w") == 0)
    {
        struct starship ship = {
            .passengers = atoi(argv[4]),
            .speed = atof(argv[5]),
        };

        strcpy(ship.name, argv[3]);
        strcpy(ship.destination, argv[6]);
        record_write(fp, atoi(argv[2]), &ship);
    }
    else 
    {
        struct starship ship;
        record_read(fp, atoi(argv[2]), &ship);
    }

    fclose(fp);
}