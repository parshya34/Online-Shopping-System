#include <stdio.h>
#include <string.h>
#define MAX_USERS 10 
struct User {
    char username[50];
    char password[50];
    char email[50];
};
int registerUser(struct User users[], int *numUsers) {
    if (*numUsers >= MAX_USERS) {
        printf("Maximum number of users reached. Registration failed.\n");
        return 0;
    }
    printf("Enter username: ");
    scanf("%s", users[*numUsers].username);
    for (int i = 0; i < *numUsers; i++) {
        if (strcmp(users[i].username, users[*numUsers].username) == 0) {
            printf("Username already exists. Registration failed.\n");
            return 0;
        }
    }
    printf("Enter email: ");
    scanf("%s", users[*numUsers].email);
    printf("Enter password: ");
    scanf("%s", users[*numUsers].password);
    (*numUsers)++;
    printf("Registration successful!\n");
    return 1;
}
int authenticateUser(struct User users[], int numUsers, char username[], char password[]) {
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return 1; // Authentication successful
        }
    }
    return 0; // Authentication failed
}
int main() {
    struct User users[MAX_USERS];
    int numUsers = 0; // Current number of registered users
    while (1) {
        printf("\nUser Authentication System Menu:\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        int choice;
        printf("Enter your choice (1/2/3): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (registerUser(users, &numUsers)) {
                    // Registration successful
                } else {
                    // Registration failed
                }
                break;
            case 2:
                char username[50], password[50];
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);

                if (authenticateUser(users, numUsers, username, password)) {
                    printf("Login successful!\n");
                } else {
                    printf("Login failed. Invalid username or password.\n");
                }
                break;
            case 3:
                printf("Exiting the User Authentication System.\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option (1/2/3).\n");
                break;
        }
    }
    return 0;
}
