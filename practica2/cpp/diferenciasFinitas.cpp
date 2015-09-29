#include <iostream>
using namespace std;

void MatrizConDirecciones(int **M, int rows, int cols){
    cout << "Elementos de la Matriz con sus direcciones: " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            M[i][j] = i + j;
            cout << M[i][j] << "--> ";
            cout << &M[i][j] << endl;
        }
        cout << endl;
    }
}

void MatrizConPunteros(int **M, int rows, int cols){
    cout << "Elementos de la Matriz con sus direcciones, con aritmética de punteros: " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Aritmética de punteros
            *(*(M + i) + j) = i + j;
            cout << *(*(M + i) + j) << "--> ";
            cout << &M[i][j] << endl;
        }
        cout << endl;
    }
}

int main()
{
    // Puntero a una matriz
    int **pm;
 
    int cols;
    int rows;
 
    cout << "Ingresa nro de filas: ";
    cin >> rows;
 
    cout << endl;
    cout << "Ingresa nro de columnas: ";
    cin >> cols;
 
    pm = new int* [rows];
    for (int i = 0; i < rows; i++) {
        pm[i] = new int[cols];
    }
 
    MatrizConDirecciones(pm, rows, cols);
    MatrizConPunteros(pm, rows, cols);
 
    // Elimino cada vector de la matriz
    for (int i = 0; i < rows; i++) {
        delete[] pm[i];
    }
 
    // Elimino el vector principal
    delete[] pm;
 
    return 0;
}