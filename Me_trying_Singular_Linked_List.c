#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
}node;

int counter=0;
node* head=NULL;
node*new,*temp,*prev,*last;

node* creation(){
    printf("\nEnter the no of data to be entered -> ");
    int n;
    scanf("%d",&n);
    node *h;
    h=NULL;
    for(int i=1;i<=n;i++){
        new =(node*)malloc(sizeof(node));
        printf("\nEnter Data -> ");
        scanf("%d",&new->data);
        new->next=NULL;
        if(h==NULL){
            h=temp=new;
        }
        else{
            temp->next = new;
            temp=new;
        }
        counter+=1;
    }
    return h;
}

void display_middle(node* h){
    if(h==NULL){
        printf("\nCreate it 1st !!!!!\n");
    }
    else{
        int i=0;
        temp=h;
        while(i<(counter)/2){
            i++;
            temp=temp->next;
        }
        printf("\nMiddle value is -> %d\n",temp->data);
    }
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

node *delete(node *h){
    printf("Enter Position -> ");
    int ch,i=1;
    int f=0;
    scanf("%d",&ch);
    temp = h;
    if(ch<1){
        printf("\nInvalid Input\n");
    }
    else if(ch==1){
        h=h->next;
        free(temp);
        f=1;
        counter-=1;
    }
    else{
        while(i<ch){
            prev = temp;
            temp=temp->next;
            i++;
        }
        prev->next=temp->next;
        free(temp);
        f=1;
        counter-=1;
    }
    if(f==1){
        printf("\nDone !!!\n");
    }
    return h;
}

node *last_one(node *h){
    
    temp=h;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    return temp;
}

node *insert(node *h){
    printf("Enter Position -> ");
    int ch,i=1;
    int f=0;
    scanf("%d",&ch);
    temp = h;
    if(ch<1){
        printf("\nInvalid Input\n");
    }
    else if(ch==1){
        new =(node*)malloc(sizeof(node));
        printf("\nEnter Data -> ");
        scanf("%d",&new->data);
        new->next=h;
        h=new;
        f=1;
        counter+=1;
    }
    else if(ch==counter+1){
        new =(node*)malloc(sizeof(node));
        printf("\nEnter Data -> ");
        scanf("%d",&new->data);
        last = last_one(h);
        new->next=last->next;
        last->next=new;
        f=1;
        counter+=1;
    }
    else{
        while(i<=ch-2){
            temp=temp->next;
            i++;
        }
        new =(node*)malloc(sizeof(node));
        printf("\nEnter Data -> ");
        scanf("%d",&new->data);
        new->next=temp->next;
        temp->next=new;
        f=1;
        counter+=1;
    }
    if(f==1){
        printf("\nDone !!!\n");
    }
    return h;
}
node* sort(node* h){
    prev=new=h;
    int changing_data;
    if(h==NULL){
        printf("\nCreate it 1st !!!!!\n");
    }
    else{ // isme linear
        while(prev->next!=NULL){ // 
            while(new->next!=NULL){
                new=new->next;
                if(prev->data > new->data){
                    changing_data = prev->data;
                    prev->data= new->data;
                    new->data=changing_data;
                }
            }
            prev=prev->next;
            new=prev;
        }
    }

    return h;
}

node *reverse(node *h){
    temp=new=h;
    prev=NULL;
    if(h==NULL){
        printf("\nCreate it 1st !!!!!\n");
    }
    else{
        while(new!=NULL){
            new=new->next;
            temp->next=prev;
            prev=temp;
            temp=new;
        }
        h=prev;
        printf("\nDone !!!\n");
    }
    return h;
}

void concatenate(node *list1,node *list2){
    if(list2==NULL){
        printf("\nCreate it 1st !!!!!\n");
    }
    else if(list1!=NULL && list2!=NULL){
            list1->next=list2;
    }
}

void reversal(node *start){
    if(start == NULL){
        return;
    }
    else{
        reversal(start->next);
        printf(" %d",start->data);
    }
}


int main(){
    node *list1,*listy;
    node *sorted_list;
    // Creation -> 
    listy = head = list1 = creation();
    printf("\nNo of Nodes -> %d\n",counter);
    display(head);

    //Easiest Reversal
    printf("\nEasy Way to Reverse -> ");
    reversal(listy);
    printf("\n\n");

    // Deletion ->
    head = delete(head);
    printf("\nNo of Nodes -> %d\n",counter);
    display(head);
    
    // Insert ->
    head = insert(head);
    printf("\nNo of Nodes -> %d\n",counter);
    display(head);

    // Reverse ->
    head = reverse(head);
    printf("\nNo of Nodes -> %d\n",counter);
    display(head);

    // Concatenate ->
    printf("\nCreate a New list to Concatenate :- \n");
    node *list2 = creation();
    printf("\nList 2 -> ");
    display(list2);
    last=last_one(list1);
    concatenate(last,list2);
    printf("\nAfter Concatenating -> ");
    display(head);

    //Sorting
    printf("\nAfter Sorting -> ");
    sorted_list=sort(head);
    display(sorted_list);
    printf("\nNo of Nodes -> %d\n",counter);
    display_middle(head);

    
}