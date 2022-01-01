#include<iostream>
#include<fstream>

using namespace std;

int main(int argc,char *argv[])
{
    string command = argv[1];
    string Filename = argv[2];

    fstream file;
    char Byte;
    int pos;

    file.open(Filename,ios::in|ios::out|ios::binary);
    if(!file)
    {
        cout<<"file not open"<<endl;
        exit(EXIT_FAILURE);
    }

    if(command=="-e")
    {
        while(!file.eof())
        {
            file.read(&Byte,sizeof(Byte));
            pos = file.tellg();
            file.seekp(pos-1);
            Byte +=5;
            file.write(&Byte,sizeof(Byte));
        }
    }
    else if(command=="-d")
    {
        while(!file.eof())
        {
            file.read(&Byte,sizeof(Byte));
            pos = file.tellp();
            file.seekp(pos-1);
            Byte -=5;
            file.write(&Byte,sizeof(Byte));
        }
    }
    else
    {
        cout<<"Invalid command"<<endl;
    }
    
    file.close();
    return 0;
}