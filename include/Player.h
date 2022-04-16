//
// Created by micha on 14.04.2022.
//

#ifndef CASINO_ROYALE_PLAYER_H
#define CASINO_ROYALE_PLAYER_H

#include "Karta.h"
#include "Casino.h"

class Player{
public:
    void takeCard(Karta* card);
    std::string showHand () const;
    friend std::ostream& operator<<(std::ostream& os, const Player& player);

private:
    std::vector<Karta*> cards_;
    int points_;
    std::string name_;
};


#endif //CASINO_ROYALE_PLAYER_H
