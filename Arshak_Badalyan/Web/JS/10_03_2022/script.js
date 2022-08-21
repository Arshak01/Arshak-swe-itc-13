
const container = document.querySelector('.container');
const inputElement = document.querySelector('.name-input');
const button = document.querySelector('.btn');
const users = [];

button.addEventListener('click', (event) => {
    event.stopPropagation();
})

inputElement.addEventListener('change', (event) => {
    console.log(`${event.target.name}: ${event.target.value}`);
});

const form = document.querySelector('.form-component');

form.addEventListener('submit', (event) => {
    event.preventDefault();
    users.push(addRow());
    console.log(users);
});

function addRow() {
    var name = document.getElementById('name').value;
    var surname = document.getElementById('surname').value;
    var age = document.getElementById('age').value;
    var investment = document.getElementById('investment').value;


    var table = document.getElementsByTagName('table')[0];
    var newRow = table.insertRow(table.rows.length);

    var cel1 = newRow.insertCell(0);
    var cel2 = newRow.insertCell(1);
    var cel3 = newRow.insertCell(2);
    var cel4 = newRow.insertCell(3);

    cel1.innerHTML = name;
    cel2.innerHTML = surname;
    cel3.innerHTML = age;
    cel4.innerHTML = investment;

    let newObj = new Object();
    newObj = {
        name: name,
        surname: surname,
        age: age,
        investment: investment
    }
    return newObj;
}