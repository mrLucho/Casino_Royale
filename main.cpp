#include <iostream>
#include "Karta.h"
#include "Casino.h"
int main() {
//    Karta karta = Karta(1,1);
//    std::cout<<karta;
    Casino casinoRoyale = Casino();
    casinoRoyale.shuffleDeck();
    std::cout<<casinoRoyale;

    return EXIT_SUCCESS;
}
