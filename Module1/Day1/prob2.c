#include <stdio.h>

int main() {
    int s;
    printf("Enter the student's Score: ");
    scanf("%d", &s);

    if (s >= 90 && s <= 100) {
        printf("Grade A\n");
    } else if (s >= 75 && s <= 89) {
        printf("Grade B\n");
    } else if (s >= 60 && s <= 74) {
        printf("Grade C\n");
    } else if (s >= 50 && s <= 59) {
        printf("Grade D\n");
    } else if (s >= 0 && s <= 49) {
        printf("Grade F\n");
    } else {
        printf("Invalid score\n");
    }

    return 0;
}
