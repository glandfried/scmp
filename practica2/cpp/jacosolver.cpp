#include <iostream>
#include <math.h>  
#include <fstream>
#include <string.h>
#include <algorithm> 
#include <stdlib.h>  
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>


using namespace std;

double iterror (double* oldvec, double* newvec, long int nvec) { 
	
	double sumita;
	long int i;
	
	
	sumita=0;
	for (i=0; i<nvec; i++) {
	   sumita=sumita+ pow((newvec[i]-oldvec[i]),2);
//	   cout << "sumando"<<pow((newvec[i]-oldvec[i]),2) <<endl;
	}
	
	return sqrt(sumita);//iterror ;
	
}

void jacostep (double **Amat, double *bvec, double *xold, double *xnew,long int n1mat, double tol){ 
	
	long int irow,icol, k;
	double suma, errit;
	
	while(errit>tol) {
	
	for (irow=0 ; irow<n1mat;irow++)	{
		suma=0;
		
		for (icol=0;icol<irow; icol++) {
	    	suma=suma+Amat[irow][icol]*xold[icol];//*xnew[icol];// 		
	     }
	     for (icol=irow+1;icol<n1mat;icol++) {
			suma=suma+Amat[irow][icol]*xold[icol];		
	     }
	   
		xnew[irow]=(bvec[irow]-suma)/(Amat[irow][irow]);	
		 cout << "xold[" << irow <<"]"<<xold[irow] <<endl; 
		errit=iterror(xold, xnew, n1mat);
		cout << "Error " << errit << endl;		
		 xold[irow]=xnew[irow];
		
	}//irow
	//return jacostep;
	
	
     } // while
}

void gaussSeidel(double **Amat, double *bvec, double *xold, double *xnew,long int n1mat, double tol){
	
}




int main() {
	
	
	string auxline ;
    long int i, j, n1mat,n2mat;
    long int istep, icount;
	//vector< vector<double> > Amat;
//	typedef std::vector< std::vector<double> > matrix;
	double tol;
	double ** Amat=NULL; 
	double * bvec=NULL, *xold=NULL, *xnew=NULL;
	ifstream AmatInput, BvecInput;
    ostringstream filename_mat, filename_vec;


	tol=0.00001;



	filename_mat.str("");
    filename_mat.clear();
    filename_mat << "../datos/Amat.dat";
	filename_vec.str("");
    filename_vec.clear();
    filename_vec << "../datos/B.dat";
	// Print file name
    cout<<filename_mat.str()<<endl;
	cout<<filename_vec.str()<<endl;
    // Open file
    AmatInput.open(filename_mat.str().c_str());	
    BvecInput.open(filename_vec.str().c_str());

   icount=0;
   if (BvecInput.is_open()){     //check is file has been opened
      while( getline( BvecInput , auxline ) ){  //getline tiene opción de usar un delimitador como tercer argumento.
        icount = icount + 1;
        cout << " i = "<< icount << endl;
      }
    } else {
        cout << "Unable to open file" << endl;
    }
	
	n1mat=icount;
	n2mat=icount;
	
	   
      // Memory allocation of pointer matrix (in the heap) based on size variables previously declared and initialized
     Amat = new double*[n1mat];
      for(int irow = 0; irow < n1mat; irow++) {
		Amat[irow] = new double[n2mat];    
		}
	 bvec = new double[n1mat];

 //   double bvec[n1mat], xvec[n1mat];
//	double Amat[n1mat][n2mat];
	//std::vector<double> bvec(n2mat);
	//std::vector<double> xvec(n2mat);
	
	
	//...Reinicio
    BvecInput.close();
    BvecInput.open(filename_vec.str().c_str());

	
	long int irow, icol; 
	for (irow = 0; irow < n1mat; irow=irow+1) {
                BvecInput >> bvec[irow];
            cout << "bvec["<<irow<<"] =" << bvec[irow] << endl;
    }
    
    
    cout <<"Loading matrix" << endl;
	for (irow = 0; irow < n1mat; irow=irow+1) {
        for (icol = 0; icol < n2mat-1; icol=icol+1) {
            AmatInput >> Amat[irow][icol];
            cout << "Amat["<<irow<<"]["<<icol<<"]="<<Amat[irow][icol]<<" " ;
        }
        AmatInput >> Amat[irow][n2mat-1];
        cout << "Amat["<<irow<<"]["<<n2mat-1<<"]="<<Amat[irow][n2mat-1]<<endl ;
   }
	
	
	cout <<"Initializing xvec[]"<< endl;
	//double xnew[n1mat], xold[n1mat];
	xnew = new double[n1mat];
	xold = new double[n1mat];
    for (irow=0;i<n1mat; i=i+1) {
	xnew[irow]=0;
	xold[irow]=0;}
//	cout << "xvec["<<irow<<"]" << endl;
//	}
	
	//for (istep=0; istep<8; istep++) {
	//    jacostep (Amat, bvec, xold, xnew, n1mat );
	//jacostep(Amat, bvec, xvec);
    // }
	//jacostep(
	double suma, errit;
    errit=100;
   // for (istep=1; istep<8; istep++){
	   istep=0;
	//   while(errit>tol) { istep=istep+1;


      jacostep (Amat, bvec, xold, xnew, n1mat, tol );
	//	for (irow=0;irow<n1mat; irow++) {
	//  xold[irow]=xnew[irow];}
  //  }
	cout << "Iterations : " << istep<<endl;
	
	
	
	
	
	// Elimino cada vector de la matriz
    for (int irow = 0; irow < n1mat; irow++) {
        delete[] Amat[irow];
    }
	delete bvec;
	
	} // end program
	
//void jacostep( double ** mat, double b[], double x[], long int n1, long int n2)
 //{
	
	//long int n1, n2;
	//double mat[n1][n2], b[n1], x[n1];
	
	
	
//	}
	
//void GSstep( vector< vector<double> > *Aptr, 
 //vector<double> *Bptr, vector<double> *Xptr ) {
//}
	
	
