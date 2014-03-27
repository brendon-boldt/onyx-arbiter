#pragma once

using namespace std;

extern mt19937 gen;

enum COLOR {
    RED = 1,
    ORANGE,
    YELLOW,
    GREEN,
    LIGHT_BLUE,
    DARK_BLUE,
    PURPLE,
    PINK
};

/* I probably do not need this.
inline unsigned int mt_rand(unsigned int m) {
    return gen() % m;
}
*/
