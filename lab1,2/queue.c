#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int value) 
{
    if (rear == SIZE - 1) 
	{
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = value;
    printf("%d inserted into the queue.\n", value);
}

void dequeue()
 {
    if (front == -1 || front > rear)
	 {
        printf("Queue Underflow\n");
        return;
    }
    printf("Deleted %d from the queue.\n", queue[front]);
    front++;
}

void display()
 {
    if (front == -1 || front > rear) 
	{
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    	for (int i = front; i <= rear; i++) 
	{
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() 
{
    int choice, value;
    while (1) 
	{
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
		{
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
