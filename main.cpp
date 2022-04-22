#include <iostream>
//#include "Karta.h"
#include "Casino.h"
//#include <Player.h>
int main() {
//    Casino casinoRoyale = Casino(true);
//    casinoRoyale.shuffleDeck();
//    casinoRoyale.setupGame();

    Player player1 =  Player("pl 1");
    Player player2 = Player("pl 2");
    Player player3 = Player("pl 3");
    Player player4 = Player("pl 4");
    std::vector<Player*> players = {&player1,&player2,&player3,&player4};


    Casino casinoRoyale = Casino(players);
    casinoRoyale.shuffleDeck();
    casinoRoyale.setupGame();
//    std::cout<<casinoRoyale.showPlayer(0);
//    std::cout<<casinoRoyale.getDeckSize()<<std::endl;
    std::cout<<casinoRoyale;

    return EXIT_SUCCESS;
}
