
#include "Bot.h"

bool Bot::askToPass() {
    autoPass();
    if (getPass()) return true;

    switch (courage_) {
        case Courage::rash:
            return false;

        case Courage::normal:
            if (points_ >=18) passed_ = true;
            return passed_;

        case Courage::cautious:
            if (points_ >=14) passed_= true;
            return passed_;
    }
}