
#include <random>
#include "Casino.h"
#include <sstream>
#include <utility>
#include <ctime>
#include <iomanip>

void Casino::prepareDeck() {
//    prepare random num gen
    std::mt19937 rng(time(0));
    rng_ = rng;
    currentCardIndexToGive_=0;

    for(int colour = 0;colour<4;colour++){
        for(int figureNum =0;figureNum<13;figureNum++) {
            currentDeck_.push_back(new Karta(colour,figureNum));
        }
    }
}
// prints hand of every player
std::ostream &operator<<(std::ostream &os, const Casino &casino) {
    for(auto playerPtr : casino.players_){
        os<<playerPtr->showHand()<<std::endl;
    }
    return os;
}



//    swaps cards, needs rng init and a proper deck
void Casino::shuffleDeck(int numTimes) {

    int cardsNum = currentDeck_.size();
    std::uniform_int_distribution<int> CardDist(0,cardsNum-1);

    for(int i=0;i<numTimes;i++){

        int index1 = CardDist(rng_);
        int index2 = CardDist(rng_);

        if(index1 != index2) { //if statement may not be needed
            std::swap(currentDeck_[index1],currentDeck_[index2]);
        }
    }
}

Karta *Casino::popCard() {
    Karta* card = currentDeck_[currentCardIndexToGive_];
    currentCardIndexToGive_++;
    return card;
}


// give two cards to every player
void Casino::give2CardsEveryPlayer() {
    for(auto playerPtr : players_){
        Karta* card = this->popCard();
        playerPtr->takeCard(card);

        Karta* card2 = this->popCard();
        playerPtr->takeCard(card2);
    }
}

void Casino::playRound() {
    give2CardsEveryPlayer(); // give two cards to every player

    std::cout<< this->to_string()<<std::endl;

    while (not checkGameOver()){
        for(auto playerPtr : players_){
            if( not playerPtr->askToPass()){
                playerPtr->takeCard(this->popCard());
            }
        }
        std::cout<< this->to_string()<<std::endl;
    }
    std::cout<<getWinner()<<std::endl;
    saveRoundToFile();
}

// checks if every player passed
bool Casino::checkGameOver() {
    for(auto player : this->players_){
        if(not player->getPass()){
            return false;
        }
    }
    return true;
}

// returns string with winner, need to previous check if all passed
std::string Casino::getWinner() const {
    std::ostringstream os;
    os<<"---------------------"<<std::endl;
    std::vector<IPlayer*> winner21P;
    std::vector<int> allPlPoints;
    for(auto playerPtr : players_){
        if(playerPtr->isWinner()){
            winner21P.push_back(playerPtr);
        }
        allPlPoints.push_back(playerPtr->getPoints());
    }
    allPlPoints.push_back(0);
    int indexHighestPointsLessThan21 = allPlPoints.size()-1; //last index
    for (int i = 0; i < getPlayersNum(); ++i) {
        if(allPlPoints[i] < 21 and allPlPoints[i] > allPlPoints[indexHighestPointsLessThan21]){
            indexHighestPointsLessThan21 = i;
//          I don't check if there are 2 winners here
        }
    }



    if(winner21P.empty() and indexHighestPointsLessThan21 == allPlPoints.size()-1){
        os<<"no one won"<<std::endl;
    }
    else if(winner21P.size() == 1){
        os<<"the winner is : "<<std::endl<<*(winner21P[0]);
    }

    else if ( not winner21P.empty()){
        os<<"the winners are ";
        for(auto playerPtr : winner21P){
            os<<*playerPtr <<", ";
        }
        os<<std::endl;
    }
    else{
        os<<"the winner is : "<<std::endl<<*(players_[indexHighestPointsLessThan21]);
    }

    os<<"---------------------"<<std::endl;
    return os.str();
}

// Debug purpose, returns player's hand
std::string Casino::showPlayer(int num) {
    return players_[num]->showHand();
}

std::string Casino::to_string()const {
    std::string result;
    for(auto playerPtr : players_){
        result+=playerPtr->showHand();
    }
    return result;
}

// debug purpose constr of casino
Casino::Casino(int numHumanPlayers,int shuffles ) {
    prepareDeck();
    shuffleDeck(shuffles);
    Player* p= nullptr;
    for (int i = 0; i < numHumanPlayers; ++i) {
        p = new Player("Player"+ std::to_string(i+1));
        players_.push_back(p);
    }
    Bot* d = nullptr;
    int botNum = 1;
    for (int j = numHumanPlayers; j < 4; j++) {
        d = new Bot("Bot"+ std::to_string(botNum),Courage::rash);
        players_.push_back(d);
        botNum++;
    }

}
// Debug purpose
void Casino::printAllCards() const {
    for (auto cardPtr : currentDeck_){
        cardPtr->wypisz();
    }
}

