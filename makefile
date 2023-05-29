compila:
		gcc musicas.c -c -g
		gcc pilha.c -c -g
		gcc fila.c -c -g
		gcc -g musicasmain.c musicas.o pilha.o fila.o -o exec
		./exec #< input.txt > output.txt
clear:
		#rm mercado.o
		#rm exec