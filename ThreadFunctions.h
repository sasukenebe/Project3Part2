#ifndef THREADFUNCTIONS_H
#define THREADFUNCTIONS_H
#include <iostream>
#include <fstream>
#include <stdlib.h>
//#include "pthread.h"

void FillMatrix(int array[4][4]);
void matrixToString(int A[4][4],int B[4][4],char *str);


int theClock=0;
int buffer=0;
int max=3;
int min=0;


using namespace std;
ifstream myfile;
ifstream myfile2;
ifstream myfilereadfrom;


void *multiplyThreaded(void *input)
{  
    int temp_row=DP.i;
    int temp_col=DP.j;
    long temp_answer;
    int k;        

     for(k=0;k<4;k++)
     {
     DP.C[temp_row][temp_col] = (DP.C[temp_row][temp_col])+(DP.A[temp_row][k])*(DP.B[k][temp_col]);
     }
            printf("(DP.C[temp_row][temp_col])=%d,", DP.C[temp_row][temp_col] );     

   //DP.count++;
             //pthread_exit(NULL);
             return NULL;
             

}

void fillMatrix(long A[4][4])
{

     int i=0;
int j=0;
char s='0';
bool end=false;



     for(i=0;i<4;i++)
     {
             for(j=0;j<4;j++)
             {

             myfilereadfrom.get(s);
             s=s-'0';
             if(s==40){printf("ENDOFFILE\n\n");break;}
             A[i][j]= s;
             }
             if(s==40){break;}
     }
 
      
// end while loop
          
     if(s==40)
     {
     end_flag=true;
     printf("endflagtrue!!\n");
     }


}



void matrixToString(long A[4][4],long B[4][4],char *str)
{
int x=0;
int i;
int j;

    for (i = 0; i < 32; i++)
    {
        str[i] = -1;
    }
    while (x != 16)
    {
        for (i = 0; i<4; i++)
        {
            for (j = 0; j<4; j++)
            {
                if (str[x] == 'X') { printf("ENDOFFILE\n\n"); break; }

                str[x] = A[i][j]+'0'; x++;
            }
            if (str[x] == 'X') { break; }

        }
        if (str[x] == 'X') { end_flag = true; }
    }// end while x!=16

    while (x != 32)
    {
        for (i = 0; i<4; i++)
        {
            for (j = 0; j<4; j++)
            {
                if (str[x] == 'X') { printf("ENDOFFILE\n\n"); break; }

                str[x] = B[i][j] +'0'; x++;
            }
            if (str[x] == 'X') { break; }

        }
        if (str[x] == 'X') { end_flag = true; }
    }// end while x!=32
    str[32] = NULL;
    puts("end of matrixtostring inside\n");
    puts(str);
    return;

}



void printMatrix(long A[4][4])
{
    int i=0;
int j=0;
     printf("matrix:\n");
     
for(i=0;i<4;i++)
{
                for(j=0;j<4;j++)
                {
                printf("%d",A[i][j]);
                }
                printf("\n");
}

     
}


void singleMatrixToString(long A[4][4],long B[4][4],char *str)
{
int x=0;
int i;
int j;

    for (i = 0; i < 32; i++)
    {
        str[i] = -1;
    }
    while (x != 16)
    {
        for (i = 0; i<4; i++)
        {
            for (j = 0; j<4; j++)
            {
                if (str[x] == 'X') { printf("ENDOFFILE\n\n"); break; }

                str[x] = A[i][j]+'0'; x++;
            }
            if (str[x] == 'X') { break; }

        }
        if (str[x] == 'X') { end_flag = true; }
    }// end while x!=16
    str[16] = NULL;
    puts("end of single_matrixtostring inside\n");
    puts(str);
    getchar();
    fseek(stdin,0,SEEK_END);
    return;

}


void matrixPrint(long M[4][4], int row, int col)
{
    int i,j;
    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
        {
            if(j==0)
                printf("\n[");
            printf("%-5ld",M[i][j]);
            if(j==col-1)
                printf("]");

        }
        printf("\n");
}






#endif
