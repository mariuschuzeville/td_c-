
#include <iostream>
#include "complex2d.h"

using namespace std;

int main() {
    Complex2D z1(2, 3);
    Complex2D z2(1, 4);
    Complex2D somme = z1 + z2;
    Complex2D difference = z1 - z2;
    Complex2D produit = z1 * z2;
    Complex2D division = z1 / z2;
    cout << "Somme : " << somme.getReel() << " + "
         << somme.getImaginaire() << "i" << endl;
    cout << "Difference : " << difference.getReel() << " + "
         << difference.getImaginaire() << "i" << endl;
    cout << "Produit : " << produit.getReel() << " + "
         << produit.getImaginaire() << "i" << endl;
    cout << "Division : " << division.getReel() << " + "
         << division.getImaginaire() << "i" << endl;
    if (z1 > z2)
        cout << "z1 est plus grand que z2" << endl;
    else
        cout << "z1 est plus petit ou egal a z2" << endl;
    return 0;
}