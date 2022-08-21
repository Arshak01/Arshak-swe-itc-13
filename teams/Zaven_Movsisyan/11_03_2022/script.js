
const container = document.querySelector('.container')
const inputElement = document.querySelector('.name-input')
const button = document.querySelector('.btn');
button.addEventListener('click', (event) => {
    event.stopPropagation();
})


const form = document.querySelector('.form-component');

form.addEventListener('submit', (event) => {
    event.preventDefault();
});


var users_investments = [];
var users_names = [];
var users_data = {};
var barColors = '#273746';


function createChart(){
    users_data.name = document.getElementById("input-element name-input").value;
    users_data.investment = document.getElementById("input-element investment-input").value;
    users_investments.push(users_data.investment);
    users_names.push(users_data.name);

    new Chart("myChart", {
        type: "bar",
        data: {
        labels: users_names,
        datasets: [{
            backgroundColor: barColors,
            data: users_investments
            }]
        },
        options: {
        legend: {display: false},
        scales: {
        yAxes: [{
            ticks: {
            beginAtZero: true
            }
            }],
        }
        }
        });
    };


