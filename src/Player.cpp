
#include "Player.h"
#include <sstream>

bool Player::askToPass() {
//    first check if needed to ask
    autoPass();
    if(getPass()){
        return true;
    }
    else{
        std::string decision;
        std::cout<<name_<<std::endl;
        std::cout<<"Do u want to pass? if so type yes or no:"<<std::endl;
        std::cin>>decision;
        std::cout<<std::endl;
        if(decision == "yes"){
            passed_ = true;
            return true;
        }
        else if(decision == "no"){
            return false;
        }
        else{
            std::cout<<"learn how to type moron, I take it as yes"<<std::endl;
            passed_ = true;
            std::cout<<std::endl;
            return true;
        }

    }
}



