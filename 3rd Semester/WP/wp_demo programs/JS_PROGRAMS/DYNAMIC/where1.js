
function disp1(x)
{
 var dom=document.getElementById("p1");
 dom.style.left=(x.clientX)+"px";
 dom.style.top=(x.clientY)+"px";
 dom.style.visibility="visible";
 }
function hideit()
{
 document.getElementById("p1").style.visibility="hidden";
}