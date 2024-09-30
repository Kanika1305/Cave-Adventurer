#include <stdio.h>
#include <stdlib.h>
#define CAVE_SIZE 5
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"
#define MAGENTA "\033[35m"

typedef struct {
    int health;
    int score;
} player;

typedef struct {
    int x;
    int y;
} position;

int cave[CAVE_SIZE][CAVE_SIZE] = {
    {0, 0, 0, 0, 2},
    {10, 0, 0, 3, 2},
    {1, 0, 2, 1, 3},
    {0, 2, 2, 2, 0},
    {3, 10, 3, 2, 10}
};

void print_cave(position pos) {
    printf(CYAN "\nCurrent Cave Layout:\n" RESET);
    for (int i = 0; i < CAVE_SIZE; i++) {
        for (int j = 0; j < CAVE_SIZE; j++) printf((i == pos.x && j == pos.y) ? MAGENTA "P  " RESET : "X  ");
        printf("\n");
    }
}

void update_map(position pos) {
    printf("\033[2J\033[H");
    print_cave(pos);
}

void bigtreasure(player *p, position pos) {
    if (cave[pos.x][pos.y] == 10) {
        printf(GREEN "\n************************************\n" RESET);
        printf(GREEN "*       You have found a           *\n" RESET);
        printf(GREEN "*         BIG TREASURE!            *\n" RESET);
        printf(GREEN "************************************\n\n" RESET);
        p->score += 20;
        cave[pos.x][pos.y] = 0;
    }
}

void smalltreasure(player *p, position pos) {
    if (cave[pos.x][pos.y] == 1) {
        printf(YELLOW "\n************************************\n" RESET);
        printf(YELLOW "*      You have found a small      *\n" RESET);
        printf(YELLOW "*         TREASURE!                *\n" RESET);
        printf(YELLOW "************************************\n\n" RESET);
        p->score += 10;
        cave[pos.x][pos.y] = 0;
    }
}

void bear(player *p, position pos) {
    if (cave[pos.x][pos.y] == 2) {
        printf(RED "\n************************************\n" RESET);
        printf(RED "*          UH OH!                  *\n" RESET);
        printf(RED "*       A Bear Attack!             *\n" RESET);
        printf(RED "************************************\n\n" RESET);
        p->health -= 15;
    }
}

void health(player *p, position pos) {
    if (cave[pos.x][pos.y] == 3) {
        printf(CYAN "\n************************************\n" RESET);
        printf(CYAN "*         HEALTH++!                *\n" RESET);
        printf(CYAN "*    You found a health boost!     *\n" RESET);
        printf(CYAN "************************************\n\n" RESET);
        p->health += 10;
        cave[pos.x][pos.y] = 0;
    }
}

int move(position *pos, int dx, int dy, int step) {
    if (pos->x + dx * step < 0 || pos->x + dx * step >= CAVE_SIZE || pos->y + dy * step < 0 || pos->y + dy * step >= CAVE_SIZE) {
        printf(RED "\n==================================\n" RESET);
        printf(RED "         Error: Out of bounds      \n" RESET);
        printf(RED "\n==================================\n" RESET);
        return 0;
    }
    pos->x += dx * step;
    pos->y += dy * step;
    return 1;
}

