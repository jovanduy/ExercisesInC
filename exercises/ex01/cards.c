/*
 * Program to count cards in blackjack.
 *
 * Jordan Van Duyne
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * Returns the integer value of card_name.
 * Alerts user if card_name does not represent a valid card value.
 *
 * card_name: array of chars representing a card name
 */
int get_value(char card_name[]) {
	int val = 0;
	switch(card_name[0]) {
		case 'K':
		case 'Q':
		case 'J':
			val = 10;
			break;
		case 'A':
			val = 11;
			break;
		default:
			val = atoi(card_name);
			if ((val <= 1) || (val > 10)) {
				puts("I don't understand that value!");
				val = 0;
			}
	}
	return val;
}

/*
 * Returns and increases count by the amount of val.
 *
 * val: int amount by which to update count
 *
 * count: int to be updated
 */
int update_count(int val, int count) {
	if ((val > 2) && (val < 7)) {
		count++;
	} else if (val == 10) {
		count--;
	}
	return count;
}

/*
 * Prompts user for card input.
 *
 */
int main() {
	char card_name[3];
	int count = 0;

	while (card_name[0] != 'X') {
		puts("Enter the card name: ");
		scanf("%2s", card_name);
		int val = get_value(card_name);
		count = update_count(val, count);
		printf("Current count: %i\n", count);
	}
	return 0;
}

