#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;

}node;

int counter;
node *head =NULL;
node *new,*temp,*prev,*last;
node *last1, *last2;

node *declareSize(node *h){
    h = (node*)malloc(sizeof(node));
    h->next=NULL;

    return h;
}

node *lastOne(node *h){
    if(h==NULL){
        printf("\nCreate toh karo pehle !!");
    }
    else{
        temp = h;
        while(temp->next != h){
            temp = temp->next;
        }
    }
    return temp;
}

node *create(){
    node *h =NULL;

    int ch;
    printf("\nEnter the no. of inputs -> ");
    scanf("%d",&ch);
    printf("\nEnter Data -> ");
    for(int i =1; i<=ch;i++){
        new = declareSize(new);
        scanf("%d",&new->data);

        if(h==NULL){
            h=last=new;
            h->next=last;
            last->next=h;
        }
        else{
            last->next = new;
            new->next = h;
            last = new;
        }
        counter+=1;
    }
    return h;
}

node *insert(node *h){
    if(h==NULL){
        printf("\nCreate toh karo pehle !!");
    }
    else{
        temp = h;
        printf("\nEnter the location -> ");
        int x;
        scanf("%d",&x);
        if(x<1){
            printf("\nInvalid INPUT\n");
        }
        else{
            new = declareSize(new);
            printf("\nEnter Data -> ");
            scanf("%d",&new->data);
            
            if(x==1){    
                new->next =h;
                last=lastOne(h);
                last->next=new;
                h=temp=new;
            }
            else if(x==counter+1){
                last = lastOne(h);
                new->next=last->next;
                last->next=new;
                last=new;
            }
            else{
                int i=1;
                while(i<x-1){
                    temp=temp->next;
                    i++;
                }
                new->next=temp->next;
                temp->next=new;
                temp=new;
            }
            counter+=1;

        }
    }
    return h;
}
node *delete(node *h){
    if(h==NULL){
        printf("\nCreate toh karo pehle !!");
    }
    else{
        temp = h;
        printf("\nEnter the location -> ");
        int x;
        scanf("%d",&x);
        if(x<1){
            printf("\nInvalid INPUT\n");
        }
        else{
            new = declareSize(new);
            
            if(x==1){  
                new=h->next;
                last=lastOne(h);
                last->next=new;
                free(h);
                h=new;
            }
            else {
                int i=1;
                while(i<x-1){
                    temp=temp->next;
                    i++;
                    }
                new=temp->next;
                temp->next=new->next;
                free(new);
            }
            counter-=1;

        }
    }
    return h; 
}
void display(node *h){
    if(h==NULL){
        printf("\nCreate toh karo pehle !!");
    }
    else{
        temp=h;
        printf("\n");
        do{
            printf("%d ",temp->data);
            temp = temp ->next;
        }while(temp != h);
        printf("\n");
    }
}

node *concatenate(node *l1, node *l2){
    if(l1 == NULL || l2 == NULL){
        printf("\nCreate toh karo pehle !!");
    }
    else{
        
        last1 = lastOne(l1);
        last2 =lastOne(l2);

        last1->next = l2;
        last2 -> next = l1;

    }
    return l1;
}

node *reverse(node *h){
    if(h==NULL){
        printf("\nCreate toh karo pehle !!");
    }
    else{                                                          
        temp =h;                                                   
        prev =NULL;                                                
        int i=1;                                                   
        while(i<counter){                                          
            new=temp->next;                                        
            temp->next=prev;                                       
            prev=temp;                                             
            temp=new;                                              
            if(i==1){
                last=prev;
            }
            i++; 
        }        
        temp->next=prev;
        last->next=temp;
    }    
    return temp;
}


int main(){
    head = create();
    last=lastOne(head);
    display(head);
    printf("\nCOunter -> %d\n",counter);
    node *newList;
    newList = create();
    head=concatenate(head,newList);
    display(head);
    printf("\nCOunter -> %d\n",counter);
    head = insert(head);
    display(head);
    printf("\nCOunter -> %d\n",counter);
    printf("%d\n",last->next->data);
    head =delete(head);
    display(head);
    printf("\nCOunter -> %d\n",counter);
    last=lastOne(head);
    printf("%d\n",last->data);
    printf("\nCOunter -> %d\n",counter);
    head =reverse(head);
    display(head);
    printf("\nCOunter -> %d\n",counter);
    printf("%d\n",last->next->data);
    return 0;
}