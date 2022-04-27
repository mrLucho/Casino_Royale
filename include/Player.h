//
// Created by micha on 14.04.2022.
//

#ifndef CASINO_ROYALE_PLAYER_H
#define CASINO_ROYALE_PLAYER_H

#include <utility>
#include <vector>
#include "IPlayer.h"


class Player:public IPlayer{
public:
    Player(std::string name) : IPlayer(std::move(name)){}
    bool askToPass()override; //returns true or asks user to input, uses auto pass
};


#endif //CASINO_ROYALE_PLAYER_H
