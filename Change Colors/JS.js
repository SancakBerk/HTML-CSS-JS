let ul = document.querySelector(".box");
let li = document.querySelectorAll(".piece");
let color = document.querySelectorAll(".color");
let button = document.querySelector(".btn");
let info = document.querySelectorAll(".info");






const copycolor = (elem ,randomcolor) =>
{
    console.log(randomcolor);
    console.log(elem);   
    const colorelement =elem.querySelector(".info");
    navigator.clipboard.writeText(randomcolor).then(()=>
    {
        colorelement.innerHTML="Copied";
        setTimeout(()=>
        {
            colorelement.innerHTML=randomcolor;
        },1000)
    })
}





function generateLi()
{
    ul.innerHTML="";
    let maxcolornumber = 21;
        for(let i =0; i<maxcolornumber;i++)
        {
            let newcolor = Math.floor(Math.random() * 0xffffff).toString(16);
            newcolor = "#" +newcolor.padStart(6,"0");
            let newli = document.createElement("li");
            newli.setAttribute("class","piece");


            newli.innerHTML='<div class="color" style="background-color:'+ newcolor+'"></div><p class="info">' + newcolor +'</p>'
            newli.addEventListener("click",() => copycolor(newli,newcolor));
            ul.appendChild(newli)

        }

}
generateLi();

button.addEventListener("click",generateLi);
