Vector<int> helper(Grid<double> &distance, int startCity, int n, double & bestDist, Vector<int> route, Set<int> visitedCities);
	
Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	int n = distance.numRows();
	Vector<int> route;
	Set<int> visitedCities;
	double bestDist = DBL_MAX;
	return bestRoute = helper(distance, startCity, n, bestDist, route,visitedCities);
}

Vector<int> helper(Grid<double> &distance, int startCity, int n, double & bestDist, Vector<int> route, Set<int> visitedCities)	{
	// base cases
	if (visitedCities.size() == n)	{
		return route;
	}
	if (visitedCities.size() == n - 1)	{
		Vector<int> newVect = route;
		newVect.add(startCity);
		Set<int> newSet = visitedCities;
		newSet.add(startCity);
		return helper(distance, startCity, n, bestDist, newVect, newSet);
	}
	// recursive case
	for (int i = 0; i < n; i++)	{
		if (!visitedCities.contains(i) && i != startCity)	{
			Vector<int> newVect = route;
			newVect.add(i);
			Set<int> newSet = visitedCities;
			newSet.add(i);
			Vector<int> backVect = helper(distance, startCity, n, bestDist, newVect, newSet);
			double dist = totalRouteDistance(distance, backVect);
			if (dist <= bestDist)	{
				bestDist = dist;
				return backVect;
			}
		}
	}
}
