#include <iostream>
#include "Card.h"
using namespace std;

int main() {
    Card AceOfDiamond(Diamond, 14);
    Card TestCard(Diamond, 14);

    // Check if both cards are structurally equivalent
    if (AceOfDiamond == TestCard) {
        std::cout << "The test card is " << TestCard.getName << std::endl;
    }

    return 0;
}