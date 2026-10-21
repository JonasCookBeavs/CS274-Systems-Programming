#include <stdio.h>

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
    // TODO
}

/**
 * Write a given struct to the record number.
 */
void record_write(FILE *fp, int record_num, struct starship *s)
{
    // TODO
}

int main(int argc, char *argv[])
{
    
}