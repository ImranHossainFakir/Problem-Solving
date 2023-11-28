#include <stdio.h>
#include <string.h>

int main() {

    int testCase, i = 0, c;
    scanf("%d", &testCase);

    while (testCase) {
        int arm, cnt = 0;
        scanf("%d", &arm);

        for (int i = 1; i <= arm*arm; i++) {
            printf("*");
            cnt++;
            if (cnt == arm) {
                printf("\n");
                cnt = 0;
            }
        }
        printf("\n");
        testCase--;
    }
    return 0;
}
