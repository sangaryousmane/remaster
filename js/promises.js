// Asynchronous JS

async function sleep(millis){
  let pr =new Promise((resolve, reject) =>{
        if (typeof millis !== 'number'){
            reject(new Error("Sorry. We expect a number."))
        }
        else{
            setTimeout(resolve, millis);
        }
    });
  return pr;
}

let p = new Promise((resolve, reject) =>{
    let a = 3 - 2;
    if (a == 1)
        resolve("Success");
    else
        reject("Failed");
})

let codeMore = new Promise((resolve, reject) =>{
    let message = "Coding";
    if (typeof message === 'string'){
        resolve("YASS!");
    }else{
        reject("OH! OH!");
    }
    return codeMore;
});

// First promise
p.then((message) =>{
    console.log(`Called successfully: ${message}`)
}).catch((message) =>{
    console.log(`Error! Unsuccessful: ${message}`);
})

// second promise

codeMore.then((m) =>{
    console.log(`What?: ${m}`);
}).catch((m) =>{
    console.error(`Failed: ${m}`);
})
// let t = Date.now();
// sleep(1000).then(() => console.log(Date.now() - t));

// async function example() {
//     console.log('Before sleep');
//     await sleep(2000);
//     console.log('After sleep');
// }
// example();


// Promise.all([
//     codeMore, p
// ]).then((messages) =>{
//     console.log(messages);
// })

Promise.race([codeMore, p]).then((message) =>{
    console.log(message)
})