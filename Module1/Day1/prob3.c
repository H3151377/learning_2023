#include <stdio.h>

int main() {
    int rn;
    char name[50];
    float phy, math, chem;
    float tm, pc;

    // Read the input from the user
    printf("Enter Roll No: ");
    scanf("%d", &rn);

    printf("Enter Name: ");
    scanf(" %[^\n]s", name);

    printf("Enter Marks in Physics: ");
    scanf("%f", &phy);

    printf("Enter Marks in Math: ");
    scanf("%f", &math);

    printf("Enter Marks in Chemistry: ");
    scanf("%f", &chem);

    tm = phy + math + chem;
    pc = (tm / 300) * 100;

    printf("\n------- Student Summary -------\n");
    printf("Roll No: %d\n", rn);
    printf("Name: %s\n", name);
    printf("Physics Marks: %.2f\n", phy);
    printf("Math Marks: %.2f\n", math);
    printf("Chemistry Marks: %.2f\n", chem);
    printf("Total Marks: %.2f\n", tm);
    printf("Percentage: %.2f%%\n", pc);

    return 0;
}
