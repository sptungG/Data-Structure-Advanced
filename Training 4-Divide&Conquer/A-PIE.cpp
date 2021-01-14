/*My birthday is coming up and traditionally I'm serving pie.
Not just one pie, no, I have a number N of them, of various tastes and of various sizes.
F of my friends are coming to my party and each of them gets a piece of pie.
This should be one piece of one pie, not several small pieces since that looks messy.
This piece can be one whole pie though.
My friends are very annoying and if one of them gets a bigger piece than the others, they start complaining.
Therefore all of them should get equally sized (but not necessarily equally shaped) pieces,
even if this leads to some pie getting spoiled (which is better than spoiling the party).
Of course, I want a piece of pie for myself too, and that piece should also be of the same size.
What is the largest possible piece size all of us can get?
All the pies are cylindrical in shape and they all have the same height 1, but the radii of the pies can be different.
**Input
One line with a positive integer: the number of test cases. Then for each test case:
One line with two integers: N and F with 1≤N,F≤10000: the number of pies && the number of friends.(25% of tests has N,F≤10 and 25% of test has solution ≤0.1.)
One line with N integers ri with 1≤ri≤10000: the radii of the pies.
**Output
For each test case, output one line with the largest possible volume V (such that me and my friends can all get a pie piece of size V).
The answer should be given as a floating point number rounding to 6 digits after the floating point (accept error ≤10^−6).
TEST
++in
1
1 10000
3
++OUT
0.002827
---------------------------------*/
#include <iostream>
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

#define EPS 0.0000001f
#define MAX 10001

int noOfCases;
int N, F;
float d[MAX];
float sumVol;

void init() {
    sumVol = 0;
    cin >> N >> F;
    F++;
    for (int i = 1; i <= N; i++) {
        cin >> d[i];
        d[i] = d[i] * d[i]* M_PI;
        sumVol += d[i];
    }
    /*
    cout << endl;
    for (int i = 0; i < N; i++) {
        printf("d[%d] = %f, ", i, d[i]);
    }
    printf("sumVol = %f", sumVol);
    */
}

short check(float v) {
    int toBeFed = F;
    //cout << "\ntoBeFed = " << toBeFed;
    for (int i = 1; i <= N; i++) {
        toBeFed -= floor(d[i] / v);
        //cout << endl << "v = " << v << ", no floor = " << d[i] / v << ", floor = " << floor(d[i] / v);
        //printf("\nv = %f, tobeFed = %d, i = %d", v, toBeFed, i);
    }
    if (toBeFed > 0)
        return 1; // thua nguoi
    else 
        return -1; // thua banh
}

void solve() {
    int num = 0;
    float mid, low = 0, high = sumVol / F;
    short retval;
    while (high - low > EPS && num++ < 100) {
        mid = (low + high)/2;
        retval = check(mid);

        //printf("\nhigh = %f, low = %f, mid = %f, check = %d", high, low, mid, retval);
        if (retval == 1)
            high = mid;
        else
            low = mid;
    }
    //cout << endl;
    printf("%.6f", mid);
}

int main() {
    cin >> noOfCases;
    for (int i = 0; i < noOfCases; i++) {
        init();
        solve();
        if (i != noOfCases - 1)
            cout << endl;
    }
}