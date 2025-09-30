import tkinter as tk
import subprocess
import threading

# Create main window
root = tk.Tk()
root.title("DSA Visualizer GUI")
root.geometry("700x500")

# Text widget to display C program output
output_box = tk.Text(root, height=25, width=80, bg="black", fg="lime", font=("Consolas", 12))
output_box.pack(pady=10)

# Entry widget to send input
input_box = tk.Entry(root, width=70, font=("Consolas", 12))
input_box.pack(pady=5)

# Button frame for menu options
button_frame = tk.Frame(root)
button_frame.pack(pady=5)

# Global variable for C process
proc = None

# Function to start the C program
def start_dsa():
    global proc
    if proc is None or proc.poll() is not None:  # start new process if not running
        proc = subprocess.Popen(
            ["dsa_visualizer.exe"],  # make sure exe is in same folder
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
            bufsize=1
        )
        threading.Thread(target=read_output, daemon=True).start()
        output_box.insert(tk.END, "DSA Visualizer started...\n")
    else:
        output_box.insert(tk.END, "DSA Visualizer is already running.\n")

# Function to read C program output
def read_output():
    while True:
        line = proc.stdout.readline()
        if line == "" and proc.poll() is not None:
            break
        if line:
            output_box.insert(tk.END, line)
            output_box.see(tk.END)

# Function to send input to C program
def send_input(event=None):
    user_input = input_box.get()
    if proc is not None:
        proc.stdin.write(user_input + "\n")
        proc.stdin.flush()
        input_box.delete(0, tk.END)

# Bind Enter key to send input
input_box.bind("<Return>", send_input)

# Start button
start_button = tk.Button(button_frame, text="Start DSA Visualizer", command=start_dsa, width=25)
start_button.pack(side=tk.LEFT, padx=5)

# Exit button
exit_button = tk.Button(button_frame, text="Exit", command=root.destroy, width=25)
exit_button.pack(side=tk.LEFT, padx=5)

# Run the GUI
root.mainloop()
