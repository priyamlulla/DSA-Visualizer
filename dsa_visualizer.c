#include <stdio.h>
#include <stdlib.h>

// ===== STACK IMPLEMENTATION =====
#define STACK_SIZE 10
int stack[STACK_SIZE];
int top = -1;

typedef struct BSTNode {
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

BSTNode* insertBST(BSTNode* root, int val) {
    if (root == NULL) {
        BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
        newNode->data = val;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (val < root->data)
        root->left = insertBST(root->left, val);
    else if (val > root->data)
        root->right = insertBST(root->right, val);
    else
        printf("Duplicate value not allowed!\n");
        fflush(stdout);
    return root;
}

void inorderBST(BSTNode* root) {
    if (!root) return;
    inorderBST(root->left);
    printf("%d ", root->data);
    fflush(stdout);
    inorderBST(root->right);
}

void preorderBST(BSTNode* root) {
    if (!root) return;
    printf("%d ", root->data);
    fflush(stdout);
    preorderBST(root->left);
    preorderBST(root->right);
}

void postorderBST(BSTNode* root) {
    if (!root) return;
    postorderBST(root->left);
    postorderBST(root->right);
    printf("%d ", root->data);
    fflush(stdout);
}

#define COUNT 5

void printBSTUtil(BSTNode* root, int space) {
    if (!root) return;

    space += COUNT;

    printBSTUtil(root->right, space);

    printf("\n");
    fflush(stdout);
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
    fflush(stdout);

    printBSTUtil(root->left, space);
}

void printBST(BSTNode* root) {
    if (!root) {
        printf("BST is empty!\n");
        return;
    }
    printf("Binary Search Tree:\n");
    fflush(stdout);
    printBSTUtil(root, 0);
    printf("\n");
    fflush(stdout);
}

void push() {
    int val;
    if (top == STACK_SIZE - 1) {
        printf("Stack Overflow!\n");
        fflush(stdout);
        return;
    }
    printf("\nEnter value to push: ");
    fflush(stdout);
    scanf("%d", &val);
    stack[++top] = val;
    printf("Pushed %d\n", val);
    fflush(stdout);
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        fflush(stdout);
        return;
    }
    printf("Popped %d\n", stack[top--]);
    fflush(stdout);
}

void printStack() {
    if (top == -1) {
        printf("Stack is empty.\n");
        fflush(stdout);
        return;
    }
    printf("Top ->\n");
    fflush(stdout);
    for (int i = top; i >= 0; i--) {
        printf("       | %d |\n", stack[i]);
        fflush(stdout);
    }
    printf("       -----\n\n");
    fflush(stdout);
}


// ===== QUEUE IMPLEMENTATION =====
#define QSIZE 10
int queue[QSIZE];
int front = -1, rear = -1;

void enqueue() {
    int val;
    if ((rear + 1) % QSIZE == front) {
        printf("Queue Full!\n");
        fflush(stdout);
        return;
    }
    printf("Enter value to enqueue: ");
    fflush(stdout);
    scanf("%d", &val);
    if (front == -1) front = rear = 0;
    else rear = (rear + 1) % QSIZE;
    queue[rear] = val;
    printf("Enqueued %d\n", val);
    fflush(stdout);
}

void dequeue() {
    if (front == -1) {
        printf("Queue Empty!\n");
        fflush(stdout);
        return;
    }
    printf("Dequeued %d\n", queue[front]);
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % QSIZE;
}

void displayQueue() {
    if (front == -1) {
        printf("Queue Empty!\n");
        fflush(stdout);
        return;
    }
    printf("Front -> ");
    fflush(stdout);
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        fflush(stdout);
        if (i == rear) break;
        i = (i + 1) % QSIZE;
    }
    printf("<- Rear\n");
    fflush(stdout);
}

// ===== SINGLY LINKED LIST =====
struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;

void insertAtEnd() {
    int val;
    printf("Enter value: ");
    fflush(stdout);
    scanf("%d", &val);
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (head == NULL) head = newNode;
    else {
        struct Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
    printf("Inserted %d\n", val);
    fflush(stdout);
}

void displayList() {
    struct Node* temp = head;
    if (!temp) {
        printf("List Empty!\n");
        fflush(stdout);
        return;
    }
    while (temp) {
        printf("[%d] -> ", temp->data);
        fflush(stdout);
        temp = temp->next;
    }
    printf("NULL\n");
    fflush(stdout);
}

// ===== CIRCULAR LINKED LIST =====
struct Node* cHead = NULL;

void insertCircular() {
    int val;
    printf("Enter value: ");
    fflush(stdout);
    scanf("%d", &val);
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    if (!cHead) {
        cHead = newNode;
        newNode->next = cHead;
    } else {
        struct Node* temp = cHead;
        while (temp->next != cHead) temp = temp->next;
        temp->next = newNode;
        newNode->next = cHead;
    }
    printf("Inserted %d (Circular LL)\n", val);
    fflush(stdout);
}

void displayCircular() {
    if (!cHead) {
        printf("Circular List Empty!\n");
        fflush(stdout);
        return;
    }
    struct Node* temp = cHead;
    do {
        printf("[%d] -> ", temp->data);
        fflush(stdout);
        temp = temp->next;
    } while (temp != cHead);
    printf("(back to head)\n");
    fflush(stdout);
}

// ===== DOUBLY LINKED LIST =====
struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
};
struct DNode* dHead = NULL;

