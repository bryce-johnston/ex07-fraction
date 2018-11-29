#include <iostream>
#include "fraction.h"

using edu::vcccd::vc::csv13::Fraction;
int main(){
    Fraction fraction(0, 0);
    fraction.output();
    std::cout << std::endl << fraction.getRealValue() << std::endl;
    fraction.setDenominator(13);
    fraction.setNumerator(4);
    std::cout << fraction.getDenominator() << std::endl;
    std::cout << fraction.getNumerator() << std::endl;
    fraction.output();
    std::cout << std::endl << fraction.getRealValue() << std::endl;
    return 0;
}
