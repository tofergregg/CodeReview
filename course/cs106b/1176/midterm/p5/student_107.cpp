Vector<int> bestRoute(Grid<double> &distance, int startCity){
	Vector<int> quick;
	Vector<int> cities;
	Vector<int> checker;
	for(int i = 0; i < distance.numCols(); i++){
		cities.add(i);
	}
	bestRoute(distance, startCity, 0, quick, cities, DEL_MAX, 				checker);
	return quick;
}

void bestRoute(Grid<double> &distance, int startCity, 						int current, Vector<int> &quick, Vector<int> &cities, double 		longest, Vector<int> &checker){
	
	if(cities.isEmpty()){
		if(totalRouteDistance(distance, checker)<longest){
			longest = totalRouteDistance(distance, quick)
			quick = checker;
		}
	}else{
		int val = cities[0];
		cities.remove[0];
		for(int r = 0; r < distance.numRows(); r++){
			for(int c= 0; c< distance.numCols(); c++){
				if (val == startCity) break;
				bestRoute(distance, startCity, val, quick, cities, 					longest, checker);
			}
		}
		cities.insert(0, val);
	}
		
}