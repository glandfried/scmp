#include <iostream> // para cin y cout
#include <fstream> // de emmanuel ejemplo para imprimir y leer archivos
#include <sstream> // de emmanuel ejemplo para imprimir y leer archivos
#include <string> // de emmanuel ejemplo para imprimir y leer archivos 

using namespace std;



int main(){
	float tolerancia = 0.001; //cout << tolerancia << endl; 
	//int n = 2; // 0,1,2 las posiciones que voy a evaluar
	double Cnuevo[30];
	double Cviejo[30];
	for (int i=0; i<30; i++){
		Cnuevo[i] = 0.01;
	}
	Cnuevo[0] = 1;
	Cnuevo[29] = 0;
	
	double error = 1.0;
	
	ofstream myfile1;
	ostringstream filename1;
	// Set file name
    filename1.str("");
    filename1.clear();
    filename1 << "../datos/ejercicioCilindros.csv";
    // Open file
    myfile1.open(filename1.str().c_str());    
	
    for (int i=0;i<30;i++){
		if (i==29){
			cout << Cnuevo[i] << endl;
			myfile1 << Cnuevo[i] << endl;
		}else{
			cout << Cnuevo[i] << ",";
			myfile1 << Cnuevo[i] << ",";
		}
	}	

	while(tolerancia < error){
		for (int i=0; i<30; i++){		
			//cout << i << j << endl;
			Cviejo[i] = Cnuevo[i];
		}
		
		error = 0;
		for (int i=0+1; i<30-1; i++){
			Cnuevo[i] = (Cviejo[i+1]+Cviejo[i-1])/2;
			if (Cnuevo[i] - Cviejo[i] > error){
				error = Cnuevo[i] - Cviejo[i];
			}		
		}
		
		cout<<"Error maximo " << error << endl;

		for (int i=0;i<30;i++){
			if (i==29){
				cout << Cnuevo[i] << endl;
				myfile1 << Cnuevo[i] << endl;
			}else{
				cout << Cnuevo[i] << ",";
				myfile1 << Cnuevo[i] << ",";
			}	
		}
	}
	cout << "Termina"<<endl;

	
    myfile1.close();
}

