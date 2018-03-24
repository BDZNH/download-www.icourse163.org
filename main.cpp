#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
    ifstream InFile("download_link.txt");
    if(!InFile)
    {
        cout<<"Can't open the download_link.txt. No such a file."<<endl;
        system("pause");
        return 0;
    }

    string DownloadUrl;
    string name;
    string temp;
    string command="aria2c -s 10 -x 10 \"";

    bool IsFound=false;//flag the +|+

    unsigned int i,k=0;

    char num[4];


    while(getline(InFile,temp))
    {
        //Divide the links into downloading links and filenames
        if(temp=="")
            continue;
        for(i=0;i<temp.size();i++)
        {
            if(!IsFound)
            {
                if(temp[i]=='+')
                {
                    i=i+2;
                    IsFound=true;
                    continue;
                }
                DownloadUrl+=temp[i];
            }
            else
            {
                name+=temp[i];
            }
        }


        //generate download command for aria2c.
        cout<<"Downlading: "<<name<<endl;
        if('v'==DownloadUrl.back())
            name+=".flv\"";
        if('4'==DownloadUrl.back())
            name+=".mp4\"";
        command=command+DownloadUrl+"\""+" -o \"src/";
        sprintf(num,"%03d",k++);
        command=command+num+" "+name;


        //use aria2c.
        system(command.c_str());

        //clear memory. reset state.
        temp.clear();
        DownloadUrl.clear();
        name.clear();
        command.clear();
        command="aria2c -s 10 -x 10 \"";
        IsFound=false;
    }
    return 0;
}
