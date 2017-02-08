#include "selfprot.h"
#include <string.h>
#include <stdio.h>

/*
 * Function: CharToMorse
 * --------------------------------------------
 * convert characters/numbers to dots and dashes (morse code).
 * the function use the character-morse and number-morse maps
 * from the common header.
 *
 * input: the convertable string
 * output: converted morse string
 *
 * returns: the index of the last converted character of the input
 */
int CharToMorse(char input[], char *output) {
	int last_valid_index;

	for(int i = 0; input[i] != '\0'; i++){
		int wat = (int) input[i];
		printf("%d",i);

		if (wat >= '0' && wat <= '9'){ /* We check if next input char is a number*/
			if((250 - strlen(output)) >= strlen(CHAR_TO_MORSE_NUMBER[wat -'0'])){ /* we check if there is enough space */
				strcat(output, CHAR_TO_MORSE_NUMBER[wat -'0']);
			}
			else{
				return i;
			}
		}
		else if(wat >= 'A' && wat <= 'Z'){/* We check if next input char is a letter*/
			if((250 - strlen(output)) >= strlen(CHAR_TO_MORSE_ALPHA[wat -'A'])){ /* we check if there is enough space */
				strcat(output, CHAR_TO_MORSE_ALPHA[wat -'A']);
			}
			else{
				return i;
			}
		}
		else{
			if((250 - strlen(output)) >= 2){ /* we check if there is enough space */
				strcat(output, "\t"); /* if not a number or letter, it must be a space */
			}
			else{
				return i;
			}
		}
		if (input[i] != ' ' && input[i+1] != ' ' && input[i+1] != '\0'){
			strcat(output, "/");
		}
	last_valid_index = i;
	}
	return last_valid_index;
}
