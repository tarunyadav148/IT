#include<iostream>

using namespace std;

/*
It will return index of first occurrence
of substring in a string.

If substring is not found or input is invalid
it will return -1

*/
int occurrence_of_substring(string main_string,string sub_string){

    //checking validity of data
    if(main_string == "") return -1;
    if(sub_string == "") return -1;
    if(sub_string.size()>main_string.size()) return -1;

    //setting index initially -1
    int index = -1;

    for(int i=0; i<main_string.size();i++){

        //match of first word of subtring with main string
        if(main_string[i]==sub_string[0]){

            //checking remaining length to check must greater 
            //than lentgh of substring
            if(main_string.size()-i-1>=sub_string.size()){
                
                int count = 0;

                for(int j=0;j<sub_string.size();j++){

                    if(main_string[i+j]==sub_string[j]) count ++;     

                }

                if(count == sub_string.size()){
                    index = i;
                    break;
                }
            }

            
        }
    }

    return index;
}


int main(){

    string str1;
    string str2;

    cout<<"Enter main string: ";
    cin>>str1;

    cout<<"Enter substring: ";
    cin>>str2;

    cout <<"First occurrence of substring in main string:" <<occurrence_of_substring(str1,str2)<<endl;

    return 0;
}