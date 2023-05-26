// More promises

const sleep = async (millis) =>{

    let promise = new Promise((resolve, reject) =>{

        if (typeof millis != 'number'){
            reject(new TypeError("soRrY! we expect a number here"));
        }
        else{
            setTimeout(resolve, millis);
        }
    })
    return promise;
}

const isGenerativeAI = async (type, isGAI = true) =>{

    if (isGAI && type == "NLP"){
        isGAI=true;
        console.log("It is a generative AI");
        await sleep(3000);
        console.log("DONE!!!")
    }
    else{
        isGAI=false;
        console.log("It is different variant of AI!!!!");
        await sleep(3000);
        console.log("DONE!!!");
    }
}

isGenerativeAI("CV");