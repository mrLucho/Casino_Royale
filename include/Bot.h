//
// Created by micha on 14.04.2022.
//

#ifndef CASINO_ROYALE_BOT_H
#define CASINO_ROYALE_BOT_H
#include <utility>

#include "Player.h"

enum class Courage {rash, normal, cautious};

class Bot : public IPlayer{
public:
    Bot(std::string name,Courage courage) : IPlayer(std::move(name)),courage_(courage) {};
    bool askToPass()override;

private:
    Courage courage_; // needed only for askToPass
};
#endif //CASINO_ROYALE_BOT_H
