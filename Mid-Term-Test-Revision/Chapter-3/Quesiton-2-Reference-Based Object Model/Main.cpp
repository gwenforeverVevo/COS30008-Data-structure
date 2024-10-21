#include <iostream>
#include "Card.h"
using namespace std;


int main()
{
    // Complete the dynamic memory allocation and pointer comparison
    Card *AceOfDiamond = new AceOfDiamond(Diamond, 14);
    Card *TestCard = new  TestCard(Diamonds, 13);

    if (*AceOfDiamond == *TestCard)
    {
        std::cout << "The test card is " << TestCard.getName << std::endl;
    }

    delete AceOfDiamond;
    delete TestCard;
    return 0;
}