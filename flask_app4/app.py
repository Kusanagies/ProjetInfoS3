from flask import Flask, render_template
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import csv
import subprocess
from flask import Flask, render_template, request

app = Flask(__name__)


def count_lines(file_path):
    try:
        with open(file_path, 'r') as file:
            lines = file.readlines()
            return len(lines)
    except FileNotFoundError:
        print(f"Le fichier '{file_path}' n'a pas été trouvé.")
        return -1  # Retourne -1 pour indiquer une erreur
    except Exception as e:
        print(f"Une erreur s'est produite : {e}")
        return -1  # Retourne -1 pour indiquer une erreur

# Exemple d'utilisation
file_path = '/root/projects/flask_app/output.csv'
line_count = count_lines(file_path)
if line_count != -1:
    print(f"Le fichier '{file_path}' contient {line_count} lignes.")
    
def compile_and_run_c_bubblesort(array_size):
    # Use subprocess to compile the C file
    subprocess.run(['gcc', 'bubblesort.c', '-o', 'output_file'])
    # Run the compiled executable with the array size as a command-line argument
    subprocess.run(['./output_file', str(array_size)])

def compile_and_run_c_Insertionsort(array_size):
    subprocess.run(['gcc', 'Insertionsort.c', '-o', 'output_file']) 
    subprocess.run(['./output_file', str(array_size)])

def compile_and_run_c_Selectionsort(array_size):
    subprocess.run(['gcc', 'selectionsort.c', '-o', 'output_file'])
    subprocess.run(['./output_file', str(array_size)])

def compile_and_run_c_Gnomesort(array_size):
    subprocess.run(['gcc', 'Gnomesort.c', '-o', 'output_file'])
    subprocess.run(['./output_file', str(array_size)])

def compile_and_run_c_Bogosort(array_size):
    subprocess.run(['gcc', 'bogosort.c', '-o', 'output_file'])
    subprocess.run(['./output_file', str(array_size)])

def compile_and_run_c_Naturalsort(array_size):
    subprocess.run(['gcc', 'Naturalsort.c', '-o', 'output_file'])
    subprocess.run(['./output_file', str(array_size)])
    
def sorting_animation(data):
    plt.switch_backend('agg')  # Switch to non-interactive mode
    fig, ax = plt.subplots()
    bars = ax.bar(range(len(data[0])), data[0], color='yellow')

    def update(frame):
        for i, (old_height, new_height) in enumerate(zip(bars, frame)):
            if old_height.get_height() != new_height:
                # Highlight bars that have changed position
                old_height.set_color('red')
            else:
                # Reset color to skyblue for bars that haven't changed
                old_height.set_color('pink')
            old_height.set_height(new_height)
        return bars

    animation = FuncAnimation(fig, update, frames=data, interval=500, repeat=False)

    return animation

@app.route('/')
def home():
    center_graph = True 
    return render_template('index.html')

#Modification de ca pour pouvoir changer la taille selon la demande de l'utilisateur

@app.route('/sort/<algorithm>', methods=['POST', 'GET'])
def sort(algorithm):
    if request.method == 'POST':
        array_size = request.form.get('array_size', type=int)
        sorting_algorithm = request.form.get('sorting_algorithm')

        if array_size is None or sorting_algorithm is None:
            return "Invalid input"

        if sorting_algorithm == 'selected_algorithm':
            # Determine the algorithm based on the form input
            algorithm = request.form.get('selected_algorithm')
        else:
            # Use the algorithm specified in the URL
            algorithm = sorting_algorithm

        # Choose the sorting algorithm based on the user's selection
        if algorithm == 'bubble':
            compile_and_run_c_bubblesort(array_size)
        elif algorithm == 'selection':
            compile_and_run_c_Selectionsort(array_size)
        elif algorithm == 'insertion':
            compile_and_run_c_Insertionsort(array_size)
        elif algorithm == 'gnome':
            compile_and_run_c_Gnomesort(array_size)
        elif algorithm == 'bogo':
            compile_and_run_c_Bogosort(array_size)
        elif algorithm == 'natural':
            compile_and_run_c_Naturalsort(array_size)
        else:
            # Handle invalid algorithm selection
            return "Invalid algorithm selected"


    # Read data from the CSV file
    with open('output.csv', 'r') as file:
        reader = csv.reader(file, delimiter=';')
        # Assuming each row in the CSV file represents a snapshot of the arrayjeu 
        data = [
            [float(value) if value.strip() else float('nan') for value in row]
            for row in reader
        ]
        print(data)  # Print data for debugging 

    try:
        # Create sorting animation using the sorted data
        animation = sorting_animation(data)

        # Convert the animation to HTML5 video
        video_html = animation.to_jshtml()

        # Close the figure to release resources
        plt.close(animation._fig)

        return render_template('sorting_result.html', algorithm=algorithm, video_html=video_html, line_count=line_count,array_size=array_size)
    except Exception as e:
        return f"Error: {str(e)}"

if __name__ == '__main__':
    app.run(debug=True)