//Author: Dev Agrawal (201ME169)
//Parallel Matrix Multiplication

#include <stdio.h> 
#include <omp.h> //open multi processing
#include <stdlib.h> //for rand_r()
#include <time.h> //for time()

/*Variable Declaration*/
long n,m,o,k,threads = 16; //Default value of threads

int main(void){
    printf("Enter the size of matrix 1 as row x col: ");
    scanf("%ldx%ld",&n,&m);
    printf("Enter the size of matrix 2 as row x col: ");
    scanf("%ldx%ld",&o,&k);
    if(o != m){
        printf("Incorrect size of matrix for multiplication \n");
        return -1;
    }
    // m = 1250;
    // n = 1250;
    // k = 1250;
    long* mat1[n]; // n x m matrix1
    long* mat2[m]; // m x k matrix2
    long* mat3[n]; // n x k result_matrix
    printf("Please enter the number of threads to be used: ");
    scanf("%lu",&threads);
    
    /*
    To assign truly unique seeds to all the threads, we use the current timestamp, and increment the thread number to it.
    Also, we use rand_r() because rand_r() is thread safe in linux based systems, whereas rand() isn't.
    */
    unsigned int seed = time(NULL) + omp_get_thread_num();
    
    /*Dynamic Memory Allocation for matrices begins*/
    for(long i=0; i<n; i++){     
        mat1[i] = (long*)calloc(m,sizeof(long));
        mat3[i] = (long*)calloc(k,sizeof(long));
    }
    for(long i = 0; i<m; i++){
        mat2[i] = (long*)calloc(k,sizeof(long));
    }
    /*Dynamic Memory Allocation for matrices ends*/

    /*Filling the matrices with random values begins*/
    for(long i=0; i<n; i++){
         for(long j=0; i<m; i++){
            mat1[i][j] = rand_r(&seed);
         }
    }
    for(long i=0; i<m; i++){
         for(long j=0; i<k; i++){
            mat2[i][j] = rand_r(&seed);
         }
    }
    /*Filling the matrices with random values ends*/

    //Matrix Multiplication
    #pragma omp parallel for num_threads(threads)    
    for(long i=0; i<n; i++){
        for (long j=0; j<k; j++ ){
            for (long k=0; k<m; k++){
                mat3[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}