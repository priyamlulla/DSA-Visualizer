from flask import Flask, request, jsonify
import subprocess

app = Flask(__name__)

@app.route('/')
def home():
    return jsonify({"message": "DSA API (C backend) is running"})

@app.route('/run', methods=['POST'])
def run_dsa():
    # The 'input' field in JSON will be passed to your C program
    user_input = request.json.get('input', '')
    result = subprocess.run(
        ["dsa_visualizer.exe"],
        input=user_input,
        text=True,
        capture_output=True
    )
    return jsonify({"output": result.stdout})

if __name__ == '__main__':
    app.run(debug=True)
