#include "recur.h"


int sumOfNaturalNums(int n) {

    if (n <= 0)
        return n;
    else {
        return n + sumOfNaturalNums(n - 1);
    }
}