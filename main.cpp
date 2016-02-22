#define buffersize 5
#define PROGRAMSPEED 0 //in milliseconds
#define DATASIZE 2000
bool end_flag=false;
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
//#include "pthread.h"
#include <pthread.h>
#include <fstream>
#include <sys/types.h>
#include <sys/wait.h>
char str[32];
char str2[16];
#include "ThreadFunctions.h"
#define BUFFERSIZE 50
using namespace std;

 /* data is shared by the thread(s) */
/* the thread runs in this separate function */
long A[4][4], B[4][4], C[4][4];
char input;
long presult;  
//char str[32];
char Astring[16];
char Bstring[16];
char ABstring[32];
char *c; 
pid_t pid;

    
               
                                                                                    // begin main
int main(int argc, char *argv[])
{     
  printf("snapppel\n");
  str[32]=NULL; 
  Bstring[16]=NULL;
  Astring[16]=NULL; 
  ABstring[32]=NULL;   
      
    printf("\nBEGIN_MAIN_PART2:\n\n ");   
    
    getchar(); 
    fseek(stdin,0,SEEK_END);

       myfile.open ("stuff.txt",fstream::app);
       myfile2.open ("debug.txt",fstream::app);

printf("Begin Part 2 of Program, press any key\n\n\t=\t=\t=\t=\t=\t=\t=\t=\t=");
myfilereadfrom.open ("stuff.txt");

while((input!='0')&&(input!='1')&&(input!='2')&&(input!='3')&&(input!='4'))
{                                                                                        
  printf("enter a command\n1-\n2-\n3-\n4-\n");

  fseek(stdin,0,SEEK_END);
  input=getchar();
  fseek(stdin,0,SEEK_END);
}
  while(end_flag!=true)
  {

   if(input=='0')
      {
      printf("========BEGIN option 0, until no more stuff.txt=========\n");
      printf("we execute “add” matrix.out using execlp, we pass the arguments 0 4 4 str arguments are: cmd row col string"); 
      fillMatrix(A);
      if(end_flag==true){break;}
      fillMatrix(B);
      if(end_flag==true){break;};
      printf("Matrix A:\n");
      printMatrix(A);
      printf("Matrix B:\n");
      printMatrix(B);
      
      matrixToString(A,B,str);
      printf("(Matrix A)+(Matrix B) string: ");
      puts(str);

  // begin fork
  pid_t parent = getpid();
  pid_t pid0 = fork();
                                                                                  
  if (pid0 == -1)
  {
      printf("fork failed\n");
  } 
          // if CHILD 
          if(pid0 == 0)
          {
              printf("Now entering execlp\n\n");
               execlp("./matrix.out","matrix.out","0","4","4",str,NULL);
              _exit(EXIT_FAILURE);   // exec never returns                                              // you could just wait for child, but that would
          }
          else// Parent Process
          {
      printf("========END option 0, until no more stuff.txt=========\n");
      //getchar();
      //fseek(stdin,0,SEEK_END);
       
       }
       
                                                                                    
      printf("matrix out was called successfully\nend option 0\n"); 
      } // end option 0
      



  if(input=='1')
  {

  printf("========BEGIN option 1, until no more stuff.txt=========\n");
      printf("we execute “add” matrix.out using execlp, we pass the arguments 0 4 4 str arguments are: cmd row col string"); 
       fillMatrix(A);
      if(end_flag==true){break;}
      fillMatrix(B);
      if(end_flag==true){break;};
      printf("Matrix A:\n");
      printMatrix(A);
      printf("Matrix B:\n");
      printMatrix(B);
      
      printf("(Matrix A)+(Matrix B) string: ");
      matrixToString(A,B,str);
      puts(str);

     // begin fork          
  pid_t parent = getpid();
  pid_t pid1 = fork();
                                                                                  // error, failed to fork()
  if (pid1 == -1)
  {
      printf("fork failed\n");
  } 
          // if CHILD 
          if(pid1 == 0)
          {
              printf("Now entering execlp\n\n");
               execlp("./matrix.out","matrix.out","1","4","4",str,NULL);
              _exit(EXIT_FAILURE);   // exec never returns                                              // you could just wait for child, but that would
          }
          else// Parent Process
          {
      printf("========END option 1, until no more stuff.txt=========\n");
      getchar();
      fseek(stdin,0,SEEK_END);
       
       }
       
                                                                                    
      printf("matrix out was called successfully\nend option 0\n"); 



}// end option 1




      if(input=='2')
      {
          fillMatrix(A);

          singleMatrixToString(A,B,str2);

          if(end_flag==true){break;}; 
  pid_t parent = getpid();
  pid_t pid2 = fork();
                                                                                  // error, failed to fork()
  if (pid2 == -1)
  {
      printf("fork failed\n");
  } 
          // if CHILD 
          if(pid2 == 0)
          {
              printf("Now entering execlp\n\n");
               execlp("./matrix.out","matrix.out","2","4","4",str2,NULL);
              _exit(EXIT_FAILURE);   // exec never returns                                              // you could just wait for child, but that would
          }
          else // Parent Process
          {
      printf("========END option 2, until no more stuff.txt=========\n");
      getchar();
      fseek(stdin,0,SEEK_END);



      }
      

}// end option 2
      if(input=='3')
      {
        int ii;
                    printf("we make 16 threads each doing a dot product.........\n\n");                
      int numberOfChildren = 16;
  pid_t *childPids;               //pid_t *childPids=NULL; -->
  pid_t p;

  /* Allocate array of child PIDs: error handling omitted for brevity */
  childPids = (pid_t *)malloc(numberOfChildren * sizeof(pid_t));

  /* Start up children */
  for (ii = 0; ii < numberOfChildren; ii++)   // changed from ++ii to ii++ 
  {
     if ((p = fork()) == 0) {
        // Child process: do your work here
        exit(0);
     }
     else {
        childPids[ii] = p;
     }
  }

  /* Wait for children to exit */
  int stillWaiting;
  do {
     stillWaiting = 0;
      for (int ii = 0; ii < numberOfChildren; ++ii) 
      {
         if (childPids[ii] > 0) {
           
            if ( waitpid(childPids[ii], NULL, WNOHANG) != 0) 
            {
               /* Child is done */
               childPids[ii] = 0;
            }
            else {
               /* Still waiting on this child */
               stillWaiting = 1;
            }
         }
         /* Give up timeslice and prevent hard loop: this may not work on all flavors of Unix */
         sleep(0);
      }
  } while (stillWaiting);

  /* Cleanup */
  free(childPids);
      
      
printf("end option 3==========================================");
  }// end option 3


printf("reached end of while loop, end_flag=%d\n\n",end_flag);
}
//end while loop, end flag is true

printf("program done, have a great day buddy\n");
getchar();
return 0;

} // end main
