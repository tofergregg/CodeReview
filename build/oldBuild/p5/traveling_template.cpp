// Traveling Salesman 

#include <iostream>
#include "simpio.h"  // for getLine
#include "vector.h"  // for Vector
#include "stack.h"
#include "queue.h"
#include "map.h"
#include "set.h"
#include "hashset.h"
#include "hashmap.h"
#include "grid.h"
#include <cfloat> // for DBL_MAX

using namespace std;

Vector<int> bestRoute(Grid<double> &distance, int startCity);
double bestRoute(Grid<double> &distance, Vector<int>&route,
                Vector<int> &leftToVisit, Vector<int> &bestOverall);
double totalRouteDistance(Grid<double> &distance, Vector<int> &route);

struct Solution {
        Grid<double> distance;
        Vector<int> solution;
};

int main() {
        Vector<Solution> solutions; 
        Grid<double> distance1 = {{0,10,15,20},
                {10,0,35,25},
                {15,35,0,30},
                {20,25,30,0}};
        Vector<int> solution1 = {0, 1, 3, 2, 0};
        solutions.add({distance1,solution1});

        Grid<double> distance2 = {{0,3,5,2},
                {3,0,9,10},
                {5,9,0,1},
                {2,10,1,0}};
        Vector<int> solution2 = {0, 1, 2, 3, 0};
        solutions.add({distance2, solution2});

        Grid<double> distance3 = {{0,13,5,2,21},
                {13,0,9,4,9},
                {5,9,0,1,21},
                {2,4,1,0,7},
                {21,9,21,7,0}};
        Vector<int> solution3 = {0, 2, 1, 4, 3, 0};
        solutions.add({distance3, solution3});

        // from here: https://developers.google.com/optimization/routing/tsp/tsp
        //    Grid<double> distance = {{   0, 2451,  713, 1018, 1631, 1374, 2408,  213, 2571,  875, 1420, 2145, 1972}, // New York 0
        //       {2451,    0, 1745, 1524,  831, 1240,  959, 2596,  403, 1589, 1374,  357,  579}, // Los Angeles 1
        //       { 713, 1745,    0,  355,  920,  803, 1737,  851, 1858,  262,  940, 1453, 1260}, // Chicago 2
        //       {1018, 1524,  355,    0,  700,  862, 1395, 1123, 1584,  466, 1056, 1280,  987}, // Minneapolis 3
        //       {1631,  831,  920,  700,    0,  663, 1021, 1769,  949,  796,  879,  586,  371}, // Denver 4
        //       {1374, 1240,  803,  862,  663,    0, 1681, 1551, 1765,  547,  225,  887,  999}, // Dallas 5
        //       {2408,  959, 1737, 1395, 1021, 1681,    0, 2493,  678, 1724, 1891, 1114,  701}, // Seattle 6
        //       { 213, 2596,  851, 1123, 1769, 1551, 2493,    0, 2699, 1038, 1605, 2300, 2099}, // Boston 7
        //       {2571,  403, 1858, 1584,  949, 1765,  678, 2699,    0, 1744, 1645,  653,  600}, // San Francisco 8
        //       { 875, 1589,  262,  466,  796,  547, 1724, 1038, 1744,    0,  679, 1272, 1162}, // St. Louis 9
        //       {1420, 1374,  940, 1056,  879,  225, 1891, 1605, 1645,  679,    0, 1017, 1200}, // Houston 10
        //       {2145,  357, 1453, 1280,  586,  887, 1114, 2300,  653, 1272, 1017,    0,  504}, // Phoenix 11
        //       {1972,  579, 1260,  987,  371,  999,  701, 2099,  600, 1162,  1200,  504,   0}}; // Salt Lake City 12
        // (takes half an hour +)
        // minimum distance = 7293
        // route = New York -> Boston -> Chicago -> Minneapolis -> Denver -> Salt Lake City -> Seattle ->
        //         San Francisco -> Los Angeles -> Phoenix -> Houston -> Dallas -> St. Louis -> New York
        // route = [0,7,2,3,4,12,6,8,1,11,10,5,9,0]

        Grid<double> distance4 = {{0,36,32,54,20,40},
                {36,0,22,58,54,67},
                {32,22,0,36,42,71},
                {54,58,36,0,50,92},
                {20,54,42,50,0,45},
                {40,67,71,92,45,0}};
        Vector<int> solution4 = {0, 1, 2, 3, 4, 5, 0};
        solutions.add({distance4, solution4});
        // min distance: 229
        // route: [0,1,2,3,4,5,0]

        Grid<double> distance5 = {{0,3,5,10000,10000,10000,3},
                {3,0,3,7,10000,10000,11},
                {5,3,0,3,10000,10000,10000},
                {10000,7,3,0,3,9,11},
                {10000,10000,10000,3,0,3,10000},
                {10000,10000,10000,9,3,0,3},
                {3,11,10000,11,10000,3,0}};
        Vector<int> solution5 = {0, 1, 2, 3, 4, 5, 6, 0};
        solutions.add({distance5, solution5});
        // min distance: 21
        // route: [0,1,2,3,4,5,6,0]

        bool allCorrect = true;
        for (Solution solution : solutions) {
                Vector<int> best = bestRoute(solution.distance,0);
                if (best != solution.solution) {
                        cout << "INCORRECT SOLUTION:" << endl;
                        cout << "\texpected:";
                        cout << solution.solution; 
                        cout << " got: " << best << endl;
                        allCorrect = false;
                } else {
                        cout << "Correct: " << best << endl;
                        //cout << "min distance: " << totalRouteDistance(solution.distance, best) << endl;
                        cout << endl;
                }
        }
        if (allCorrect) {
                cout << "ALL CORRECT!" << endl;
        } else {
                cout << "SOME INCORRECT!" << endl;
        }
        cout << endl;
        return 0;
}

