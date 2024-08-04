#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// map 함수를 정의하여 2차원 배열을 반환
int** map() {
    // 6x6 크기의 2차원 배열을 동적으로 할당
    int** mapArray = malloc(6 * sizeof(int*));
    for (int i = 0; i < 6; i++) {
        mapArray[i] = malloc(6 * sizeof(int));
    }

    // 랜덤 숫자를 생성하여 배열을 채움
    srand(time(NULL));
    for (int i = 1; i < 6; i++) {
        for (int j = 1; j < 6; j++) {
            int random = (rand() % 5) + 1;
            if (random == 1) {
                mapArray[i][j] = 1;
            } else {
                mapArray[i][j] = 0;
            }
        }
    }
    
    return mapArray; // 2차원 배열 포인터 반환
}

int main() {
    // map 함수를 호출하여 2차원 배열을 받음
    int** maped = map();

    // 결과 출력
    for (int i = 1; i < 6; i++) {
        for (int j = 1; j < 6; j++) {
            printf("%d ", maped[i][j]);
        }
        printf("\n");
    }

    // 동적으로 할당한 메모리 해제
    for (int i = 0; i < 6; i++) {
        free(maped[i]);
    }
    free(maped);

    return 0; // main 함수는 int형을 반환해야 함
}
