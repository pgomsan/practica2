#ifndef DYV_H
#define DYV_H


#include<vector>


template <typename T>
int partition(std::vector <T>& V, int ini, int fin);

template <typename T>
int quickSort(std::vector <T>& V, int ini ,int fin);

template <typename T>
int swap( T& a, T& b);

template <typename T>
int busquedaBinaria(const T& x, const std::vector <T>& v, int ini, int fin);









/* 
 * Implementacion de la funcion búsqueda binaria
 * DEfinimos el parametro T como template, de esta forma puede entrar en esa T
 * lo que queramos(int float, string...). De la misma manera se le pasa a la función 
 * un valor tipo T(int, float o lo que se necesite en esa llamada) constante(para que
 * no lo pueda cambiar la función) por referencia. A se vez le pasamos un vector de 
 * T's para que procese.
 * 
 * */



template <typename T>
int busquedaBinaria(const T& x, const std::vector <T>& v, int ini, int fin){
	if(ini>fin){
                return -1;
        }
        int medio = (ini + fin) / 2;
	if (v[medio] == x) {
        	return medio; // Elemento encontrado
    	} else if (v[medio] < x) {
        	return busquedaBinaria(x, v, medio + 1, fin); // Busca en la mitad derecha
    	} else {
        	return busquedaBinaria(x, v, ini, medio - 1); // Busca en la mitad izquierda
   	 }	
}

/*Implementación del Quick Sort*/


template <typename T>
int quickSort(std::vector <T>& V, int ini, int fin){
	if(ini<fin){
		int pivot = partition(V, ini, fin);
		quickSort(V, ini, pivot-1);
		quickSort(V, pivot+1, fin);
	}
	return 1;
}

template <typename T>
int partition(std::vector <T>& V, int ini, int fin){
	T x = V[fin];
	int i = ini;
	for(int j=ini; j<fin ; j++){
		if(V[j]<= x){
			swap(V[i],V[j]);
			i = i+1;
		}
	}
	swap(V[i], V[fin]);
	return i;
}

template <typename T>
int swap(T& a, T& b){
	T aux = a;
	a = b;
	b = aux;
	return 1;
}


#endif
