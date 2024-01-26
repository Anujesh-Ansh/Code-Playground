#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
}node;

int counter;
node* head=NULL;
node* last,*temp,*new,*previous,*next_one;

node* declareSize(node* n){
    n = (node*)malloc(sizeof(node));
    n->next = n->prev = NULL;
    return n;

}

node* creation(){
    printf("\nEnter the no of data to be entered -> ");
    int n;
    scanf("%d",&n);
    node *h;
    h=NULL;
    for(int i=1;i<=n;i++){
        new =declareSize(new);
        printf("\nEnter Data -> ");
        scanf("%d",&new->data);
        if(h==NULL){
            h=temp=new;
        }
        else{
            new->prev=temp;
            temp->next=new;
            temp=new;
        }
        counter+=1;
    }
    return h;
}

void display(node *h){
    if(h==NULL){
        printf("\nCreate it 1st !!!!!\n");
    }
    else{
        temp =h;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

node* last_one(node *h){
    
    temp=h;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    return temp;
}

node* insert(node* h){
    int f=0;
    int ch;
    int i=1;
    temp=h;
    printf("\nEnter the position -> ");
    scanf("%d",&ch);
    if(h==NULL){
        printf("\nCreate it 1st !!!!\n");
    }
    else if(ch<1){
        printf("\nInvalid Input\n");
    }
    else if(ch==1){
        new=declareSize(new);
        printf("\nEnter Data -> ");
        scanf("%d",&new->data);
        new->prev=h->prev;
        new->next=h;
        h=new;
        f=1;
        counter+=1;
    }
    else if(ch==counter+1){
        last=last_one(h);
        new=declareSize(new);
        printf("\nEnter Data -> ");
        scanf("%d",&new->data);
        last->next=new;
        new->prev=last;
        f=1;
        counter+=1;
    }
    else{
        while(i<=ch-2){
            temp=temp->next;
            i++;
        }
        new =declareSize(new);
        printf("\nEnter Data -> ");
        scanf("%d",&new->data);
        new->next=temp->next;
        new->prev=temp;
        temp->next=new;
        f=1;
        counter+=1;
    }
    if(f==1){
        printf("\nDone !!!\n");
    }
    else{
        printf("\nERROR !!!\n");
    }

    return h;
}

node* delete(node* h){
    int ch;
    int f=0;
    int i=1;

    temp=h;
    
    printf("\nEnter the position -> ");
    scanf("%d",&ch);
    if(h==NULL){
        printf("\nCreate it 1st !!!!\n");
    }
    else if(ch<1){
        printf("\nInvalid Input\n");
    }
    else if(ch==1){
        new=temp->next;
        new->prev=NULL;
        h=new;
        free(temp);
        f=1;
        counter-=1;
    }
    else if(ch==counter){
        last=last_one(h);
        new=last->prev;
        new->next=NULL;
        free(last);
        f=1;
        counter-=1;
    }
    else{
        while(i<ch){
            previous=temp;
            temp=temp->next;
            next_one=temp->next;
            i++;
        }
        next_one->prev=previous;
        previous->next=next_one;
        free(temp);
        f=1;
        counter-=1;
    }
    if(f==1){
        printf("\nDone !!!\n");
    }
    return h;
}
node* concatenate(node* list1, node* list2){
    if(list1 == NULL || list2 == NULL ){
        printf("\nCreate it 1st !!!\n");
    }
    else{
        list1->next=list2;
        list2->prev=list1;
    }
    return list1;
}
node* reverse(node* h){
    temp=new=h;
    previous=NULL;
    if(h==NULL){
        printf("\nCreate it 1st !!!!!\n");
    }
    else{
        while(new!=NULL){
            new=new->next;
            temp->next=previous;
            temp->prev=new;
            previous=temp;
            temp=new;
        }
        h=previous;
        printf("\nDone !!!\n");
    }
    return h;
}

int main(){
    node* h;
    head=h=creation();
    display(head);
    head=insert(head);
    display(head);
    head=delete(head);
    display(head);
    head=delete(head);
    display(head);
    node* head1=creation();
    last=last_one(head);
    h=concatenate(last,head1);
    display(head);
    head=reverse(head);
    display(head);
    
    return 0;
}