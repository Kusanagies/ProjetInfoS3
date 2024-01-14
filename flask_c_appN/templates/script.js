// Fonction pour effectuer le tri rapide (QuickSort)
function quickSort(arr) {
    if (arr.length <= 1) {
        return arr;
    }

    const pivot = arr[0];
    const left = [];
    const right = [];

    for (let i = 1; i < arr.length; i++) {
        arr[i] < pivot ? left.push(arr[i]) : right.push(arr[i]);
    }

    return [...quickSort(left), pivot, ...quickSort(right)];
}

// Fonction pour générer un tableau de données aléatoires
function generateRandomArray(size) {
    const array = [];
    for (let i = 0; i < size; i++) {
        array.push(Math.floor(Math.random() * 100) + 1);
    }
    return array;
}

// Fonction pour afficher le graphique
function displayChart(data) {
    const ctx = document.getElementById('myChart').getContext('2d');
    const myChart = new Chart(ctx, {
        type: 'bar',
        data: {
            labels: data.map((_, index) => index + 1),
            datasets: [{
                label: 'Array Values',
                data: data,
                backgroundColor: 'skyblue',
            }],
        },
        options: {
            responsive: true,
            scales: {
                x: {
                    type: 'linear',
                    position: 'bottom',
                },
                y: {
                    beginAtZero: true,
                },
            },
        },
    });
}

// Tri rapide et affichage du graphique
const arrayToSort = generateRandomArray(10);  // Change the size as needed
const sortedArray = quickSort(arrayToSort);
displayChart(sortedArray);
