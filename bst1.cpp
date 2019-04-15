#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}Node;
int cnt=0;
Node* BST_insert(Node* root, int data)
{
    if(root == NULL)
    {
        root = (Node*) malloc(sizeof(Node));
        root->left = root->right = NULL;
        root->data = data;
        return root;
    }
    else
    {
        if (root->data >= data)
            root->left = BST_insert(root->left, data);
        else
            root->right = BST_insert(root->right, data);
    }
    return root;
}

void BST_print(Node* root)

{
    if(root == NULL)
        return;
	BST_print(root->left);
    printf("%d ", root->data);
    BST_print(root->right);
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
int main()
{
	int digit = 8;
	int select,input_num;
	Node* root = NULL;
	while (1) {
		printf("\n\n0 : exit\n");
		printf("1 : Create Node\n");
		printf("Select 0-1 : ");
		check_num(&select, digit);	
			if (select == 0) {
			BST_print(root);
			return 0;
		}
		else if (select == 1) {
			cnt++;
			printf("Please enter a value: ");
			check_num(&input_num, digit);
			root = BST_insert(root, input_num);
		}
		else
			printf("only 0 or 1");
		if(cnt==6){
			BST_print(root);
			printf("\nFinish");
			break;
		}
	}
}
