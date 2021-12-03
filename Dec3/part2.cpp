#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>       /* pow */
using namespace std;

int most_common_num(vector<string> origin, int times){

    cout << origin.size();
    vector<string> copy;
    copy.reserve(1000);
    int bits=0;
    for (int j = 0; j < origin.size(); j++){
        if(origin[j].at(11-times)=='1'){
            bits++;
        }
    }

    char dominant = '1';
    if (bits<(origin.size()/2)){
        dominant = '0';
    }

    //cout << "dominant bit is " << dominant << endl;
    for (int i =0; i < origin.size(); i++){
        string s = origin[i];
       // cout << "are bits equal? "<<(s[0] == dominant) << endl;
        if (s[11-times] == dominant){
           // cout << "will erase" << endl;
            copy.push_back(origin.at(i));
        }
    }
    copy.shrink_to_fit();
    //cout << "size is "<< copy.size() <<endl;
   // cout << "elem 0 is "<< copy.at(0) << endl<<endl;
    if (copy.size()==1){
        string value = copy.at(0);
        uint64_t retunrVal = 0;
        cout << "the value is: " <<value << endl;
        for (int i = 0; i < value.length(); i++){
            cout << "position is: " << value[i] << endl;
            cout << "would add: " << pow(2,(12-i-1)) << endl;
            if(value[i] == '1'){
                cout << "is in if";
                retunrVal += pow(2,(12-i-1));
            }
            cout << "return is now " << retunrVal << endl;
        }
        cout << "the result is " << retunrVal;
        return retunrVal;
    }
    //cout << "one more time..." << endl;
    most_common_num(copy, times-1);
    //return "nothing";
    //return result;
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
    most_common_num(binary_numbers,11);


    return 0;
}