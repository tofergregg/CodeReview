Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> currRoute;
	currRoute += startCity;
	return bestRouteHelper(distance, startCity, currRoute, DBL_MAX);;
}

Vector<int> bestRouteHelper(Grid<double> &distance, int currCity, Vector<int> currRoute, double bestRouteDist) {
	if (!currRoute.isEmpty() && currRoute[0] == currRoute[currRoute.size() - 1]) {
		double dist = totalRouteDistance(distance, currRoute);
		if (dist < bestRouteDist) return currRoute;
	} else {
		int cities = distance[currCity].size();
		int nextCity = distance[currCity][currCity + 1 % cities];
		currRoute += nextCity;
		double dist = totalRouteDistance(distance, currRoute);
		bestRouteHelper(distance, nextCity, currRoute, dist);
	}		
}

