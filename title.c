#include "head.h"
void title() {
    int start_num;
    printf("----------Cat Snack Collection Game----------\n");
    printf("|1. ���������� ����                         |\n");
    printf("|2. ���� ����                             |\n");
    printf("|3. ����                                    |\n");
    printf("|4. ���� ����                               |\n");
    printf("---------------------------------------------\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("---------------------------------------------\n");
    printf("\t �̵��� ȭ���� ���ڸ� �Է��ϼ���!\n");
    scanf_s("%d", &start_num);
    if (start_num == 1) { system("cls"); rock(); }
    else if (start_num == 2) { system("cls"); blackjack(); }
    else if (start_num == 3) { system("cls");}
    else if (start_num == 4) { printf("%d", snack); }


}