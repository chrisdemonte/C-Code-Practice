#include<stdlib.h>
#include<stdio.h>


enum Mode {Enter, Delete, Read, Write, Print, Quit};

struct UserData {
	char name[50];
	char id[10];
	char title[50];
};

int main() {

	struct UserData* userData = malloc(sizeof(struct UserData )* 10);
	struct UserData* userDataPtr = userData;
	int numUsers = 0;

	printf("*** Welcome to User Data ***\n");

	int option = -1;
	while (1) {
		printf("*** Enter an option ***\n 0 = Enter, 1 = Delete, 2 = Read, 3 = Write, 4 = Print, 5 = Quit\n");
		scanf_s(" %d", &option);
		char name_buf[50];
		char* charPtr;
		char title_buf[50];

		if (option == Enter) {
			printf("Enter a name:\n");
			scanf_s(" %49s", name_buf, 49);
			printf("Enter a title:\n");
			scanf_s(" %49s", title_buf, 49);
			
			charPtr = name_buf;
			int counter = 0;
			while (*charPtr != '\0') {
				userDataPtr->name[counter] = *charPtr;
				counter++;
				charPtr++;
			}
			userDataPtr->name[counter] = '\0';

			charPtr = title_buf;
			counter = 0;
			while (*charPtr != '\0') {
				userDataPtr->title[counter] = *charPtr;
				counter++;
				charPtr++;
			}
			userDataPtr->title[counter] = '\0';

			userDataPtr->id[0] = 'I';
			userDataPtr->id[1] = 'D';
			userDataPtr->id[2] = '_';
			userDataPtr->id[3] = '0';
			userDataPtr->id[4] = '\0';

			numUsers++;
			userDataPtr++;
		}
		if (option == Delete) {
			printf("Enter a user to delete:\n");
			int userNumber = -1;
			scanf_s(" %d", &userNumber);
			if (userNumber > -1 && userNumber < numUsers) {
				for (int i = userNumber; i < numUsers - 1; i++) {
					int counter = 0;
					while (userData[i + 1].name[counter] != '\0') {
						userData[i].name[counter] = userData[i + 1].name[counter];
						counter++;
					}
					userData[i].name[counter] = '\0';
					counter = 0;
					while (userData[i + 1].title[counter] != '\0') {
						userData[i].title[counter] = userData[i + 1].title[counter];
						counter++;
					}
					userData[i].title[counter] = '\0';
				}
				userData[numUsers - 1].name[0] = '\0';
				userData[numUsers - 1].title[0] = '\0';
				numUsers--;
			}

		}
		if (option == Print) {
			for (int i = 0; i < numUsers; i++) {
				printf("Name:\t%s\tID:\t%s\tTitle:\t%s\n", userData[i].name, userData[i].id, userData[i].title);
			}

		}
		if (option == Write) {
			printf("Enter a user number:\n");
			int userNumber = -1;
			scanf_s(" %d", &userNumber);
			printf("Name:\t%s\tID:\t%s\tTitle:\t%s\n", userData[userNumber].name, userData[userNumber].id, userData[userNumber].title);
			printf("Enter a user data field to edit:\n 0 = Name, 1 = ID, 2 = Title\n");
			int userDataObj = -1;
			scanf_s(" %d", &userDataObj);
			if (userDataObj < 0 || userDataObj > 2) {
				continue;
			}
			char entry[50];
			printf("Enter new data:\n");
			scanf_s(" %49s", entry, 49);
			entry[49] = '\0';

			int counter = 0;
			if (userDataObj == 0) {
				while (entry[counter] != '\0') {
					userData[userNumber].name[counter] = entry[counter];
					counter++;
				}
				userData[userNumber].name[counter] = '\0';
			}
			if (userDataObj == 1) {
				while (entry[counter] != '\0' && counter < 9) {
					userData[userNumber].id[counter] = entry[counter];
					counter++;
				}
				userData[userNumber].id[counter] = '\0';

			}
			if (userDataObj == 2) {
				while (entry[counter] != '\0') {
					userData[userNumber].title[counter] = entry[counter];
					counter++;
				}
				userData[userNumber].title[counter] = '\0';
			}

		}
		if (option == Read) {
			printf("Enter a user number:\n");
			int userNumber = -1;
			scanf_s(" %d", &userNumber);
			if (userNumber > -1 && userNumber < numUsers) {
				printf("Name:\t%s\tID:\t%s\tTitle:\t%s\n", userData[userNumber].name, userData[userNumber].id, userData[userNumber].title);
			}
		}
		if (option == Quit) {
			break;
		}
	}
	return 0;
}