// Function Inputs and outputs

// Let's memoize
let fibonacci = (n, memo = {}) => {
    if (n in memo) {
        return memo[n];
    }
    if (n <= 2) {
        return 1;
    }
    memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
    return memo[n];
}

let n = 8;
console.log(" ", fibonacci(n));

// Play with Maps in Js
