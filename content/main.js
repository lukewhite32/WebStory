var date = new Date();

var currDate = (date.getMonth() + 1) + "-" + date.getDate() + "-" + date.getFullYear();

document.getElementById("")

document.getElementById("todays-date").innerText = currDate;
document.getElementById("today").innerText = currDate;
document.getElementById("submit").onclick = () => {
    fetch("http://localhost:8080/stories/" + currDate, {
        method: "POST",
        body: document.getElementById("story").value
    })
    .then((response) => {
        alert("Sent successfully");
    });
};