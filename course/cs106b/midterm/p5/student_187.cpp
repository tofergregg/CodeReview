void bestRoute(Grid<double> &distance, int startCity, int currentCity, 		Vector<int> &alreadyBeen, Vector<int> &route, Map<double, Vector<int>> &allDistances); 

Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<bool> alreadyBeen;
	for (int i = 0; i < 60; i++) {
		alreadyBeen.add(false);
	}
	Vector<int> route;
	route.add(startCity);
	Map<double, Vector<int>> allDistances;
	bestRoute(distance, startCity, startCity alreadyBeen, route, 			allDistances);
	double minDistance = DBL_MAX;
	for (double dist : allDistances) {
		if (dist < minDistance) {
			minDistance = dist; 
		}
	}
	return allDistances.get(minDistance);		
}

void bestRoute(Grid<double> &distance, int startCity, int currentCity 		Vector<int> &alreadyBeen, Vector<int> &route, Map<double, Vector<int>> &allDistances) {
	if(startCity == currentCity && beenEverywhere
		allDistances.put(totalRouteDistance(distance, route), route);
	} else {
		for (int i = 0; i < alreadyBeen.size(); i++) {
			if (alreadyBeen[i] == false) {
				route.add(i);
				alreadyBeen[i] == true;
				bestRoute(distance,startCity,i, alreadyBeen,route,allDistances);	
			}
		}
	}
}
				
