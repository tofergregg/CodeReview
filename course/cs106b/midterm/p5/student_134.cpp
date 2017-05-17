Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> best;
	HashSet<int> remainingCities;
	Vector<int> curRoute;
	curRoute.add(startCity);
	for(int i = 0; i < distance.numCols(); i++){
		remainingCities.add(i);
	}
	findRoute(distance, remainingCities, best, curRoute);
	return bestRoute;
}

void findRoute(Grid<double> &distance, HashSet<int> &remainingCites, Vector<int> &best, Vector<int> &curRoute){
	remainingCities.remove(curRoute[curRoute.size()-1]);
	if(remainingCities.isEmpty()){
		curRoute.add(curRoute[0]);
		if(!best.isEmpty() || totalRouteDistance(distance, curRoute) < totalRouteDistance(distance, best)){
			best = curRoute;
		}
	}else{
		for(int nextCity : remainingCities){
			curRoute.add(nextCity);
			findRoute(distance, remainingCities, bestRoute, curRoute, startCity);
			curRoute.remove(nextCity);
		}
	}
	remainingCities.add(curRoute[curRoute.size()-1]);
}