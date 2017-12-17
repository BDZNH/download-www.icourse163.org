#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <cstdlib>
using namespace std;

void gogogo(char *name,char *command)
{
    cout<<"Downloading :"<<name<<endl;
//    cout<<command<<endl;
    system(command);
}
int main ()
{
    freopen("download_link.txt","r",stdin);
    char url[1000]={0},cc=0,name[1000]={0},command[10000]={"aria2c -s 10 -x 10 \""},dd=0;
    int Len=strlen(command);
    bool ft=true;
    int i=0,j=0,len;
    while(scanf("%c",&dd)!=EOF)
    {
        if(cc=='\n'&&dd=='\n')
            continue;
        cc=dd;
        if(cc=='\n')
        {
            strcat(command,url);
            strcat(command,"\" -o \"src/");
            strcat(command,name);
            len=strlen(url);
            if(url[len-1]=='v')
                strcat(command,".flv\"\n");
            if(url[len-1]=='4')
                strcat(command,".mp4\"\n");
//            printf("%d     %s",count++,command);
//            system(command);

            gogogo(name,command);
            command[Len]=0;
            i=0;
            j=0;
            ft=true;
            continue;
        }
        if(cc=='+'||cc=='|')
        {
            ft=false;
            continue;
        }
        if(ft)
        {
            url[i++]=cc;
        }
        else
        {
            name[j++]=cc;
        }
    }
    if(cc!='\n')
    {
        strcat(command,url);
        strcat(command,"\" -o \"");
        strcat(command,name);
        if(url[i-1]=='v')
            strcat(command,".flv\"\n");
        if(url[i-1]=='4')
            strcat(command,".mp4\"\n");
        gogogo(name,command);
    }
    return 0;
}
