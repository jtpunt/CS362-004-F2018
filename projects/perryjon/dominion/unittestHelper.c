#include "unittestHelper.h"
void printTestResult(bool result, int a, int b){
	if(result){
		printf("%d == %d" ": TEST SUCCESSFULLY COMPLETED\n", a, b);
	}else{
		printf("%d == %d" ": TEST FAILED\n", a, b);
	}
}
bool assertTrue(int a, int b){
	bool result = (a == b);
	printTestResult(result, a, b);
	return result;
}
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