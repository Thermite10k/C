#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

#define MAX_LINE 150
#define KEY "key2.txt"

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
        1- make the dims vector automatic i.e., the x, y should be the lenght and number of lines -- DONE
        2- the count antinote only works if pt2.x > pt1.x. otherwise it will return garbage, find a geometric solution -- DONE
*/

char uniquenessMap[MAX_LINE][MAX_LINE];
int main(int argc, char* argv[]){
    
    memset(uniquenessMap, '.', sizeof(uniquenessMap));
    FILE* fp = fopen(KEY, "r");

    int32_t rows = 0;
    int32_t columns = 0;

    char map[MAX_LINE][MAX_LINE];
    int32_t lineCounter = 0;

    while (lineCounter < MAX_LINE && fgets(*(map + lineCounter), MAX_LINE, fp)){
        
        printf("%s", (map+lineCounter));
        lineCounter++;
    }
    
    vector dims = {.x = (strlen(map[0]) - 1), .y = lineCounter};
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

                for(pt2.y = pt1.y; pt2.y < mapDims.y; pt2.y++, pt2.x){
                    for(pt2.x = (pt1.y == pt2.y ? pt1.x+1 : 0); pt2.x < mapDims.x; pt2.x++){
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


    /*

        I need a way to determie whether v2 (antenna 2) is to the left or right of a1, it's always on the bottom 
        or the same line, so I only need to deal with the 'x' alignment.
            
            v1            |         v1
                          |
        v2          1     |               v2    -1
    
    */

    int32_t direction = v1.x < v2.x ? -1 : 1; // dir is 1 if v2 to the left, else -1.

    vector a1  = {.x = v1.x + direction * distance.x, .y = v1.y - distance.y};
    vector a2 =  {.x = v2.x +  -direction * distance.x, .y = v2.y + distance.y};
    /*
        The following if statements register the nodes as antinodes if they are not
        -already on the same spot as an other antinode.
    */
    if(uniquenessMap[v1.y][v1.x] != '1'){
            uniquenessMap[v1.y][v1.x] = '1';
            antiodeCount++;
        }
    if(uniquenessMap[v2.y][v2.x] != '1'){
            uniquenessMap[v2.y][v2.x] = '1';
            antiodeCount++;
        }

        /*
            The folloing while loops check for harmonics along the path
        */

    while(vectorInVector(&a1, &mapDims)){
        printf("a1 at y: %d x:%d\n", a1.y, a1.x);
        if(uniquenessMap[a1.y][a1.x] != '1'){
            uniquenessMap[a1.y][a1.x] = '1';
            antiodeCount++;
        }
        a1.x = a1.x + direction * distance.x;
        a1.y = a1.y - distance.y;
    }


    while(vectorInVector(&a2, &mapDims)){
        printf("a2 at y: %d x:%d\n", a2.y, a2.x);
        if(uniquenessMap[a2.y][a2.x] != '1'){
            uniquenessMap[a2.y][a2.x] = '1';
            antiodeCount++;
        }
        a2.x = a2.x + -direction * distance.x;
        a2.y = a2.y + distance.y; 
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