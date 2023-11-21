from flask import Flask, render_template
import subprocess

app = Flask(__name__)

@app.route('/')
def index():
    # Compile and run the C file
    compile_and_run_c()
    
    # Read the output from the C program
    result = read_c_output()

    return render_template('index.html', result=result)

def compile_and_run_c():
    # Use subprocess to compile the C file
    subprocess.run(['gcc', 'a.c', '-o', 'output_file'])

    # Run the compiled executable
    subprocess.run(['./output_file'])

def read_c_output():
    # Read the output from the C program
    result = subprocess.check_output(['./output_file'], text=True)
    return result

if __name__ == '__main__':
    app.run(debug=True, port=5002)
