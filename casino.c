#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 and 6
int generateRandomNumber() {
    return rand() % 6 + 1;
}

// Function to play the game
void playGame() {
    int balance = 100; // Initial balance
    int bet;

    printf("Welcome to the Slot Machine game!\n");
    printf("Your initial balance is: %d\n", balance);

    while (balance > 0) {
        printf("Enter your bet (1-10) or 100 to quit: ");

        // Check if Ctrl+D is pressed
        scanf("%d",&bet);
       if ( bet== 100) {
          printf("Game over. You quit the game.\n");
            return;
        }

        // Check if bet is less than 1
       if (bet < 1 || bet>10) {
            printf("Invalid bet.Enter a valid bet betwen 1-10\n");
           continue;
       }

        if (bet > balance) {
            printf("Insufficient balance. Please try again.\n");
            return;
        }

        int reel1 = generateRandomNumber();
        int reel2 = generateRandomNumber();
        int reel3 = generateRandomNumber();

        printf("Reels: %d %d %d\n", reel1, reel2, reel3);

        if (reel1 == reel2 && reel2 == reel3) {
            printf("Congratulations! You won: %d\n", bet * 3);
            balance += bet * 3;
        } else if (reel1 == reel2 || reel2 == reel3 || reel1 == reel3) {
            printf("You won: %d\n", bet * 2);
            balance += bet * 2;
        } else {
            printf("Sorry, you lost: %d\n", bet);
            balance -= bet;
        }

        printf("Your current balance is: %d\n", balance);
    }

    printf("Game over. You ran out of balance.\n");
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    playGame();
    return 0;
}