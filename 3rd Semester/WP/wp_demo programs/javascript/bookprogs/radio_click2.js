//   The event registering code for radio_click2
alert("In radio_click2.js");
var dom = document.getElementById("myForm");

dom.elements[0].onclick = planeChoice;
dom.elements[1].onclick = planeChoice;
dom.elements[2].onclick = planeChoice;
dom.elements[3].onclick = planeChoice;
/*
document.getElementById("152").onclick = planeChoice;
document.getElementById("172").onclick = planeChoice;
document.getElementById("182").onclick = planeChoice;
document.getElementById("210").onclick = planeChoice;
*/