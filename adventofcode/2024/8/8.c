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
/*
    TODO:
        1- make the dims vector automatic i.e., the x, y should be the lenght and number of lines
        2- the count antinote only works if pt2.x > pt1.x. otherwise it will return garbage, find a geometric solution
*/
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
    


    int32_t totalAntinodes = 0;

    vector pt1 = {.x  = startAt.x, .y = startAt.y};
    vector pt2 = {.x = startAt.x, .y = startAt.y};
    char currentNode = '.';
    
    for(pt1; pt1.y < mapDims.y; pt1.y++){
        for(pt1.x = startAt.x; pt1.x < mapDims.x; pt1.x++){
            if(map[pt1.y][pt1.x] != '.'){
                currentNode = map[pt1.y][pt1.x];
                pt2.x = pt1.x + 1 < mapDims.x ? pt1.x + 1 : 0;
                pt2.y = pt2.x ? pt1.y : pt1.y + 1; // if pt2.x is set to 0, you'll go to next line, y++
                for(pt2; pt2.y < mapDims.y; pt2.y++, pt2.x = 0){ // reset the pt2.x here becasue reserring it in the loop initates it to 0, which we usually don't want until a new line, which happens here
                    for(pt2; pt2.x < mapDims.x; pt2.x++){
                        if(currentNode == map[pt2.y][pt2.x]){
                            totalAntinodes += count_antinodes(pt1, pt2, mapDims);
                        }
                    }
                }
                
            }
            }
        }
        return totalAntinodes;
}
int32_t count_antinodes(vector v1, vector v2, vector mapDims){
    
    vector distance = getL1Distance(&v1, &v2);

    int32_t antiodeCount = 0;


    vector a1  = {.x = v1.x - distance.x, .y = v1.y - distance.y};
    vector a2 =  {.x = v2.x + distance.x, .y = v2.y + distance.y};

    if(vectorInVector(&a1, &mapDims)){
        printf("One at y: %d x:%d\n", a1.y, a1.x);
        antiodeCount++;
    }


    if(vectorInVector(&a2, &mapDims)){
        printf("One at y: %d x:%d\n", a2.y, a2.x);
        antiodeCount++;
    }

    printf("Returnign %d\n", antiodeCount);

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

    return (v1->x >= 0 && v1->y >= 0 && v1->x < v2->x && v1->y < v2->y)? 1 : 0;

}