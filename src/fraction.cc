#include <iostream>
#include "fraction.h"

uint64_t edu::vcccd::vc::csv13::findGCD(uint64_t a, uint64_t b){
    return b == 0 ? a : findGCD(b, a % b);
}

double edu::vcccd::vc::csv13::Fraction::getRealValue() const {
    double real;
    if(this->numerator == 0 && this->denominator == 0) { return 0; };
    real = (double)this->numerator / (double)this->denominator;
    return real;
}
uint64_t edu::vcccd::vc::csv13::Fraction::getNumerator() const {
    return this->numerator;
}

int64_t edu::vcccd::vc::csv13::Fraction::getDenominator() const {
    return this->denominator;
}

void edu::vcccd::vc::csv13::Fraction::setNumerator(uint64_t numerator) {
    this->numerator = numerator;
}

void edu::vcccd::vc::csv13::Fraction::setDenominator(int64_t denominator) {
    this->denominator = denominator;
}

void edu::vcccd::vc::csv13::Fraction::output() {
    if(numerator == 0 && denominator == 0) {
        std::cout << "NAN";
    } else if (denominator == 0){
        std::cout << "INF";
    } else if(numerator == 0){
        std::cout << "0";
    } else {
        std::cout << numerator << " / " << denominator;
    }
}
