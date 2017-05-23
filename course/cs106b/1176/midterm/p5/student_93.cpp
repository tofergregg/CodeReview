Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> testRoute;
	double shortest = DBL_MAX;
	int currenCity;
	Set<int>cityNumbers;
	for(i=0; i<distance.numRows(); i++)
		cityNumbers.add(i);
	findRoute(distance, cityNumbers, currentCity, startCity, shortest);
	
	
	
	void findRoute(Grid<double> &distance, Vector<int> cityNumbers, int currentCity, int startCity, double shortest){
	Vector<Vector<int>>allRoutes;
	Vector<int> bestPossibleRoute;
	if(currentCity = startCity){
		testRoute.add(startCity);
		allRoutes.add(testRoute);
	}else{
		testRoute.add(startCity);
		cityNumbers.remove(startCity);
		for(int j = 0; j<cityNumbers.size(); j++){
			if(cityNumbers.contains(j){
				testRoute.add(j);
				cityNumbers.remove(j);
			}
			findRoute(cityNumbers,j,startCity);
		}
		cityNumbers.add(j);
	for(Vector<int> selected : allRoutes){
		if(totalRouteDistance(distance,selected) <shortest){
			selected=bestPossibleRoute;
		}
	}
	return bestPossibleRoute;
			  
	
	
			