
var s1="hello welcome";
document.write(s1,"<br/>");
var str=s1.search(/el/);
document.write(str,"<br/><br/>");
document.write (str.length);
for(var i=0;i<str.length;i++)
 document.write("abc"+str[i]," ");

var str=s1.search(/ll./);
document.write(str,"<br/>");
var s2="Welcome to the elegant course";

 str=s2.match(/el./);
for(i=0;i<str.length;i++)
 document.write(str[i]," ");
document.write("<br/>");

str=s2.match(/el./g);
document.write(str,"<br/>");

for(i=0;i<str.length;i++)
 document.write(str[i],"--");
document.write("<br/>");

var s3= "WINDOWS 7 HOME BASIC SERVICE PACK 13.798";

str= s3.match(/\d/g);

for(i=0;i<str.length;i++)
 document.write(i+" "+str[i]," ");
document.write("<br/>");

str= s3.match(/\w{7}/g);
for(i=0;i<str.length;i++)
 document.write(str[i]," ");
document.write("<br/>");


var s4=s3.replace(/7/g,"8");
document.write(s4);

document.write("<br/>");

var s4=s3.replace(/o/g,"PPPPP");
document.write(s4);

document.write("<br/>");


var s4=s3.replace(/o/gi,"PPPPP");
document.write(s4);

document.write("<br/>");

str=s3.match(/\d\.\d{3}/);
 document.write(str);
document.write("<br/>");

str=s3.match(/\d+/g);
 document.write(str);
document.write("<br/>");

str=s3.match(/^WIN/);
document.write(str);
document.write("<br/>");


str=s3.match(/698$/);
document.write(str);
document.write("<br/>");


document.write("OBSERVER PARANTHESIZED SUBEXPRESSIONS <br/>");
str=s3.match(/(\d+)([\D]+)(\d+)/);
document.write("<br/>",str,"<br/>");
for(i=0;i<str.length;i++)
 document.write(str[i],"<br />");
document.write("<br/>");