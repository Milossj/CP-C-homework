#include <stdio.h>

//function to receive input from the user
//validating the input
char getInput() {
    char input;
    scanf(" %c", &input);
    while (input != 'G' && input != '1' && input != '2' && input != '3' && input != '4' && input != '5' && input != 'B1' && input != 'B2' && input != 'B3' ) {
        printf("Invalid input received. Please enter a valid floor (G, 1, 2, 3, 4, 5, B1, B2, B3): ");
        scanf(" %c", &input);
    }
    return input;
}

//moving the elevator
void moveElevator(char currentFloor, char destinationFloor, int *passengerCount) {
    printf("Elevator is now moving from floor %c to floor %c...\n", currentFloor, destinationFloor);
    currentFloor = destinationFloor;
    printf("You have now arrived at floor %c.\n", currentFloor);
    if(*passengerCount>1) *passengerCount-=1;
}
int main() {
    char currentFloor = 'G'; //starting at G floor
    char destinationFloor;
    int passengerCount;
    printf("Welcome. You are currently on the %c floor.\n", currentFloor);
    printf("How many passengers are there : ");
    scanf("%d", &passengerCount);
    printf("To which floor would you like to go? (G, 1, 2, 3, 4, 5, B1, B2, B3): ");
    destinationFloor = getInput();
    moveElevator(currentFloor, destinationFloor, &passengerCount);
    while(passengerCount>0){
        printf("Passenger count : %d\n", passengerCount);
        printf("Which floor would you like to go to next? (G, 1, 2, 3, 4, 5, B1, B2, B3): ");
        destinationFloor = getInput();
        moveElevator(currentFloor, destinationFloor, &passengerCount);
    }
    printf("All passengers have been dropped off.\n");
    return 0;
}
