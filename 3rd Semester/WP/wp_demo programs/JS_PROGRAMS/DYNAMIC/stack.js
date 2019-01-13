var top1="one";
function ttop(x)
{
 var dtop=document.getElementById(top1).style;
 var dnew=document.getElementById(x).style;

 dtop.zIndex="0";
 dnew.zIndex="10";
 top1=x;
}