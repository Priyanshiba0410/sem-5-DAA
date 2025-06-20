#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node* next;
}head* = null;
	void insertAtLast(int element){
		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode ->data = value;
		newNode ->next = null;
		if(head==null){
			head = newNode;
		}
		else{
			struct Node* temp = head;
			while(temp->next!=NULL)
				temp = temp->next;
			temp->next = newNode;
		}
	}
	void display(){
		struct Node* temp = head;
		if(temp==NULL){
			printf("list is empty/n");
			return;
		}
		printf("linked list:");
		while(temp!=NULL){
			printf("%d->",temp->data);
			temp=temp->next;
		}
		printf("null/n");
		
	}
