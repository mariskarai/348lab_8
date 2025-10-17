#include <stdio.h>

int main() {
    int score;
    
    // Keep asking until user enters 1 to stop
    while (1) {
        printf("Enter the NFL score (Enter 1 to stop): ");
        scanf("%d", &score);
        
        // Check if user wants to stop
        if (score == 1) {
            break;
        }
        
        if (score < 0) {
        printf("Invalid input. Score cannot be negative.\n");
        continue; 
    }
    
        printf("Possible combinations of scoring plays if a team's score is %d:\n", score);
        
        // Try all possible combinations using nested loops
        // TD + 2pt = 8 points
        for (int td_2pt = 0; td_2pt * 8 <= score; td_2pt++) {
            // TD + FG = 7 points
            for (int td_fg = 0; td_2pt * 8 + td_fg * 7 <= score; td_fg++) {
                // TD = 6 points
                for (int td = 0; td_2pt * 8 + td_fg * 7 + td * 6 <= score; td++) {
                    // FG = 3 points
                    for (int fg = 0; td_2pt * 8 + td_fg * 7 + td * 6 + fg * 3 <= score; fg++) {
                        
                        // Calculate remaining points after all other scores
                        int remaining = score - (td_2pt * 8 + td_fg * 7 + td * 6 + fg * 3);
                        
                        // Check if remaining points can be made with safeties
                        // Remaining must be even number
                        if (remaining % 2 == 0) {
                            int safety = remaining / 2;
                            
                            // Print valid combination
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                   td_2pt, td_fg, td, fg, safety);
                        }
                    }
                }
            }
        }
        printf("\n"); 
    }
    return 0;
}