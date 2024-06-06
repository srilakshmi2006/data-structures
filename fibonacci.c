#include <stdio.h>
void fibonacci(int n) {
    int prev = 0, curr = 1, next;
    int i;
    printf("Fibonacci Series up to %d terms:\n", n);
    for( i = 0; i < n; i++) {
        printf("%d, ", prev);
        next = prev + curr;
        prev = curr;
        curr = next;
    }
    printf("\n");
}
int main() {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    if(n <= 0) {
        printf("Number of terms should be positive.\n");
    } else {
        fibonacci(n);
    }
    return 0;
}
