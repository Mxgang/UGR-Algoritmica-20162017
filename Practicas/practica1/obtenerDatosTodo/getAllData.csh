#!/bin/csh
@ inicio = 1000
@ fin = 31000
@ incremento = 1000

@ alg = 1
@ efi = 1

@ i = $inicio
while($i <= $fin )
	echo Ejecución tam = $i
	echo `./bin/burbuja $i $i` >> data/burbuja.dat
	@ i += $incremento
end

@ i = $inicio
while($i <= $fin )
	echo Ejecución tam = $i
	echo `./bin/insercion $i $i` >> data/insercion.dat
	@ i += $incremento
end

@ i = $inicio
while($i <= $fin )
	echo Ejecución tam = $i
	echo `./bin/seleccion $i` >> data/seleccion.dat
	@ i += $incremento
end

@ i = $inicio
while($i <= $fin )
	echo Ejecución tam = $i
	echo `./bin/mergesort $i` >> data/mergesort.dat
	@ i += $incremento
end

@ i = $inicio
while($i <= $fin )
	echo Ejecución tam = $i
	echo `./bin/quicksort $i` >> data/quicksort.dat
	@ i += $incremento
end

@ i = $inicio
while($i <= $fin )
	echo Ejecución tam = $i
	echo `./bin/heapsort $i` >> data/heapsort.dat
	@ i += $incremento
end

@ inicio = 1
@ fin = 25
@ incremento = 1

@ i = $inicio
while($i <= $fin )
	echo Ejecución tam = $i
	echo `./bin/floyd $i` >> data/floyd.dat
	@ i += $incremento
end

@ i = $inicio
while($i <= $fin )
	echo Ejecución tam = $i
	echo `./bin/hanoi $i` >> data/hanoi.dat
	@ i += $incremento
end

