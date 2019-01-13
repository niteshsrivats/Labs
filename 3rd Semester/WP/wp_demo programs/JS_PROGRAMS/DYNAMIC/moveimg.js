
function moveimg(img2)
{
 var t11=document.getElementById("t1");
 var t21=document.getElementById("t2");
 var img1=document.getElementById(img2).style;
  img1.left=t11.value+"px";
  img1.top=t21.value+"px";
 
}

function toggimg(img2)
{
 var img1=document.getElementById(img2).style;
 if (img1.visibility=="visible")
   {
    img1.visibility="hidden";
   }

 else
    img1.visibility="visible";
}
