let allbuttons = document.querySelectorAll(".btn");
let ul = document.querySelector(".boxes")



const createelementfunc = (id) => {
    const newli = document.createElement("li");
    if (id == "success") {
        newli.className = `success`;
        newli.innerHTML = `<div class="infodiv">
        <div class="idiv">
            <i class="fa-solid fa-check"></i>
        </div>
        <h3>Success: This is a Success box</h3>
    </div>

    <i class="fa-solid fa-x" id="iid"></i>`
        ul.appendChild(newli);


    }
    if (id == "error") {
        newli.className = `error`;
        newli.innerHTML = `<div class="infodiv">
        <div class="idiv">
            <i class="fa-solid fa-xmark"></i>
        </div>
        <h3>Error: This is a error box</h3>
    </div>
    <i class="fa-solid fa-x" id="iid"></i>`
        ul.appendChild(newli);


    }
    if (id == "warning") {
        newli.className = `warning`;
        newli.innerHTML = `<div class="infodiv">
        <div class="idiv">
            <i class="fa-solid fa-triangle-exclamation"></i>
        </div>
        <h3>Warning: This is a warning box</h3>
    </div>
    <i class="fa-solid fa-x id="iid""></i>`
        ul.appendChild(newli);


    }
    if (id == "info") {
        newli.className = `info`;
        newli.innerHTML = `<div class="infodiv">
        <div class="idiv">
            <i class="fa-solid fa-info"></i>
        </div>
        <h3>Info: This is a info box</h3>
    </div>
    <i class="fa-solid fa-x" id="iid"></i>`
        ul.appendChild(newli);

    }
    let cross = newli.querySelector(".fa-x");

    cross.addEventListener("click", (click) => {

        newli.setAttribute("class","delanimation");
        setTimeout(()=>
        {
            ul.removeChild(newli);
        },2000)
    })



    setTimeout(() => {
        ul.removeChild(newli);

    }, 5000)


}


allbuttons.forEach((btn) => {
    btn.addEventListener("click", () => createelementfunc(btn.id));
})


