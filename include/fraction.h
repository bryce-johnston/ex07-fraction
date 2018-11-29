
#ifndef EX07_FRACTION_FRACTION_H
#define EX07_FRACTION_FRACTION_H
#include <cstdint>

namespace edu{
    namespace vcccd{
        namespace vc{
            namespace csv13{
                uint64_t findGCD(uint64_t a, uint64_t b);
                class Fraction {
                public:
                    Fraction(uint64_t numerator, int64_t denominator){
                    uint64_t gcd = findGCD (numerator, denominator);
                    if(gcd != 0) {
                        this->numerator = numerator / gcd;
                        this->denominator = denominator / gcd;
                    } else {
                        this->numerator = numerator;
                        this->denominator = denominator;
                    }
                    }

                public:
                    uint64_t getNumerator() const;
                    int64_t getDenominator() const;
                    double getRealValue() const;

                    void setNumerator( uint64_t numerator );
                    void setDenominator ( int64_t denominator );

                    void output();

                private:
                    uint64_t numerator;
                    int64_t denominator;
                };
            }
        }
    }
}
#endif //EX07_FRACTION_FRACTION_H
