#include <iostream>
#include <string>
#include "main.h"

my_class::my_class() : nom("") {}

my_class::my_class(std::string nom2) : nom(nom2) {}

int my_class::print_my_element(std::string mot) {
    std::cout << mot << std::endl;
    return 0;
}

std::string my_class::getnom() const {
    return nom;
}

