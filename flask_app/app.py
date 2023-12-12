from flask import Flask, render_template
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import csv
import subprocess

app = Flask(__name__)

def compile_and_run_c_bubblesort():
    # Use subprocess to compile the C file
    subprocess.run(['gcc', 'a.c', '-o', 'output_file'])

    # Run the compiled executable
    subprocess.run(['./output_file'])

def compile_and_run_c_Insertionsort():
    subprocess.run(['gcc', 'Insertionsort.c','-o','output_file'])
    subprocess.run(['./output_file'])
    
def compile_and_run_c_Selectionsort():
    subprocess.run(['gcc', 'selectionsort.c','-o','output_file'])
    subprocess.run(['./output_file'])


def sorting_animation(data):
    print(data)  # Print the received data to debug
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
    else:
        # Handle invalid algorithm selection
        return "Invalid algorithm selected"

    # Read data from the CSV file
    with open('output.csv', 'r') as file:
        reader = csv.reader(file, delimiter=';')
        # Assuming each row in the CSV file represents a snapshot of the array
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

        return render_template('sorting_result.html', algorithm=algorithm, video_html=video_html)
    except Exception as e:
        return f"Error: {str(e)}"

if __name__ == '__main__':
    app.run(debug=True)