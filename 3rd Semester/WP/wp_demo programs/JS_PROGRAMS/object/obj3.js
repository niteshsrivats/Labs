function stud()
{
var x1=prompt("Enter stud no:"); 
 x2=prompt("Enter stud name:"); 
 x3=prompt("Enter stud mark1:");
 x4=prompt("Enter stud mark2:");
 this.stno=Number(x1);
 this.stname=x2;
 this.mark1=Number(x3);
 this.mark2=Number(x4);
 
 this.calc=calculate;
}

function calculate()
{
 document.write("The students details are","<br />");
 document.write("The students no ",this.stno,"<br />");
 document.write("The students name ",this.stname,"<br />");
 document.write("The students avg marks ",(this.mark1+this.mark2)/2);
}


var st;
var st1=[];

for(var i=0;i<4;i++)
{
 st1[i]=new stud();
 st1[i].calc();
}