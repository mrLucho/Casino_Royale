
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



