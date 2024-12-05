#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_USERS 100
#define USERNAME_LENGTH 50
#define PASSWORD_LENGTH 50

// Structure to store user credentials
typedef struct {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
} User;

// Array to hold registered users
User users[MAX_USERS];
int user_count = 0;

// Function to initialize users directly in code
void initialize_users() {
    strcpy(users[0].username, "admin");
    strcpy(users[0].password, "password123");
    strcpy(users[1].username, "user1");
    strcpy(users[1].password, "passw0rd");
    strcpy(users[2].username, "user2");
    strcpy(users[2].password, "123456");
    user_count = 3; // Number of initialized users
    printf("Initialized %d users.\n", user_count);
}

// Function to authenticate a user
int authenticate_user(const char *username, const char *password) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0 &&
            strcmp(users[i].password, password) == 0) {
            return 1; // Authentication successful
        }
    }
    return 0; // Authentication failed
}

// Function to log connected users
void log_connection(const char *username) {
    FILE *logfile = fopen("connections.log", "a");
    if (!logfile) {
        perror("Error opening log file");
        return;
    }
    fprintf(logfile, "User %s connected.\n", username);
    fclose(logfile);
    printf("Connection logged for user: %s\n", username);
}

// Main server loop
void start_server() {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
    printf("Wireless Access System Server Started\n");

    while (1) {
        printf("\nEnter username: ");
        scanf("%s", username);
        printf("Enter password: ");
        scanf("%s", password);

        if (authenticate_user(username, password)) {
            printf("Access granted. Welcome, %s!\n", username);
            log_connection(username);
            printf("Exiting system. Goodbye!\n");
            exit(0); // Exit after successful connection
        } else {
            printf("Access denied. Invalid credentials.\n");
        }
    }
}

int main() {
    // Initialize registered users
    initialize_users();
    // Start the server
    start_server();
    return 0;
}
