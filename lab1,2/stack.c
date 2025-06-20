#include<stdio.h>
#include<stdlib.h>
#define size 100 
	struct Stack{
		int top;
		int arr[size];
		
	}s;
	void PUSH(int element){
		s.arr[++s.top]=element;
	}
	void POP(){
		printf("pop element is : %d\n",s.arr[s.top--]);
		
	}
	void CHANGE(int element,int index){
		s.arr[s.top-index+1]=element;
	}
	void DISPLAY(){
		int i=0;
		for(i=s.top;i>=0;i--){
			printf("element is = %d\n",s.arr[i]);
		}
	}
	int main() {
    s.top = -1;
    int choice, element, index;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. CHANGE\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to PUSH: ");
                scanf("%d", &element);
                PUSH(element);
                break;

            case 2:
                POP();
                break;

            case 3:
                printf("Enter index to CHANGE (1 = top, 2 = next, ...): ");
                scanf("%d", &index);
                printf("Enter new element: ");
                scanf("%d", &element);
                CHANGE(element, index);
                break;

            case 4:
                DISPLAY();
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
