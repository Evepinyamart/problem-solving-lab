#include <iostream>
using namespace std;

int main(void)
{
    int n, swp, exc;
    int sw[100001], status[1000001]; // item i (index) being hold by who (value)
    int maxRound = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> exc;
        sw[i] = exc - 1;
    }

    for (int i = 0; i < n; i++)
    {
        int round = 1;
        int holdBy = sw[i];
        // hold will represent who currently hold item i
        //  1st round of swaping ended
        if (status[i] != 1)
        {
            // go through the entire circle, we will get the # minimum round required for every person in circle to get their specific gift at least 1 time
            while (i != holdBy)
            {
                status[holdBy] = 1;
                holdBy = sw[holdBy];
                round++;
            }
            if (maxRound < round)
            {
                maxRound = round;
            }
        }
    }

    cout << maxRound;

    return 0;
}