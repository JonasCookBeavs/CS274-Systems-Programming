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

    // struct llm opus;
    // struct llm qwen;
    // struct llm kimi;

    // strcpy(opus.name, "Opus");
    // strcpy(qwen.name, "Qwen");
    // strcpy(kimi.name, "Kimi");

    // opus.parameters = 700000000000;
    // qwen.parameters = 24000000000;
    // kimi.parameters = 1000000000000;

    // opus.context = 2000000;
    // qwen.context = 262000;
    // kimi.context = 4000000;

    struct llm opus = {
        .name = "Opus",
        .parameters = 700000000000,
        .context = 2000000
    };

    struct llm qwen = {
        .name = "Qwen",
        .parameters = 24000000000,
        .context = 262000
    };

    struct llm kimi = {
        .name = "Kimi",
        .parameters = 1000000000000,
        .context = 4000000
    };
    printf("Model %s:\n \tParameters: %llu\n\tContext   : %u\n", opus.name, opus.parameters, opus.context);
    printf("Model %s:\n \tParameters: %llu\n\tContext   : %u\n", qwen.name, qwen.parameters, qwen.context);
    printf("Model %s:\n \tParameters: %llu\n\tContext   : %u\n", kimi.name, kimi.parameters, kimi.context);

}