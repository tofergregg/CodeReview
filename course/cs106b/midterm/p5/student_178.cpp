Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> bestRoute;
	Set<int> citiesVis;
	return findBestRoute(distance, route, citiesVis, startCity, startCity, DBL_MAX);
}

void findBestRoute(Grid<double> &distance, Vector<int> &route, Set<int> &citiesVis, int currCity, int startCity, double &routeDist){
	
	if(currCity == startCity && citiesVis.size() == distance.height() + 1){
		if(totalRouteDistance(distance, route) < routeDist){
			routeDist = totalRouteDistance(distance, route);
			return;
		}
	}
	
	for(int i = 0; i < distance.height(); i++){
		if(!citiesVis.contains(i)){
			route.add(distance[currCity][i]);
			citiesVis.add(i);
			findBestRoute(distance, route, citiesVis, i, startCity, routeDist);
		}
	}
}