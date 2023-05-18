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

// let n = 8;
// console.log(" ", fibonacci(n));

// Play with Maps in Js
const entry = new Map();

entry.set("Ousmane", 23);
entry.set("Francis", 40);
entry.set("Jacob", 27);

if (entry.size >= 3){
    console.log(entry.get("Jacob"))
}
else {
    throw new Error("Sorry, size if lower than expected");
}
