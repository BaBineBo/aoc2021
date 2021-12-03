#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>       /* pow */
using namespace std;

int main () {

    ////////////////////////////////////////////////////////////
    // Setup
    ////////////////////////////////////////////////////////////
    vector<string> binary_numbers;
    binary_numbers.reserve(1000);
    ifstream input_binary("input.txt");

    if(!input_binary.is_open()){
            
        cout << "no file open" << endl;
        return EXIT_FAILURE;
    } 

    string current;
    while(input_binary>>current){
        binary_numbers.push_back(current);
    }
        // close the fstream
    input_binary.close();

    binary_numbers.shrink_to_fit();
   //cout << (binary_numbers.at(0)).at(0);

    int bits[12] = {0};

    for (int i = 0; i < sizeof(bits)/4; i++){

        for (int j = 0; j < binary_numbers.size(); j++){
            if(binary_numbers[j].at(i)=='1'){
                bits[i]++;
            }
        }
        cout << bits[i] << endl;
    }

    //cout << bits[0] <<bits[1] <<bits[2] <<bits[3] <<bits[4] <<bits[5] << endl;
    int gammaL[12]={0};
    int epsilonL[12]={0};
    for (int i = 0; i < sizeof(bits)/4; i++){
        //cout << bits[i] << endl;
        if(bits[i]>500){
            gammaL[i]=1;
            epsilonL[i]=0;
        } else {
            gammaL[i]=0;
            epsilonL[i]=1;
        }
        //cout << "gamma: "<<gammaL[i] << " epi: "<<epsilonL[i] <<endl; //correct calculations
    }

    int gamma=0, epsilon=0;
    for (int i = 0; i < sizeof(bits)/4; i++){
       
        double g = pow(2,(12-i-1));
         cout <<"2 to power of "<< sizeof(bits)/4-i-1 << " is "<<g<< endl;
        //cout << g << " " << e << endl;
        gamma += gammaL[i]*g;
        epsilon += epsilonL[i]*g;
        //cout << "gamma: "<<gammaL[i]*g << "         "<<epsilonL[i]<< " epi: "<<epsilonL[i]*g <<endl;
        cout << "gamma: " << gamma << " and epsilon " << epsilon << endl;
    }

    cout << "Gamma is " << gamma << " and epsilon is " << epsilon << endl << "The product is " << gamma*epsilon;
    return 0;
}