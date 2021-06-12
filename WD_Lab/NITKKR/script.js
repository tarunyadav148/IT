//-----------slideshow-----------
// var slideshowCounter = 0;
// var slides = ["./pics/nitkkr.jpg","./pics/dirertor.jpg","./pics/inaug.jpeg"]
// const slide = document.querySelector('#slideshowimg');
// slide.addEventListener('click',changeImg);
// function changeImg()
// {
//     slide.src=slides[slideshowCounter];
//     slideshowCounter = (slideshowCounter+1)%3;
// }

//------------------------------

var slideshowCounter = 0;
var slides = ["./pics/nitkkr.jpg","./pics/dirertor.jpg","./pics/inaug.jpeg"]
const slide = document.querySelector('#slideshowimg');
const leftbtn = document.querySelector('#left');
console.log(leftbtn);
leftbtn.addEventListener('click',leftShift);
function leftShift()
{
    slide.src=slides[slideshowCounter];
    slideshowCounter = Math.abs(slideshowCounter-1)%3;
}

const rightbtn = document.querySelector('#right');
console.log(rightbtn);
rightbtn.addEventListener('click',rightShift);
function rightShift()
{
    slide.src=slides[slideshowCounter];
    slideshowCounter = (slideshowCounter+1)%3;
    
}



