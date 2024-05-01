#include <stdio.h>

// Kombinasyon hesaplayan fonksiyon
int kombinasyon(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    } else {
        return kombinasyon(n - 1, k - 1) + kombinasyon(n - 1, k);
    }
}

// Pascal üçgenini çizen fonksiyon
void pascal_ucgeni(int satirSayisi) {
    int i, j;
    for (i = 0; i < satirSayisi; i++) {
        // Boşlukları basma
        for (j = 0; j < satirSayisi - i - 1; j++) {
            printf("  "); // Her bir boşluk için iki adet boşluk basıyoruz
        }
        // Yıldızları veya boşlukları basma
        for (j = 0; j <= i; j++) {
            if (kombinasyon(i, j) % 2 == 0) {
                printf("  "); // Boşluk
            } else {
                printf("* "); // Yıldız ve bir boşluk
            }
        }
        printf("\n");
    }
}

int main() {
    int satirSayisi = 7; // Üçgenin satır sayısı
    pascal_ucgeni(satirSayisi);
    return 0;
}
