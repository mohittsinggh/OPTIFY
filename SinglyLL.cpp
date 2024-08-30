#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
class node{
   public:
   int data;
   node*next;
   node(int data){
    this->data=data;
    this->next=NULL;
   }
};
node*head=NULL,*tail,*newnode;
void insert(){
    int data;
    cout<<"enter data : ";
    cin>>data;
    newnode=new node(data);
    if(head==NULL){
        head=tail=newnode;
    }
    else{
        tail->next=newnode;
        tail=newnode;
    }
}
void display(){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void insertathead(){
    if(head==NULL){
        insert();
    }
    else{
        int data;
    cout<<"enter data : ";
    cin>>data;
    newnode=new node(data);
    newnode->next=head;
    head=newnode;
    }
}
void insertattail(){
    if(head==NULL){
        insert();
    }
    else{
         int data;
    cout<<"enter data : ";
    cin>>data;
    newnode=new node(data);
        tail->next=newnode;
        tail=newnode;
    }
}
 void insertatspac(){
    node*temp=head;
    int size=0;
    int pos;
    while(temp!=NULL){
        size++;
        temp=temp->next;
    }
    temp=head;
    cout<<"size = "<<size<<endl;
    cout<<"enter the position : ";
    cin>>pos;
    if(pos<1){
        cout<<"you cannot insert";
    }
    else if(pos==1){
        insertathead();
    }
   else if(pos>size){
        insertattail(); 
    }
   else{
     int i=1;
     while(i!=pos-1){
        i++;
        temp=temp->next;
     }
     int data;
    cout<<"enter data : ";
    cin>>data;
    newnode=new node(data);
    newnode->next=temp->next;
    temp->next=newnode;
   }

 }
 void deleteList() {
    while (head != NULL) {
        node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = NULL; 
}
void deleteathead(){
    node*temp=head;
    head=temp->next;
    delete temp;
}
void deleteattail(){
    node *prev, *temp=head;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    tail=prev;
   delete temp;
}
void deleteatspec(){
 node*prev,*temp=head;
    int size=0;
    int pos;
    while(temp!=NULL){
        size++;
        temp=temp->next;
    }
    temp=head;
    cout<<"size = "<<size<<endl;
    cout<<"enter the position : ";
    cin>>pos;
    if(pos<1){
        cout<<"you cannot delete";
    }
    else if(pos==1){
        deleteathead();
    }
   else if(pos==size){
        deleteattail(); 
    }
   else{
     int i=1;
     while(i!=pos){
        i++;
        prev=temp;
        temp=temp->next;
     }
     prev->next=temp->next;
     delete temp;
}
}
void reverselist(){
    if (head == NULL) {
        cout << "List is empty"<<endl;
        return;
    }
    else{
        node*prev=NULL;
    node*curr=head;
    node*next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head=prev;
    }  
    if(head==NULL){
        tail=NULL;
    }
    else{
        tail=head;
        while(tail->next!=NULL){
            tail=tail->next;
        }
    }
}
void findmiddle(){
    if (head == NULL) {
        cout << "List is empty"<<endl;
        return;
    }
     node*fast,*slow;
    fast=slow=head;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
             fast=fast->next;
             slow=slow->next;
        }
    }
    cout<<"Middle  Element is = "<<slow->data<<endl;
}
void searchelement(){
   int key, pos = 1;
   bool found=false;
   cout << "Enter the element to search: ";
   cin >> key;
   node*temp=head;
   while(temp!=NULL){
    if(temp->data==key){
        cout<<"Element found at position : "<<pos<<endl;
        found=true;
        break;
    }
    else{
        temp = temp->next;
        pos++;
    }
   }
   if(!found){
    cout<<"Element is not found in List";
   }
}
int main(){ 
cout<<"Menu"<<endl;
cout<<"1.To insert"<<endl;
cout<<"2. To print"<<endl;
cout<<"3.To insert at head"<<endl;
cout<<"4.To insert at tail"<<endl;
cout<<"5.To insert at specific position"<<endl;
cout<<"6. To delete the linked list"<<endl;
cout<<"7.To delete at head"<<endl;
cout<<"8.To delete at tail"<<endl;
cout<<"9.To delete at specific position"<<endl;
cout<<"10. To reverse the list"<<endl;
cout<<"11. To find the middle element"<<endl;
cout<<"12. To search for an element"<<endl;
cout<<"13. To exit"<<endl;
int choice=0;
while(choice!=-1){
    cout<<"Enter your choice : ";
    cin>>choice;
    switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                insertathead();
                break;
            case 4:
                insertattail();
                break;
            case 5:
                insertatspac();
                break;
            case 6:
                deleteList();
                break;
            case 7:
                deleteathead();
                break;
            case 8:
                deleteattail();
                break;
            case 9:
                deleteatspec();
                break;
            case 10:
                reverselist();
                break;
            case 11:
                findmiddle();
                break;
            case 12:
                searchelement();
                break;
                case 13:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
    }
}
        }


