#include <stdio.h>

void nfl_score_combinations(int nfl_score) {
    if (nfl_score == 0) {
        printf("0 TD + 2pt, 0 TD + FG, 0 TD, 0 3pt FG, 0 Safety\n");
        return;
    }

    for (int touchdown = 0; touchdown <= nfl_score / 6; touchdown++) {
        for (int field_goal = 0; field_goal <= nfl_score / 3; field_goal++) {
            for (int safety = 0; safety <= nfl_score / 2; safety++) {
                for (int touchdown_2pt = 0; touchdown_2pt <= (nfl_score - (touchdown * 6 + field_goal * 3 + safety * 2)) / 8; touchdown_2pt++) {
                    for (int touchdown_fieldgoal = 0; touchdown_fieldgoal <= (nfl_score - (touchdown * 6 + field_goal * 3 + safety * 2 + touchdown_2pt * 8)) / 7; touchdown_fieldgoal++) {
                        int score_left = nfl_score - (touchdown * 6 + field_goal * 3 + safety * 2 + touchdown_2pt * 8 + touchdown_fieldgoal * 7);
                        if (score_left == 0) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", touchdown_2pt, touchdown_fieldgoal, touchdown, field_goal, safety);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    while (1) {
        printf("Enter 0 or 1 to STOP\n");
        int input_score;
        printf("Enter the NFL score: ");
        scanf("%d", &input_score);

        if (input_score <= 1) {
            break;
        }

        printf("Possible combinations of scoring plays:\n");
        nfl_score_combinations(input_score);
    }

    return 0;
}

