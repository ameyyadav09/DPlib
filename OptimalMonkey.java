/*
Created on Wed Jan  31 11:11:20 2018
@author: amey

In a garden, trees are arranged in a circular fashion with an equal distance between two adjacent trees. Height of trees may vary.
Two monkeys live in that garden should take maximum possible time to reach him.

The conditions are that a monkey cannot directly jump from one tree to other. There are 30 trees in the garden. If the height of a
tree is H, a monkey can live at any height from 0 to H. Lets say he lives at the height of K then it would take him K unit of time
to climb down to the ground level. Similarly if a monkey wants to climb up to K height it would again take K unit of time. Time to
travel between two adjacent tree is 1 unit.

So the question is where should two monkeys live such that the traveling time between them is maximum while choosing the shortest
path between them in any direction clockwise or anti-clockwise. You have to answer only the maximum traveling time.
Input Format
You will be given an integer array representing the height of trees in clock wise fashion.

Constraints
1 <= Total Trees <= 30
1 <= Height Of Trees(H) <= 10000

Output Format
You must print an integer which will be the maximum possible travel time.

sample:
4
1
2
3
4
output:
8
*/

import java.io.BufferedReader;
import java.io.InputStreamReader;
class Solution {
    public static int getMax(int [] heights, int n) {
        int [][] res = new int[n+1][n+1];
        for(int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) {
                    res[i][j] = 0;
                }
                else {
                    //finding min distance in clock-wise and anti-clock-wise
                    int dis = (i == j)?0:Math.min(n-Math.abs(i-j),  Math.abs(i-j));
                    //finding max steps
                    res[i][j] = Math.max(heights[i-1]+heights[j-1]+dis, Math.max(res[i-1][j-1], Math.max(res[i-1][j], res[i][j-1])));
                }
            }
        }
        return res[n][n];
    }

    public static void main(String ... args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int [] heights = new int[n];
        int i = 0;
        while(i < n) {
            heights[i++] = Integer.parseInt(br.readLine());
        }
        System.out.println(getMax(heights, n));
    }
}
