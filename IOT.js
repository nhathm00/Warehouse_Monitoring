var tabButtons=document.querySelectorAll(".tabContainer .buttonContainer button");
var tabPanels=document.querySelectorAll(".tabContainer .tabPanelContainer .tabPanel");

function showPanel(panel) {
    tabButtons.forEach(function(node){
        node.style.backgroundColor="";
        node.style.color="";
    });
    tabButtons[panel].style.color="black";
    tabButtons[panel].style.backgroundColor="green"
    tabPanels.forEach(function(node){
        node.style.display="none";
    });
    tabPanels[panel].style.display="block";


}
showPanel(0);

// khoi tao cac thong so
let btn1 = document.querySelector('#btn1');
let img = document.querySelector('#light');
let btn2 = document.querySelector('#btn2');

// functions nut bam
btn1.addEventListener('click', ()=>{   
    img.src = 'image/light_on.png';
})

btn2.addEventListener('click', ()=>{
    img.src = 'image/light_off.png';
})


let btn3 = document.querySelector('#btn3');
let img2 = document.querySelector('#fan');
let btn4 = document.querySelector('#btn4');

// functions nut bam
btn3.addEventListener('click', ()=>{   
    img2.src = 'image/fan_on.png'; 
})

btn4.addEventListener('click', ()=>{
    img2.src = 'image/fan_off.png';
})


let btn5 = document.querySelector('#btn5');
let img3 = document.querySelector('#TV');
let btn6 = document.querySelector('#btn6');

// functions nut bam
btn5.addEventListener('click', ()=>{   
    img3.src = 'image/camera_on.png'; 
})

btn6.addEventListener('click', ()=>{
    img3.src = 'image/camera_off.png';
})
