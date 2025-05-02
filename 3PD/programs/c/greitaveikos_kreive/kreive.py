import matplotlib.pyplot as plt

threads = [1, 2, 3, 4, 8]
times = [21.84, 9.50, 6.65, 5.39, 4.9]
speedup = [times[0]/t for t in times]

plt.plot(threads, speedup, marker='o')
plt.xlabel('Gijų skaičius')
plt.ylabel('Pagreitis (speedup)')
plt.title('Greitaveikos kreivė')
plt.grid(True)
plt.show()