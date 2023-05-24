compila:
		gcc musicas.c -c -g
		gcc -g musicasmain.c musicas.o -o exec
		./exec #< input.txt > output.txt
clear:
		#rm mercado.o
		#rm exec