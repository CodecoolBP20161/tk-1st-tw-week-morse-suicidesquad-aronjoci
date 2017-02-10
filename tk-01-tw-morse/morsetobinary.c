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

	for(int i=0; input[i] != '\0'; i++){
		int index_of_byte = number_of_valid_bits/8;
		int index_of_bit_in_byte = number_of_valid_bits%8;
		switch(input[i]){
			case '.':
				*(output + index_of_byte) = *(output + index_of_byte) | (1<<(7 - index_of_bit_in_byte));
				number_of_valid_bits += 1;
				break;

			case '-':
				if(index_of_bit_in_byte < 6){
					*(output + index_of_byte) =  *(output + index_of_byte) |  7<<(7 - index_of_bit_in_byte - 2);
				}
				else if(index_of_bit_in_byte == 6){
					*(output + index_of_byte) =  *(output + index_of_byte) |  3<<(7 - index_of_bit_in_byte - 1);
					*(output + index_of_byte + 1) =  *(output + index_of_byte + 1) |  1<<7;
				}
				else{
					*(output + index_of_byte) =  *(output + index_of_byte) |  1<<(7 - index_of_bit_in_byte);
					*(output + index_of_byte + 1) =  *(output + index_of_byte + 1) |  3<<6;
				}
				number_of_valid_bits += 3;
				break;

			case ' ':
				number_of_valid_bits += 1;
				break;

			case '/':
				number_of_valid_bits += 3;
				break;

			case '\t':
				number_of_valid_bits += 7;
				break;

			default:
				printf("Not valid character given");
				return -1;
		}
	}
	return number_of_valid_bits;
}
