import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# Cargar los datos desde el CSV
df = pd.read_csv('raw_benchmark_data_100k.csv')

# Agrupar por tamaño y calcular el promedio de las repeticiones
grouped = df.groupby('Tamaño').mean()

# Algoritmos a graficar
algorithms = ['Bubble Sort', 'Selection Sort', 'Insertion Sort', 'Quick Sort', 'STL Sort']
colors = ['red', 'blue', 'green', 'orange', 'purple']

# Generar una gráfica para cada algoritmo con la curva de mejor ajuste
for i, algorithm in enumerate(algorithms):
    # Tiempos promedio por tamaño
    x = grouped.index  # Tamaño del conjunto de datos
    y = grouped[algorithm]  # Tiempos promedio

    # Graficar los puntos promedio
    plt.figure(figsize=(10, 6))
    plt.scatter(x, y, label=f'{algorithm} (promedio)', color=colors[i])

    # Ajustar una curva polinomial de grado 2 para algoritmos O(n^2) o grado 1 para O(n log n)
    if algorithm in ['Bubble Sort', 'Selection Sort', 'Insertion Sort']:
        degree = 2  # Ajuste de grado 2 para O(n^2)
    else:
        degree = 1  # Ajuste de grado 1 para O(n log n)

    # Realizar ajuste polinomial
    poly_coeffs = np.polyfit(x, y, degree)
    poly_eq = np.poly1d(poly_coeffs)

    # Generar puntos para la curva ajustada
    x_curve = np.linspace(min(x), max(x), 100)
    y_curve = poly_eq(x_curve)

    # Graficar la curva de mejor ajuste
    plt.plot(x_curve, y_curve, label=f'Curva de mejor ajuste ({degree}º grado)', color=colors[i])

    # Configurar etiquetas y título
    plt.xlabel('Tamaño del conjunto de datos')
    plt.ylabel('Tiempo promedio (ms)')
    plt.title(f'Tiempos promedio y curva de mejor ajuste para {algorithm}')
    plt.legend()

    # Guardar la gráfica como imagen
    plt.savefig(f'curva_ajuste_{algorithm.replace(" ", "_")}.png')

    # Mostrar la gráfica
    plt.show()
