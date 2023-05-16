#include "recur.h"


// n + (n-1) + (n - 1) + (n -1 )
// Let n =3
// 3 + (3 - 1) + (2-1) + (1-1)
// So, 3 + 2 + 1 + 0
// Therefore, 6
int sumOfNaturalNums(int n) {

    if (n <= 0)
        return n;
    else {
        return n + sumOfNaturalNums(n - 1);
    }
}

// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34....
int fibonacci(int n){
    if (n <= 0){
        return 0;
    }
    if (n == 1){
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int _strlen_rev(char *str){
    int i = 0;

    if (str[i] != '\0'){
        return 1 + _strlen_rev(str + 1);
    }
    return 0;
}

int factorial(int n){
    if(n < 0)
        return -1;
    if (n == 0)
        return 1;

    return n * factorial(n - 1);
}