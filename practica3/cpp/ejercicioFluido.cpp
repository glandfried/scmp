#include <iostream> // para cin y cout
#include <fstream> // de emmanuel ejemplo para imprimir y leer archivos
#include <sstream> // de emmanuel ejemplo para imprimir y leer archivos
#include <string> // de emmanuel ejemplo para imprimir y leer archivos 

using namespace std;



int main(){
	float tolerancia = 0.001; //cout << tolerancia << endl; 
	//int n = 2; // 0,1,2 las posiciones que voy a evaluar
	double Cproximo[31];
	double Cactual[31];
	double Cviejo[31];
	double v = 0.001;
	double h = (1.0/31);
	double r = ((2*v)/h); 
	for (int i=0; i<31; i++){
		Cviejo[i] = (i/15.0)*0.07;
		Cviejo[30-i] = (i/15.0)*(0.07);
	}
	Cviejo[0] = 0.5;
	Cviejo[30] = -0.5;

	Cactual[0]= 0;
	Cactual[30]=0; 
	for (int i=1; i<30; i++){
		Cactual[i] =  r*(Cviejo[i+1]-2*Cviejo[i]+Cviejo[i-1]) + Cviejo[i] -  Cviejo[i]*(Cviejo[i+1]-Cviejo[i-1]);
	}

	double error = 1.0;
	
	ofstream myfile1;
	ostringstream filename1;
	// Set file name
    filename1.str("");
    filename1.clear();
    filename1 << "../Datos/ejercicioFluido.csv";
    // Open file
    myfile1.open(filename1.str().c_str());    
	
    for (int i=0;i<31;i++){
		if (i==30){
			cout << Cviejo[i] << endl;
			myfile1 << Cviejo[i] << endl;
		}else{
			cout << Cviejo[i] << ",";
			myfile1 << Cviejo[i] << ",";
		}
	}	

	// double D = (40*9.80665)*( (0.001*0.001)/((1.0/31)*(1.0/31)) );

	Cproximo[0]=0.5;
	Cproximo[30]=-0.5;
	
	int k=0;
	while(k < 100){

		error = 0;
		for (int i=0+1; i<31-1; i++){
			Cproximo[i] =r*(Cactual[i+1]-2*Cactual[i]+Cactual[i-1]) + Cviejo[i] -  Cactual[i]*(Cactual[i+1]-Cactual[i-1]);
		}

		for (int i=0; i<31; i++){		
			//cout << i << j << endl;
			Cviejo[i] = Cactual[i];
			Cactual[i] = Cproximo[i];
		}
		
		for (int i=0;i<31;i++){
			if (i==30){
				cout << Cviejo[i] << endl;
				myfile1 << Cviejo[i] << endl;
			}else{
				cout << Cviejo[i] << ",";
				myfile1 << Cviejo[i] << ",";
			}
		}	

		k++;
	}

	for (int i=0;i<31;i++){
		if (i==30){
			cout << Cactual[i] << endl;
			myfile1 << Cactual[i] << endl;
		}else{
			cout << Cactual[i] << ",";
			myfile1 << Cactual[i] << ",";
		}
	}

	cout << "Termina"<<endl;

	
    myfile1.close();
    
}

