//
// Created by micha on 14.04.2022.
//

#include "Player.h"
#include <sstream>

std::string Player::showHand()const {
std::stringstream os;
    for(auto card : cards_){
        os<<card<<std::endl;
//        os<< card << " ";
    }
    return os.str();
}

std::ostream& operator<<(std::ostream& os,const Player& player){
    os << "Player : " << player.name_ << "Points" << player.points_ <<std::endl;
    os<<player.showHand();
    os << "------------------------------";
}

void Player::takeCard(Karta *card) {
    if(cards_.size() != 10){
        cards_.push_back(card);
    }
}