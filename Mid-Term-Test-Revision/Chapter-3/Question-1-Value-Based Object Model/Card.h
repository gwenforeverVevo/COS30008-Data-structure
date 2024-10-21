class Card
{
public:
    Card(Suit suit, int rank) : fSuit(suit), fRank(rank) {}
    bool operator==(const Card &other) const;
    std::string getName() const;

private:
    Suit fSuit;
    int fRank;
};