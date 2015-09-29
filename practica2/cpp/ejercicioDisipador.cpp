#include <iostream> // para cin y cout
#include <fstream> // de emmanuel ejemplo para imprimir y leer archivos
#include <sstream> // de emmanuel ejemplo para imprimir y leer archivos
#include <string> // de emmanuel ejemplo para imprimir y leer archivos 

using namespace std;



int main(){
	float tolerancia = 0.001; //cout << tolerancia << endl; 
	//int n = 2; // 0,1,2 las posiciones que voy a evaluar
	double Tnuevo[9][11];
	double Tviejo[9][11];
	for (int i=0; i<=8; i++){
		for (int j=0;j<=10;j++){
			Tnuevo[i][j] = 30;
		}
	}
	for (int j=1;j<=9;j++){
		Tnuevo[8][j] = 60;
	}

	double error = 1.0;
	
	ofstream myfile1;
	ostringstream filename1;
	// Set file name
    filename1.str("");
    filename1.clear();
    filename1 << "../datos/ejercicioDisipador.csv";
    
    // Print file name
    // cout<<filename1.str()<<endl;
    
    // Open file
    myfile1.open(filename1.str().c_str());    

    for (int i=0; i<=8; i++){
		for (int j=0;j<=10;j++){
			if (j==10){
				cout << Tnuevo[i][j] << endl;
			}else{
				cout << Tnuevo[i][j] << ",";
			}	
		}
	}
	
	while(tolerancia < error){
		for (int i=0; i<=8; i++){		
			for (int j=0;j<=10;j++){
				//cout << i << j << endl;
				Tviejo[i][j] = Tnuevo[i][j];
			}
		}
		
		error = 0;
		
		for (int j=1; j<=9; j++){
			if (j % 2 == 1){
				for (int i=1;i<=7;i++){
					Tnuevo[i][j] = (Tviejo[i][j-1] + Tviejo[i][j+1] + Tviejo[i-1][j] + Tviejo[i+1][j])/4;
					if (Tnuevo[i][j] - Tviejo[i][j] > error){
						error = Tnuevo[i][j] - Tviejo[i][j];
					}
				}
			}else{
				for (int i=6;i<=7;i++){
					Tnuevo[i][j] = (Tviejo[i][j-1] + Tviejo[i][j+1] + Tviejo[i-1][j] + Tviejo[i+1][j])/4;
					if (Tnuevo[i][j] - Tviejo[i][j] > error){
						error = Tnuevo[i][j] - Tviejo[i][j] ;
					}
				}
			}		
		}
		
		cout<<"Error maximo " << error << endl;

	}

	cout << "Termina"<<endl;

	    for (int i=0; i<=8; i++){
		for (int j=0;j<=10;j++){
			if (j==10){
				cout << Tnuevo[i][j] << endl;
			}else{
				cout << Tnuevo[i][j] << ",";
			}	
		}
	}

    for (int i=0; i<=8; i++){
		for (int j=0;j<=10;j++){
			if (j==10){
				myfile1 << Tnuevo[i][j] << endl;
			}else{
				myfile1 << Tnuevo[i][j] << ",";
			}	
		}
	}
	
    myfile1.close();
}

