var dom,x,y,finalx=300,finaly=300;

function inittext()
{
 dom=document.getElementById("p1").style;
 var x=dom.left;
 var y=dom.top;
  
 x=x.match(/\d+/);
 y=y.match(/\d+/);
 movetext(x,y);
}

function movetext(x,y)
{
 if(x!=finalx)
  if(x>finalx)x--;
  else if(x <finalx) x++;
  
 if(y!=finaly)
  if(y>finaly)y--;
  else if(y <finaly) y++;

 if((x!=finalx)|| (y!=finaly))
  {
   dom.left= x +"px";
   dom.top= y +"px";
   setTimeout("movetext("+x+","+y+")",1000); 
  }
}

