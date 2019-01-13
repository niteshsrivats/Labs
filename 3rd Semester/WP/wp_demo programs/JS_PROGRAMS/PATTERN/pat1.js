
var str="Web progisramming is very interesting";
var pos=str.search(/is/);
if(pos>0)
 document.write("'is' appears in position", pos,"<br />");
else
 document.write("'is' doesnot appears in str");

var s1="hello welcome";
document.write(s1);
var str=s1.search(/el./);
document.write(str,"<br />");

var str1=s1.match(/el./);
document.write(str1,"<br />");

var str2=s1.match(/el./g);

for(var i=0;i<str2.length;i++)
document.write(str2[i],"<br />");



