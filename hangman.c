#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main() {

	char strings[10][10] = {"APPLE", "ORANGE", "BANANA", "AVACADO", "PINEAPPLE", "PEAR", "DURIAN", "BLUEBERRY", "CHERRY", "LEMON"};

	/*
	for (int i = 0; i < 10; i++) {
		printf("%s \n", strings[i]);
	}*/

	srand(time(NULL));
	int wordChoice = rand() % 10;

	//printf("%d \n", wordChoice);

	int points = 6;

	char wordDisplay[20] = "_ _ _ _ _ _ _ _ _ _";
	char* wordPtr = strings[wordChoice];
	char* wordDisplayPtr = wordDisplay;

	//printf("%s\n", wordDisplay);

	while (*wordPtr != '\0') {
		//printf("%c", *wordPtr);
		wordPtr++;
		wordDisplayPtr++;
		wordDisplayPtr++;
		
	}
	//printf("\n");
	*wordDisplayPtr = '\0';
	//printf("%s\n", wordDisplay);

	printf("Starting Game...\n");

	int playing = 1;
	int winLoss = 0;
	int found = 0;
	char selection = ' ';
	while (playing) {
		printf("Word:\t%s\tMistakes Left:\t%d\nEnter a letter:\n", wordDisplay, points);
		scanf_s(" %1c", &selection);

		found = 0;
		wordPtr = strings[wordChoice];
		wordDisplayPtr = wordDisplay;
		while (*wordPtr != '\0') {
			//printf("%c", *wordPtr);
			if (*wordPtr == selection) {
				*wordDisplayPtr = selection;
				found = 1;
			}
			wordPtr++;
			wordDisplayPtr++;
			wordDisplayPtr++;

		}
		if (found == 0) {
			points--;
		}

		if (points == 0) {
			break;
		}

		found = 0;
		wordDisplayPtr = wordDisplay;
		while (*wordDisplayPtr != '\0') {
			//printf("%c", *wordPtr);
			if (*wordDisplayPtr == '_') {
				found = 1;
			}
			wordDisplayPtr++;

		}
		if (found == 0) {
			winLoss = 1;
			break;
		}

		
	}
	if (winLoss == 0) {
		printf("You Lost!\n");
	}
	else {
		printf("%s\nYou Won!\n", wordDisplay);
	}


	return 0;
}