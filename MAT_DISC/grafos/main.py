# link do video https://photos.app.goo.gl/SeiqxNRPdRTJXKmN6
import csv

matriz = []

# Ler arquivo
with open('grafo.csv', newline='', encoding='utf-8') as arquivo:
    leitor = csv.reader(arquivo)
    for linha in leitor:
        matriz.append(linha)

print(matriz)

#Imprime a matriz
for i in matriz:
    print('|', end=' ')
    for j in i:
        print(j, end=' ')
    print('|')

arestas = 0

#Somar aresas
for i in matriz:
    for j in i:
        if int(j) != 0:
            arestas+=1

print(f'\nO grafo tem {len(matriz)} nos e {arestas} arestas!')

digrafo = True

#Digrafo ou grafo
for i in range(len(matriz)):
    if (digrafo == False):
        break
    for j in range(len(matriz)):
        if matriz[i][j] != matriz[j][i]:
            digrafo = False
            break

if digrafo:
    print("\nEh um Digarfo\n")
else:
    print("\nNao eh um Digrafo\n")

simples = True
#Grau de cada no e se em simples
for i in range(len(matriz)):
    g = 0
    if int(matriz[i][i]) == 1:
        simples = False
    for j in range(len(matriz)):
        if int(matriz[i][j]) == 1 and int(matriz[j][i]) == 1:
            simples = False

        #mostrar o grau
        if int(matriz[i][j]) != 0:
            g += 1
    print(f"No {i} tem grau {g}")

if simples:
    print("\nGrafo eh simples")
else:
    print("\nGrafo nao eh simples")

#Grafo tem no isolados
for i in range(len(matriz)):
    isolados = True
    for j in range(len(matriz)):
        if int(matriz[i][j]) != 0 or int(matriz[j][i]) != 0:
            isolados = False
    if isolados:
        print(f'O no {i} eh isolado')
