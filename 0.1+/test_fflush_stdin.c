#include <stdio.h>
#include <unistd.h>

int main()
{
    int i;
    char c;

    printf("input int i: \n");
    scanf("%d", &i);

    //fflush((NULL));
    //fflush(stdin);
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }

    printf("input char c: \n");
    scanf("%c", &c);

    printf("i = %d, c = %c\n", i, c);

    return 0;
}
