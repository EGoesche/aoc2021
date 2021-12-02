#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char line[50];
    char delim[] = " ";
    int forward_count = 0;
    int depth_count = 0;

    // Open file and check for errors
    FILE *fp = fopen("input.txt", "r");
    if(fp == NULL) {
      perror("Error opening file");
      return -1;
    }

    // Read line by line
    while(fgets(line, 50, fp) != NULL) {
        // Split each line in operation and amount
        char *ptr = strtok(line, delim);

        // Check which variable has to be changed
        int operation = 0;
        if (strcmp(ptr, "forward") == 0) {
            operation = 1;
        } 
        else if (strcmp(ptr, "down") == 0) {
            operation = 2;
        }
        else if (strcmp(ptr, "up") == 0) {
            operation = 3;
        }
        else {
            return -1;
        }

        // Read the secound sub string
        ptr = strtok(NULL, delim);

        // Remove new line characters in secound sub strings
        if(ptr[strlen(ptr)-1] == '\n') {
            ptr[strlen(ptr)-1] = '\0';
        }

        // Depending on the operation add or substract from the variable
        if(operation == 1) {
            forward_count = forward_count + atoi(ptr);
        }

        if(operation == 2) {
            depth_count = depth_count + atoi(ptr);
        }

        if(operation == 3) {
            depth_count = depth_count - atoi(ptr);
        }
    }
    fclose(fp);

    printf("Result: %d (horizontal) / %d (depth)\n", forward_count, depth_count);
    int final_result = forward_count * depth_count;
    printf("Final result: %d\n", final_result);

    return 0;
}