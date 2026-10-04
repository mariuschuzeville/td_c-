#ifndef MAIN_H
#define MAIN_H

#include <string>

class my_class
{
public:
    my_class();
    my_class(std::string nom2);
    int print_my_element(std::string mot);
    std::string getnom() const;

private:
    std::string nom;
};

#endif