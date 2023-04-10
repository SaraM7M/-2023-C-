//Sara Markovska INKI1045
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
using namespace std;
struct Carte
{
    int tip = 0;
    string ime;
    string boja;
};

constexpr size_t PAQUET_MAX = 54; // 13 * 4 + 2 jokers

Carte* createStdPaquet(Carte paquet[], size_t size);
void displayPaquet(Carte paquet[], size_t size);
Carte* shufflePaquet(Carte paquet[], size_t size);

int main()
{
    Carte paquet[PAQUET_MAX];
    createStdPaquet(paquet, PAQUET_MAX);
    cout << "Karti pred meshanje:\n";
    displayPaquet(paquet, PAQUET_MAX);
    cout<<"\n";

    srand (std::time(NULL));
    shufflePaquet(paquet, PAQUET_MAX);
    cout << "Izmeshani karti:\n";
    displayPaquet(paquet, PAQUET_MAX);
    cout<<"\n";
    return 0;
}
Carte* createStdPaquet(Carte paquet[], std::size_t size)
{
    // J --> joker
    // V --> dzandar/jack
    const string karti[] { "ACE", "2",  "3", "4", "5", "6", "7",
                                 "8", "9", "10", "V", "D", "K", "J"};
    const string boi[] { "List", "Srce",  "Detelina", "Baklava" };
    size_t cards = (size - 2) / 4; // 13
    for(size_t i=0; i<cards; ++i) {
        paquet[i].tip = i + 1;
        paquet[i].ime = karti[i];
    }
    // Mnozenje x 4
    for(int i=1; i<4; ++i) { copy(paquet, paquet+cards, paquet+cards*i); }
    
    for(int i=0; i<4; ++i) {
        for(size_t j=0; j<cards; ++j) { paquet[j+cards*i].boja = boi[i]; }
    }
    // Dodavanje na jokeri
    paquet[size-2].ime = "J"; // paquet[52]
    paquet[size-1].ime = "J";
    return paquet;
}

void displayPaquet(Carte paquet[], size_t size)
{
    for(size_t i=0; i<size; ++i) {
        cout << "Tip na Karta: "  << setw(2) << paquet[i].tip
             << "; karta: "   << setw(2) << paquet[i].ime
             << "; boja: " << setw(7) << paquet[i].boja
             << '\n';
    }
}

Carte* shufflePaquet(Carte paquet[],size_t size)
{
    random_shuffle(paquet, paquet+size);
    return paquet;
}
