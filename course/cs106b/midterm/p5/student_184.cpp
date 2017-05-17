Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	double min = DBL_MAX;
	Vector<int> path;
	Vector<int> bestPath;
	Vector<int> citiesLeft; 
	int currCity = startCity;
	
	for(int i = 1; i<distance.getCols(); i++){
		citiesLeft.set(i);
	}
	
	return bestRouteHelper(startCity, currCity, bestPath, citiesLeft);
		
		
	
	
		//Use this helper recursively to test different permutations of paths, choosing, exploring, and removing each time to test each case. Then, compare which path is shortest and return that vector. 
	Vector<int> bestRouteHelper(Vector<int> &route){
		//basecase: path from 0 to 0
		if(route[0]==0){
			for
			
	
	
