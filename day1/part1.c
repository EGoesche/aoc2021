#include <stdio.h>
#include <stdlib.h>

int main() {
    int count_larger_ones = 0;
    int prev_num = -1;
    char line[50];

    // Open file and check for errors
    FILE *fp = fopen("input.txt", "r");
    if(fp == NULL) {
      perror("Error opening file");
      return -1;
    }

    // Read line by line
    while(fgets(line, 50, fp) != NULL) {
        int curr_num = atoi(line);
        // Check if current number is higher than the previous one
        if((prev_num != -1) && (prev_num < curr_num)) {
            count_larger_ones++;
        }
        // Save current number to use it in the next iteration
        prev_num = curr_num;
    }
    fclose(fp);

    printf("There are %d measurements larger than the previous ones.\n", count_larger_ones);
    
    return 0;
}