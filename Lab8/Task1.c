/*ask the user for NFL SCOREA(int)
calculate combinations of scoring- 
TD, FG, Safety, Touchdown (TD) 2POINT, (TD) 1 POINT) */
#include <stdio.h>

int main(void) {
    int score;
    printf("Enter the NFL score (Enter 1 to stop): ");
    if (scanf("%d", &score) != 1) return 0;

    while (score != 1) {
        int found = 0;
        printf("Possible combinations of scoring plays if a team scores is %d:\n", score);

        for (int td8 = 0; td8 <= score / 8; td8++) {
            int rem8 = score - 8 * td8;

            for (int td7 = 0; td7 <= rem8 / 7; td7++) {
                int rem7 = rem8 - 7 * td7;

                for (int td6 = 0; td6 <= rem7 / 6; td6++) {
                    int rem6 = rem7 - 6 * td6;

                    for (int fg = 0; fg <= rem6 / 3; fg++) {
                        int rem3 = rem6 - 3 * fg;

                        if (rem3 % 2 != 0) continue;   // only now check parity
                        int safety = rem3 / 2;

                        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                               td8, td7, td6, fg, safety);
                        found = 1;
                    }
                }
            }
        }

        if (!found) printf("No combinations.\n");

        printf("\nEnter the NFL score (Enter 1 to stop): ");
        if (scanf("%d", &score) != 1) break;
    }
    return 0;
}
