#include "unittestHelper.h"
// Function helper to print the current values being compared and the whether or not those values are equal to the console screen
void printTestResult(bool result, int a, int b){
	if(result){
		printf("%d == %d" ": TEST SUCCESSFULLY COMPLETED\n", a, b);
	}else{
		printf("%d == %d" ": TEST FAILED\n", a, b);
	}
}
// Function helper to evaluate if values a and b are equal to each other
bool assertTrue(int a, int b){
	bool result = (a == b);
	printTestResult(result, a, b);
	return result;
}
// Function helper to print out the final result of a unit test or card test
void printFinalResult(bool results[], int numTests){
	int i;
	for(i = 0; i < numTests; i++){
		if(!results[i]){
			printf("\nFailed\n");
			break;
		}
	}
	printf ("\nPassed\n");
}