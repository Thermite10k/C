#include <stdio.h>
#define XMAX 100
#define YMAX 100
#define MIN(a, b) ((a < b) ? (a) : (b))
#define MAX(a, b) ((a > b) ? (a) : (b))

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
struct rect canonrect(struct rect r);
int main(){

   struct rect screen;
   struct point middle;


   screen.pt1 = makepoint(0, 0);
   screen.pt2 = makepoint(XMAX, YMAX);

    struct point p1 = makepoint(10, 20);
    struct point p2 = {30, 40};
    struct point p3 = addpoint(p1, p2);
    struct point p4 = {.y = 30, .x = 100};

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
    printf("%d\n", p4.x);

    struct rect notcanonical = {
        .pt1 = makepoint(10, 50),
        .pt2 = makepoint(25, 20)
    };

    printf("%d\n", notcanonical.pt1.x);
    printf("%d\n", notcanonical.pt1.y);
    printf("%d\n", notcanonical.pt2.x);
    printf("%d\n", notcanonical.pt2.y);
    notcanonical = canonrect(notcanonical);

    printf("%d\n", notcanonical.pt1.x);
    printf("%d\n", notcanonical.pt1.y);
    printf("%d\n", notcanonical.pt2.x);
    printf("%d\n", notcanonical.pt2.y);
    

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
/* 
    the ptinbounds assumes that the rect is in the standard or canonical form, that is 
    the coordinates of rect.pt1 < rect.pt2.
    let's write a function 
*/

struct rect canonrect(struct rect r){

    // if(!(r.pt1.x < r.pt2.x)  || !(r.pt1.y < r.pt2.y)){    
    //     //struct point temppt = {.x = r.pt1.x , .y = r.pt1.y}
    //     struct point temppt = makepoint(r.pt1.x, r.pt1.y);
    //     r.pt1 = r.pt2;
    //     r.pt2 = temppt;
    // }
    // return r;
    // this approcah does not consider the condition where only x or y is incorrect, it can be fixed with more if/elses but 
    // I'll use the approach from the book as it's more concise, offers brevity.
    
    struct rect temprect = {
        .pt1.x = MIN(r.pt1.x, r.pt2.x),
        .pt1.y = MIN(r.pt1.y, r.pt2.y),
        .pt2.x = MAX(r.pt1.x, r.pt2.x),
        .pt2.y = MAX(r.pt1.y, r.pt2.y)
    };

    return temprect;


}