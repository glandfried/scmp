#include <iostream> // para cin y cout
#include <fstream> // de emmanuel ejemplo para imprimir y leer archivos
#include <sstream> // de emmanuel ejemplo para imprimir y leer archivos
#include <string> // de emmanuel ejemplo para imprimir y leer archivos 

using namespace std;



int main(){
	float tolerancia = 0.001; //cout << tolerancia << endl; 
	int n = 2; // 0,1,2 las posiciones que voy a evaluar
	double viejo[n]; /*cout << old[1] << endl;*/  
	double nuevo[n];
	double error = 1.0;
	
	ofstream myfile1;
	ofstream myfile2;
	ostringstream filename1;
	ostringstream filename2;

	// Set file name
    filename1.str("");
    filename1.clear();
    filename1 << "../datos/ejercicio2Valores.csv";
    
    filename2.str("");
    filename2.clear();
    filename2 << "../datos/ejercicio2Errores.csv";
    
    // Print file name
    // cout<<filename1.str()<<endl;
    
    // Open file
    myfile1.open(filename1.str().c_str());
    myfile2.open(filename2.str().c_str());
    

    for(int i = 0; i < 3; i++){
		nuevo[i] = 0;
		if (i==n){
			cout << nuevo[i] << endl;
			myfile1 << nuevo[i] << endl;
		}
		else{
			cout << nuevo[i] << ",";
			myfile1 << nuevo[i] << ",";
		} 
		
	}
    
	while(tolerancia < error){
		for(int j = 0; j < 3; j++){
			viejo[j] = nuevo[j];
		}
		
		nuevo[0] = (2+viejo[1])/4;
		nuevo[1] = (6+viejo[2]+nuevo[0])/4;
		nuevo[2] = (2+nuevo[1])/4;
		
		for(int j = 0; j < 3; j++){
			if (j == n){
				cout << nuevo[j] << endl;
				myfile1 << nuevo[j] << endl;
			}
			else{
				cout << nuevo[j] << ",";
				myfile1 << nuevo[j] << ",";
			}
		}

		
		error = nuevo[0] - viejo[0] ;
		for(int j = 1; j < 3; j++){
			if (nuevo[j] - viejo[j] < error){
				error = nuevo[j] - viejo[j] ;
			}
		myfile2 << error << endl;
		}
	}
	
	 // Close file name
    myfile1.close();
    myfile2.close();
}