void read_instructions() {
    FILE *file = fopen("instructions.txt", "r");
    if (file == NULL) {
        printf(RED "Could not open instruction file\n" RESET);
        return;
    }
    char line[200];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

int read_highscore() {
    FILE *file = fopen("highscore.txt", "r");
    int high_score = 0;
    if (file == NULL) {
        printf (RED "Could not open highscore file\n" RESET);
        return high_score;
    }
    fscanf(file, "%d", &high_score);
    fclose(file);
    return high_score;
}

void write_highscore(int score) {
    FILE *file = fopen("highscore.txt", "w");
    if (file == NULL) {
        printf(RED "Could not write highscore to file\n" RESET);
        return;
    }
    fprintf(file, "%d", score);
    fclose(file);
}

int main() {
    player p = {10, 0};
    position pos = {0, 0};
    int high_score = read_highscore();
    int max_score = 100;
     printf(CYAN" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"RESET);
    printf(CYAN" ~  ____    ___     _______                                        ~\n"RESET);
    printf(CYAN" ~ / ___|  / \\ \\   / / ____|                                       ~\n"RESET);
    printf(CYAN" ~| |     / _ \\ \\ / /|  _|                                         ~\n"RESET);
    printf(CYAN" ~| |___ / ___ \\ V / | |___                                        ~\n"RESET);
    printf(CYAN" ~ \\____/_/___\\_\\_/  |_____|_ _   _ _____ _   _ ____  _____ ____   ~\n"RESET);
    printf(CYAN" ~   / \\  |  _ \\ \\   / / ____| \\ | |_   _| | | |  _ \\| ____|  _ \\  ~\n"RESET);
    printf(CYAN" ~  / _ \\ | | | \\ \\ / /|  _| |  \\| | | | | | | | |_) |  _| | |_) | ~\n"RESET);
    printf(CYAN" ~ / ___ \\| |_| |\\ V / | |___| |\\  | | | | |_| |  _ <| |___|  _ <  ~\n"RESET);
    printf(CYAN" ~/_/   \\_\\____/  \\_/  |_____|_| \\_| |_|  \\___/|_| \\_\\_____|_| \\_\\ ~\n"RESET);
    printf(CYAN" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"RESET);
   int start_choice;
    do {
        printf("\nWhat would you like to do?\n");
        printf("1. View Instructions\n");
        printf("2. View High Score\n");
        printf("3. Play Game\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &start_choice);

        switch (start_choice) {
            case 1:
                printf(CYAN "\n************************************\n" RESET);
                printf(CYAN "*        Game Instructions         *\n" RESET);
                printf(CYAN "************************************\n\n" RESET);
                read_instructions();
                break;

            case 2:
                printf(MAGENTA "\n************************************\n" RESET);
                printf(MAGENTA "*       Current High Score: %d      *\n" RESET, high_score);
                printf(MAGENTA "************************************\n\n" RESET);
                break;

            case 3:
                printf(GREEN "\n************************************\n" RESET);
                printf(GREEN "*       Starting the Game!         *\n" RESET);
                printf(GREEN "************************************\n" RESET);
                print_cave(pos);
                break;

            case 4:
                printf(BLUE "\n************************************\n" RESET);
                printf(BLUE "*       >_<  Goodbye! See you!        *\n" RESET);
                printf(BLUE "************************************\n" RESET);
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
        printf("1. Move left\n");
        printf("2. Move right\n");
        printf("3. Move up\n");
        printf("4. Move down\n");
        printf("5. Quit\n");

        int choice, steps;
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 4) {
            printf("Enter number of steps to move: ");
            scanf ("%d", &steps);
        }

        int moved = 0;
        switch (choice) {
            case 1:
                moved = move(&pos, 0, -1, steps);
                break;
            case 2:
                moved = move(&pos, 0, 1, steps);
                break;
            case 3:
                moved = move(&pos, -1, 0, steps);
                break;
            case 4:
                moved = move(&pos, 1, 0, steps);
                break;
            case 5:
                printf(BLUE "\n************************************\n" RESET);
                printf(BLUE "*            Goodbye >_<!          *\n" RESET);
                printf(BLUE "************************************\n" RESET);
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
     printf(GREEN "\n************************************\n" RESET);
    printf(GREEN "*       Game Over! Your score: %d  *\n" RESET, p.score);
    printf(GREEN "************************************\n" RESET);
      if (p.score > high_score) {
        printf(MAGENTA "\nCongratulations! New High Score: %d\n" RESET, p.score);
        write_highscore(p.score);
    }
 return 0;
}