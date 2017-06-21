#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *create_word(const char *secret);
int check_trash(char letter);
int replace(const char *secret, char *word, char letter);
void display_result(const char *secret, char *word, char letter);

char trash[256];

int main(void){

    const char *test = "MARRON";
    char *my_word = create_word(test);
    char c;

    puts(my_word);

    while (1){
        printf("Proposer votre lettre: ");
        scanf("%c", &c);
        display_result(test, my_word, c);
        while ((c = getchar()) != '\n' && c != EOF);
    }

    return 0;
}

char *create_word(const char *secret){

    size_t length = strlen(secret);
    char star = '*';

    char *word = malloc(length+1);
    if (word == NULL) exit(-1);

    for (int i=0; secret[i]!='\0'; i++)
        word[i] = star;

    word[length] = '\0';

    return word;
}

int check_trash(char letter){

    for (int i=0; trash[i]!='\0'; i++){
        if (letter == trash[i]) return 1;
    }
    return 0;
}

int replace(const char *secret, char *word, char letter){

    char p[2];
    p[0] = letter;
    p[1] = '\0';

    int check = 0;

    if (!check_trash(letter)){
        strcat(trash, p);
        for (int i=0; secret[i]!='\0'; i++){
            if (secret[i] == letter){
                word[i] = letter;
                check = 1;
            }
        }
    }
    return check;
}

void display_result(const char *secret, char *word, char letter){

    if (replace(secret, word, letter)){
        if (strcmp(secret, word) == 0){
            printf("Vous avez gagné ! Le mot secret est %s\n", secret);
            free(word);
            exit(1);
        }
        puts(word);
    }
    else
        printf("lettre %c déjà proposée !\n", letter);

}
