/*Author: Akash Sinha */
/* GitHub: https://github.com/itsakashsinha  */ 
#include<stdio.h>
#define size 8
    
    int x[size]= {9,13,7,16,10,12,8,14};
    int y[size]= {12,17,23,21,19,16,13,20};
    int rankX[size], rankY[size], tempArr[size], tempRank[size]= {1,2,3,4,5,6,7,8};
    int d[size], d_2[size], n = size;
/* Coping array ele to tempArray */
void arrCopy(int arr[], int tempArr[]){
    
    for(int i=0; i<size; i++){
        tempArr[i] = arr[i];
    }
}
/* Sorting elements in tempArray */
void sort(int arr[], int tempArr[]){

    arrCopy(arr, tempArr);
    int temp;
    for(int i=0; i<size; i++){

        for(int j=0; j<size; j++){
            
            if(tempArr[i]<tempArr[j]){
                temp = tempArr[i];
                tempArr[i] = tempArr[j];
                tempArr[j] = temp;
            }
        }
    }
}
/* Calculating Rank */
void calRank(int arr[], int rank[], int tempArr[]){    /* arr, rank, temp sorted array  */
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(arr[i] == tempArr[j]){
                rank[i] = tempRank[j];
            }
        }
    }
}
/* Calculating d */
void cal_d(int rankX[], int rankY[]){
    for(int i=0; i<size; i++){
        d[i] = rankX[i]-rankY[i];
    }

}
/* Calculating d^2 */
void cal_dSqr(int d[]){
    for(int i=0; i<size; i++){
        d_2[i]= d[i]*d[i];
    }
}

int sum(int arr[], int n){
    int res= 0;
    for(int i=0; i<n; i++){
        res = res+arr[i];
    }
    return res;
}

float rankCorelation(){
    float sum_d_2 = sum(d_2, size);
    float upper= 6*sum_d_2;
    float lower=n*(n*n -1);
    float upper1= lower - upper;
    float result = upper1/lower;

    return result;
}

void printing(){
        printf("\tX\t RankX\t Y\t RankY\t d\t d^2  \n");
        printf("\t------\t------\t----\t------\t----\t-----\n");
    for(int i=0; i<size; i++){
        printf("\t%d\t %d\t %d\t %d\t %d\t %d\n ",x[i],rankX[i],y[i],rankY[i],d[i],d_2[i]);
    }
    printf("\n");
    printf("Rank corelation: %f",rankCorelation());
}

int main(){
    /* Calculating rank of X */
    sort(x, tempArr);
    calRank(x, rankX, tempArr);
    // printing(x, rankX);

    /* Calculating rank of Y */
    sort(y, tempArr);
    calRank(y, rankY, tempArr);
    // printing(y, rankY);

    /* Calculating d */
    cal_d(rankX, rankY);
    cal_dSqr(d);
    // printf("%d",sum(d_2, size));
    printing();
    // float rank = rankCorelation();
    // printf("%f",rank);

    return 0;
}