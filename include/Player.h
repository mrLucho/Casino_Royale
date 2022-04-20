//
// Created by micha on 14.04.2022.
//

#ifndef CASINO_ROYALE_PLAYER_H
#define CASINO_ROYALE_PLAYER_H

#include "Karta.h"
#include "Casino.h"

class Player{
public:
    Player(std::string name);
    Player();
    void takeCard(Karta* card);
    std::string showHand() const;
    friend std::ostream& operator<<(std::ostream& os, const Player& player);
    bool askToPass(); //returns true or asks user to input

    void autoPass();//updates if points exceeded limit

    int getPoints()const{return points_;}
    bool isWinner()const {return points_ ==21;}
    bool getPass()const{return passed_;};
    bool operator==(const Player &other){return other.name_ == this->name_;}
private:

    std::vector<Karta*> cards_;
    int points_;
    std::string name_;
    bool passed_ = false;
};


#endif //CASINO_ROYALE_PLAYER_H
