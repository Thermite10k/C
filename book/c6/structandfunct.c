#include <stdio.h>
#define XMAX 100
#define YMAX 100


struct point {
    int x;
    int y;
};
struct rect {
    struct point pt1;
    struct point pt2;
};
struct  point makepoint(int x, int y);
struct point addpoint(struct point pt1, struct point pt2);
int ptinbounds(struct rect rec, struct point p);

int main(){

   struct rect screen;
   struct point middle;


   screen.pt1 = makepoint(0, 0);
   screen.pt2 = makepoint(XMAX, YMAX);

    struct point p1 = makepoint(10, 20);
    struct point p2 = {30, 40};
    struct point p3 = addpoint(p1, p2);

   middle = makepoint(
    ((screen.pt1.x + screen.pt2.x)/2),
    ((screen.pt1.y + screen.pt2.y)/2));

    printf("%d\n", middle.x);
    printf("%d\n", middle.y);
    printf("x: %d, y: %d\n", p3.x, p3.y);

    struct point out = makepoint(102, 102);
    struct point in = makepoint(middle.x, middle.y);
    printf("%d\n", ptinbounds(screen, in));
    printf("%d\n", ptinbounds(screen, out));

    return 0;
}

struct point makepoint(int x, int y){
    struct point temp;
    temp.x = x;
    temp.y = y;

    return temp;
}

struct point addpoint(struct point pt1, struct point pt2){
    pt1.x += pt2.x;
    pt1.y += pt2.y;

    return pt1;
}
int ptinbounds(struct rect rec, struct point p){
    return(
        ((p.x >= rec.pt1.x)&&(p.x < rec.pt2.x)) && 
        ((p.y >= rec.pt1.y)&&(p.y <= rec.pt2.y))
        );
}