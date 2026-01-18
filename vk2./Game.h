#ifndef GAME_H
#define GAME_H

class Game{
private:
    int maxNumber; // suurin mahollinen arvottu
    int numberToGuess; //salainenluku
    int guesses; // arvausten määrä


public:
    Game(int maxNumber);
    ~Game();

    void Play();
    void PrintGameResult();
};


#endif // GAME_H