//    don't touch it
Casino::~Casino() {

    for (auto pObj = players_.begin();
         pObj != players_.end(); ++pObj) {
        delete *pObj;
    }
    for (auto pObj = currentDeck_.begin();
         pObj != currentDeck_.end(); ++pObj) {
        delete *pObj; // Note that this is deleting what pObj points to,
        // which is a pointer
    }
}

// used in main, complete integration of all methods
void Casino::userInterface() {
    while(true)
    {

        std::cout << "Menu" << std::endl;
        std::cout << "-----------------" << std::endl;
        std::cout << "CHOOSE AN OPTION:" << std::endl;
        std::cout << "1. Play" << std::endl;
        std::cout << "2. Exit" << std::endl;

        int choice = 0;
        std::cout << std::endl;
        std::cout << "CHOICE: ";
        std::cin >> choice;
        std::cout << std::endl;

        switch (choice){
            case 1:{
                int humans = -1;
                char sign = 0;
                std::string name;
                while(humans < 1 or humans > 4)
                {
                    std::cout << "Type humans (1-4 required):" << std::endl;
                    std::cout << "PICKED AMOUNT: ";
                    std::cin >> humans;
                    std::cout << std::endl;

                    if(humans >= 1 and humans <= 4)
                    {
                        std::cout << "Good choice sir." << std::endl;
                    }
                    else
                    {
                        std::cout << "Incorrect num of players." << std::endl;
                        std::cout << "Pick again - enter 1,2,3 or 4.\n" << std::endl;

                    }
                }
//                humans is set
                std::vector<std::string> names;
                for (int i = 0; i < humans; ++i) {
                    std::cout<<"Enter "<<std::to_string(i+1)<<" Player name:"<<std::endl;
                    std::cin>>name;
                    names.push_back(name);
                }
//                names are set



                std::vector<Courage> botTypes;
                std::string botTypeChoice;
                for (int i = 0; i < 4-humans; ++i) {
                    std::cout<<"Enter bot type rash, normal or cautious:"<<std::endl;
                    std::cin>>botTypeChoice;

                    if (botTypeChoice == "rash") botTypes.push_back(Courage::rash);
                    else if (botTypeChoice == "normal") botTypes.push_back(Courage::normal);
                    else if (botTypeChoice == "cautious") botTypes.push_back(Courage::cautious);
                    else{
                        std::cout<<"learn how to type moron, i take it as normal"<<std::endl;
                        botTypes.push_back(Courage::normal);
                    }

                }
//                bot types set


                setupGame(humans,names,botTypes);
                playRound();
                break;
            }

            case 2:{
                exit(EXIT_SUCCESS);
            }

            default:{
                system("cls");
                break;
            }
        }
    }
}




void Casino::saveRoundToFile() const {
    std::ofstream file;
    file.open("Results.txt");

    const char separator    = ' ';
    const int nameWidth     = 30;
    const int cardWidth      = 50;
    for (auto playerPtr:players_) {
        file << std::left << std::setw(nameWidth) << std::setfill(separator) << playerPtr->getName()<<' ';
        file << std::left << std::setw(nameWidth) << std::setfill(separator) << playerPtr->getCardsForFile();
        file << std::left << std::setw(nameWidth) << std::setfill(separator) << playerPtr->getPoints();
        file<<std::endl;
    }


    file.close();
}
// complete game setter
void Casino::setupGame(int numHumanPlayers, std::vector<std::string> names,const std::vector<Courage>& botTypes) {
    currentCardIndexToGive_=0;
    players_.clear();
    prepareDeck();
    shuffleDeck();
    //    names
    if(names.size() != numHumanPlayers) std::cout<<"Wrong data"<<std::endl;
    Player* p= nullptr;
    for (int i = 0; i < numHumanPlayers; ++i) {
        p = new Player(names[i]);
        players_.push_back(p);
    }
    Bot* d = nullptr;
    int botNum = 1;
    for (int j = numHumanPlayers; j < 4; j++) {
        d = new Bot("Bot"+ std::to_string(botNum),botTypes[botNum-1]);
        players_.push_back(d);
        botNum++;
    }
}
