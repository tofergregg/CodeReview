Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	HashMap<int, Vector<int>> hmap;
	double min = DBL_MAX;
	for (int i = 0; i < distance.nCols()^2; i++) {
		Vector<int> route = bestRoute(distance,{startCity}, startCity, startCity);
		double dis = totalRouteDistance(distance, route);
		if (dis < min) {
			min = dis;
		}
		hmap.add(dis, route);
	}
	return map[min];
}

Vector<int> bestRoute(Grid<double> &distance, Vector<int> used, int current, int original) {
	if (current == original && used.size() == distance.numCols() - 1) {
		used += original;
		return used;
	}
	if (used.size() > distance.numCols() - 1) return {DBL_MAX};
	for (int c = current + 1; c < distance.numCols(); c++) {
		if (!used.contains(c)) {
			used += c;
			bestRoute(distance, used, c, original);
		}
	}
}
				