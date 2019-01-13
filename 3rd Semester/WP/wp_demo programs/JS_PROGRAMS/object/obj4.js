function stud(y1,y2,y3,y4)
{
 this.stno=Number(y1);
 this.stname=y2;
 this.mark1=Number(y3);
 this.mark2=Number(y4);
 
 this.calc=calculate;
}

function calculate()
{
 document.write("The students details are","<br />");
 document.write("The students no ",this.stno,"<br />");
 document.write("The students name ",this.stname,"<br />");
 document.write("The students avg marks ",(this.mark1+this.mark2)/2);
}

var x1=prompt("Enter stud no:"); 
 x2=prompt("Enter stud name:"); 
 x3=prompt("Enter stud mark1:");
 x4=prompt("Enter stud mark2:");

var st=new stud(x1,x2,x3,x4);
st.calc();