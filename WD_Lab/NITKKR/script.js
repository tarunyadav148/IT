
var slideshowCounter = 0;
var slides = ["./pics/nitkkr.jpg","./pics/dirertor.jpg","./pics/inaug.jpeg"]
const slide = document.querySelector('#slideshowimg');
const leftbtn = document.querySelector('#left');
leftbtn.addEventListener('click',leftShift);
function leftShift()
{
    slideshowCounter = Math.abs(slideshowCounter-1)%3;
    slide.src=slides[slideshowCounter];
}

const rightbtn = document.querySelector('#right');
rightbtn.addEventListener('click',rightShift);
function rightShift()
{
    slideshowCounter = (slideshowCounter+1)%3;
    slide.src=slides[slideshowCounter];
    
}



