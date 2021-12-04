#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// function prototype
int convert(long long);

int main() {
    char line[50];
    int count_lines = 0;
    int count_bit[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int gamma_rate[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    long gamma = 0;
    int epsilon_rate[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    long epsilon = 0;

    // Open file and check for errors
    FILE *fp = fopen("input.txt", "r");
    if(fp == NULL) {
      perror("Error opening file");
      return -1;
    }

    // Read line by line
    while(fgets(line, 50, fp) != NULL) {
        count_lines++;
        for(int i = 0; i < 12; i++) {
            if(line[i] == '1') {
                count_bit[i]++;
            }
        }
    }
    fclose(fp);

    // Set bit to one in the gamma rate if the majoriy is an one at this position
    // Set it to zero in the epislon rate
    for(int i = 0; i < 12; i++) {
        if(count_bit[i] >= count_lines / 2) {
            gamma_rate[i] = 1;
            epsilon_rate[i] = 0;
        }
    }

    // Print gamma and epsilon rate
    for (int i = 0; i < 11; i++) {
        gamma *= 10;
        gamma += gamma_rate[i];
    }   
    printf("Gamma rate: %ld\n", gamma);
    for (int i = 0; i < 11; i++) {
        epsilon *= 10;
        epsilon += epsilon_rate[i];
    }   
    printf("Epsilon rate: %ld\n", epsilon);

    int result = convert(gamma) * convert(epsilon);
    printf("Result: %d\n", result);
    
    return 0;
}


// function to convert binary to decimal
int convert(long long n) {
  int dec = 0, i = 0, rem;

  while (n!=0) {
    rem = n % 10;
    n /= 10;
    dec += rem * pow(2, i);
    ++i;
  }

  return dec;
}