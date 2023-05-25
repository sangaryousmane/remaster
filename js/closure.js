
// TODO: closures in JS
function greet(name) {
    let hi = `Hi there ${name}`;

    function printHi() {
        console.log(hi);
    }

    return printHi;
}

// https://leetcode.com/problems/counter-ii/description/
var createCounter = function (init) {
    var temp = init;

    return {
        increment: function (){
            ++init
            return init;
        },
        decrement: function (){
            --init
            return init;
        },
        reset: function () {

            init = temp
            return init;
        }
    }
}
const rest = (n, ...args) => {
    let i = 0, sum = 0;
    while (i < n) {
        sum += args[i];
        i++;
    }
    return sum;
}
// console.log(rest(4, 5, 3, 14, 5))

const count = createCounter(5);
console.log(`Increment: ${count.increment()}`)
console.log(`Decrement: ${count.decrement()}`)
console.log(`Reset: ${count.reset()}`)