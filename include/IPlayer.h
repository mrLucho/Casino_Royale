//
// Created by user on 26.04.2022.
//

#ifndef CASINO_ROYALE_IPLAYER_H
#define CASINO_ROYALE_IPLAYER_H

#include <utility>

#include "Karta.h"
#include "vector"
class IPlayer{
public:
    IPlayer(std::string name):name_(std::move(name)){};
    virtual ~IPlayer()=default;
    void takeCard(Karta* card);
    friend std::ostream& operator<<(std::ostream& os, const IPlayer& player);
    std::string showHand() const;


    void autoPass();//updates if points exceeded limit
    int getPoints()const{return points_;}
    bool isWinner()const {return points_ ==21;}
    bool getPass()const{return passed_;};
    bool operator==(const IPlayer &other){return other.name_ == this->name_;}

    virtual bool askToPass() = 0;

    void PunktyRzeczywiscieWyjebalo()const{if(points_>100){std::cout<<"jeblo"<<std::endl;}};

protected:
    std::vector<Karta*> cards_;
    int points_ = 0;
    bool passed_ = false;
    std::string name_;
};


#endif //CASINO_ROYALE_IPLAYER_H
