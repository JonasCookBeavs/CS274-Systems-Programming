#include <stdio.h>
#include <string.h>

struct llm {
    char name[32];
    unsigned long long parameters;
    unsigned context;
};

void set_llm(struct llm *x, char *name, unsigned long long parameters,
             unsigned context)
{
    strcpy(x->name, name);
    x->parameters = parameters;
    x->context = context;
}

int main(void)
{
    struct llm opus;

    set_llm(&opus, "Opus", 700000000000, 2000000);

    printf("Model %s:\n", opus.name);
    printf("   Parameters: %llu\n", opus.parameters);
    printf("   Context   : %u\n", opus.context);
}