from timeit import default_timer
import random
def listaAleatorios(n):
	lista = [random.randint(0,1000) for _ in range(n)] #creamos una lista con numeros aleatorios entre 0 y 1000
	return lista

def Insert(l,comparaciones,asignaciones):
	comparaciones=3 #por la primera comparacion de cada bucle
	asignaciones=1 #i=1 seria la primera asigancion
	i=1
	while i<len(l):
		++comparaciones	#por cada vuelta del bucle
		x=l[i]
		j=i-1
		while j>=0 and l[j]>x:
			comparaciones = comparaciones + 2 #el bucle presenta dos condiciones
			l[j+1]=l[j]
			j=j-1
			asignaciones=asignaciones + 2 #por las 2 lineas de codigo anteriores
		l[j+1]=x
		i=i+1
		asignaciones=asignaciones+4 #el bucle presenta 4 asignacionesen total, sin contar el bucle interno

def Bubble(l,comparaciones,asignaciones):
	asignaciones=2 # 2 por el primer valor que toma i y j en los for
	comparaciones=2 #  2 por las primeras comparaciones que se hara en los for
	for i in range(len(l)-1):
		++asignaciones #por la futura asignacion de i
		++comparaciones #por la futura asignacion de j
		for j in range(len(l)-1):
			++asignaciones
			++comparaciones
			if l[j]>l[j+1]:
				++comparaciones #comparacion de IF
				t=l[j]
				l[j]=l[j+1]
				l[j+1]=t
				asignaciones=asignaciones+3

#CREACION DE ARRAY Y VALORAMOS ESPACIO DE MEMORIA

print("Ingrese cuantos numeros aleatorios desea obtener")
n=int(input())
InicioAleatorios=default_timer()
aleatorios=listaAleatorios(n)
print(aleatorios)
aleatorios2=aleatorios #se crea una segunda lista identica para comparar los tiempos de insertion y bubble
ValorArrayMemoria=2*50+n*10 #se crean 2 array, por ende se multiplica 2X50
FinAleatorios=default_timer()
TotalAleatorios=FinAleatorios - InicioAleatorios

print("------------------------------------")
print("-----------Insertion SORT-----------")
print("------------------------------------")
#creamos el valor de las asignaciones y comparaciones de Insert sort
asignacionesI=0
comparacionesI=0
InicioInsertion = default_timer()
Insert(aleatorios,comparacionesI,asignacionesI)
print(aleatorios)
FinInsertion = default_timer()
TotalInsertion = FinInsertion - InicioInsertion

print("------------------------------------")
print("-----------BUBBLE SORT-----------")
print("------------------------------------")
#creamos el valor de las asignaciones y comparaciones de Insert sort
asignacionesB=0
comparacionesB=0
InicioBubble=default_timer()
Bubble(aleatorios2,comparacionesB,asignacionesB)
print(aleatorios2)
FinBubble=default_timer()
TotalBubble = FinBubble - InicioBubble



