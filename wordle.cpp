#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> 
#include <ctime>
#include <unistd.h>

#define SIZE (5)
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_RESET   "\x1b[0m"

using namespace std;

ifstream in;
int file_size = 0;

int verify_letter(int position, char c, string word){
	int i, found = -1;
	if (word[position] == c)
		return 1;

	for (i = 0; i < SIZE; i++){
		if (word[i] == c){
			found = 0;
			break;
		}
	}
	return found;
}

void print_all_words(){
	string line;
	in.open("words.txt");
	while(in.peek()!=EOF){
		getline(in, line);
		cout << line << " ";
	}
	cout << "\n";
	in.close();
}

void welcome_message(){
	printf(COLOR_RED "\n\n                Bem-vindo\n" COLOR_RESET);
	printf(COLOR_YELLOW "            W O R D L E - P T\n\n" COLOR_RESET);
	printf(COLOR_GREEN "Escreva:\n" COLOR_RESET);
	printf(COLOR_BLUE "    help" COLOR_RESET);
	cout << " - Para ver a lista de palavras.\n";
	printf(COLOR_BLUE "    quit" COLOR_RESET);
	cout << " - Para sair do jogo.\n";
	printf(COLOR_GREEN "    Uma palavra de 5 letras" COLOR_RESET);
	cout << " - para tentar adivinhar a resposta.\n";
}

int check_attempt(string attempt){

	if (attempt.compare("quit") == 0)
		exit(EXIT_SUCCESS);
	else if (attempt.compare("help") == 0){
		print_all_words();
		return false;
	}
	string word;
	in.open("words.txt");
	for (int i = 0; i < file_size; i++){
		getline(in, word);
		if (attempt.compare(word) == 0){
			in.close();
			return true;
		}
	}
	in.close();
	cout << "Palavra não existente\n";
	return false;
}

int main(){

	string right_word;
	int correct_letters, attempts_num = 0, count = 0, n;
	in.open("words.txt");

	while(in.peek()!=EOF){
		getline(in, right_word);
		count++;
	}
	in.close();
	file_size = count;
	in.open("words.txt");

	srand((unsigned)time(0));
	for(int i = 0; i < rand() % file_size + 1; i++){
		getline(in, right_word);
	}
	in.close();
	if (right_word.length() != 5)
		exit(EXIT_FAILURE);

	welcome_message();
	do {
		string attempt;
		cin >> attempt;
		if (!check_attempt(attempt))
			continue;
		correct_letters = 0;
		for (int i = 0; i < SIZE; i++){
			n = verify_letter(i, attempt[i], right_word);
			if (n == -1)
				printf("%c ", attempt[i]);		
			else if (n == 0)
				printf(COLOR_YELLOW "%c " COLOR_RESET, attempt[i]);
			else if (n == 1){
				correct_letters++;
				printf(COLOR_GREEN "%c " COLOR_RESET, attempt[i]);
			}
		}
		cout << "\n";
		attempts_num++;

	} while (correct_letters != 5 && attempts_num < 5);
	if (attempts_num == 5 && correct_letters != 5)
		cout << "Perdeu. Palavra certa: " << right_word << "\n";
	else
		printf(COLOR_GREEN "PARABÉNS!!" COLOR_RESET);

	return 0;
}

/* */
