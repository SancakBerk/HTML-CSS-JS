const ul = document.querySelector(".buttonul");
const menu = document.querySelector(".menu")
const arrowleft = document.querySelector(".fa-arrow-left");
const arrowright = document.querySelector(".fa-arrow-right");

let stillclick = false;
const slide = (e)=>
{
    if (stillclick) {
        console.log("slide");
    ul.scrollLeft -= e.movementX;
    }
    else return 0;
    
}

const clicked =()=>
{
    console.log(ul);
    stillclick=true;
}

const leaveclick =()=>
{
    console.log(ul);
    stillclick=false;
}

menu.addEventListener("mousedown",clicked);
menu.addEventListener("mousemove",slide);
menu.addEventListener("mouseup",leaveclick);


const moveleft =()=>
{
    ul.scrollLeft -= 350;
}
const moveright =()=>
{
    ul.scrollLeft += 350;
}


arrowleft.addEventListener("click",moveleft);
arrowright.addEventListener("click",moveright);




