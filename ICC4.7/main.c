#include <stdio.h>

/**
 * Display a file on stdout.
 */
void cat(char *filename)
{
    char buf[4096];
    int count;

    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        perror("cat");
        return;
    }

    do {
        count = fread(buf, 1, sizeof buf, fp);
        fwrite(buf, 1, count, stdout);
    } while (count > 0);

    putchar('\n');

    fclose(fp);
}

/**
 * Main.
 */
int main(void)
{
    // TODO: Open the file `seeker.txt` for writing
    FILE* fp = fopen("seeker.txt", "w");
    // Turn off buffering for this demo
    // (Replace `fp` with whatever your `FILE*` variable is)
    setbuf(fp, NULL);

    // TODO: Write 60 `-` characters to the file
    fputs("------------------------------------------------------------", fp);
    // TODO: Seek to position 0
    // TODO: Write "interrupting"
    // TODO: cat("seeker.txt");
    fseek(fp, 0, SEEK_SET);
    fputs("interrupting", fp);
    cat("seeker.txt");

    // TODO: Seek to position 40
    // TODO: Write "cow"
    // TODO: cat("seeker.txt");
    fseek(fp, 40, SEEK_SET);
    fputs("cow", fp);
    cat("seeker.txt");

    // TODO: Seek to position 20
    // TODO: Write "MOOOOOOO!"
    // TODO: cat("seeker.txt");
    fseek(fp, 20, SEEK_SET);
    fputs("MOOOOOOO!", fp);
    cat("seeker.txt");

    // TODO: Close the file
    fclose(fp);
}