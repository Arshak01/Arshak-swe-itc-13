
const container = document.querySelector('.container');
const inputElement = document.querySelector('.name-input');
const button = document.querySelector('.btn');

const users = [];

button.addEventListener('click', (event) => {
    event.stopPropagation();
});

inputElement.addEventListener('change', (event) => {
    console.log(`${event.target.name}: ${event.target.value}`)
});

const form = document.querySelector('.form-component');

form.addEventListener('submit', (event) => {
    event.preventDefault();
    users.push(addRow());
    console.log(users);
});


function addRow() {
    let newObj = new Object();
    var myForm = document.getElementById("myForm");
    for (var i = 0; i < myForm.elements.length; i++) {
        newObj[myForm.elements[i].name] = myForm.elements[i].value;
    }

    var table = document.getElementsByTagName('table')[0];
    var newRow = table.insertRow(table.rows.length);

    var cel1 = newRow.insertCell(0);
    var cel2 = newRow.insertCell(1);
    var cel3 = newRow.insertCell(2);
    var cel4 = newRow.insertCell(3);

    cel1.innerHTML = myForm.name.value;
    cel2.innerHTML = myForm.surname.value ;
    cel3.innerHTML = myForm.age.value;
    cel4.innerHTML = myForm.investment.value;

    return newObj;

}
