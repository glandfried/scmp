// basic file operations
// more information in: http://www.cplusplus.com/doc/tutorial/files/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


int main()
{
  int n=5;
  string line;
  ofstream myfile1;
  ifstream myfile2;
  ostringstream filename;

  // Write files
  for(int i=0; i<n; i++){
   
    // Set file name
    filename.str("");
    filename.clear();
    filename << "test_file_" << i << ".txt";
    
    // Print file name
    cout<<filename.str()<<endl;
    
    // Open file
    myfile1.open(filename.str().c_str());
    
    // Write content
    myfile1 << "This is file " << i <<", line 1 content.\n";
    myfile1 << "This is file " << i <<", line 2 content.\n";
    
    // Close file name
    myfile1.close();
    
  }
  
  cout << endl;
  
  // Read files
  for(int i=0; i<n; i++){
   
    // Set file name
    filename.str("");
    filename.clear();
    filename << "test_file_" << i << ".txt";
    
    // Print file name
    cout<<filename.str()<<endl;
    
    // Open file
    myfile2.open(filename.str().c_str());
    
    // Read file and print
    if (myfile2.is_open()){
      while( getline(myfile2,line) ){
	cout << line << endl;
      }
      myfile2.close();
    }
    else cout << "Unable to open file"; 
   
    // Close file name
    myfile2.close();
    
    cout << endl;
  }
  
  return 0;
}
