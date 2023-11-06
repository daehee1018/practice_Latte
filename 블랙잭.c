#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// 카드 모양 정의
enum Suit { SPADES, DIAMONDS, HEARTS, CLUBS };

// 카드 랭크 정의
enum Rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

// 카드 구조체
struct Card {
    enum Suit suit;
    enum Rank rank;
};


// 카드 덱을 초기화하는 함수
void initialize_deck(struct Card deck[]) {
    int index = 0;
    for (int suit = SPADES; suit <= CLUBS; suit++) {
        for (int rank = ACE; rank <= KING; rank++) {
            deck[index].suit = suit;
            deck[index].rank = rank;
            index++;
        }
    }
}

// 카드를 무작위로 섞는 함수
void shuffle_deck(struct Card deck[], int size) {
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        struct Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// 카드를 출력하는 함수
void print_card(struct Card card) {
    char* suit_names[] = { "♠", "♦", "♥", "♣" };
    char* rank_names[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
    printf("\n┌─────────┐\n");
    printf("│%s        │\n",suit_names[card.suit]);
    printf("│         │\n");
    printf("│         │\n");
    printf("│         │\n");
    printf("│    %s    │\n",rank_names[card.rank - 1] );
    printf("│         │\n");
    printf("│         │\n");
    printf("│        %s│\n",suit_names[card.suit]);
    printf("└─────────┘");
printf("%s %s",suit_names[card.suit], rank_names[card.rank - 1]);}

void print_card1(struct Card card) {
    char* suit_names[] = { "♠", "♦", "♥", "♣" };
    char* rank_names[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
    


    printf("%s %s",suit_names[card.suit], rank_names[card.rank - 1]);
    }

// 카드 합을 계산하는 함수
int calculate_hand_value(struct Card hand[], int num_cards) {
    int value = 0;
    int num_aces = 0;

    for (int i = 0; i < num_cards; i++) {
        int rank = hand[i].rank;
        if (rank >= TEN) {
            value += 10;
        } else if (rank == ACE) {
            num_aces++;
            value += 11;
        } else {
            value += rank;
        }
    }

    while (value > 21 && num_aces > 0) {
        value -= 10;
        num_aces--;
    }

    return value;
}

int main() {
    srand(time(NULL));
    struct Card deck[52];
    int deck_size = 52;
    int player_score = 0;
    int dealer_score = 0;
    int playAgain = 1;

    printf("블랙잭 게임을 시작합니다.\n");

    while (playAgain) {
        struct Card player_hand[10];
        struct Card dealer_hand[10];
        int player_hand_size = 0;
        int dealer_hand_size = 0;

        initialize_deck(deck);
        shuffle_deck(deck, deck_size);

        // 플레이어와 딜러에게 초기 카드 2장씩 나눠줌
        player_hand[player_hand_size++] = deck[--deck_size];
        dealer_hand[dealer_hand_size++] = deck[--deck_size];
        player_hand[player_hand_size++] = deck[--deck_size];
        dealer_hand[dealer_hand_size++] = deck[--deck_size];

        printf("당신의 패: ");
        print_card(player_hand[0]);
        printf(" ");
        print_card(player_hand[1]);
        printf("\n딜러의 패: X ");
        print_card(dealer_hand[1]);
        printf("\n");
  




        while (1) {
            int player_value = calculate_hand_value(player_hand, player_hand_size);

            if (player_value == 21) {
                printf("블랙잭! 당신 승리!\n");
                player_score += 3;
                break;
            } else if (player_value > 21) {
                printf("패배! 21을 초과했습니다.\n");
                player_score -= 2;
                break;
            }

            printf("카드를 더 받으시겠습니까? (1: 예, 2: 아니오): ");
            int choice;
            scanf("%d", &choice);

            if (choice == 1) {
                player_hand[player_hand_size++] = deck[--deck_size];
                printf("당신의 패: ");
                for (int i = 0; i < player_hand_size; i++) {
                    print_card(player_hand[i]);
                    printf(" ");
                }
                printf("\n");
            } else {
                while (1) {
                    int dealer_value = calculate_hand_value(dealer_hand, dealer_hand_size);
                    if (dealer_value >= 17) {
                        break;
                    }
                    dealer_hand[dealer_hand_size++] = deck[--deck_size];
                }

                printf("딜러의 패: ");
                for (int i = 0; i < dealer_hand_size; i++) {
                    print_card(dealer_hand[i]);
                    printf(" ");
                }
                printf("\n");

                int dealer_value = calculate_hand_value(dealer_hand, dealer_hand_size);

                if (dealer_value > 21 || player_value > dealer_value) {
                    printf("당신 승리!\n");
                    player_score += 2;
                } else if (player_value < dealer_value) {
                    printf("패배! 딜러 승리!\n");
                    player_score -= 2;
                } else {
                    printf("무승부!\n");
                }
                break;
            }
        }

        printf("현재 점수 - 당신: %d, 딜러: %d\n", player_score, dealer_score);

        printf("게임을 계속하시겠습니까? (1: 예, 2: 아니오): ");
        scanf("%d", &playAgain);
    }

    printf("게임 종료. 최종 점수 - 당신: %d, 딜러: %d\n", player_score, dealer_score);

    return 0;
}
/* printf("┌─────────┐┌─────────┐\n");
    printf("│ %s       ││ %s       │\n", suit, suit);
    printf("│         ││         │\n");
    printf("│         ││         │\n", suit);
    printf("│         ││         │\n", suit);
    printf("│    %d   ││   %d    │\n",(player_hand[0]),print_card(player_hand[1]));
    printf("│         ││         │\n", suit);
    printf("│         ││         │\n");
    printf("│        %s ││       %s │\n", suit, suit);
    printf("└─────────┘└─────────┘\n");
    printf("딜러 카드의 합 :???\n");
    printf("┌─────────┐┌─────────┐\n");
    printf("│ %s       ││ %s       │\n", suit, suit);
    printf("│         ││         │\n");
    printf("│         ││         │\n", suit);
    printf("│         ││         │\n", suit);
    printf("│    7    ││    10   │\n");
    printf("│         ││         │\n", suit);
    printf("│         ││         │\n");
    printf("│       %s ││       %s │\n", suit, suit);
    printf("└─────────┘└─────────┘\n");
    printf("유저 카드의 합 :17\n");*/