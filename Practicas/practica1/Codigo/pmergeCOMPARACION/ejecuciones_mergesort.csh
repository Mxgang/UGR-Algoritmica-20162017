#!/bin/csh
@ inicio = 1000
@ fin = 30000
@ incremento = 1000
@ i = $inicio
echo > tiempos_ordenacion.dat
while ( $i <= $fin )
echo Ejecución tam = $i
echo `./mergesort $i 10000` >> tiempos_ordenacion.dat
@ i += $incremento
end
