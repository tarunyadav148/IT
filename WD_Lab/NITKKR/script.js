var slideshowCounter = 0;
var slides = ["./pics/nitkkr.jpg","./pics/dirertor.jpg","./pics/inaug.jpeg","./pics/library.jpg","./pics/pond.jpg","./pics/nitkkr2.jpg","./pics/hostel1.jpg","./pics/hostel2.jpg","./pics/hostel3.jpg"]
const slide = document.querySelector('#slideshowimg');
const leftbtn = document.querySelector('#left');
leftbtn.addEventListener('click',leftShift);
function leftShift()
{
    slideshowCounter = Math.abs(slideshowCounter-1)%slides.length;
    slide.src=slides[slideshowCounter];
}

const rightbtn = document.querySelector('#right');
rightbtn.addEventListener('click',rightShift);
function rightShift()
{
    slideshowCounter = (slideshowCounter+1)%slides.length;
    slide.src=slides[slideshowCounter];
    
}

setTimeout(slideshow,5000);
function slideshow()
{
    slideshowCounter = (slideshowCounter+1)%slides.length;
    slide.src=slides[slideshowCounter];
    setTimeout(slideshow,5000);
}


//Night mode
setTimeout(nightmode,60000*60);
function nightmode()
{ 
    
    date = new Date;
    if(date.getHours()>14||date.getHours()<5)
    {
        console.log("d")
        document.body.style.backgroundColor = "rgb(173, 173, 172)";
    }
    else
    {
        document.body.style.backgroundColor = "rgb(230, 230, 218)";
    }
    
}



