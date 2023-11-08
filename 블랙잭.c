#include <stdio.h>
#include "head.h"

void blackjack() {
    int snack;
    printf("블랙잭 게임\n");
    printf("베팅할 간식 수를 입력하세요 \n");
    printf("입력 : ");
    scanf_s(" %d\n", &snack);
    printf("입력한 개수 : %d개\n", snack);
    printf("게임이 시작됩니다. \n");
}

