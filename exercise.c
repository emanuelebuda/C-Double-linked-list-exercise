#include <stdio.h>
#include <stdlib.h>

//Double linked list
struct Node { 
    int data; 
    struct Node*left;
    struct Node* right;
};

//Creates a new node
struct Node* newNode(int data) {
	struct Node* new = (struct Node*)malloc(sizeof(struct Node)); 
    new->data = data; 
    return new;
}

//Inserts a new node after the given node 
void insert(struct Node *left, struct Node* nn) { 
    if (left == NULL) { 
        printf("Please insert a valid node."); 
        return; 
    }
  
  	//Inserts and re-build links
    nn->right = left->right; 
    left->right = nn; 
    nn->left = left; 
  
  	//Changes the left (previous) node of new node's next node
    if (nn->right != NULL) 
        nn->right->left = nn; 
} 

//Insert a new node as head (push) [for practical tests]
void fill(struct Node** headp, struct Node* nn) { 
  	//Makes the old head at the right of the new node and left as NULL
    nn->right = (*headp); 
    nn->left = NULL; 
  
    //Updates the left of old head node
    if ((*headp) != NULL) 
        (*headp)->left = nn; 
  
    //Updates the head pointer
    (*headp) = nn; 
} 

void print(struct Node* node) { 
    struct Node* last; 
    while (node != NULL) { 
        printf("(%d) <-> ", node->data); 
        last = node; 
        node = node->right; 
    } 
    printf("[ ]\n");		// NULL is represented with []
} 


//Practical test
int main() { 
    struct Node* head = NULL; 
    // NULL->

    fill(&head, newNode(1));
    // 1 <-> NULL 

    fill(&head, newNode(1)); 
    // 1 <-> 1 <-> NULL
  
    insert(head, newNode(7)); 
    // 1 <-> 7 <-> 1 <-> NULL

    insert(head->right->right, newNode(9));
    // 1 <-> 7 <-> 1 <-> 9 <-> NULL

    insert(head->right->right->right, newNode(6));
    // 1 <-> 7 <-> 1 <-> 9 <-> 6 <-> NULL 
    fill(&head, newNode(1));


  
    printf("Output: \n"); 
    print(head); 
    return 0; 
} 