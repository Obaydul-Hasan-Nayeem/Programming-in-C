/// Problem Statement
/*
One day Bablu went to the supermarket to buy a new phone. He was eagerly waiting for the launch of the Alien phone.
It has a 15000 mAh battery. Finally he bought it! The salesman told him that, if the charge is less than 60% then it will take 1 minute
to charge for every 1%. If the charge is less than 80% then it will take 2 minute to charge for every 1%.
And finally from 80% it will take 3 minutes to charge 1%.

Now he wants to calculate if the current charge is X% then how many minutes it will take to charge completely.
Can you calculate for him?

Input Format
The first line will contain an integer T, the number of test case.
For every test case, one line will contain an integer X, current percentage of charge in the battery.% sign will also given as input

Constraints
1 <= T <=101
0 <= X <= 100

Output Format
Output a single line for every test case, how many minutes it will take to charge completely and print "minutes" after it.
Don't forget to put a new line after it.

Sample Input 0
5
35%
88%
0%
100%
68%

Sample Output 0
125 minutes
36 minutes
160 minutes
0 minutes
84 minutes

Explanation 0
For the first test case, from 35% to 60% it will take 25 minutes.
From 60% to 80% it will take 40 minutes and from 80% to 100% it will take 60 minutes.
In total 25+40+60=125 minutes.
*/

/// Solution in C:
#include<stdio.h>
int main() {

   int t;
   scanf("%d", &t);

   int time;

   while(t--) {
       char crg[5];
       fgets(crg, sizeof(crg), stdin);

        int l = -1;
        for (int i = 0; crg[i] != '\0'; i++) {
           l++;
        }

        int charge = 0, x = 1;
        for (int i = l - 2; i >= 0; i--) {
            int c = crg[i] - '0';
            charge = charge + c * x;
            x *= 10;
        }

        scanf("%d", &charge);
        if (charge >= 80) {
            time = (100 - charge) * 3;
        }
        else if (charge >= 60 && charge < 80) {
            time = ((80 - charge) * 2) + ((100 - 80) * 3);
        }
        else if (charge < 60) {
            time = ((60 - charge) * 1) + ((80 - 60) * 2) + ((100 - 80) * 3);
        }
        printf("%d minutes\n", time);
   }

   return 0;
}
