#include <iostream>
#include <string>
#include "main.h"

/*
Exercice 1.1 :
int main(){
    std::cout << "Hello World" << std::endl;
    return 0;
}
*/

/*
Exercice 1.2 :
int affiche(std::string mot){
    std::cout << mot << std::endl;
    return 0;
}

int main(){
    affiche("Hello World!");
}
*/

int main(){
    my_class test("Hello World!");
    test.print_my_element(test.getnom());
    return 0;
}
