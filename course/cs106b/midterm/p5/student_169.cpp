Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> options;
	for(int i = 0; i < distance.size()[0]; i++){
		options.add(i);
	}
	options.remove(startCity)
	Vector<int> bestPoss = bestRoute(distance, startCity, options, DBL_MAX);
	bestPoss.insert(0, startCity);
	return bestPoss;
}

Vector<int> bestRoute(Grid<double> &distance, 
					  int startCity,
					  int endCity
					  Vector<int> &options, 
					  int minLength
					  double lengthSoFar){
	int localMinLength = minLength;
	Vector<int> localBestRoute;
	//base case: nowhere left to go, must return to starting point
	if(options.size()==0){
		Vector<int> route;
		route.add(endCity);
		return route; 
	}
	else{
		for(int i = 0; i < options.size(); i++){
			int nextPt = options[i]; //choose
			options.remove(i); //remove choice
			double newLength = lengthSoFar+distance[startCity, nextCity];
			Vector<int> currRoute = bestRoute(&distance, 
											  nextPt,
											  endCity,
											  options, 
											  minLength,
											  newLength
											  );
			currRoute.insert(0, nextPt);
			double currLength = totalRouteDistance(distance, currRoute)+newLength;
			if(currLength<localMinLength){
				localMinLength = currDist;
				localBestRoute = currRoute;
			}
			options.insert(i, nextPt)//unchoose
		}
		return localBestRoute;
	}
}

