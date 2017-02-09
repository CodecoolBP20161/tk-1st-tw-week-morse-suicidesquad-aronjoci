#include "selfprot.h"
#include <stdio.h>

/*
 * Function: MorseToBinary
 * --------------------------------------------
 * converts morse string input bits
 *
 * input: the convertable morse string
 * output: morse in bits
 *
 * returns: the number of used bits for morse
 */
int MorseToBinary(char input[], char output[]) {
	int number_of_valid_bits=0;

	for(int i; input[i] != '\0'; i++){
		switch(input[i]){
			case '.':
				*output = *output<<1;
				*output = *output | 1;
				number_of_valid_bits += 1;
				break;

			case '-':
				*output = *output<<3;
				*output = *output | 7;
				number_of_valid_bits += 3;
				break;

			case ' ':
				*output = *output<<1;
				number_of_valid_bits += 1;
				break;

			case '/':
				*output = *output<<3;
				number_of_valid_bits += 3;
				break;

			case '\t':
				*output<<7;
				number_of_valid_bits += 7;
				break;

			default:
				printf("Not valid character given");
				return -1;
		}
	}
	*output<<(256-number_of_valid_bits);
	return number_of_valid_bits;
}
