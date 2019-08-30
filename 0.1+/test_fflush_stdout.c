#include <stdio.h>
#include <unistd.h>

int main()
{
    for(int i = 0; i < 10; i++)
    {
        printf("%d", i);
        //fflush((NULL));
        fflush(stdout);
        sleep(1);
    }
    printf("\n");

    return 0;
}
