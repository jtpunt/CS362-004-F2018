#include "unittestHelper.h"
// Function helper to print the current values being compared and the whether or not those values are equal to the console screen
void printTestResult(bool result, char str[], int a, int b){
	if(result){
		printf("%s TEST: %d == %d" ": TEST SUCCESSFULLY COMPLETED\n", str, a, b);
	}else{
		printf("%s TEST: %d == %d" ": TEST FAILED\n", str, a, b);
	}
}
// Function helper to evaluate if values a and b are equal to each other
bool assertTrue(char str[], int a, int b){
	bool result = (a == b);
	printTestResult(result, str, a, b);
	return result;
}
// Function helper to print out the final result of a unit test or card test
void printFinalResult(bool results[], int numTests){
	int i;
	for(i = 0; i < numTests; i++){
		if(!results[i]){
			printf("\nFailed\n\n");
			return;
		}
	}
	printf ("\nPassed\n\n");
}