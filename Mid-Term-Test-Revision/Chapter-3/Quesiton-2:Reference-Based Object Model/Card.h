class Card {
public:
    Card(Suit suit, int rank) : fSuit(suit), fRank(rank) {}
    std::string getName() const;

private:
    Suit fSuit;
    int fRank;
};