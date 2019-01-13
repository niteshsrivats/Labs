var str="Web Programming Is a course In 3rd sem current is JAN 20$13 2013";

var pos=str.search(/Web/);
if(pos>=0)
 document.write("1.Web is in position ",pos);
else
 document.write("<br />","2.web is not seen in the given string");



pos=str.search(/i./);
document.write("<br />","3. The first 'i' is in pos:",pos);
var pos1=str.match(/i./gi);
document.write("<br />","4.The matching string is ",pos1);

pos1=str.search(/[pqr]/gi);
document.write("<br />","5. The matching string is ",pos1);

pos1=str.match(/[^a-d]/g);
document.write("<br />","6. The matching string is ",pos1);

var str1="Todaaaay's date is 19/3/13";
pos1=str1.match(/\d+\w*\d?/g);
document.write("<br />","7. The matching string is ",pos1);

pos1=str1.match(/[A-F]\d+\w*/g);
document.write("<br />","8. The matching string is ",pos1);

pos1=str1.match(/a{4}/g);
document.write("<br />","9. The matching string is ",pos1);


pos1=str.match(/\bin\b/gi);
document.write("<br />","10. The matching string is ",pos1);

pos1=str.match(/^Web/gi);
document.write("<br />","11. The matching string is ",pos1);

pos1=str.match(/20\$13/gi);
document.write("<br />","12. The matching string is ",pos1);

pos1=str.match(/2013$/gi);
document.write("<br />","13. The matching string is ",pos1);

pos1=str.match(/20$13/gi);
document.write("<br />","14. The matching string is ",pos1);


pos1=str.match(/\d+\D*\w*/g);
document.write("<br />","15. The matching string is ",pos1);

pos1=str.replace(/cur/g,"new");
document.write("<br />","16. The matching string is ",pos1);

pos1=str.match(/(\d+)([^\d]+)(\d)/);
document.write("<br />","17. The matching string is ",pos1);


 

