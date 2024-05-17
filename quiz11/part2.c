#include <stdio.h>

union VehicleData
{
    struct
    {
        int door;
        int seat;
    }car;
    
    struct
    {
        int wheels;
        int power;
    }motorcycle;

    struct
    {
        int wheels;
    }bicycle;
};

typedef struct
{
    union VehicleData data;
    int type;
}Vehicle;


int calculateMaxSpeed(Vehicle vehicle)
{
    int max_speed;
    if (vehicle.type == 0)
    {
        max_speed = vehicle.data.car.door * 20;
    }
    else if (vehicle.type == 1)
    {
        max_speed = vehicle.data.motorcycle.power / 2; 
    }
    else if (vehicle.type == 2)
    {
        max_speed = 30; 
    }

    return max_speed;
}


void modify_car_doors(Vehicle *car, int new_num_doors)
{
   car->data.car.door = new_num_doors;
}

int main()
{
    Vehicle vehicle;
    vehicle.type = 0;

    if (vehicle.type == 0) 
    {
        vehicle.data.car.door = 4;
        vehicle.data.car.seat = 5;
    }
    printf("Max Speed: %d\n", calculateMaxSpeed(vehicle));
    modify_car_doors(&vehicle, 2);
    printf("Updated Maximum Speed of Car : %d\n", calculateMaxSpeed(vehicle));

    printf("\n");
    vehicle.type = 1;
    if (vehicle.type == 1) 
    {
        vehicle.data.motorcycle.wheels = 2;
        vehicle.data.motorcycle.power = 250;
    } 
    printf("Motorcycle Max Speed: %d\n", calculateMaxSpeed(vehicle));

    printf("\n");
    vehicle.type = 2;
    if (vehicle.type == 2) 
    {
        vehicle.data.bicycle.wheels = 2;
    }
    printf("Bicycle Max Speed: %d\n", calculateMaxSpeed(vehicle));
    return 0;

    
}