//Vector<int> bestRoute(Grid<double> &distance, int startCity) {
//        Vector<int> currentRoute;
//        // add startCity to best
//        currentRoute.add(startCity);
//        Vector<int> leftToVisit;
//
//        // populate leftToVisit with cities;
//        for (int i=0; i < distance.numCols(); i++) { // same as numRows()
//                if (i != startCity) { // don't add start city
//                        leftToVisit += i;
//                }
//        }
//        Vector<int> bestOverall;
//        bestRoute(distance, currentRoute, leftToVisit, bestOverall);
//        return bestOverall;
//}
//
//double bestRoute(Grid<double> &distance, Vector<int> &currentRoute,
//                Vector<int> &leftToVisit, Vector<int> &bestOverall) {
//        double minDist;
//        // base case
//        if (leftToVisit.isEmpty()) {
//                // return the current route's distance,
//                // and consider this the best overall route
//                minDist = totalRouteDistance(distance, currentRoute);
//                bestOverall = currentRoute;
//
//                // add start city to bestOverall
//                int startCity = bestOverall[0];
//                minDist += distance[bestOverall[bestOverall.size()-1]][startCity];
//                bestOverall.add(startCity);
//        } else {
//                minDist = DBL_MAX;
//                Vector<int> localBestRoute = bestOverall; // keep local best
//
//                for (int i = 0; i < leftToVisit.size(); i++) {
//                        // go through all remaining cities, removing one at a time
//                        int currentCity = leftToVisit[i];
//                        // add it to the current route
//                        currentRoute.add(currentCity);
//
//                        // remove it from the cities we still have to visit
//                        leftToVisit.remove(i);
//
//                        // recursively calculate the best route with the new city
//                        double newDist = bestRoute(distance, currentRoute,
//                                        leftToVisit, bestOverall);
//
//                        // update minDist and the best route
//                        if (newDist < minDist) {
//                                minDist = newDist;
//                                localBestRoute = bestOverall;
//                        }
//                        // backtrack:
//                        // replace the city in the cities we have to visit
//                        // and remove it from the current route
//                        leftToVisit.insert(i,currentCity);
//                        currentRoute.remove(currentRoute.size()-1);
//                }
//                // once we finish the loop, we have a best route
//                bestOverall = localBestRoute;
//        }
//        return minDist;
//}

double totalRouteDistance(Grid<double> &distance, Vector<int> &route) {
        int routeSize = route.size();
        if (routeSize == 0) {
                return DBL_MAX;
        }
        double totalDistance = 0;
        for (int i=0; i < routeSize-1; i++) {
                int city1 = route[i];
                int city2 = route[i+1];
                totalDistance += distance[city1][city2];
        }
        return totalDistance;
}

