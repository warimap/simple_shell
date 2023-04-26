#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a linked list node
struct node {
    char* directory;
    struct node* next;
};

void print_list(struct node* head) {
    while (head != NULL) {
        printf("%s\n", head->directory);
        head = head->next;
    }
}

void free_list(struct node* head) {
    while (head != NULL) {
        struct node* temp = head;
        head = head->next;
        free(temp->directory);
        free(temp);
    }
}

void build_list(struct node** head) {
    char* path = getenv("PATH"); // Get the value of the PATH environment variable
    if (path == NULL) {
        printf("PATH environment variable not found.\n");
        return;
    }

    char* token = strtok(path, ":"); // Tokenize the PATH variable using ':' as the delimiter
    while (token != NULL) {
        // Allocate memory for a new node and copy the directory string
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        new_node->directory = strdup(token);
        new_node->next = *head;
        *head = new_node; // Set the new node as the head of the list
        token = strtok(NULL, ":"); // Move to the next token
    }
}

int main() {
    struct node* head = NULL;
    build_list(&head);
    print_list(head);
    free_list(head);
    return (0);
}
