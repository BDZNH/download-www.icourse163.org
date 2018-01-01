/*
BDZNH
我觉得这个东西实在是有点那啥
*/
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <cstdlib>
using namespace std;

void gogogo(char *name,char *command)
{
    int static  num=1;
    if(num==1)
    {
        cout<<"Please put in init number (Default 1):";
        cin>>num;
    }
    cout<<"Downloading : No."<<num++<<" "<<name<<endl;
    cout<<command<<endl;
//    system(command);
}
int main ()
{
    freopen("download_link.txt","r",stdin);
    char url[1000]={0},cc=0,name[1000]={0},command[10000]={"aria2c -s 10 -x 10 \""},dd=0,bb[4]={0};
    int Len=strlen(command);
    bool ft=true;
    int i=0,j=0,len,haha=1;
    while(scanf("%c",&dd)!=EOF)
    {
        if(cc=='\n'&&dd=='\n')
            continue;
        cc=dd;
        if(cc=='\n')
        {
            strcat(command,url);
            strcat(command,"\" -o \"src/");
            sprintf(bb,"%02d ",haha++);
            strcat(command,bb);
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
            memset(url,0,sizeof(char)*1000);
            memset(name,0,sizeof(char)*1000);
            memset(command+20,0,sizeof(char)*1000);
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
