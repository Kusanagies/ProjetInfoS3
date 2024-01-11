from flask import Flask, render_template
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import csv
import subprocess

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
    
def compile_and_run_c_bubblesort():
    # Use subprocess to compile the C file
    subprocess.run(['gcc', 'bubblesort.c', '-o', 'output_file'])
    # Run the compiled executable
    subprocess.run(['./output_file'])
    
def compile_and_run_c_Insertionsort():
    subprocess.run(['gcc', 'Insertionsort.c','-o','output_file'])
    subprocess.run(['./output_file'])
    
def compile_and_run_c_Selectionsort():
    subprocess.run(['gcc', 'selectionsort.c','-o','output_file'])
    subprocess.run(['./output_file'])

def compile_and_run_c_Gnomesort():
    subprocess.run(['gcc','Gnomesort.c','-o','output_file'])
    subprocess.run(['./output_file'])
    
def compile_and_run_c_Bogosort():
    subprocess.run(['gcc','bogosort.c','-o','output_file'])
    subprocess.run(['./output_file'])
    
def compile_and_run_c_Naturalsort():
    subprocess.run(['gcc','Naturalsort.c','-o','output_file'])
    subprocess.run(['./output_file'])
    
def sorting_animation(data):
    plt.switch_backend('agg')  # Switch to non-interactive mode
    fig, ax = plt.subplots()
    bars = ax.bar(range(len(data[0])), data[0], color='skyblue')

    def update(frame):
        for i, bar in enumerate(bars):
            bar.set_height(frame[i])
        return bars

    animation = FuncAnimation(fig, update, frames=data, interval=500, repeat=False)

    return animation

@app.route('/')
def home():
    return render_template('index.html')

@app.route('/sort/<algorithm>')
def sort(algorithm):
    # Choose the sorting algorithm based on the user's selection
    if algorithm == 'bubble':
        compile_and_run_c_bubblesort()
    elif algorithm == 'selection':
        compile_and_run_c_Selectionsort()
    elif algorithm == 'insertion':
        compile_and_run_c_Insertionsort()
    elif algorithm == 'gnome':
        compile_and_run_c_Gnomesort()
    elif algorithm == 'bogo':
        compile_and_run_c_Bogosort()
    elif algorithm == 'natural':
        compile_and_run_c_Naturalsort()
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

        return render_template('sorting_result.html', algorithm=algorithm, video_html=video_html, line_count=line_count)
    except Exception as e:
        return f"Error: {str(e)}"

if __name__ == '__main__':
    app.run(debug=True)