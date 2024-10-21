#include <Card.h>
using namespace std;

Card::Card(Suit suit, int rank) : fSuit(suit), fRank(rank)
{
}

bool Card::operator==(const Card &other) const
{
    return fSuit == other.fSuit && fRank == other.fRank;
}

string Card::getName() const {
    string rankName;
    if (fRank == 14)
        rankName = "Ace";
    else if (fRank == 13)
        rankName = "King";
    else if (fRank == 12)
        rankName = "Queen";
    else if (fRank == 11)
        rankName = "Jack";
    else
        rankName = to_string(fRank); // For numbers 2-10, convert rank to string

    string suitName;
    switch (fSuit) {
        case Spades:   suitName = "Spades"; break;
        case Hearts:   suitName = "Hearts"; break;
        case Diamonds: suitName = "Diamonds"; break;
        case Clubs:    suitName = "Clubs"; break;
    }

    // Return the card's full name, e.g., "Ace of Spades"
    return rankName + " of " + suitName;
}