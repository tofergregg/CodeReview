Vector<Vector<int>> bestRouteHelper(Grid<double> distance, int startCity, 			Vector<int>& cityVec, Vector<Vector<int>>& result, 						Vector<int>& allCities);

Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> allCities;
		for (int i = 0; i < distance.numCols(); i++) {
			allCities.add(i);
		}
		allCities.remove(startCity);
	Vector<int> cityVec;
	cityVec.add(startCity);
	Vector<Vector<int>> result;
	result = bestRouteHelper(distance, startCity, cityVec, result, 				Vector<int>& allCities);
	double bestDistance = DBL_MAX
	Vector<int> bestVector;
		for (Vector<int> singleVec: result) {
			if (totalRouteDistance(distance, singleVec) < bestDistance) {
				bestDistance = totalRouteDistance(distance, singleVec);
				bestVector = singleVec;
			}
		}
	return singleVec;
}

Vector<Vector<int>> bestRouteHelper(Grid<double> distance, int startCity, 			Vector<int>& cityVec, Vector<Vector<int>>& result,Vector<int>& allCities) {
	
	// base case
	if (cityVec.size() == distance.numCols()) {
		cityVec.add(startCity);
		result.add(cityVec);
		cityVec.clear();
	}

	// recursive case
	} else {
		int currCity = allCities.get(0);
		allCities.remove(0);
			for (int i = 0; i < allCities.size(); i++) {
				cityVec.add(i);
				bestRouteHelper(distance, startCity, cityVec, result, 						allCities);
			}
		allCities.add(currCity);
	}
}


	
	
