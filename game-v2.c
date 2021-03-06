#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_castle();
void print_smile();
void print_sad_face();

int main(void){
    printf("\n");
    
    print_castle();
    printf("\n\n\n");

    int seconds = time(0);
    srand(seconds);
    int secret_number = rand() % 100;
    int user_attempt;
    int attempts_quantity;
    int numbers_are_equal;
    int won_the_game = 0;
    int counter;
    int difficulty_level;
    double score = 1000;

    printf("Qual o nível de dificuldade?\n");
    printf("(1) Fácil (2) Médio (3) Difícil\n\n");
    printf("Escolha: ");
    scanf("%d", &difficulty_level);

    switch(difficulty_level)
    {
        case 1:
            attempts_quantity = 20;
            break;
        case 2:
            attempts_quantity = 15;
            break;
        default:
            attempts_quantity = 6;
    }

    for(counter = 1; counter <= attempts_quantity; counter++){
        printf("TENTATIVA - %d\n\n", counter);
        printf("Qual é o seu chute? ");
        scanf("%d", &user_attempt);

        if(user_attempt < 0){
            printf("Não é permitido chutar números negativos.\n");
            continue;
        }

        numbers_are_equal = (user_attempt == secret_number);

        if(numbers_are_equal)
            break;
        else{
            int smaller = (user_attempt < secret_number);

            if(smaller)
                printf("O seu chute foi MENOR que o número secreto.\n");
            else
                printf("O seu chute foi MAIOR que o número secreto.\n");
        }
        printf("\n");
        double lost_points = (user_attempt - secret_number) / (double) 2;

        score -= (lost_points < 0) ? (-lost_points) : lost_points;
    }

    if(numbers_are_equal){
        print_smile();
        printf("Você ganhou, PARABÉNS!\n");
        printf("Você acertou em %d tentativas.\n", counter);
        printf("Total de pontos: %.2f\n", score);
    }else{
        print_sad_face();
        printf("Você perdeu, tente novamente.");
    }
}


void print_castle()
{
    //ASCII ART: https://www.asciiart.eu/buildings-and-places/castles
    printf("   /\\                                                        /\\       \n");
    printf("  |  |                                                      |  |        \n");
    printf(" /----\\                  Bem-vindo ao                      /----\\     \n");
    printf("[______]             Jogo de Adivinhação                  [______]      \n");
    printf(" |    |         _____                        _____         |    |        \n");
    printf(" |[]  |        [     ]                      [     ]        |  []|        \n");
    printf(" |    |       [_______][ ][ ][ ][][ ][ ][ ][_______]       |    |        \n");
    printf(" |    [ ][ ][ ]|     |  ,----------------,  |     |[ ][ ][ ]    |        \n");
    printf(" |             |     |/'    ____..____    '\\|     |             |       \n");
    printf("  \\  []        |     |    /'    ||    '\\    |     |        []  /        \n");
    printf("   |      []   |     |   |o     ||     o|   |     |  []       |            \n");
    printf("   |           |  _  |   |     _||_     |   |  _  |           |            \n");
    printf("   |   []      | (_) |   |    (_||_)    |   | (_) |       []  |            \n");
    printf("   |           |     |   |     (||)     |   |     |           |            \n");
    printf("   |           |     |   |      ||      |   |     |           |            \n");
    printf(" /''           |     |   |o     ||     o|   |     |           ''\\       \n");  
    printf("[_____________[_______]--'------''------'--[_______]_____________]      \n");
}

void print_smile()
{
    printf("                    *****************                       \n");
    printf("               ******               ******                  \n");
    printf("           ****                           ****              \n");
    printf("        ****                                 ***            \n");
    printf("      ***                                       ***         \n");
    printf("     **           ***               ***           **        \n");
    printf("   **           *******           *******          ***      \n");
    printf("  **            *******           *******            **     \n");
    printf(" **             *******           *******             **    \n");
    printf(" **               ***               ***               **    \n");
    printf("**                                                     **   \n");
    printf("**       *                                     *       **   \n");
    printf("**      **                                     **      **   \n");
    printf(" **   ****                                     ****   **    \n");
    printf(" **      **                                   **      **    \n");
    printf("  **       ***                             ***       **     \n");
    printf("   ***       ****                       ****       ***      \n");
    printf("     **         ******             ******         **        \n");
    printf("      ***            ***************            ***         \n");
    printf("        ****                                 ****           \n");
    printf("           ****                           ****              \n");
    printf("               ******               ******                  \n");
    printf("                    *****************                       \n");
}

void print_sad_face()
{
    printf("     .-''''''-.      \n");
    printf("   .'          '.    \n");
    printf("  /   O      O   \\  \n");
    printf(" :           `    :  \n");
    printf(" |                |  \n");
    printf(" :    .------.    :  \n");
    printf("  \\  '        '  /  \n");
    printf("   '.          .'    \n");
    printf("     '-......-'      \n");
}
