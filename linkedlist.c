#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *nextadd;
}NODE;

NODE *firstnode = NULL;
NODE *lastnode = NULL;
int cnt = 0;

void add(int num) {
	if (cnt > 9) {
		printf("You can't make more than 10 of them.");
		return;
	}
	NODE *newnode = (NODE *)malloc(sizeof(NODE));
	cnt++;
	newnode->data = num;
	newnode->nextadd = NULL;
	if (firstnode == NULL) {

		firstnode = newnode;
		lastnode = newnode;
	}
	else {
		lastnode->nextadd = newnode;
		lastnode = newnode;
	}
}

void erase(int num) {
	NODE *temp = firstnode;
	if (firstnode == NULL) {
		printf("No value.\n");
		return;
	}
	if (firstnode->data == num) {

		firstnode = firstnode->nextadd;
		cnt--;

	}
	else {
		NODE *before = firstnode;
		while (1) {
			if (temp->data == num) {
				NODE *node_free = temp;
				before->nextadd = temp->nextadd;
				free(node_free);
				lastnode = before;
				cnt--;
				break;
			}
			else {
				if (temp->nextadd == NULL) {
					printf("No value.\n");
					break;
				}
				before = before->nextadd;
				temp = temp->nextadd;
			}
		}
	}
	return;
}

void insert(int num, int num1) {
	int i;
	if (firstnode == NULL) {
		printf("No value.\n");
		return;
	}
	NODE *temp = firstnode;
	for (i = 1;temp != NULL;++i) {
		if (temp->data == num) {
			NODE *newnode = (NODE *)malloc(sizeof(NODE));
			newnode->data = num1;
			newnode->nextadd = temp->nextadd;
			temp->nextadd = newnode;
			cnt++;
			break;
		}
		temp = temp->nextadd;
	}

}

void show() {
	int i;
	if (firstnode == NULL) {
		printf("No value.\n");
		return;
	}
	else {
		NODE *temp = firstnode;
		for (i = 1; temp != NULL; ++i) {
			printf("%d value : %d \t", i, temp->data);
			temp = temp->nextadd;
		}
	}
}



int main() {
	int select,  input_num, input_num1;
	int digit = 8;
	while (1) {
		printf("\n\n0 : exit\n");
		printf("1 : Create Node\n");
		printf("2 : Delete Node\n");
		printf("3 : Insert Node\n");
		printf("4 : View nodes\n");
		printf("Select 0-4 : ");
		check_num(&select, digit);

		if (select == 0) {
			return 0;
		}
		else if (select == 1) {
			printf("Please enter a value: ");
			check_num(&input_num, digit);
			add(input_num);

		}
		else if (select == 2) {
			show();
			printf("\nPlease enter a value to clear : ");
			check_num(&input_num, digit);
			erase(input_num);

		}
		else if (select == 3) {

			printf("\n|----------------------------------------------------------------------------------------------------------|");
			printf("\n  EX) first value:A		second value:B		third value:C				                                           ");
			printf("\n  EX) Please enter a value for the location you want to insert: B					    	                                       ");
			printf("\n  EX) Please enter a value to insert: AA									                                       ");
			printf("\n  EX)first value:A		second value:B		third value:AA 	   fourth value:C                              ");
			printf("\n|----------------------------------------------------------------------------------------------------------|\n\n\n\n");
			show();
			printf("\n\nPlease enter a value for the location you want to insert:");
			check_num(&input_num, digit);
			printf("Please enter a value to insert: ");
			check_num(&input_num1, digit);
			insert(input_num, input_num1);

		}
		else if (select == 4) {
			show();
		}
		else {
			printf("Only numbers between 0 and 4 can be entered.");
		}
	}
}

int check_num(int *result, int form) {

	int i;

	int j = 1;

	int sign = 1;

	int input_size;

	char *str;

	*result = 0;

	str = (char *)malloc(sizeof(char) * form + 2);

	while (1) {

		sign = 1;

		fgets(str, form + 2, stdin);

		for (i = 0; i < form + 1; i++) {

			if (str[i] == '\n') {

				input_size = i;

				break;

			}

		}

		if (str[0] == 10) {

			printf("Enter the number and press Enter. \n Please re-enter : ");

			continue;

		}

		if (i == form + 1) {

			printf("The input range has been exceeded. \n");

			while (getchar() != '\n') {

			}

			printf("Please re-enter : ");

			continue;

		}



		for (i = 0; i < input_size; i++) {

			if (str[i] < 48 || str[i] > 57) {

				if (str[i] != '\n') {

					printf("Only integer greater than 0 can be entered.\n");

					printf("Please re-enter : ");

					sign = 0;

					break;

				}

			}

		}

		if (sign == 0) {

			continue;

		}

		for (i = 0; i < input_size; i++) {

			*result = *result + (str[input_size - i - 1] - 48) * j;

			j = j * 10;

		}

		break;

	}

	free(str);

	return 0;

}