void insertDoubly() {
    int val;
    printf("Enter value: ");
    fflush(stdout);
    scanf("%d", &val);
    struct DNode* newNode = malloc(sizeof(struct DNode));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;
    if (!dHead) dHead = newNode;
    else {
        struct DNode* temp = dHead;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Inserted %d (Doubly LL)\n", val);
    fflush(stdout);
}

void displayDoubly() {
    if (!dHead) {
        printf("Doubly List Empty!\n");
        fflush(stdout);
        return;
    }
    struct DNode* temp = dHead;
    printf("NULL <-> ");
    fflush(stdout);
    while (temp) {
        printf("[%d] <-> ", temp->data);
        fflush(stdout);
        temp = temp->next;
    }
    printf("NULL\n");
    fflush(stdout);
}

// ===== MAIN MENU =====
void stackMenu() {
    int choice;
    do {
        printf("\n--- Stack Menu ---\n1.Push\n2.Pop\n3.Display\n4.Back\nEnter choice: ");
        fflush(stdout);
        scanf("%d", &choice);
        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: printStack(); break;
        }
    } while (choice != 4);
}

void queueMenu() {
    int choice;
    do {
        printf("\n--- Queue Menu ---\n1.Enqueue\n2.Dequeue\n3.Display\n4.Back\nEnter choice: ");
        fflush(stdout);
        scanf("%d", &choice);
        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: displayQueue(); break;
        }
    } while (choice != 4);
}

void sllMenu() {
    int choice;
    do {
        printf("\n--- Singly Linked List Menu ---\n1.Insert\n2.Display\n3.Back\nEnter choice: ");
        fflush(stdout);
        scanf("%d", &choice);
        switch (choice) {
            case 1: insertAtEnd(); break;
            case 2: displayList(); break;
        }
    } while (choice != 3);
}

void cllMenu() {
    int choice;
    do {
        printf("\n--- Circular Linked List Menu ---\n1.Insert\n2.Display\n3.Back\nEnter choice: ");
        fflush(stdout);
        scanf("%d", &choice);
        switch (choice) {
            case 1: insertCircular(); break;
            case 2: displayCircular(); break;
        }
    } while (choice != 3);
}

void dllMenu() {
    int choice;
    do {
        printf("\n--- Doubly Linked List Menu ---\n1.Insert\n2.Display\n3.Back\nEnter choice: ");
        fflush(stdout);
        scanf("%d", &choice);
        switch (choice) {
            case 1: insertDoubly(); break;
            case 2: displayDoubly(); break;
        }
    } while (choice != 3);
}

int main() {
    setvbuf(stdout, NULL, _IONBF, 0); // disables output buffering
        BSTNode* bstRoot = NULL;
    int choice;
    do {
        printf("\n=== DSA Visualizer ===\n");
        fflush(stdout);
        printf("1.Stack\n2.Queue\n3.Singly Linked List\n4.Circular Linked List\n5.Doubly Linked List\n6.Binary Search Tree\n7.nExit\n.Enter choice: ");
        fflush(stdout);
        scanf("%d", &choice);
        switch (choice) {
            case 1: stackMenu(); break;
            case 2: queueMenu(); break;
            case 3: sllMenu(); break;
            case 4: cllMenu(); break;
            case 5: dllMenu(); break;
            case 6:
    int bstChoice, bstVal;
    do {
        printf("\n--- BST Menu ---\n");
        printf("1. Insert\n2. Inorder\n3. Preorder\n4. Postorder\n5. Display Tree\n0. Back\n");
        printf("Enter choice: "); fflush(stdout);
        scanf("%d", &bstChoice);
        switch (bstChoice) {
            case 1:
                printf("Enter value to insert: "); fflush(stdout);
                scanf("%d", &bstVal);
                bstRoot = insertBST(bstRoot, bstVal);
                printf("Value %d inserted!\n", bstVal); fflush(stdout);
                break;
            case 2:
                printf("Inorder: "); fflush(stdout);
                inorderBST(bstRoot);
                printf("\n"); fflush(stdout);
                break;
            case 3:
                printf("Preorder: "); fflush(stdout);
                preorderBST(bstRoot);
                printf("\n"); fflush(stdout);
                break;
            case 4:
                printf("Postorder: "); fflush(stdout);
                postorderBST(bstRoot);
                printf("\n"); fflush(stdout);
                break;
            case 5:
                printBST(bstRoot);
                break;
            case 0: break;
            default:
                printf("Invalid choice!\n"); fflush(stdout);
        }
    } while (bstChoice != 0);
    break;

        }
    } while (choice != 7);
    printf("Exiting...\n");
    fflush(stdout);
    return 0;
}
