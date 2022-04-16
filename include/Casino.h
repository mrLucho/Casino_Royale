//
// Created by micha on 13.04.2022.
//

#ifndef CASINO_ROYALE_CASINO_H
#define CASINO_ROYALE_CASINO_H

#include <vector>
#include <random>

#include "Karta.h"
#include "Player.h"
class Casino{
public:
    Casino();
    void shuffleDeck(int numTimes=100);
    friend std::ostream& operator<<(std::ostream& os, const Casino& casino);
    Karta* popCard();

private:
    void prepareDeck();
    std::mt19937 rng_;
    std::vector<Karta*> currentDeck_;
    std::vector<Player*> players_;
};
#endif //CASINO_ROYALE_CASINO_H
