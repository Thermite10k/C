#include <stdio.h>
#define N_ENTRIES  sizeof(maxTime) / sizeof(maxTime[0])
/*
    NAMING CONVENTION
    ≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡
    DEFINE_SOMETHING
    a_function()
    myVariable - exception for two char vars such as dx, Vy, etc
    ≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡
*/

/*
    d = (maxTime - t) * t => maxTime.t - t^2
    d > minDistance ? win
    dd/dt = 0 ? END, total options = 2 * #winners

*/



int main(){

    //long long nEntries = 4;
    long long maxTime[] = {40929790};
    long long minDistance[] = {215106415051100};
    
    long long distanceCovered = 0;
    long long lastDistanceCovered = 0; // used to check dd/dt
    long long i = 0;
    long long winningOption = 0; // is the time enough to win?
    long long totalAnswer = 1;
    long long pushTime = 0, minimumDistance = 0, totalTime;
    /*
    
        time = total time (maxTime[i])
        distanceCovered = time - pushTime * pushTime
        minimumDistance = minDistance[i]
    */
    
    for(i = 0; i < N_ENTRIES; i++){
        totalTime = maxTime[i];
        minimumDistance = minDistance[i];
        winningOption = 0;
        for(pushTime = 0; pushTime <= totalTime; pushTime++){
            if((distanceCovered = ((totalTime - pushTime) * pushTime)) > minimumDistance){
                // if(lastDistanceCovered  > 0 && (lastDistanceCovered >= distanceCovered)){
                //     break;
                // }
                winningOption++;
                lastDistanceCovered = distanceCovered;

            }
        }
        // if(winningOption % 2){ // if is odd
        //     winningOption = (winningOption * 2) - 1;
        // }else{
        //     winningOption *= 2;
        // }
        printf("%lld\n", winningOption);
        if(winningOption){
            totalAnswer *= (winningOption);
        }
        winningOption = 0;

    }

    printf("Answer: %lld\n", totalAnswer);
        

    return 0;
}