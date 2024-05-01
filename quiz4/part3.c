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

int main() {
    int n = 7; // Yıldızların maksimum sayısı
    int i, j;

    // Her satır için döngü
    for (i = 1; i <= n; i++) {
        // Her satırdaki yıldız sayısını belirleme
        int stars = (i <= (n+1)/2) ? i : n+1-i;

        // Boşlukları yazdırma
        for (j = 1; j <= n-stars; j++) {
            printf(" ");
        }

        // Yıldızları yazdırma
        for (j = 1; j <= 2*stars-1; j++) {
            printf("*");
        }

        // Bir sonraki satıra geçme
        printf("\n");
    }

    return 0;
}
