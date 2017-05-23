Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	int numCities = distance.width();
	Vector<int> route = startCity;
	Set<int> visited;
	int dist = DBL_MAX;
	dist = travel(distance, visited, startCity, startCity, dist, numCities, route);
	return route;
}


int travel(const Grid<double>& distance, Set<int>& visited, const int startCity, int currCity, int &dist, const int numCities, Vector<int>& route) {
	
	//base cases
	if (currCity == startCity && visited.size() == numCities) {
		return route;
	} else if (visited.contains(nextCity)) {
		return DBL_MAX;
	} else if (currCity == startCity && visited.size() != numCities) {
		return DBL_MAX;
	}
	
	//recursive step: go to each city next (all options)
	for (int i = 0; i < numCities; i++) {
		int nextCity = (currCity + i) % numCities;
		visited.add(nextCity);
		route += nextCity;
		dist += distance[currCity][nextCity];
		route = travel(distance, visited, startCity, nextCity, dist, numCities);
		visited.remove(nextCity);
	}
	
	return dist;
}
