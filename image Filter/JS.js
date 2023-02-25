// let Allbutton = document.getElementById("allbutton");
// let pencilbutton = document.getElementById("pencilbutton");
// let eraserbutton = document.getElementById("eraserbutton");
// let bookbutton = document.getElementById("bookbutton");

let buttons = document.querySelectorAll(".btn");
let imgdiv = document.querySelector(".imagediv");
let images = document.getElementsByTagName("img");


buttons.forEach(function(e)
{
    e.addEventListener("click",function(bt)
    {
        for(let i=0;i<images.length;i++)
            {
                images[i].style.display="inline-block"

            }

        if(bt.target.id =="allbutton")
        {
            for(let i=0;i<images.length;i++)
            {
                images[i].style.display="inline-block"

            }
        }
        if(bt.target.id =="pencilbutton")
        {
            for(let i=0;i<images.length;i++)
            {
                if(images[i].id!="pencil")
                {
                    images[i].style.display="none";
                }

            }
        }
        if(bt.target.id =="eraserbutton")
        {
            for(let i=0;i<images.length;i++)
            {
                if(images[i].id!="eraser")
                {
                    images[i].style.display="none";
                }

            }
        }
        if(bt.target.id =="bookbutton")
        {
            for(let i=0;i<images.length;i++)
            {
                if(images[i].id!="book")
                {
                    images[i].style.display="none";
                }

            }
        }
    })
})




