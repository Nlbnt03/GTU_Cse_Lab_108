#include <stdio.h>

// Fonksiyon prototipleri
int isLeapYear(int year);
int dayOfMonth(int month, int year);
int dayOfYear(int day, int month, int year);
int daysBetweenDates(int day1, int month1, int year1, int day2, int month2, int year2);

// Bir sonraki günü hesaplayın ve yazdırın
void nextDate(int day, int month, int year) {
    int days_in_month = dayOfMonth(month, year);

    // Eğer gün sayısı ayın son gününden küçükse
    if (day <= days_in_month) {
        printf("%02d %02d %04d\n", day, month, year);
    }
    // Eğer gün sayısı ayın son gününe eşitse ve ay sonu değilse
    else if (day == days_in_month && month != 12) {
        printf("01 %02d %04d\n", month + 1, year);
    }
    // Eğer gün sayısı ayın son günü ve yılın son ayıysa
    else if (day == days_in_month && month == 12) {
        printf("01 01 %04d\n", year + 1);
    }
}

int main() {
    int first_day, first_month, first_year;
    int second_day, second_month, second_year;

    // İlk tarihin girişi
    printf("enter a first date (dd mm yyyy): ");
    scanf("%d %d %d", &first_day, &first_month, &first_year);

    // İkinci tarihin girişi
    printf("enter a second date (dd mm yyyy): ");
    scanf("%d %d %d", &second_day, &second_month, &second_year);

    // İki tarih arasındaki gün sayısını hesaplayın
    int days_between = daysBetweenDates(first_day, first_month, first_year, second_day, second_month, second_year);

    // Hesaplanan gün sayısını yazdırın
    printf("Days between the two dates: %d\n", days_between);
    printf("following day: ");
    nextDate(first_day + 1, first_month, first_year);

    return 0;
}

// Artık yıl kontrolü
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Verilen ay ve yıla göre ayın gün sayısını döndürme
int dayOfMonth(int month, int year) {
    switch(month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return -1; // Geçersiz ay
    }
}

// Verilen tarihin yılın kaçıncı günü olduğunu hesaplayın
int dayOfYear(int day, int month, int year) {
    int day_count = day;

    for (int i = 1; i < month; i++) {
        day_count += dayOfMonth(i, year);
    }

    return day_count;
}

// İki tarih arasındaki gün sayısını hesaplayın
int daysBetweenDates(int day1, int month1, int year1, int day2, int month2, int year2) {
    int day_count1 = dayOfYear(day1, month1, year1);
    int day_count2 = dayOfYear(day2, month2, year2);

    int year_diff = year2 - year1;
    int leap_years = 0;

    // Artık yılları sayın
    for (int i = year1; i < year2; i++) {
        if (isLeapYear(i)) {
            leap_years++;
        }
    }

    int total_days = (year_diff * 365) + leap_years + (day_count2 - day_count1);

    return total_days;
}


