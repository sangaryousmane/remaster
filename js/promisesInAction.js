// fetch, async/await/ then
// https://www.youtube.com/@KindsonTheTechPro/featured
// import fetch from 'fetch'
//
// const callIt = async () => {
//     const pathUrl = 'https://jsonplaceholder.typicode.com/todos/1';
//     const res = await fetch(pathUrl)
//     console.log(res);
// }
// https://leetcode.com/problems/promise-time-limit/description/
var timeLimit = function (fn, t) {
    return async function (...args) {
        const p =new Promise((res, rej) => {
            setTimeout(() => rej(`Time Limit Exceeded`), t);
        });
        const f = fn(...args)
        return Promise.race([p , f]);
    }
}

const limited = timeLimit((t) => new Promise(res => setTimeout(res, t)), 100);
limited(150).catch(console.log)