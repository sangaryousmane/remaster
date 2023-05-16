/*
This question is intended as an introduction to callbacks.
A callback is defined as a function passed as an argument to another function
 */

// https://leetcode.com/problems/filter-elements-from-array/description/
var filter = function (arr, fn) {
    //fn(arr[i], i) == true
    const newArray = [];
    for (let i = 0; i < arr.length; ++i) {
        if (fn(arr[i], i)) {
            newArray.push(arr[i]);
        }
    }
    return newArray;
}

// https://leetcode.com/problems/apply-transform-over-each-element-in-array/description/
var map = function (arr, fn){
    var newArray = [];

    for (let i = 0; i < arr.length; ++i){
        newArray[i]=fn(arr[i], i);
    }
    return newArray;
}

// https://leetcode.com/problems/array-reduce-transformation/description/
var reduce = function (nums, fn, init){
    if (nums.length === 0) return init;

    let value = init;
    for(const n of nums){
        value = fn(value, n);
    }
    return value;
}

arr = [1,3, 5, 10, 20, 30]

fn = function addTen(n){
    return n  + 10;
}


const odd = n => n % 2 !== 0;

newArray = arr.filter(odd);

const mixNum = n => n * 1.5;
// console.log(newArray.map(mixNum))


const students = [
    { name: 'Quincy', grade: 96 },
    { name: 'Jason', grade: 84 },
    { name: 'Alexis', grade: 100 },
    { name: 'Sam', grade: 65 },
    { name: 'Katie', grade: 90 }
];

const passed = students.filter(std => std.grade >= 70);

console.log(passed)
// Test
// const result = map(arr, fn);
// console.log(result)


