Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> bestRoute;
	Set<int> allCities;
	Vector<int> Route;
	for(int i = 0; i < distance.numRows(); i++){
		allCitieas.add(i);
	}		
	double bestDistance = DBL_MAX;
	bestRoute.add(startCity);
	allCities.remove(startCity);
	bestRouteHelper(distance,startCity,Route,bestDistance,bestRoute);
	return bestRoute;
}
		
void bestRouteHelper(Grid<double> &distance, int startCity, Vector<int>& Route, Set<int>& allCities, double& bestDistance,Vector<double>& bestRoute){
	if(allCities.isEmpty()){
		double distance = totalRouteDistance(distance,Route);
		if(distance < bestDistance){
			bestDistance == distance;
			bestRoute = Route;
			
		}
	}
	else{
		for(int j = 0; j < allCities.size();j++){
			if(allCities.contains(i)){
				allCities.remove(i);
				Route.add(i);
			    (distance,startCity, bestRoute, allCities,bestDistance,bestRoute);
				Route.remove(i);
			}
		}	
	}
}

