var screen = document.querySelector(".screen");
var buttons = document.querySelectorAll(".btn");
var equal = document.querySelector(".btn-success");
var clear = document.querySelector(".btn-danger");

console.log(screen)
console.log(buttons)
console.log(equal)
console.log(clear)


buttons.forEach(function (e) {


    e.addEventListener("click", function (b) {
        let result = b.target.value;
        console.log(result);
        screen.value += result;
    })
    equal.addEventListener("click",function()
    {
        if(screen.value==="")
        {
            screen.value="";
            
        }
        else
        {
            let answer = eval(screen.value)
            screen.value= answer;
        }

    })
    clear.addEventListener("click",function()
    {
        screen.value="";
    })



})