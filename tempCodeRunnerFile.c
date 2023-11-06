// 카드 모양 정의
enum Suit { SPADES, DIAMONDS, HEARTS, CLUBS };

// 카드 랭크 정의
enum Rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

// 카드 구조체
struct Card {
    enum Suit suit;
    enum Rank rank;
};
