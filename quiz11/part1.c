#include <stdio.h>
#define PI 3.14
#include <math.h>

typedef struct 
{
    double width;
    double height;   
}Rectangle;

typedef struct 
{
    double radius;
}Circle;

typedef struct 
{
    double side1;
    double side2;
    double side3;
}Triangle;

void calculate_area(Rectangle rectangle, Circle circle, Triangle triangle, double areas[3])
{
    double rarea;
    double carea;
    double tarea;

    double tmpS;

    rarea = rectangle.width * rectangle.height;
    areas[0] = rarea;
    
    carea = PI * (circle.radius * circle.radius);
    areas[1] = carea;

    tmpS = (triangle.side1 + triangle.side2 + triangle.side3) / 2;
    tarea = sqrt(tmpS * (tmpS - triangle.side1) * (tmpS - triangle.side2) * (tmpS - triangle.side3));
    areas[2] = tarea;

}

int main()
{
    Rectangle rectangle = {5.0, 3.0};
    Circle circle = {2.0};
    Triangle triangle = {3.0, 4.0, 5.0};
    double areas[3];

    calculate_area(rectangle, circle, triangle, areas);

    printf("Inputs :\n");
    printf("Rectangle = {5.0, 3.0}\n");
    printf("Circle = {2.0}\n");
    printf("Triangle = {3.0, 4.0, 5.0}\n");

    printf("Outputs :\n");
    printf("Area Of Rectangle = %.2lf\n", areas[0]);
    printf("Area Of Circle = %.2lf\n", areas[1]);
    printf("Area Of Triangle = %.2lf\n", areas[2]);
    

}