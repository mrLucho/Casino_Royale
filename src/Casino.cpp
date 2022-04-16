//
// Created by micha on 13.04.2022.
//
#include<bits/stdc++.h>
#include <random>

#include "Casino.h"



void Casino::prepareDeck() {
//    prepare random num gen
    std::random_device dev;
    std::mt19937 rng(dev());
    rng_ = rng;

//    fill current deck
    std::vector<Karta> temp;
    for(int colour = 0;colour<4;colour++){
        for(int figureNum =0;figureNum<13;figureNum++){
            Karta tempCard = Karta(colour,figureNum);
            temp.emplace_back(tempCard);
        }
    }
//    ugly af but works instead of range for loop
    for(int i = 0;i<temp.size();i++){
        currentDeck_.push_back(&(temp[i]));
    }
}

std::ostream &operator<<(std::ostream &os, const Casino &casino) {
    for(auto cardPtr : casino.currentDeck_){
        os << *cardPtr << std::endl;
    }
}

void Casino::shuffleDeck(int numTimes) {
    int cardsNum = currentDeck_.size();
    std::uniform_int_distribution<int> CardDist(0,cardsNum-1);
    for(int i=0;i<numTimes;i++){
        int index1 = CardDist(rng_);
        int index2 = CardDist(rng_);
//        equal indexes shouldn't be a problem
        if(index1 == index2) {
            std::cout << "equal indexes" << std::endl;
        }
        Karta* temp = currentDeck_[index1];
        currentDeck_[index1] = currentDeck_[index2];
        currentDeck_[index2] = temp;
    }
}

Karta *Casino::popCard() {
    Karta* card = currentDeck_[currentDeck_.size()-1];
    currentDeck_.pop_back();
    return card;
}

Casino::Casino() {

}