


var image = document.getElementById("voiceimg");
console.log(image);
image.addEventListener("click" , playmusic);
function playmusic(image)
{
    console.log(image)
    let audio = new Audio("furievox-105000.mp3");
    audio.play();
    
}
