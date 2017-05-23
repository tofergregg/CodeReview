Vector<int> bestRouteHelper(Grid<double> &distance, Vector<int> &cities, Vector<int> &route, int startCity, double min){
	if (cities.size()==0){
		//adds the start city to the end
		route.add(route(0));
		return route;
	}
	for (int i = 0; i <cities.size(); i++){
		int city = cities[i];
		cities.remove(i);
		route.add(i)
		Vector<int> nextRoute =  bestRouteHelper (distance, cities, route, 	city, min);
		
		double currValue = totalRouteDistance (distance, nextRoute);
		if (currValue<min){
			return bestRouteHelper (distance, cities, route, city, currValue);
		}
		cities.insert (i,city);
	}
}



Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> cities;
	Vector<int> route;
	route.add(startCity);
	for (int i = 0; i < distance.numRows(); i++){
		cities.add (i);
		if (i == startCity){
			cities.remove(i);
		}
	}
	double min = DBL_MAX;
	bestRouteHelper (distance, cities, route, startCity, min);
}

