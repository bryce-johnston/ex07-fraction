// Copyright 2018, Allan Knight.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Allan Knight nor the names of other
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// A unit tester for EX05-String in CS140 at Santa Barbara City College.
//
// Author: ahknight@pipeline.sbcc.edu (Allan Knight)


// Includes for google test and the unit under test.

#include <climits>
#include <random>
#include <chrono>

#include "fraction.h"

#include "gtest/gtest.h"
#include "GTestNoDeath.h"

namespace {

using edu::vcccd::vc::csv13::Fraction;

using std::string;

using namespace ::testing_internal;

typedef uint64_t uint;

class FractionTest : public ::testing::Test {
protected:
    static const uint MAX_TESTED_SCORE = 20;
    static const uint MAX_OVERALL_SCORE = 25;
    static uint _testScore;

protected:
    static void TearDownTestCase() {
        if (_testScore == MAX_TESTED_SCORE) {
            std::cout << std::endl << "Your unit test score is "
                      << _testScore << " out of "
                      << MAX_TESTED_SCORE << std::endl;
        } else {
            std::cout << "Your unit test score is "
                      << _testScore << " out of "
                      << MAX_TESTED_SCORE << " ("<< (int)(_testScore - MAX_TESTED_SCORE)
                      << ")" << std::endl;
        }

        std::cout << "The assignment is worth a total of " << MAX_OVERALL_SCORE
                  << " where the remaining points" << std::endl;
        std::cout << "comes from grading related to documentation, algorithms, and other"
                  << std::endl;
        std::cout << "criteria." << std::endl << std::endl;
    }
};

uint FractionTest::_testScore = 0;

void _testFractionOutput(int32_t i1, int32_t i2, const std::string &expected, uint &score, uint points) {
    // This can be an ofstream as well or any other ostream
    std::stringstream buffer;

    // Save cout's buffer here
    std::streambuf *sbuf = std::cout.rdbuf();

    Fraction fraction(i1, i2);
    std::cout.rdbuf(buffer.rdbuf());
    fraction.output();
    std::cout.rdbuf(sbuf);
    ASSERT_EQ(expected, buffer.str());

    score += points;
}

TEST_F(FractionTest, Basic) {
    // This test is named "Identity", it checks that the basic identity
    // complex number, i, has the correct values for real and imaginary
    // parts.

    std::mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int32_t> gcdDistribution(10, 100);

    int32_t gcd = gcdDistribution(generator);

    _testFractionOutput(gcd * 45, gcd * 32, "45 / 32", _testScore, 6);
    _testFractionOutput(gcd *  1, gcd *  3, "1 / 3", _testScore, 6);
    _testFractionOutput(gcd *  9, gcd * 17, "9 / 17", _testScore, 6);
}

TEST_F(FractionTest, TestZeroDenominator) {

    Fraction f(0, 0);
    ASSERT_NO_DEATH(f.output(), "");

    _testFractionOutput(0, 0, "NAN", _testScore, 1);
    _testFractionOutput(0, 1, "0", _testScore, 1);
    _testFractionOutput(1, 0, "INF", _testScore, 0);
}

}
