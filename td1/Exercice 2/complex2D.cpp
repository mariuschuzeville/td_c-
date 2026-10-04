
#include "complex2d.h"
#include <stdexcept>

Complex2D::Complex2D() {
    reel = 0;
    imaginaire = 0;
}

Complex2D::Complex2D(double r, double i) {
    reel = r;
    imaginaire = i;
}

Complex2D::Complex2D(double valeur) {
    reel = valeur;
    imaginaire = valeur;
}

Complex2D::Complex2D(const Complex2D& autre) {
    reel = autre.reel;
    imaginaire = autre.imaginaire;
}

double Complex2D::getReel() const {
    return reel;
}

double Complex2D::getImaginaire() const {
    return imaginaire;
}

void Complex2D::setReel(double r) {
    reel = r;
}

void Complex2D::setImaginaire(double i) {
    imaginaire = i;
}

Complex2D Complex2D::operator+(const Complex2D& autre) const {
    return Complex2D(reel + autre.reel,
                     imaginaire + autre.imaginaire);
}

Complex2D Complex2D::operator-(const Complex2D& autre) const {
    return Complex2D(reel - autre.reel,
                     imaginaire - autre.imaginaire);
}

Complex2D Complex2D::operator*(const Complex2D& autre) const {
    double r = reel * autre.reel - imaginaire * autre.imaginaire;
    double i = reel * autre.imaginaire + imaginaire * autre.reel;

    return Complex2D(r, i);
}

Complex2D Complex2D::operator/(const Complex2D& autre) const {
    double denom = autre.reel * autre.reel
                 + autre.imaginaire * autre.imaginaire;

    if (denom == 0) {
        throw std::invalid_argument("Division par zero");
    }

    double r = (reel * autre.reel
              + imaginaire * autre.imaginaire) / denom;

    double i = (imaginaire * autre.reel
              - reel * autre.imaginaire) / denom;

    return Complex2D(r, i);
}


bool Complex2D::operator<(const Complex2D& autre) const {
    double module1 = reel * reel + imaginaire * imaginaire;
    double module2 = autre.reel * autre.reel
                   + autre.imaginaire * autre.imaginaire;
    return module1 < module2;
}

bool Complex2D::operator>(const Complex2D& autre) const {
    double module1 = reel * reel + imaginaire * imaginaire;
    double module2 = autre.reel * autre.reel
                   + autre.imaginaire * autre.imaginaire;
    return module1 > module2;
}