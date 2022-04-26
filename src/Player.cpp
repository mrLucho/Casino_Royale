
#include "Player.h"
#include <sstream>

//std::string Player::showHand()const {
//    std::stringstream os;
//    os<<Player::name_<<" Points: " << Player::points_<<std::endl;
//    for(auto card : cards_){
//        os<<*card<<std::endl;
//    }
//    return os.str();
//}
//void Player::takeCard(Karta *card) {
//    if(cards_.size() != 10){
//        cards_.push_back(card);
//        points_+= card->getWartosc();
//    }
//}
//
//std::ostream& operator<<(std::ostream& os,const Player& player){
//    os<<player.showHand();
//    return os;
//}
//
//void Player::autoPass() {
//    if(points_ >= 21){
//        passed_ = true;
//    }
//}



bool Player::askToPass() {
//    first check if needed to ask
    autoPass();
    if(getPass()){
        return true;
    }
    else{
        std::string decision;
        std::cout<<name_<<std::endl;
        std::cout<<"Do u want to pass? if so type true or false:"<<std::endl;
        std::cin>>decision;
        if(decision == "true"){
            passed_ = true;
            return true;
        }
        else if(decision == "false"){
            return false;
        }
        else{
            std::cout<<"learn how to type moron, I take it as yes"<<std::endl;
            passed_ = true;
            return true;
        }
    }
}



