#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int game(int maxnum){

    time_t aika = time(nullptr);
    srand(aika);

    int koneenLuku = rand() % maxnum;

    int arvaus=-1;
    int laskuri= 0;

    while (arvaus !=koneenLuku){
        cout<<"Arvaa lukua:";
        cin >> arvaus;
        laskuri++;

        if(arvaus < koneenLuku){
            cout <<"Luku on isompi" <<endl;
        }
        else if (arvaus > koneenLuku){
            cout <<("Luku on pienempi") <<endl;

        }
    }
    cout <<"Oikein arvattu!"<<endl;
    return laskuri;

}

int main()
{
    cout << "Anna maksimiluku minka kone pystyy valitsemaan:";
    int maxnum;
    cin >> maxnum;
    int laskuri = game(maxnum);

    cout <<"Arvauksia yhteensa:"<<laskuri <<endl;

}
