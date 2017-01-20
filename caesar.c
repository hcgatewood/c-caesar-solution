#include <stdio.h>
#include <string.h>

int alphabet_size = 26;
const char * alphabet = "abcdefghijklmnopqrstuvwxyz";

// NOTE: preserve spaces (i.e. don't try to "decode" them)
const char * message = "dknm ltrj bzmmns ctmj";

int main() {
    // Get the length of the input message
    int message_len = strlen(message);

    // Iterate over all possible cipher transformations
    for (int rotation = 0; rotation < alphabet_size; rotation++) {
        printf("\n");

        char letter;
        int alphabet_idx;
        char decoded_letter;
        // Iterate over all letters in the message
        for (int msg_idx = 0; msg_idx < message_len; msg_idx++) {
            letter = message[msg_idx];

            // Handle the special case of not decoding spaces
            if (letter == ' ') {
                printf(" ");
                continue;
            }

            // Get the current letter's position in our alphabet
            alphabet_idx = strchr(alphabet, letter) - alphabet;

            // Increment the current letter's position in our alphabet by
            // the current rotation
            alphabet_idx = (alphabet_idx + rotation) % alphabet_size;

            decoded_letter = alphabet[alphabet_idx];
            printf("%c", decoded_letter);
        }
    }
}
