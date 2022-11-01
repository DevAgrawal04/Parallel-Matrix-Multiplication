//Author: Dev Agrawal (201ME169)
//Parallel Matrix Multiplication

#include <stdio.h> 
#include <omp.h> //open multi processing
#include <stdlib.h> //for rand_r()
#include <time.h> //for time()

/*Variable Declaration*/
long n,m,o,k,sum,threads = 1; //Default value of threads

int main(void){
    printf("Enter the size of matrix 1 as row x col: ");
    scanf("%ldx%ld",&n,&m);
    printf("Enter the size of matrix 2 as row x col: ");
    scanf("%ldx%ld",&o,&k);
    if(o != m){
        printf("Incorrect size of matrix for multiplication \n");
        return -1;
    }
    long* mat1[n]; //Matrix declaration n x m
    long* mat2[m]; // m x k
    long* mat3[n]; // n x k
    printf("Please enter the number of threads to be used: ");
    scanf("%lu",&threads);
    
    /*
    To assign truly unique seeds to all the threads, we use the current timestamp, and increment the thread number to it.
    Also, we use rand_r() because rand_r() is thread safe in linux based systems, whereas rand() isn't.
    */
    unsigned int seed = time(NULL) + omp_get_thread_num();
    
    /*Dynamic Memory Allocation for matrices begins*/
    #pragma omp parallel for num_threads(threads)
    for(long i=0; i<n; i++){     
        mat1[i] = (long*)malloc(m * sizeof(long));
        mat3[i] = (long*)malloc(k * sizeof(long));
    }
    #pragma omp parallel for num_threads(threads)
    for(long i = 0; i<m; i++){
        mat2[i] = (long*)malloc(k * sizeof(long));
    }
    /*Dynamic Memory Allocation for matrices ends*/

    /*Filling the matrices with random values begins*/
    #pragma omp parallel for num_threads(threads)
    for(long i=0; i<n; i++){
         for(long j=0; i<m; i++){
            mat1[i][j] = rand_r(&seed);
         }
    }
    #pragma omp parallel for num_threads(threads)
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
            sum = 0;
            for (long k=0; k<m; k++){
                sum += mat1[i][k] * mat2[k][j];
            }
            mat3[i][j] = sum;
        }
    }
}