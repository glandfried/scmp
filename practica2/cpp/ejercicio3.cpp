#include <iostream> // para cin y cout
#include <fstream> // de emmanuel ejemplo para imprimir y leer archivos
#include <sstream> // de emmanuel ejemplo para imprimir y leer archivos
#include <string> // de emmanuel ejemplo para imprimir y leer archivos 

using namespace std;



double* jacobi(int n, double** A, double* X0, double* B, double tolerancia){
	double viejo[n];
	double nuevo[n];
	bool iniciado = false;
	double error; 

	for(int i = 0; i < n; i++){
		viejo[i] = X0[i];	
	}

	double sum; 
	while( !iniciado || tolerancia < error){
				
		for(int i = 0; i < n; i++){
			sum=0; 
			for(int j = 0; j < n; j++){
				cout << i << j << endl;
				sum = sum + (A[i][j]*viejo[j]);
			}
			nuevo[i] = (B[i] - sum)/A[i][i]; 
		} 
		
		error = nuevo[0] - viejo[0];
		for(int i = 1; i < n; i++){
			if (nuevo[i] - viejo[i] < error){
				error = nuevo[i] - viejo[i] ;
			}
		}
		
		for(int i = 0; i < n; i++){
			viejo[i] = nuevo[i];
		}		
	}  
	return X0;
}

int main(){
	int n=2;
	double **A[n][n];
	/*double** A = new double*[n];
	for(int i=0, i < n, i++)
		A[i] = new double[n];*/

	A[0][0] = 4; A[0][1] = -1; A[0][2] = 0;
	A[1][0] = -1; A[1][1] = 4; A[1][2] = -1;
	A[2][0] = 4; A[2][1] = -1; A[2][2] = 0;
	double X0[n];
	X0[0] = 0; X0[1] = 0; X0[2] = 0;
	double B[n];
	B[0]=2;B[1]=6;B[2]=2; 
	double tolerancia = 0.01; 

	jacobi(n,A,X0,B,tolerancia);
	//jacobi(n,A,X0,B,tolerancia);



}

