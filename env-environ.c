#include <unistd.h>
#include <stdio.h>

extern char **environ;

int main(int ac, char **av, char **env)
{
    (void)(ac);
    (void)(av);

    printf("adress env %p\n", (void *) env);
    printf("adress environ %p\n", (void *) environ);

    return (0);

}