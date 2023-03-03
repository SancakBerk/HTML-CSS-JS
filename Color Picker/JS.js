let pickcolorbutton = document.querySelector("#pickcolor");
let ul = document.querySelector(".colorul")

let clearall = document.querySelector(".clearall");

let pickedcolors = localStorage.getItem("pickedcolors") || [];
const createlements = (sRGBHex) => {

    ul.innerHTML="";
    pickedcolors.map((item) => {
        navigator.clipboard.writeText(item.sRGBHex);
        const newli = document.createElement("li");
        newli.setAttribute("class", "colorli");
        newli.innerHTML='<button class="libutton btn-primary" style="background-color:'+ item.sRGBHex+ ';"></button>'+ item.sRGBHex;
        ul.appendChild(newli);
        console.log(item.sRGBHex);
    })

}


const activateeyetracker = async () => {
    try {
        const eyedropper = new EyeDropper();
        const sRGBHex = await eyedropper.open();
        pickedcolors.push(sRGBHex);
        console.log(sRGBHex);
        console.log(pickedcolors);
        createlements(sRGBHex);
    }
    catch (error) {
        console.log(error);

    }

}
pickcolorbutton.addEventListener("click", activateeyetracker);


const clearallfunc = ()=>
{
    ul.innerHTML="";
    pickedcolors=[];
}

clearall.addEventListener("click",clearallfunc);




