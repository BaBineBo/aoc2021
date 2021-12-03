#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>       /* pow */
using namespace std;

void most_common_num(vector<string> o2_origin,vector<string> co2_origin, int times){

    vector<string> o2_copy;
    int size_o2 = o2_origin.size();
    o2_copy.reserve(size_o2);

    vector<string> co2_copy;
    int size_co2 = co2_origin.size();
   // cout << "sice of origin: " << co2_origin.size() << endl;
 
    co2_copy.reserve(size_co2);
   // cout << "sice of vector: " << co2_copy.size() << endl;
    // count number of 1:s at position 11-times
    int bits_o2=0;
    for (int j = 0; j < o2_origin.size(); j++){
        if(o2_origin[j].at(11-times)=='1'){
            bits_o2++;
        }
    }
    // determine what sign there is the most of
    char dominant_o2 = '1';
    if (bits_o2<(o2_origin.size()/2)){
        dominant_o2 = '0';
    }


    // same for co2
    int bits_co2=0;
    for (int j = 0; j < co2_origin.size(); j++){
        if(co2_origin[j].at(11-times)=='1'){
            bits_co2++;
        }
    }

    // determine what sign there is the most of
    char dominant_co2 = '1';
    if (bits_co2<(co2_origin.size()/2)){
        dominant_o2 = '0';
    }

    // O2
    //Gather all vector elements that match dominant_o2 value att locatio 11-times
    for (int i =0; i < o2_origin.size(); i++){
        string s = o2_origin[i];
        if (s[11-times] == dominant_o2){
            o2_copy.push_back(o2_origin.at(i));
        }
    }

    // CO2

    for (int i =0; i < co2_origin.size(); i++){
        string s = co2_origin[i];
 //cout <<"s: "<<s <<" i: " << i << "of" << co2_origin.size()<< endl;
        if (s[11-times] != dominant_co2){ // !!!!!!!!!!!!!!!!!!!!!!!!!!
        //cout << "will pushback"<< endl;
            co2_copy.push_back(co2_origin.at(i));
           // cout << co2_copy.back();        
        }
    }

    // shrink vector to its contents
    o2_copy.shrink_to_fit();
    co2_copy.shrink_to_fit();

    // start calculating the actual value from binary string
    // when there is one elem left inte vector<string>
    if (o2_copy.size()==1){
        string o2 = o2_copy.at(0);
        string co2 = co2_copy.at(0);
        uint64_t returnValO2 = 0;
        uint64_t returnValCO2 = 0;
        for (int i = 0; i < o2.length(); i++){
            if(o2[i] == '1'){
                returnValO2 += pow(2,(12-i-1));
            }
            if(co2[i] == '1'){
                returnValCO2 += pow(2,(12-i-1));
            }
        }
        // write the results to terminal
        cout <<endl<< "the result of O2 is " << returnValO2<<endl;
        cout <<endl<< "the result of CO2 is " << returnValCO2<<endl;
        cout << "The product is: " << returnValO2 * returnValCO2 << endl;
        return;
    }

    cout << co2_copy.at(0) << endl;
    // will run total of 11 times
    cout << "one more time.." << endl;
    most_common_num(o2_copy,co2_copy, times-1);
    return;
}

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

// get data in string format, resize vectors and close file
    string current;
    while(input_binary>>current){
        binary_numbers.push_back(current);
    }
        // close the fstream
    input_binary.close();
    binary_numbers.shrink_to_fit();

// know ho many 1.s are found in each position
    int bits[12] = {0};


    for (int j = 0; j < binary_numbers.size(); j++){
        if(binary_numbers[j].at(0)=='1'){
            bits[0]++;
        }
    }
    most_common_num(binary_numbers,binary_numbers,11); // 126 for O2


    return 0;
}