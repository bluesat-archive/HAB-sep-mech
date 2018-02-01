#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define SEPARATE_INSTANCES 4

int main(){
    char target = '1';
    char turn_off = '2';
    char test = '5';
    char curr = 0;
    int position = 0;
    int running = TRUE;
    int testLEDOn = FALSE;
    while (running == TRUE){
        char in = getchar();

	// Validate the input chars -- only process numbers and letters
		int islegal = FALSE;
		if (in >= 'a' && in <= 'z') islegal = TRUE;
		if (in >= 'A' && in <= 'Z') islegal = TRUE;
		if (in >= '0' && in <= '9') islegal = TRUE;
		
		if (islegal == TRUE){
			printf("%c", in);
			if (position == 0){
				if (in == target){
                    curr = target;
                    position++;
                } else if (in == turn_off){
                    curr = turn_off;
                    position++;
                }
            }
            

			if (in == curr){
				printf(" ###\n");
				position++;
				if (position == SEPARATE_INSTANCES){
					// We have a match
                    position = 0;
                    if (curr == target){
						printf("\n\033[32mTURNING OFF PIN (Turning on SSR)\033[0m\n");
						system("./setPin.py 11 0"); // Turn pin 11 to low
					} else if (curr == turn_off){
                        printf("\n\033[32mTURNING OFF PIN (Turning off SSR)\033[0m\n");
                        system("./setPin.py 11 1"); // Turn pin 11 to high
                    }
                }
			} else {
				position = 0;
			}

			if (in == test){
				if (testLEDOn == FALSE){
					printf("\n\033[32mtestpin 15 ON\033[0m\n");
					system("./setPin.py 15 1");
					testLEDOn = TRUE;
				} else {
					printf("\n\033[32mtestpin 15 OFF\033[0m\n");
					system("./setPin.py 15 0");
					testLEDOn = FALSE;
				}
			}
		}
	}
	return EXIT_SUCCESS;
}
