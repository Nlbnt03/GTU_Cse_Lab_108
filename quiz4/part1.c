#include <stdio.h>
int faktoriyel(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * faktoriyel(n - 1);
  }
}
int kombinasyon(int n, int k) {
  return faktoriyel(n) / (faktoriyel(k) * faktoriyel(n - k));
}

void pascal_ucgeni(int satirSayisi, int baslangicBosluk) {
  int i, j;
  if(satirSayisi % 2 != 0)
  {
    satirSayisi++;
  }
  for (i = 0; i < satirSayisi; i++) {
    for (j = 0; j < baslangicBosluk + satirSayisi - i - 1; j++) {
      printf(" ");
    }
    for (j = 0; j <= i; j++) {
        if(kombinasyon(i,j) % 2 == 0)
        {
            printf(" ");
            printf(" ");
        }
        else
        {
            printf("*");
            printf(" ");
        }
    }
    printf("\n");
  }
}
void elmas_ciz(int boyut, int baslangic_bosluk)
{
    int total_bosluk;
  int k = 1;
  int counter = 0;
  if (boyut % 2 == 0)
  {
    boyut++; 
  }
  while (k != boyut)
  {
    k+=2;
    counter++;
  }
    int n = boyut; 
    int i, j;

    for (i = 1; i <= n; i++) {
        int stars;
        if (i <= (n + 1) / 2)
        {
            stars = i;
        }
        else
        {
            stars = n + 1 - i;
        }

        for (j = 1; j <= n-stars; j++) {
            printf(" ");
        }

        for (j = 1; j <= 2*stars-1; j++) {
            printf("*");
        }

        printf("\n");
    }
  
}
int main() {
  int satirSayisi;
  int flag = 1;
  int choice;
    int choice2;
  while (flag)
  {
    printf("1. Pascal's Triangle Pattern\n2. Diamond Pattern\n3. Exit\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        printf("Enter the pattern size :");
        scanf("%d",&satirSayisi);
        pascal_ucgeni(satirSayisi,0);
        printf("would you like to draw another pattern ? (yes : 1, no : 0) :");
        scanf("%d",&choice2);
        if (choice2 == 0)
        {
            flag = 0;
        }
        break;
    case 2:
        printf("Enter the pattern size :");
        scanf("%d",&satirSayisi);
        elmas_ciz(satirSayisi,0);
        printf("would you like to draw another pattern ? (yes : 1, no : 0) :");
        scanf("%d",&choice2);
        if (choice2 == 0)
        {
            flag = 0;
        }
        break;
    case 3:
        flag = 0;
        printf("Exiting ...");
        break;
    default:
        printf("invalid choice !\n");
        break;
    }
  }
  return 0;
}
