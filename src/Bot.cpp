//
// Created by micha on 14.04.2022.
//
#include "Bot.h"

bool Bot::askToPass() {
    autoPass();
    std::cout<<"func from bot has been called" << std::endl;
    if (getPass()) return true;

    switch (courage_) {
        case Courage::rash:
            return false;

        case Courage::normal:
            if (points_ >=18) return true;
            else return false;

        case Courage::cautious:
            if (points_ >=14) return true;
            else return false;
    }
}