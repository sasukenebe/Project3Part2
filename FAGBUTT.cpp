#define buffersize 5
#define PROGRAMSPEED 0 //in milliseconds
#define DATASIZE 2000
bool end_flag=0;
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "pthread.h"
#include <fstream>
#include "ThreadFunctions.h"
#define BUFFERSIZE 5
using namespace std;

 /* data is shared by the thread(s) */
/* the thread runs in this separate function */
long A[4][4], B[4][4], C[4][4];
char input;
long presult;  
char *str; 
char *c; 

    
               
                                                                                    // begin main
int main(int argc, char *argv[])
{     
              
      
    printf("\nBEGIN_MAIN_PART2:\n\n ");   
    
    getchar(); 
    fseek(stdin,0,SEEK_END);

       myfile.open ("stuff.txt",fstream::app);
       myfile2.open ("debug.txt",fstream::app);

printf("Begin Part 2 of Program, press any key\n\n\t=\t=\t=\t=\t=\t=\t=\t=\t=");
getchar();
myfilereadfrom.open ("stuff.txt");
while((input!='0')&&(input!='1')&&(input!='2')&&(input!='3')&&(input!='4'))
{                                                                                        
printf("enter a command\n1-\n2-\n3-\n4-\n");
fseek(stdin,0,SEEK_END);
input=getchar();
fseek(stdin,0,SEEK_END);

while(end_flag!=true)
{
    if(input=='0')
    {
    printf("we execute “add” matrix.out using execlp, we pass the arguments 0 4 4 str arguments are: cmd row col string"); 
    fillMatrix(A);
    if(end_flag==true)
    break;
    printf("fill matrix ok===========================\n");
    
    fillMatrix(B);
    if(end_flag==true){break;};
    printf("fill matrix ok============================\n");
    
    printMatrix(A);printMatrix(B);
    matrixToString(A,B,str);
        printf("about to call matrix.out\n");
        getchar();
        fseek(stdin,0,SEEK_END);
        
    //puts(str);  
    execlp("matrix.out",0,4,4,str,NULL); 
    printf("matrix out was called successfully\nend option 0\n"); 
    }
    
    if(input=='1')
    {
    printf("we execute subtract matrix.out using execlp, we pass the arguments 1 4 4 str arguments are: cmd row col string");                
    fillMatrix(A);
    if(end_flag==true){break;};
    fillMatrix(B);
    if(end_flag==true){break;};
    matrixToString(A,B,str);
        execlp("matrix.out","1",4,4,str,NULL);
        printf("matrix out was called successfully\nend option 1\n");
        getchar();    
        fseek(stdin,0,SEEK_END);
    }
    
    if(input=='2')
    {
        fillMatrix(A);
        if(end_flag==true){break;}; 
        execlp("matrix.out", "2",4,4,str,NULL);
        getchar();    
    }
    
    if(input=='3')
    {                
             
        cout<<presult;
        execlp("matrix.out","3",4,4,str,NULL);
        getchar();    
    }
    if(input=='4')
    {                
             
        cout<<presult;
        execlp("matrix.out", 0,4,4,str,NULL);
        getchar();    
    }
}

}//end while loop

cout<<"program done, have a great day buddy\n";
getchar();
return 0;
}
