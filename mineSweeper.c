#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function prototype
int **map(int lenth, int width);
void drawMap(int** Target, int length, int width);


//메인 함수
int main() {
    int mapWidth, mapLength;
    //맵사이즈 입력
    printf("Enter length of the map : ");
    scanf_s("%d", &mapLength);
    printf("Enter width of the map : ");
    scanf_s("%d", &mapWidth);

    int **maped = map(mapLength,mapWidth); //동적할당 하였기에 포인터 사용
    drawMap(maped,mapLength,mapWidth);


    while (1) {
        int y, x = 0;
        printf("\n y, x : ");
        scanf_s("%d %d",&y,&x);
        if (maped[y][x] == 1) {
            printf("boooom");
            return 0;
        }
        if (maped[y][x] > 9) {
            continue;
        }
        maped[y][x] = maped[y][x] + 10;
        //printf("%d", maped[y][x]); 
        drawMap(maped,mapLength,mapWidth);
        //printf("%d", maped[y][x]);
    }

    for (int i = 0; i < mapLength; i++) {
        free(maped[i]);
    }
    free(maped);
    return 0;
}


//맵 생성 함수
int **map(int length,int width) { 

    //맵 크기 동적 할당
    int** map = malloc(length * sizeof(int*));
    for (int i = 0; i < length; i++) {
        map[i] = malloc(width * sizeof(int));
    }

    //지뢰 or 땅을 1과 0으로 이차원 정수 배열에 넣음
    srand(time(NULL));
    for (int a = 0; a<length; a++) {
        for (int j = 0; j < width ; j++) {
            int random = (rand() % 7) + 1;
            if (random == 1) {
                map[a][j] = 1;
            }
            else {
                map[a][j] = 0;
            }
        }
    }
    for (int a = 0; a < length; a++) {
        for (int j = 0; j < width; j++) {
            int minecnt = 0;
            if (map[a][j] != 1) {
                for (int c = -1; c <= 1; c++) {
                    for (int d = -1; d <= 1; d++) {
                        int ni = a + c;
                        int nj = j + d;
                        if (ni >= 0 && ni < length && nj >= 0 && nj < width && map[ni][nj] == 1) {
                            minecnt++;
                        }
                        
                    }
                    
                }
            }
            if (minecnt != 0) {
                map[a][j] = minecnt + 1;
            }
        }
    }
    return map;
}
 

//map print function 
void drawMap(int** Target, int length, int width) {
    for (int i = 0; i < length; i++) {
        printf("\n");
        for (int j = 0; j < width; j++) {
            if (Target[i][j] > 9) {
                int a = Target[i][j] - 10;
                if (a != 0) {
                    a = a -1;
                }
                printf("%d ", a);
            }
            else {
                printf("■");

            }
        }
    }
}
