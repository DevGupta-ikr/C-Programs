// Program to calculate the area of a circle

#include<stdio.h>

int main()
{
    float radius, area;

    printf("Enter Radius =  ");
    scanf("%f", &radius);

    area = 3.14159 * radius * radius;
    printf("\nArea = %.2f", area);

    return 0;
}
