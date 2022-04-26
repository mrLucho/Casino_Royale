//
// Created by micha on 14.04.2022.
//

#ifndef CASINO_ROYALE_PLAYER_H
#define CASINO_ROYALE_PLAYER_H

#include <utility>
#include <vector>
#include "Karta.h"
#include "IPlayer.h"
class Player:public IPlayer{
public:
    Player(std::string name) : IPlayer(name){}
    bool askToPass()override; //returns true or asks user to input uses auto pass




//    bool operator==(const Player &other){return other.name_ == this->name_;}
//    void takeCard(Karta* card);
//    friend std::ostream& operator<<(std::ostream& os, const Player& player);
//    std::string showHand() const;


//    void autoPass();//updates if points exceeded limit
//    int getPoints()const{return points_;}
//    bool isWinner()const {return points_ ==21;}
//    bool getPass()const{return passed_;};
//    bool operator==(const Player &other){return other.name_ == this->name_;}


//protected:
//    std::vector<Karta*> cards_;
//    int points_ = 0;
//    bool passed_ = false;
//    std::string name_;

};


#endif //CASINO_ROYALE_PLAYER_H
