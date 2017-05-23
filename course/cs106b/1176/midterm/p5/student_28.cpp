Vector<int> bestRoute(Grid<double> &distance, int startCity) {
        Vector<int> currentRoute;
        // add startCity to best
        currentRoute.add(startCity);
        Vector<int> leftToVisit;

        // populate leftToVisit with cities;
        for (int i=0; i < distance.numCols(); i++) { // same as numRows()
                if (i != startCity) { // don't add start city
                        leftToVisit += i;
                }
        }
        Vector<int> bestOverall;
        bestRoute(distance, currentRoute, leftToVisit, bestOverall);
        return bestOverall;
}

double bestRoute(Grid<double> &distance, Vector<int> &currentRoute,
                Vector<int> &leftToVisit, Vector<int> &bestOverall) {
        double minDist;
        // base case
        if (leftToVisit.isEmpty()) {
                // return the current route's distance,
                // and consider this the best overall route
                minDist = totalRouteDistance(distance, currentRoute);
                bestOverall = currentRoute;

                // add start city to bestOverall
                int startCity = bestOverall[0];
                minDist += distance[bestOverall[bestOverall.size()-1]][startCity];
                bestOverall.add(startCity);
        } else {
                minDist = DBL_MAX;
                Vector<int> localBestRoute = bestOverall; // keep local best

                for (int i = 0; i < leftToVisit.size(); i++) {
                        // go through all remaining cities, removing one at a time
                        int currentCity = leftToVisit[i];
                        // add it to the current route
                        currentRoute.add(currentCity);

                        // remove it from the cities we still have to visit
                        leftToVisit.remove(i);

                        // recursively calculate the best route with the new city
                        double newDist = bestRoute(distance, currentRoute,
                                        leftToVisit, bestOverall);

                        // update minDist and the best route
                        if (newDist < minDist) {
                                minDist = newDist;
                                localBestRoute = bestOverall;
                        }
                        // backtrack:
                        // replace the city in the cities we have to visit
                        // and remove it from the current route
                        leftToVisit.insert(i,currentCity);
                        currentRoute.remove(currentRoute.size()-1);
                }
                // once we finish the loop, we have a best route
                bestOverall = localBestRoute;
        }
        return minDist;
}
