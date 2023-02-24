function search() {
    let input = document.querySelector(".searchbar").value;
    input = input.toLowerCase();
    let products = document.querySelectorAll(".item");
    let productname = document.querySelectorAll(".info")
    console.log("deneme")
    if (input.innerHTML != "") {
        for (let i = 0; i < products.length; i++) {
            if (!productname[i].innerHTML.toLowerCase().includes(input)) {
                products[i].style.display = "none";
            }
            else {
                products[i].style.display = "list-item"
            }
        }
    }
}
////////
// Adding new item
addbutton = document.querySelector(".addnewitembutton");
addbutton.addEventListener("click", function () {
    addname = document.querySelector(".name").value;
    addprice = document.querySelector(".price").value;
    addlink = document.querySelector(".link").value;
    ul = document.querySelector(".items");
    console.log(addname);
    console.log(addprice);

    if (!(addname == ""|| addprice == "" || addlink == "")) {
        console.log("deneme");
        let newitem = document.createElement("li");
        newitem.setAttribute("class", "item");
        console.log(newitem);

        let image = document.createElement("img");
        image.setAttribute("src", addlink);
        console.log(image);

        let newdiv = document.createElement("div");
        newdiv.setAttribute("class", "info")
        console.log(newdiv);

        let infos = document.createElement("h2");
        infos.innerHTML = addname + "<br>" + addprice;
        console.log(infos);
        newdiv.appendChild(infos);

        newitem.appendChild(image);
        newitem.appendChild(newdiv);
        console.log(newitem);
        ul.appendChild(newitem);
        console.log(ul);   

        document.getElementById('namee').value='';
                    document.getElementById('pricee').value='';
                    document.getElementById('linkkk').value='';


    }
    else
    {
        alert("Fill all the blanks")
    }
})
////
