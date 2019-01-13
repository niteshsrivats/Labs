var diffx,diffy;
 var theele;
function grabber(x)
{
 
 theele=x.currentTarget;
 var posx=theele.style.left;
 var posy=theele.style.top;

  posx=posx.match(/\d+/);
  posy=posy.match(/\d+/);

diffx=x.clientX-posx;
diffy=x.clientY-posy;

document.addEventListener("mousemove",mover,true);
document.addEventListener("mouseup",dropper,true);

x.stopPropagation();
x.preventDefault();
}

function mover(x)
{

 theele.style.left=(x.clientX-diffx)+"px";
 theele.style.top=(x.clientY-diffy)+"px";
 x.stopPropagation();
}

function dropper(x)
{
document.removeEventListener("mousemove",mover,true);
document.removeEventListener("mouseup",dropper,true);
x.stopPropagation();
}

