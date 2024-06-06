#include <stdio.h>
void checkOddEven(int numbers[], int size) {
	int i;
    printf("Odd or Even:\n");
    for(i = 0; i < size; i++) {
        if(numbers[i] % 2 == 0) {
            printf("%d is Even\n", numbers[i]);
        } else {
            printf("%d is Odd\n", numbers[i]);
        }
    }
}
int main() {
    int numbers[] = {12, 7, 15, 20, 25};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    checkOddEven(numbers, size);
    return 0;
}
