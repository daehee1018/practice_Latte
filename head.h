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
int main() {
    srand(time(NULL));
    struct Card deck[52];
    int deck_size = 52;
    int player_score = 0;
    int dealer_score = 0;
    int playAgain = 1;}