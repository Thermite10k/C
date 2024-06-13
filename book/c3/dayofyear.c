#include <stdio.h>
#define leap(year) year % 4 == 0 && year % 100 != 0 || year % 400 == 0

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31}
};

int dayofyear(int year, int month, int day);
int dayofyearptr(int year, int month, int day);

void monthday(int year, int yeaday, char *dp, char *mp);
void monthdayptr(int year, int yeaday, char *dp, char *mp);

char *mothname(int n);

int main(void){

    char data[2]; // 0 = day, 1 = month
    int day = dayofyearptr(1988, 2, 29);
    printf("%d\n", day); // expect 60
    monthdayptr(1988, day, &data[0], &data[1]);
    printf("%d th day in the year 1988 was %d th day of %s", day,data[0], mothname(data[1]) );

    return 0;
}

char *mothname(int n){
    static char *months[] = {
        "Illegal month", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sept", "Oct", "Dec"
    };
    return ((n > 12 || n < 1) ? months[0] : months[n]);
}

int dayofyear(int year, int month, int day){
    int i, isleap;

    isleap = leap(year);
    // if(leap){
    //     for(i = 1; i <  month; i++){
    //         day += daytab[1][i];
    //     }
    // }else{
    //     for(i = 1; i< month; i++){
    //         day += daytab[0][i];
    //     }
    // }
    for(i=1; i<month;i++){
        day += daytab[isleap][i];
    }

    return day;
}
int dayofyearptr(int year, int month, int day){
    int i, isleap;
    i = 0;
    isleap = leap(year);
    while(++i < month){
        day += *(*(daytab +isleap)+i);
    }
    return day;
}
void monthday(int year, int yearday, char *dp, char *mp){
    
    int isleap, i;

    isleap = leap(year);
    
    for(i=1; yearday > daytab[isleap][i]; i++){
        yearday -= daytab[isleap][i];
    }

    *dp = yearday;
    *mp = i;
}

void monthdayptr(int year, int yearday, char *dp, char *mp){
    int isleap, i;

    isleap = leap(year);
    i = 1;

    while(yearday > *(*(daytab + isleap)+i)){
        yearday -= *(*(daytab + isleap) + i);
        i++;
    }

    *dp = yearday;
    *mp = i;
}
