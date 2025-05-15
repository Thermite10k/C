#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define MAX_LINE 150
#define KEY "key.txt"

typedef struct {
    int32_t x;
    int32_t y;

} vector;

int32_t find_unique_pairs(char map[MAX_LINE][MAX_LINE], vector mapDims, vector startAt);
int32_t count_antinodes(vector v1, vector v2, vector mapDims);
vector getL1Distance(vector *v1, vector *v2);
int32_t vectorInVector(vector *v1, vector *v2); // returns 1 if v1 is in v2.

int main(int argc, char* argv[]){

    FILE* fp = fopen(KEY, "r");

    int32_t rows = 0;
    int32_t columns = 0;

    char map[MAX_LINE][MAX_LINE];
    int32_t lineCounter = 0;

    while (lineCounter < MAX_LINE && fgets(*(map + lineCounter), MAX_LINE, fp)){
        
        printf("%s", (map+lineCounter));
        lineCounter++;
    }
    vector dims = {.x = 12, .y = 12};
    vector start = {.x = 0, .y = 0};
    printf("%d\n", find_unique_pairs(map, dims, start));
    
    return 0;
}

int32_t find_unique_pairs(char map[MAX_LINE][MAX_LINE], vector mapDims, vector startAt){
    

    vector currentPosition = {.x = startAt.x, .y = startAt.y};

    int32_t totalAntinodes = 0;
    
    for(currentPosition.y = startAt.y; currentPosition.y < mapDims.y; currentPosition.y++){
        for(currentPosition.x = startAt.x; currentPosition.x < mapDims.x; currentPosition.x++){
            
            }
        }
        return totalAntinodes;
}
int32_t count_antinodes(vector v1, vector v2, vector mapDims){
    
    vector distance = getL1Distance(&v1, &v2);

    int32_t antiodeCount = 0;
    vector antinodes[2];

    vector a1  = (vector) {.x = v1.x - distance.x, .y = v1.y - distance.y};
    vector a2 =  {.x = v2.x + distance.x, .y = v2.y + distance.y};

    if(vectorInVector(&v1, &mapDims)){
        antiodeCount++;
    }


    if(vectorInVector(&v2, &mapDims)){
        antiodeCount++;
    }

    printf("Returnign %d", antiodeCount);

    return antiodeCount;



}
vector getL1Distance(vector *v1, vector *v2){
    vector ans = {
        .x = fabs(v1->x - v2->x),
        .y = fabs(v1->y - v2->y)
    };

    return ans;
}
int32_t vectorInVector(vector *v1, vector *v2){ // returns 1 if v1 is in v2.

    return (v1->x && v1->y && v1->x < v2->x && v1->y < v2->y)? 1 : 0;

}