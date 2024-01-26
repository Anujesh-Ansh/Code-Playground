#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    printf("\nEnter the last Number -> ");
    scanf("%d",&n);
    int p[n]; // an array which would be storing the prime numbers
    int i; // for running the values till n
    p[0]=2; // initializing the 1st value of the prime array as 2, in order to compare it with the rest of the elements
    int k; // to initialize the index of the prime array
    int c=1; // to counter the number of inputs in prime array
    for(i=3;i<=n;i+=2){ // here it runs from 3,5,7 ... till n
        k=0; // it always initialize the k value as 0 for every for loop
        while(p[k]!=0 && k < c){ // while prime array's k th index is not 0 and k is within the valid indices of the array
            if(i%p[k] != 0){ // it would be comparing the number with the elements of the prime array, so that, if any number is divisible by prime array numbers, then it is not a prime number
                k++; // it moves from p[0] to p[1]
            }
            else{
                break;// if it was divisible then it will go back to the for loop, and the loop would run for i+2
            }
        }
        if(k == c){
            p[k] = i;
            c++; // if p[k] == 0 and i is still not divisible with any number from prime array, then add the i to the prime array
        }
    }

printf("\nThe prime Numbers are -> ");
for(i=0;i<c;i++){
    printf("%d ",p[i]);
}
printf("\nNumber of prime numbers -> %d\n",c);
    return 0;
}

/*

To add Dynamic Memory Allocation in the code ->

int* p = malloc(sizeof(int)); // allocate memory for one integer
p[0] = 2;
int c = 1;
for (int i = 3; i <= n; i += 2) {
    int k = 0;
    while (k < c && i % p[k] != 0) {
        k++;
    }
    if (k == c) { // i is prime
        c++;
        p = realloc(p, c * sizeof(int)); // increase the size of p by one
        p[c - 1] = i; // add i to the end of p
    }
}

*/