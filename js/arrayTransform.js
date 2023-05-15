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

var map = function (arr, fn){
    var newArray = [];

    for (let i = 0; i < arr.length; ++i){
        newArray[i]=fn(arr[i], i);
    }
    return newArray;
}

arr = [1,3, 5, 10, 20, 30]

fn = function addTen(n){
    return n  + 10;
}


const odd = n => n % 2 != 0;

newArray = arr.filter(odd);

const mixNum = n => n * 1.5;
console.log(newArray.map(mixNum))

// Test
// const result = map(arr, fn);
// console.log(result)


