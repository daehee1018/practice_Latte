#include "head.h"
void title() {
    int start_num;
    printf("----------Cat Snack Collection Game----------\n");
    printf("|1. 가위바위보 게임                         |\n");
    printf("|2. 블랙잭 게임                             |\n");
    printf("|3. 상점                                    |\n");
    printf("|4. 게임 설명                               |\n");
    printf("---------------------------------------------\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("---------------------------------------------\n");
    printf("\t 이동할 화면의 숫자를 입력하세요!\n");
    scanf_s("%d", &start_num);
    if (start_num == 1) { system("cls"); rock(); }
    else if (start_num == 2) { system("cls"); blackjack(); }
    else if (start_num == 3) { system("cls");}
    else if (start_num == 4) { printf("%d", snack); }


}