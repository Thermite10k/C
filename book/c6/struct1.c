#include <stdio.h>

/*
    the keyword struct introduces a structure declaration
    which can be followed by an optional name called 
    structure tag.

    the variables named in the structore are called members
    a structure member, structure tag, and an ordinary
    variable can have the same name without conflicts
    as they can always be distinguished by context.

*/
struct point {
    int x;
    int y;
};


/*
    makepoint: make a point form x, y components and return a struct
*/
struct makepoint(int x, int y){
    struct point temp;

    temp.x = x;
    temp.y = y;
    return temp;
}

// a member of a structure can be accessed by '.' structure-name.member
int main(){
struct point pt; // pt is a structure of type struct point
struct point maxpt = {320, 200};
    pt.x = 29;

    printf("%d\n", pt.x);

    struct rect {
        struct point pt2;
        struct point pt1;
    };

    struct rect screen;

    screen.pt1.x = 100;
    printf("%d\n", screen.pt1.x);
    
    return 0;
}