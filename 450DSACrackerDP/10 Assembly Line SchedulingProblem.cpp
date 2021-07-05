//Assembly Line Scheduling | DP-34 | DP on graph
#include <iostream>
using namespace std;
#define NUM_LINE 2
#define NUM_STATION 4
int carAssembly(int a[][NUM_STATION],int t[][NUM_STATION],int *e, int *x){
    int T1[NUM_STATION], T2[NUM_STATION], i;
    T1[0]=a[0][0]+e[0];
    T2[0]=a[1][0]+e[1];
    for(int i=1;i<NUM_STATION;i++){
       T1[i]= a[0][i] + min(T1[i-1],T2[i-1]+t[1][i]);
       T2[i]= a[1][i] + min(T2[i-1],T1[i-1]+t[0][i]);
    }
    return min(T1[NUM_STATION-1]+x[0] , T2[NUM_STATION-1]+x[1]);
}

int main() {
    //cost of each station
    int a[][NUM_STATION] = {{4, 5, 3, 2},
                            {2, 10, 1, 4}};
    //Transaition time
    int t[][NUM_STATION] = {{0, 7, 4, 5},
                            {0, 9, 2, 8}};
    //starting time and ending time
    int e[] = {10, 12}, x[] = {18, 7};
 
    cout << carAssembly(a, t, e, x);

    return 0;
}
