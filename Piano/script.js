const blackpieces = document.querySelectorAll(".blackpiece");
const whitepieces = document.querySelectorAll(".whitepiece");
const checkbox = document.querySelector(".check");
const allpieces = document.querySelectorAll(".piece")
const volumeslider = document.querySelector(".volumerange");


const allkeys=[];
checkbox.addEventListener("change", () => {
    allpieces.forEach((key)=>
        {
            key.innerHTML=`<p></p>`
        })
    if (checkbox.checked) {
        allpieces.forEach((key)=>
        {
            key.innerHTML=`<p>${key.dataset.value}</p>`
        })

    }

})
let audio = new Audio("tunes/a.wav"); // a tune


const playmusic = (letter)=>
{
    if(allkeys.includes(letter.toUpperCase()))
    {
        audio.src=`tunes/${letter}.wav`
        audio.play();
    }
    
}

allpieces.forEach((key)=>
{
    allkeys.push(key.dataset.value);
    key.addEventListener("click",()=>playmusic(key.dataset.value));
})


const pressedkey = (key)=>
{
    playmusic(key.key);
        allpieces.forEach((a)=>
        {
            if (key.key.toUpperCase()== a.dataset.value)
            {
                a.classList.add("activate");
                setTimeout(()=>
                {
                    a.classList.remove("activate");
                },200)
                
            }
        })
}


const volumefunc=(e)=>
{
    console.log(e);
    audio.volume= e.target.value;
    
}


volumeslider.addEventListener("change",volumefunc);


document.addEventListener("keydown",pressedkey)















