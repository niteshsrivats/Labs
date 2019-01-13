
function comm(x)
{
 var v=document.getElementById("ta1");

 if(x=="t1")
  v.value="Name must contain only characters";
 else if(x=="t2")
  v.value="Age must be between 0 and 99";
}

function clea(y)
{
 var v=document.getElementById("ta1");

 if(y=="t1")
  v.value=" ";
 else
  v.value=" ";
document.write("Dont use document.write in event handlers here");
}