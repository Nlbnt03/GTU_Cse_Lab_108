#include <stdio.h>
void question2(int age, char gender)
{
    double drugA, drugB, drugC;
    switch (gender)
    {
    case 'M':
        if(age < 18)
        {
            drugA = 25;
            drugB = drugA * 2;
            drugC = 30 + drugB - (1.5 * (drugA / 2));
            break;
        }
        else if(18 <= age && age < 65)
        {
            drugA = 45;
            drugB = 5 * drugA;
            drugC = 40 + (2 * drugB) - (3 * (drugA / 2));
            break;
        }
        else if(age >= 65)
        {
            drugA = 30;
            drugB = 3 * drugA;
            drugC = 35 + drugB - (2.5 * (drugA / 2));
            break;
        }
        else
        {
            printf("invalid age");
            break;
        }
    case 'F':
        if(age < 18)
        {
            drugA = 25;
            drugB = drugA * 2;
            drugC = 30 + drugB - (1.5 * (drugA / 3));
            break;
        }
        else if(18 <= age && age < 65)
        {
            drugA = 45;
            drugB = 5 * drugA;
            drugC = 40 + (2 * drugB) - (3 * (drugA / 3));
            break;
        }
        else if(age >= 65)
        {
            drugA = 30;
            drugB = 3 * drugA;
            drugC = 35 + drugB - (2.5 * (drugA / 3));
            break;
        }
        else
        {
            printf("invalid age");
            break;
        }
    default:
        printf("invalid gender");
        break;
    }

    printf("Drug A = %.2lf\n",drugA);
    printf("Drug B = %.2lf\n",drugB);
    printf("Drug C = %.2lf\n",drugC);

}
int main()
{
    int age;
    char gender;
    printf("Enter a age : ");
    scanf("%d", &age);
    printf("Enter a gender (M or F) : ");
    scanf(" %c", &gender);
    question2(age,gender);
}