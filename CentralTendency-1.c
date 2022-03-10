/* Write a program to calculate the AM, GM, HM, Median and Mode from n observations. 
The value of n and the observations are taken by user. */
/* Author: Akash Sinha */

#include<stdio.h>
#include<math.h>

void arthMean(float arr[], int size){
    float sum =0;
    for(int i=0; i<size; i++){
        sum = sum+arr[i];
    }
    sum = sum/size;
    printf("Arithmetic mean: %f\n",sum);
}

void harmoMean(float arr[], int size)
{
    float sum=0;
    for(int i=0; i<size; i++){
        sum+=(1/arr[i]);
    }
    sum+=size/sum;
    printf("Harmonic mean: %f\n",sum);
}

void geoMean(float arr[], int size){
    int sum = 1;
            for(int i=0;i<size;i++)
            {
            
            sum *= arr[i];
            }
            
            float res = pow(sum,(float)1/size);
            printf("Geometric mean: %2.5f",res);
}
int main(){
    int op, size;
    float arr[100];
    printf("Enter size: \n");
    scanf("%d",&size);
    printf("Enter elements: \n");
    for(int i=0; i<size; i++){
        scanf("%f",&arr[i]);
    }
    // arthMean(arr, size);
    // harmoMean(arr, size);
    // geoMean(arr, size);

    printf("1. Arithmetic mean\n");
    printf("2. Geometic mean\n");
    printf("3. Harmonic mean\n");
    printf("4. Mode\n");
    scanf("%d",&op);
    
    switch (op)
    {
    case 1:
        arthMean(arr, size);
        break;
    case 2:
        geoMean(arr, size);
        break;
    case 3:
        harmoMean(arr, size);
        break;
    case 4:
        


    default:
        break;
    }
}

// OUTPUT:
// Enter size: 
// 3
// Enter elements: 
// 1
// 2
// 5
// Arithmetic mean: 2.666667
// Harmonic mean: 3.464706
// Geometric mean: 2.15443