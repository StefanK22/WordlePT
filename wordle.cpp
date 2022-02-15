#include <iostream>
#include <stdlib.h>
#define SIZE (5)

using namespace std;

int verify_letter(int position, char c, const char* word){
	int i, found = 0;
	for (i = 0; i < SIZE; i++){
		if (word[c] == c){
			found = 1;
			break;
		}
	}
	if (found != 0){
		if (i == position)
			return 2;
	}
	return -1;
	
}

int main(){

	const char* right_word = "ANDAR";
	char attempt[SIZE + 1];

	cout << "Digite a palavra: ";
	cin >> attempt;
	printf("A sua palavra é %s e a certa é %s\n", attempt, right_word);
	for (int i = 0; i < SIZE; i++){
		if (right_word[i] == attempt[i])
			printf("1 ");
		else
			printf("0 ");
	}
	printf("\n");

	return 0;
}