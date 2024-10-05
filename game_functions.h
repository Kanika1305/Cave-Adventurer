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
        for (int j = 0; j < CAVE_SIZE; j++) printf((i == pos.x && j == pos.y) ? MAGENTA "P     " RESET : "X     ");
        printf("\n\n");
    }
}

void update_map(position pos) {
    printf("\033[2J\033[H");
    print_cave(pos);
}

void bigtreasure(player *p, position pos) {
    if (cave[pos.x][pos.y] == 10) {
         printf(YELLOW "\n************************************\n" RESET);
        printf(YELLOW "*       You have found a           *\n" RESET);
        printf(YELLOW "*         BIG TREASURE!            *\n" RESET);
        printf(YELLOW "************************************\n\n" RESET);
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
        printf(GREEN"\n************************************\n" RESET);
        printf(GREEN "*    You found a health boost!     *\n" RESET);
        printf(GREEN "************************************\n\n" RESET);
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
