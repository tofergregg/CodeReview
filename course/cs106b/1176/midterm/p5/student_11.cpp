Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> vect = bestRouteHelper(distance, startCity, vect);
	return vect;
}

Vector<int> bestRouteHelper(Grid<double> &distance, int startCity, Vector<int>& vec) {
		if (startCity == vec[vec.length-1]) {
			return vec;
		} else {
			double best = totalRouteDistance(distance, vec);
			for (int i = 0; i < distance.Rows(); i++) {
				int o = vec[i];
				vec.remove(i);
				double n = bestRoute(distance, vec);
				vec.insert(i, o);
				if (best > n) {
					best = n;
				}
			}
		}
		return vec;
}