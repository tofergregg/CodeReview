Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<string> path;
	Vector<int> cities;
	for(int i=0; i<distance.numCols(); i++) {
		if(i!=startCity) { // don't add in the start city to the remaining cities
			cities+=i;
		}
	}
	path = bestRouteHelper(distance, cities, path, 0);
	path.insert(0,startCity); // make path begin with startcity
	path+=startCity); // make path end with startcity
	return path;
}
	
Vector<int> bestRouteHelper(Grid<double> &distance, Vector<int> &cities, Vector<int> &path, int &currLength) {
	// base case
	if(cities.size()==0) { 
		int distance = totalRouteDistance(distance, path);
		if(distance < currLength){ // if path length is less than current length, return that path
			currLength=distance;
			return path;
		}
	}
	
	// recursive case
	for(int city : cities) {
		path+=cities[city];// add current city to the path
		cities.remove[city];// remove current city from list
		bestRouteHelper(distance, cities, path, currLength);
		path.remove(path.size()-1);
		cities.insert(city,city);
	}
}

