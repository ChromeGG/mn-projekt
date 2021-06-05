/*
 * =====================================================================================
 *
 *       Filename:  random_number_generator.cpp
 *
 *    Description:  Napisz program do generowania liczb pseudolosowych o zadanej
 *                  numerycznie funkcji prawdopodobieństwa
 *
 *        Version:  1.0
 *        Created:  19.03.2021 16:23:08
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Adam Tkaczyk, Piotr Pakulski, Marcin Makarewicz
 *   Organization:  PUW
 *
 * =====================================================================================
 */

#include <cmath>
#include <iostream>

using namespace std;

// Donald Knuth variables
const long m = 34359738368;  // 2^35
const long a = 3141592653;   // π * 10^9
const long c = 2718281829;   // e * 10^9

long seed;

// a * b mod n
long multiply(long a, long b, long n) {
    long m = 0, w = 0;

    while (m) {
        if (b & m) {
            w = (w + a) % n;
        }
        a = (a << 1) % n;
        m <<= 1;
    }
    return w;
}

long LCG() {
    seed = multiply(seed, a, m);
    seed = (seed + c) % m;
    return seed;
}

int main() {
    long min, max, result, rangeLength;
    int n;
    double realResult;
    cout << "Input seed:" << endl;
    cin >> seed;
    cout << "Input lower range:" << endl;
    cin >> min;
    cout << "Input upper range:" << endl;
    cin >> max;
    cout << "Input number of repeats:" << endl;
    cin >> n;

    rangeLength = max - min + 1;

    cout << "Results:" << endl;
    for (int i = 0; i < n; i++) {
        realResult = LCG() / (double)m;
        result = floor(realResult * rangeLength) + min;
        cout << result << " ";
    }

    return 0;
}
