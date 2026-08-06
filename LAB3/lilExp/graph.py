import matplotlib.pyplot as plt

n = []
steps = []

with open("average_steps.txt", "r") as file:
    for line in file:
        x, y = map(int, line.split())
        n.append(x)
        steps.append(y)

plt.figure(figsize=(8,5))
plt.plot(n, steps, marker='o')

plt.title("Insertion Sort Average Case")
plt.xlabel("Number of Elements (n)")
plt.ylabel("Number of Steps")
plt.grid(True)

plt.show()