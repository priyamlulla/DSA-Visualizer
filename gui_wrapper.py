import tkinter as tk
import requests

API_URL = "http://127.0.0.1:5000/run"

def send_to_api():
    user_input = input_box.get()
    if not user_input.strip():
        return
    # Send value to Flask API
    payload = {"input": f"{user_input}\n"}
    response = requests.post(API_URL, json=payload)
    data = response.json()
    output_box.delete(1.0, tk.END)
    output_box.insert(tk.END, data.get("output", "No output"))
    input_box.delete(0, tk.END)

root = tk.Tk()
root.title("DSA Visualizer GUI (via Flask API)")
root.geometry("700x500")

tk.Label(root, text="Enter Menu / Value for C Program:", font=("Arial", 12)).pack()
input_box = tk.Entry(root, width=50, font=("Arial", 12))
input_box.pack(pady=5)

send_button = tk.Button(root, text="Send to DSA API", command=send_to_api)
send_button.pack(pady=5)

output_box = tk.Text(root, height=20, width=80, bg="black", fg="lime", font=("Consolas", 12))
output_box.pack(pady=10)

root.mainloop()
