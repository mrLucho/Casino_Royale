#include <iostream>
#include "Casino.h"

int main() {
    Casino casinoRoyale = Casino();
    casinoRoyale.userInterface();
//    casinoRoyale.shuffleDeck();
//    casinoRoyale.give2CardsEveryPlayer();

//    Player player1 =  Player("pl 1");
//    Player player2 = Player("pl 2");
//    Player player3 = Player("pl 3");
//    Bot bot1 = Bot("Bot1",Courage::rash);
//    std::vector<Player*> players = {&player1,&player2,&player3,&bot1};


//    Casino casinoRoyale = Casino(2,100);
//    casinoRoyale.give2CardsEveryPlayer();

//    casinoRoyale.saveRoundToFile();
//    casinoRoyale.printAllCards();

//    for (int i = 0; i < 52; ++i) {
//        std::cout<<*casinoRoyale.popCard()<<std::endl;
//    }

//    std::cout<<casinoRoyale.showPlayer(0);
    std::cout<<casinoRoyale<<std::endl;
//    std::cout<<casinoRoyale;
//    casinoRoyale.playRound();
//std::cout<<casinoRoyale

    return EXIT_SUCCESS;
}
