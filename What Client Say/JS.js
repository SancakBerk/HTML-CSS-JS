let buttons = document.querySelectorAll(".btn");
let li = document.getElementsByTagName("li");

var counter = 0;
buttons.forEach(function(e)
{
    e.addEventListener("click",function()
    {
        console.log(e)
        if(e.id=="left")
        {
            if(counter!=0)
            {
                li[counter].style.display="none";
                counter--;
                li[counter].style.display="list-item";
                
            }

        }
        if(e.id=="right")
        {
            if(counter!=(li.length-1))
            {
                li[counter].style.display="none";
                counter++;
                li[counter].style.display="list-item";
            }

        }
    })

})