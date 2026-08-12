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

# Worst Case Data
worst_n = []
worst_steps = []

with open("worst_steps.txt", "r") as file:
    for line in file:
        x, y = map(int, line.split())
        worst_n.append(x)
        worst_steps.append(y)

plt.figure(figsize=(8, 5))

# Best Case - Green
plt.plot(
    best_n,
    best_steps,
    color='green',
    marker='s',
    linewidth=2,
    label='Best Case'
)

# Average Case - Blue
plt.plot(
    avg_n,
    avg_steps,
    color='blue',
    marker='o',
    linewidth=2,
    label='Average Case'
)

# Worst Case - Red
plt.plot(
    worst_n,
    worst_steps,
    color='red',
    marker='^',
    linewidth=2,
    label='Worst Case'
)

plt.title("Insertion Sort: Best, Average and Worst Case")
plt.xlabel("Number of Elements (n)")
plt.ylabel("Number of Steps")
plt.grid(True)
plt.legend()

plt.show()