#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * This function converts a 12-hour time string to a 24-hour time string.
 * The input string `s` is in the format "hh:mm:ssAM" or "hh:mm:ssPM".
 * The function modifies the input string in place and returns it.
 */
char* timeConversion(char* s) {
    // Check if the time is PM
    if (s[8] == 'P' && s[9] == 'M') {
        // If it's 12 PM, no change to the hour is needed
        if (s[0] == '1' && s[1] == '2') {
            // Do nothing, the hour is already correct (12)
        } else {
            // For other PM hours, add 12 to the hour value
            int hour = (s[0] - '0') * 10 + (s[1] - '0');
            hour += 12;
            s[0] = (hour / 10) + '0';
            s[1] = (hour % 10) + '0';
        }
    } else { // Time is AM
        // If it's 12 AM (midnight), convert the hour to "00"
        if (s[0] == '1' && s[1] == '2') {
            s[0] = '0';
            s[1] = '0';
        }
        // Other AM hours (01-11) are already in the correct 24-hour format
    }
    
    // Null-terminate the string after removing the AM/PM part
    s[8] = '\0';
    
    return s;
}

int main() {
    // Test cases
    char s1[] = "07:05:45PM";
    printf("Input: %s, Output: %s\n", s1, timeConversion(s1)); // Expected: 19:05:45

    char s2[] = "12:01:00AM";
    printf("Input: %s, Output: %s\n", s2, timeConversion(s2)); // Expected: 00:01:00

    char s3[] = "12:40:22PM";
    printf("Input: %s, Output: %s\n", s3, timeConversion(s3)); // Expected: 12:40:22

    char s4[] = "06:40:03AM";
    printf("Input: %s, Output: %s\n", s4, timeConversion(s4)); // Expected: 06:40:03

    return 0;
}
