//
// Created by micha on 13.04.2022.
//

#ifndef CASINO_ROYALE_CASINO_H
#define CASINO_ROYALE_CASINO_H

#include <vector>
#include <random>

#include "Karta.h"
#include "Player.h"
#include "Bot.h"
#include "IPlayer.h"



class Casino{
public:
    Casino(Casino const &a) = default;
    Casino(std::vector<IPlayer*>players);


    void shuffleDeck(int numTimes=100);
    friend std::ostream& operator<<(std::ostream& os, const Casino& casino);
    Karta* popCard();
    void setupGame();
    void play();
    bool checkGameOver();  // check if all passed
    std::string getWinner()const;
    std::string to_string()const;


//    --------------Debug
    std::string showPlayer(int num); //prints players hand
    int getDeckSize()const{return currentDeck_.size();} //current size

    Casino(int numHumanPlayers=4);
    ~Casino(){
        for (auto pObj = players_.begin();
             pObj != players_.end(); ++pObj) {
            delete *pObj; // Note that this is deleting what pObj points to,
            // which is a pointer
        }
    }

private:
    void prepareDeck(); //used once during constr of casino sets rng
    std::mt19937 rng_;
    std::vector<Karta*> currentDeck_;
    std::vector<IPlayer*> players_;
};
#endif //CASINO_ROYALE_CASINO_H
