#include <stdio.h>
#include <stdlib.h>

int main() {
    int count_larger_ones = 0;
    int window[] = {-1, -1, -1};
    int window_sum = -1;
    int prev_window_sum = -1;
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
        // Move window
        if(window[2] != -1) {
            if(window[1] != -1) {
                window[0] = window[1];
            }
            window[1] = window[2];
        }
        window[2] = curr_num;
        // Calculate window sum
        if((window[0] != -1) && (window[1] != -1) && (window[2] != -1)) {
            window_sum = window[0] + window[1] + window[2];
        }
        // Check if current sum is higher than the previous one
        if((prev_window_sum != -1) && (window_sum != -1) && (prev_window_sum < window_sum)) {
            count_larger_ones++;
        }
        // Save current window sum to use it in the next iteration
        prev_window_sum = window_sum;
    }
    fclose(fp);

    printf("There are %d measurements larger than the previous ones.\n", count_larger_ones);
    
    return 0;
}