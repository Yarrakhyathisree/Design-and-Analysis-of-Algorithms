#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SUITS = 4;
const int RANKS = 13;
const int DECK_SIZE = SUITS * RANKS;

struct Card {
    int suit;   
    int rank;   
};

void initializeDeck(Card deck[]) {
    int cardIndex = 0;
    for (int suit = 0; suit < SUITS; suit++) {
        for (int rank = 0; rank < RANKS; rank++) {
            deck[cardIndex].suit = suit;
            deck[cardIndex].rank = rank;
            cardIndex++;
        }
    }
}

void shuffleDeck(Card deck[]) {
    srand(static_cast<unsigned int>(time(0))); 
    for (int i = 0; i < DECK_SIZE; i++) {
        int j = rand() % DECK_SIZE;

        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void printCard(const Card& card)
{
    const char* suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    const char* ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

    cout << ranks[card.rank] << " of " << suits[card.suit];
}

void dealCards(Card deck[], int numPlayers, int numCardsPerPlayer)
{
    int cardIndex = 0;
    for (int player = 0; player < numPlayers; player++)
	{
        cout << "Player " << player + 1 << ":\n";
        for (int card = 0; card < numCardsPerPlayer; card++)
		{
            if (cardIndex < DECK_SIZE)
			{
                printCard(deck[cardIndex]);
                cout << endl;
                cardIndex++;
            } 
			else
			{
                cout << "No more cards left to deal.\n";
                return;
            }
        }
        cout << endl;
    }
}

int main() {
    Card deck[DECK_SIZE];

    initializeDeck(deck);  
    shuffleDeck(deck);      

    int numPlayers = 4;
    int numCardsPerPlayer = 5;

    dealCards(deck, numPlayers, numCardsPerPlayer);

    return 0;
}

