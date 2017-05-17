Struct route {
	Vector<int> order;
	double mileage;
};

Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	double best = DBL_MAX;
	route bestPath;
	bestPath.mileage = best;
	route path;
	path.order.add(startCity);
	path.mileage = 0;
	route shortest = bestRoute(distance, path, bestPath, startCity, startCity);
	return shortest.order;
}

route bestRoute(Grid<double> &distance, route path, route &bestPath, int currCity, int startCity) {
	for (int i = 0; i < distance.numCols(); i++) {
		route newPath = path;
		if (!newPath.order.contains(i)) {
			newPath.order.add(i);
			newPath.mileage += distance[currCity][i];
			bestRoute(distance, newPath, bestPath, i, startCity);
		}
		if (newPath.order.size() == distance.numCols()) {
			newPath.order.add(startCity);
			newPath.mileage += distance[i][startCity];
			if (newPath.distance < bestPath.mileage) {
				bestPath = newPath;
			}
		}
	}
	return bestPath;
}
	
