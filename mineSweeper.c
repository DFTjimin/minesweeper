#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main (){
    int map [6][6];
    srand(time(NULL));
    for (int i = 1; i < 6; i++){
        printf("\n");
        for(int j = 1; j < 6; j++){
            int random = (rand() % 5) + 1;
            if (random == 1){
                map [i][j] = 1;
                printf("%d ",map[i][j]);
            }
            else{
                map [i][j] = 0;
                printf("%d ",map[i][j]);
            }
        }
    }
}


