#include <stdio.h>
#include <math.h>
void region(double x, double y)
{
    if(x > 0 && y > 0)
    {
        printf("(%.2lf , %.2lf) Region is Q1\n",x,y);
    }
    else if(x > 0 && y < 0)
    {
        printf("(%.2lf , %.2lf) Region is Q4\n",x,y);
    }
    else if(x < 0 && y < 0)
    {
        printf("(%.2lf , %.2lf) Region is Q3\n",x,y);
    }
    else if(x < 0 && y > 0)
    {
        printf("(%.2lf , %.2lf) Region is Q2\n",x,y);
    }
    else
    {
        printf("(%.2lf , %.2lf) invalid region\n",x,y);
    }
}

void calculate_distance()
{
    double x, y, x1, y1;

    printf("Enter coordinates of first point (x y): ");
    scanf("%lf %lf", &x, &y);

    printf("Enter coordinates of second point (x1 y1): ");
    scanf("%lf %lf", &x1, &y1);

    double distance = sqrt(pow(x1 - x, 2) + pow(y1 - y, 2));

    printf("Distance between the points: %.2lf\n", distance);
    region(x,y);
    region(x1,y1);
}
int main() {
    calculate_distance();
    return 0;
}
