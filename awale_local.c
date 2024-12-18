#include "awale/awale.h"
#include "stdio.h"

void print_sep() {
    // +--+--+
    for (int i = 0; i < WIDTH; i++) printf("+--");
    printf("+\r\n");
}

void display_awale(Awale* awale) {
    print_sep();

    for (int i = 0; i < WIDTH; i++) printf("|%2d", CELL_COUNT - 1 - i); // Affichage des indices
    printf("|\r\n");
    for (int i = 0; i < WIDTH; i++) printf("|%2d", awale->cells[CELL_COUNT - 1 - i]);
    printf("|\r\n");

    print_sep();

    for (int i = 0; i < WIDTH; i++) printf("|%2d", awale->cells[i]);
    printf("|\r\n");

    print_sep();
}

int main() {
    Awale awale = init_game();
    while (awale.state == STATE_PLAYING) {
        display_awale(&awale);
        printf("Player %d: ", awale.turn+1);
        int cell = 0;
        scanf("%d", &cell);
        int res = play(&awale, awale.turn, cell);
        printf("%d\r\n", res);
        for (int p = 0; p < PLAYER_COUNT; p++) {
            printf("P%d: %d\r\n", p, awale.score[p]);
        }
        
    }
}