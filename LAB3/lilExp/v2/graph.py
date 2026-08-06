import matplotlib.pyplot as plt

# Average Case Data
avg_n = []
avg_steps = []

with open("average_steps.txt", "r") as file:
    for line in file:
        x, y = map(int, line.split())
        avg_n.append(x)
        avg_steps.append(y)

# Best Case Data
best_n = []
best_steps = []

with open("best_steps.txt", "r") as file:
    for line in file:
        x, y = map(int, line.split())
        best_n.append(x)
        best_steps.append(y)

plt.figure(figsize=(8, 5))

# Average Case - Red
plt.plot(avg_n, avg_steps,
         color='red',
         marker='o',
         linewidth=2,
         label='Average Case')

# Best Case - Blue
plt.plot(best_n, best_steps,
         color='blue',
         marker='s',
         linewidth=2,
         label='Best Case')

plt.title("Insertion Sort: Average Case vs Best Case")
plt.xlabel("Number of Elements (n)")
plt.ylabel("Number of Steps")
plt.grid(True)
plt.legend()

plt.show()
