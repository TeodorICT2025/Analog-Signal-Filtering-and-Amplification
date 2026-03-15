import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("data1.csv")

plt.figure(figsize=(12,6))
plt.plot(df["time"], df["V_in"], label="Input Voltage")
plt.plot(df["time"], df["V_real"], label="Real Voltage")
plt.plot(df["time"], df["V_theoretical"], label="Theoretical Voltage")
plt.plot(df["time"], df["V_output"], label="Output Voltage")

plt.xlabel("Time (s)")
plt.ylabel("Voltage (V)")
plt.title("Real vs Theoretical RC Circuit Response")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.show()