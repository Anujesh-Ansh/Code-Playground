#include <stdio.h>
#include <stdlib.h>

typedef struct Student{
    int n;
}st;

void search(){
    int n;
    FILE *ptr = fopen("file.txt","r");
    printf("\nEnter Number -> ");
    scanf("%d",&n);

    if(ptr == NULL){
        printf("\nFile Not Found");
        exit(1);
    }
    else{
        st s;
        while(fscanf(ptr,"%d",&s.n)!=EOF){
            if(n==s.n){
                printf("Found");
                return;
            }
            else{
                continue;
            }
        }
    }
        fclose(ptr);
        printf("Not Found");
        return;
}

int main(){
    FILE *ptr = fopen("file.txt","w");
    if(ptr==NULL){
        printf("\nFile Not Found");
        exit(1);
    }
    else{
        printf("\nEnter no of data -> ");
        int x;
        scanf("%d",&x);
        for(int i=1;i<=x;i++){
            st s;
            s.n = i;
            fprintf(ptr,"%d\n",s.n);
        }
        fclose(ptr);
        
    }
    search();
    search();
    return 0;
}