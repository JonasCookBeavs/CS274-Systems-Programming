#include <stdio.h>
#include <string.h>

/*

*/

int main(void)
{
    struct llm
    {
        char name[32];
        unsigned long long parameters;
        unsigned int context;
    };

    struct llm llms[3] = {
        {.name = "Opus",
         .parameters = 700000000000,
         .context = 2000000},

        {.name = "Qwen",
         .parameters = 24000000000,
         .context = 262000},

        {.name = "Kimi", 
         .parameters = 1000000000000, 
         .context = 4000000}};
         
    for(int i = 0; i < 3; i++)
    {
        printf("Model %s:\n \tParameters: %llu\n\tContext   : %u\n", llms[i].name, llms[i].parameters, llms[i].context);
    }
}