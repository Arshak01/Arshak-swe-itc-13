let promise1 = fetch('https://raw.githubusercontent.com/SevanIM/SevansRepo/main/Homework/Users').then(res => res.json());
let promise2 = fetch('https://raw.githubusercontent.com/SevanIM/SevansRepo/main/Homework/Investments').then(res => res.json());

let onlyusers = [];
let investments = [];

let promises = Promise.all([promise1, promise2]).then((res) => {
    for (let a = 0; a < res[0]['users'].length; ++a) {
        onlyusers.push(res[0]['users'][a].name);
    }
    for (let a = 0; a < res[1]['investments'].length; ++a) {
        investments.push(res[1]['investments'][a].investment);
    }
    createDiagram(onlyusers, investments)
})

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

    for(let i = 0; i < users.length; i++){
        onlyusers.push(users[i].name)
        investments.push(users[i].investment)
    }

    createDiagram(onlyusers,investments)

});

function addRow() {
    let newObj = new Object();
    var myForm = document.getElementById("form_id");
    for (var i = 0; i < myForm.elements.length; i++) {
        newObj[myForm.elements[i].name] = myForm.elements[i].value;
    }
    return newObj;
}

function createDiagram(names, investments){
    var data = [{
        x:names,
        y:investments,
        type: 'bar'
    }];
    layout = {
        width: 1000, height: 500,
        paper_bgcolor: 'rgb(179, 214, 223)',
        plot_bgcolor: 'rgb(179, 214, 223)'
    }
    Plotly.newPlot('diagramDiv', data, layout);
}