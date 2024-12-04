#include <iostream>
#include <vector>
#include <fstream>
#include "DyV.h"

// Función para imprimir un vector en un archivo
template <typename T>
void printVectorToFile(std::ofstream& file, const std::vector<T>& vec) {
    for (const auto& val : vec) {
        file << val << " ";
    }
    file << std::endl;
}

// Pruebas con búsqueda binaria
void prueba_busqueda_binaria() {
    std::ofstream file("prueba_busqueda_binaria.txt");
    if (!file.is_open()) {
        std::cerr << "Error al abrir el archivo de salida." << std::endl;
        return;
    }

    file << "Resultados de las pruebas de Búsqueda Binaria:\n\n";

    // Prueba con enteros
    file << "Prueba con vectores de enteros:\n";
    std::vector<int> intVec = {1, 3, 5, 7, 9, 11};
    int buscarEntero = 7;
    file << "Vector: ";
    printVectorToFile(file, intVec);
    file << "Buscando: " << buscarEntero << "\n";
    int resultadoEntero = busquedaBinaria(buscarEntero, intVec, 0, intVec.size() - 1);
    if (resultadoEntero != -1) {
        file << "Resultado: Entero encontrado en la posición " << resultadoEntero << "\n\n";
    } else {
        file << "Resultado: Entero no encontrado\n\n";
    }

    // Prueba con floats
    file << "Prueba con vectores de floats:\n";
    std::vector<float> floatVec = {1.1, 2.2, 3.3, 4.4, 5.5};
    float buscarFloat = 3.3;
    file << "Vector: ";
    printVectorToFile(file, floatVec);
    file << "Buscando: " << buscarFloat << "\n";
    int resultadoFloat = busquedaBinaria(buscarFloat, floatVec, 0, floatVec.size() - 1);
    if (resultadoFloat != -1) {
        file << "Resultado: Flotante encontrado en la posición " << resultadoFloat << "\n\n";
    } else {
        file << "Resultado: Flotante no encontrado\n\n";
    }

    // Prueba con cadenas
    file << "Prueba con vectores de cadenas:\n";
    std::vector<std::string> stringVec = {"apple", "banana", "cherry", "date", "fig"};
    std::string buscarCadena = "cherry";
    file << "Vector: ";
    printVectorToFile(file, stringVec);
    file << "Buscando: " << buscarCadena << "\n";
    int resultadoCadena = busquedaBinaria(buscarCadena, stringVec, 0, stringVec.size() - 1);
    if (resultadoCadena != -1) {
        file << "Resultado: Cadena encontrada en la posición " << resultadoCadena << "\n\n";
    } else {
        file << "Resultado: Cadena no encontrada\n\n";
    }

    file.close();
    std::cout << "Resultados guardados en prueba_busqueda_binaria.txt" << std::endl;
}

// Pruebas con QuickSort
void pruebaQuickSort() {
    std::ofstream file("pruebaQuickSort.txt");
    if (!file.is_open()) {
        std::cerr << "Error al abrir el archivo de salida." << std::endl;
        return;
    }

    file << "Resultados de las pruebas de QuickSort:\n\n";

    // Prueba con enteros
    file << "Prueba con vectores de enteros:\n";
    std::vector<int> intVec1 = {5, 2, 9, 1, 5, 6};
    std::vector<int> intVec2 = {10, 8, 7, 2, 3};

    file << "Vector desordenado 1: ";
    printVectorToFile(file, intVec1);
    quickSort(intVec1, 0, intVec1.size() - 1);
    file << "Vector ordenado 1: ";
    printVectorToFile(file, intVec1);

    file << "Vector desordenado 2: ";
    printVectorToFile(file, intVec2);
    quickSort(intVec2, 0, intVec2.size() - 1);
    file << "Vector ordenado 2: ";
    printVectorToFile(file, intVec2);

    // Prueba con floats
    file << "\nPrueba con vectores de floats:\n";
    std::vector<float> floatVec1 = {3.1, 2.4, 5.6, 1.2, 3.3};
    std::vector<float> floatVec2 = {9.8, 7.7, 6.5, 4.4, 3.2};

    file << "Vector desordenado 1: ";
    printVectorToFile(file, floatVec1);
    quickSort(floatVec1, 0, floatVec1.size() - 1);
    file << "Vector ordenado 1: ";
    printVectorToFile(file, floatVec1);

    file << "Vector desordenado 2: ";
    printVectorToFile(file, floatVec2);
    quickSort(floatVec2, 0, floatVec2.size() - 1);
    file << "Vector ordenado 2: ";
    printVectorToFile(file, floatVec2);

    // Prueba con cadenas
    file << "\nPrueba con vectores de cadenas:\n";
    std::vector<std::string> stringVec1 = {"apple", "orange", "banana", "grape"};
    std::vector<std::string> stringVec2 = {"zebra", "lion", "tiger", "cat", "dog"};

    file << "Vector desordenado 1: ";
    printVectorToFile(file, stringVec1);
    quickSort(stringVec1, 0, stringVec1.size() - 1);
    file << "Vector ordenado 1: ";
    printVectorToFile(file, stringVec1);

    file << "Vector desordenado 2: ";
    printVectorToFile(file, stringVec2);
    quickSort(stringVec2, 0, stringVec2.size() - 1);
    file << "Vector ordenado 2: ";
    printVectorToFile(file, stringVec2);

    file.close();
    std::cout << "Resultados guardados en pruebaQuickSort.txt" << std::endl;
}

// Menú principal
int main() {
    int opcion;
    std::cout << "Elige una opción:\n";
    std::cout << "1. Probar QuickSort\n";
    std::cout << "2. Probar Búsqueda Binaria\n";
    std::cout << "Opción: ";
    std::cin >> opcion;

    switch (opcion) {
    case 1:
        pruebaQuickSort();
        break;
    case 2:
        prueba_busqueda_binaria();
        break;
    default:
        std::cout << "Opción no válida" << std::endl;
        break;
    }

    return 0;
}
