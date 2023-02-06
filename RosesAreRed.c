#include <stdio.h>

int main()
{
    char color[20];
    char noun[20];
    char name1[20];
    //char name2[20];
    
    printf("Enter a color:");
    scanf("%s", color);
    printf("Enter a plural noun:");
    scanf("%s", noun);
    printf("Enter a name:");
    scanf("%s", name1);
    
    printf("Roses are %s,\n", color);
    printf("%s are blue,\n", noun );
    //printf("I love %s %s.", name1, name2);
    printf("I love %s.", name1);

    return 0;
}
