function stud()
{
 this.stno=10;
 this.stname="asha";
 this.mark1=52;
 this.mark2=58;
 this.calc=calculate;
}

function calculate()
{
 document.write("The students details are","<br />");
 document.write("The students no ",this.stno,"<br />");
 document.write("The students name ",this.stname,"<br />");
 document.write("The students avg marks ",(this.mark1+this.mark2)/2);
}

var st=new stud();

st.calc();

