/*============================================================================================================
FILENAME        : main.c
DESCRIPTION     : The main file that outputs the functions that are being used
AUTHOR          : himmel
CREATED ON      : February 14, 2024
REVISION HISTORY
Date:  	        		By:                     	Description:
============================================================================================================*/
#include "Statistician.h"

int main() {
    Statistician s = NULL;
    int choice, data;

    do {
        // Display menu options
        printf("\n[1] New Statistician\n");
        printf("[2] Destroy Statistician\n");
        printf("[3] Add Data\n");
        printf("[4] Delete Data\n");
        printf("[5] Display Statistics\n");
        printf("[6] QUIT\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Create a new statistician
                s = newStatistician();
                printf("Create new statistician done!\n");
                break;
            case 2:
                // Destroy the current statistician
                destroyStatistician(&s);
                printf("Destroy current statistician done!\n");
                break;
            case 3:
                // Add data to the statistician
                printf("Add data to Statistician\n");
                printf("Enter data: ");
                scanf("%d", &data);
                add(&s, data);
                displayData(s);
                break;
            case 4:
                // Remove data from the statistician
                printf("Remove data from Statistician\n");
                printf("Enter data: ");
                scanf("%d", &data);
                removeData(&s, data);
                displayData(s);
                break;
            case 5:
                // Display statistics for the statistician
                if (!isEmpty(s)) {
                    printf("STATISTICIAN DATA: ");
                    displayData(s);
                    printf("\nMinimum: %d\n", minimum(s));
                    printf("Maximum: %d\n", maximum(s));
                    printf("Range: %d\n", range(s));
                    printf("Mean (Average): %.12f\n", mean(s));
                    printf("Median: %.12f\n", median(s));
                    DataStore modeData = mode(s);
                    printf("Mode: %d, appeared %d times\n", modeData->item, modeData->next->item);
                    printf("Variance: %.12f\n", variance(s));
                    printf("Standard Deviation: %.12f\n", standardDeviation(s));
                } else {
                    printf("Statistician is empty.\n");
                }
                break;
            case 6:
                // Exit the program
                printf("Exiting...\n");
                break;
            default:
                // Invalid choice
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 6);

    return 0;
}
