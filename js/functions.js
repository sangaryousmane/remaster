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

// name and age
entry.set("Ousmane", 23);
entry.set("Francis", 40);
entry.set("Jacob", 27);

function accessMap() {
    if (entry.size >= 3) {
        if (entry.has("Jacob")) {
            entry.delete("Jacob")
            entry.get("Ousmane") + 1;
        }
        console.log(entry.entries())
        entry.clear();
    } else {
        throw new Error("Sorry, size if lower than expected");
    }

    console.log(entry.size);   // // // //
    entry.set("Rexford", 20); // // // //
    console.log(entry.entries()); // //  // //
}

const display = () =>{
    console.log(entry.entries());
}

entry.set("Jack", 25);

let jack = entry.get("Jack");

if (entry.has(jack)) {
    entry.delete(jack);
}
else {
    entry.set("Krishna", 30)
}

let values = entry.values();

for (const i of values){

    if (i >= 24)
    {
        console.log(i)
    }
}