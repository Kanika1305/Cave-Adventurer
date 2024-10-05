#include <stdio.h>
#include <stdlib.h>
#include "game_functions.h"
#ifdef _WIN32
    #define CLEAR_SCREEN() system("cls")
#else
    #define CLEAR_SCREEN() system("clear")
#endif

int main() {
    player p = {10, 0};
    position pos = {0, 0};
    int high_score = read_highscore();
    int max_score = 100;
    int start_choice;
    printf(CYAN"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n"RESET);
    printf(CYAN"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n"RESET);
    printf(CYAN"::                                                                                                        ::\n"RESET);
    printf(CYAN"::_________                           _____       .___                    __                              ::\n"RESET);
    printf(CYAN"::\\_   ___ \\_____ ___  __ ____       /  _  \\    __| _/__  __ ____   _____/  |_ __ _________  ___________  ::\n"RESET);
    printf(CYAN"::/    \\  \\/\\__  \\\\  \\/ // __ \\     /  /_\\  \\  / __ |\\  \\/ // __ \\ /    \\   __\\  |  \\_  __ \\/ __ \\_  __ \\ ::\n"RESET);
    printf(CYAN"::\\     \\____/ __ \\\\   /\\  ___/    /    |    \\/ /_/ | \\   /\\  ___/|   |  \\  | |  |  /|  | \\|  ___/|  | \\/ ::\n"RESET);
    printf(CYAN":: \\______  (____  /\\_/  \\___  >   \\____|__  /\\____ |  \\_/  \\___  >___|  /__| |____/ |__|   \\___  >__|    ::\n"RESET);
    printf(CYAN"::        \\/     \\/          \\/            \\/      \\/           \\/     \\/                       \\/        ::\n"RESET);
    printf(CYAN"::                                                                                                        ::\n"RESET);
    printf(CYAN"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n"RESET);
    printf(CYAN"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n"RESET);

    do {
        printf("\nWhat would you like to do?\n");
        printf("1. View Instructions\n");
        printf("2. View High Score\n");
        printf("3. Play Game\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &start_choice);
     CLEAR_SCREEN();
        switch (start_choice) {
            case 1:
    printf(CYAN">>==========================================================================<<\n"RESET);
    printf(CYAN"||                                                                          ||\n"RESET);
    printf(CYAN"||  ________                                                                ||\n"RESET);
    printf(CYAN"|| /  _____/_____    _____   ____                                           ||\n"RESET);
    printf(CYAN"||/   \\  ___\\__  \\  /     \\_/ __ \\                                          ||\n"RESET);
    printf(CYAN"||\\    \\_\\  \\/ __ \\|  Y Y  \\  ___/                                          ||\n"RESET);
    printf(CYAN"|| \\______  (____  /__|_|  /\\___  >                                         ||\n"RESET);
    printf(CYAN"||.___    \\/     \\/   __ \\/     \\/             __  .__                      ||\n"RESET);
    printf(CYAN"|||   | ____   ______/  |________ __ __  _____/  |_|__| ____   ____   ______||\n"RESET);
    printf(CYAN"|||   |/    \\ /  ___|   __\\_  __ \\  |  \\/ ___\\   __\\  |/  _ \\ /    \\ /  ___/||\n"RESET);
    printf(CYAN"|||   |   |  \\\\___ \\ |  |  |  | \\/  |  |  \\___|  | |  (  <_> )   |  \\\\___ \\ ||\n"RESET);
    printf(CYAN"|||___|___|  /____  >|__|  |__|  |____/ \\___  >__| |__|\\____/|___|  /____  >||\n"RESET);
    printf(CYAN"||         \\/     \\/                        \\/                    \\/     \\/ ||\n"RESET);
    printf(CYAN"||                                                                          ||\n"RESET);
    printf(CYAN">>==========================================================================<<\n"RESET);
    read_instructions();
break;

            case 2:
    printf(MAGENTA">>==============================================================<<\n"RESET);
    printf(MAGENTA"||                                                              ||\n"RESET);
    printf(MAGENTA"||  ___ ___ .__   ____ .__                                      ||\n"RESET);
    printf(MAGENTA"|| /   |   \\|__| / ___\\|  |__   ______ ____  ___________  ____  ||\n"RESET);
    printf(MAGENTA"||/    ~    \\  |/ /_/  >  |  \\ /  ___// ___\\/  _ \\_  __ \\/ __ \\ ||\n"RESET);
    printf(MAGENTA"||\\    Y    /  |\\___  /|   Y  \\\\___ \\\\  \\__(  <_> )  | \\|  ___/ ||\n"RESET);
    printf(MAGENTA"|| \\___|_  /|__/_____/ |___|  /____  >\\___  >____/|__|   \\___  >||\n"RESET);
    printf(MAGENTA"||       \\/                 \\/     \\/     \\/                 \\/ ||\n"RESET);
    printf(MAGENTA"||                                                              ||\n"RESET);
    printf(MAGENTA">>==============================================================<<\n"RESET);
                printf("\n");
                printf(MAGENTA "\n************************************\n" RESET);
                printf(MAGENTA "*       Current High Score: %d      *\n" RESET, high_score);
                printf(MAGENTA "************************************\n\n" RESET);
                break;

            case 3:
    printf(GREEN"*********************************************************\n"RESET);
    printf(GREEN"*                                                       *\n"RESET);
    printf(GREEN"*.____           __ /\\            ________           ._.*\n"RESET);
    printf(GREEN"*|    |    _____/  |\\\\( ______    /  _____/  ____     | |*\n"RESET);
    printf(GREEN"*|    |  _/ __ \\   __\\/  ___/   /   \\  ___ /  _ \\    | |*\n"RESET);
    printf(GREEN"*|    |__\\  ___/|  |  \\___ \\    \\    \\_\\  (  <_> )    \\|*\n"RESET);
    printf(GREEN"*|_______ \\___  >__| /____  >    \\______  /\\____/     __*\n"RESET);
    printf(GREEN"*        \\/   \\/          \\/            \\/            \\/*\n"RESET);
    printf(GREEN"*                                                       *\n"RESET);
    printf(GREEN"*********************************************************\n"RESET);
                print_cave(pos);
                break;

            case 4:
    printf(CYAN":  ________                  ._____.                    ._.:\n"RESET);
    printf(CYAN": /  _____/  ____   ____   __| _|_ |__ ___.__. ____     | |:\n"RESET);
    printf(CYAN":/   \\  ___ /  _ \\ /  _ \\ / __ | | __ <   |  |/ __ \\    | |:\n"RESET);
    printf(CYAN":\\    \\_\\  (  <_> |  <_> ) /_/ | | \\_\\ \\___  \\  ___/     \\|:\n"RESET);
    printf(CYAN": \\______  /\\____/ \\____/\\____ | |___  / ____|\\___  >    __:\n"RESET);
    printf(CYAN":        \\/                   \\/     \\/\\/         \\/     \\/:\n"RESET);
    printf(CYAN":                                                          :\n"RESET);
return 0;

            default:
                printf(RED "Invalid choice. Please try again.\n" RESET);
        }
    } while (start_choice != 3 && start_choice != 4);

    while (p.health > 0 && p.score < max_score) {
        printf("\nYou are currently at position (" YELLOW "%d" RESET ", " YELLOW "%d" RESET ")\n", pos.x, pos.y);
        printf("Your current health is " YELLOW "%d\n" RESET, p.health);
        printf("Your current score is " GREEN "%d\n" RESET, p.score);

        printf("\nWhat do you want to do?\n");
        printf("R/r. Move right\n");
        printf("L/l. Move left\n");
        printf("U/u. Move up\n");
        printf("D/d. Move down\n");
        printf("Q/q. Quit\n");

        char choice;
        int steps;
        printf("Enter your choice: ");
        scanf(" %c", &choice); 

        if (choice == 'r' || choice == 'R' || choice == 'l' || choice == 'L' || choice == 'u' || choice == 'U' || choice == 'd' || choice == 'D') {
            printf("Enter number of steps to move: ");
            scanf("%d", &steps);
        }
        int moved = 0;
        switch (choice) {
    
            case 'l':
            case 'L':
            CLEAR_SCREEN();
                moved = move(&pos, 0, -1, steps);
                break;
            case 'r':
            case 'R':
            CLEAR_SCREEN();
                moved = move(&pos, 0, 1, steps);
                break;
            case 'u':
            case 'U':
            CLEAR_SCREEN();
                moved = move(&pos, -1, 0, steps);
                break;
            case 'd':
            case 'D':
            CLEAR_SCREEN();
                moved = move(&pos, 1, 0, steps);
                break;
            case 'q':
            case 'Q':
            CLEAR_SCREEN();
  printf(CYAN":  ________                  ._____.                    ._.:\n"RESET);
    printf(CYAN": /  _____/  ____   ____   __| _|_ |__ ___.__. ____     | |:\n"RESET);
    printf(CYAN":/   \\  ___ /  _ \\ /  _ \\ / __ | | __ <   |  |/ __ \\    | |:\n"RESET);
    printf(CYAN":\\    \\_\\  (  <_> |  <_> ) /_/ | | \\_\\ \\___  \\  ___/     \\|:\n"RESET);
    printf(CYAN": \\______  /\\____/ \\____/\\____ | |___  / ____|\\___  >    __:\n"RESET);
    printf(CYAN":        \\/                   \\/     \\/\\/         \\/     \\/:\n"RESET);
    printf(CYAN":                                                          :\n"RESET);                              
                return 0;
            default:
                printf(RED "Invalid choice. Please try again.\n" RESET);
        }

        if (moved) {
            update_map(pos);
            bigtreasure(&p, pos);
            smalltreasure(&p, pos);
            bear(&p, pos);
            health(&p, pos);
        }
    }
    
    printf(RED "\n************************************\n" RESET);
    printf(GREEN "*       Game Over! Your score: %d  *\n" RESET, p.score);
    printf(RED "************************************\n" RESET);

    if (p.score > high_score) {
        printf(GREEN "\n************************************\n" RESET);
        printf(MAGENTA "\nCONGRATULATIONS! NEW HIGH SCORE: %d\n" RESET, p.score);
        printf(GREEN "\n************************************\n" RESET);
        write_highscore(p.score);
    }

    return 0;
}
