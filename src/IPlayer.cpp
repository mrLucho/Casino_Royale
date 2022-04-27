//
// Created by user on 26.04.2022.
//

#include <sstream>
#include "IPlayer.h"
std::string IPlayer::showHand()const {
    std::stringstream os;
    os<<IPlayer::name_<<" Points: " << IPlayer::points_<<std::endl;
    for(auto card : cards_){
        os<<*card<<" ";
    }
    os<<std::endl;
    return os.str();
}
void IPlayer::takeCard(Karta* card) {
    if(cards_.size() != 10){
        cards_.push_back(card);
        points_+= card->getWartosc();
    }
}

std::ostream& operator<<(std::ostream& os,const IPlayer& player){
    os<<player.showHand();
    return os;
}

void IPlayer::autoPass() {
    if(points_ >= 21){
        passed_ = true;
    }
}

std::string IPlayer::getCardsForFile() const {
    std::stringstream os;
    for (auto cardPtr:cards_) {
        os<<cardPtr->getFigura()<<' ';
        switch (cardPtr->getKolor()) {
            case 6:
                os<<"spades";
                break;
            case 3:
                os<<"hearts";
                break;
            case 4:
                os<<"diamonds";
                break;
            case 5:
                os<<"clubs";
                break;
            default:
                os<<"this will never happen";
        }
    }
    return os.str();
}