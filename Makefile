mochila: mochila.cpp
	g++ -o mochila mochila.cpp

# Regla para ejecutar el binario
testMochila: mochila
	./mochila

# Limpieza de archivos generados
clean:
	rm -f mochila *.o 
