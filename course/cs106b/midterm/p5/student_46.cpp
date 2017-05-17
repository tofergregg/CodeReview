Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Set<int> citiesVisited();
	citiesVisited.add(startCity);
	int total=0;
	int bestSoFar=DBL_MAX;
	Stack<int> route();
	goToRemainingCities(distance, citiesVisited, startCity, total, bestSoFar, route);
	route.push(startCity);
	Vector<int> best();
	while(!route.isEmpty){
		best.add(route.pop());
	}
	return best;

	


bool goToRemainingCities(Grid<double> &distance, Set<int>& citiesVisited, int startCity, int currentCity, int total, int bestSoFar, Stack<int> & route()){
	if(citiesVisited.size()==distance.width()){
		total+=distance[currentCity][startCity];
		if(total<bestSoFar){
			while(!route.isEmpty){
				route.pop();
			}
			route.push(startCity);
			route.push(currentCity); 
			return true;	
		} else {
			return false;
	} else {
		for(int c=0; c<distance.width(); r++){
			if(!citiesVisited.contains(c)){
				total+=distance[currentCity][c];
				citiesVisited.add(c);
				if(goToRemainingCities(distance, citiesVisited, startCity, c, total, bestSoFar, route)){
				route.push(c);
				return true;	
				}
			}
		}
		return false;	
	}
}
	