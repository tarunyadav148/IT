#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

int main(int argc,char *argv[])
{
    string command = argv[1];
    if(command=="-s")
    {
        cout<<command;
        string Filename = argv[2];
        string filename = Filename.substr(0,Filename.find("."));

        int splitSize = stoi(argv[3])*1024*1024;

        int cnt = 0;
        int filecnt = 1;

        fstream fin,fout;
        char Byte;

        fin.open(Filename,ios::in|ios::binary);
        
        while(!fin.eof())
        {

            fout.open(filename+to_string(filecnt)+".dat",ios::out|ios::binary);
            while(!fin.eof()&&cnt<splitSize)
            {
                fin.read(&Byte,sizeof(Byte));
                fout.write(&Byte,sizeof(Byte));
                cnt++;
            }
            cnt = 0;
            filecnt++;
            fout.close();
        }
        fin.close();
    }
    else if(command=="-j")
    {
        string Filename = argv[2];
        fstream fin,fout;
        fout.open(Filename,ios::out|ios::binary);
        char Byte;
        cout<<argc<<endl;
        for(int i=3;i<argc;i++)
        {
            cout<<argv[i]<<endl;
            fin.open(argv[i],ios::in|ios::binary);
            while(!fin.eof())
            {
                fin.read(&Byte,sizeof(Byte));
                fout.write(&Byte,sizeof(Byte));
            }
            int pos = fout.tellp();
            fout.seekp(pos-1);
            fin.close();
        }
        fout.close();
    }
    else
    {
        cout<<"Invalid command"<<endl;
    }
    

    return 0;
}