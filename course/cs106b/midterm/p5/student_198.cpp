Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Vector<int> path;
	path.add(startCity);
	HashSet<int> used;
	used.add(startCity);
	double sum = totalRouteDistance(distance, path);
	return bestHelper(distance, startCity, path, used, sum);
}

Vector<int> bestHelper(Grid<double> &distance, int start, Vector<int> path, HashSet<int> used, double sum){
	Vector<int> finalResult; 
	double t = DBL_MAX;
	for(int i = 0; i < distance.getCols(); i++){
		if(!used.contains(i)){ //this incorporates the base case because if all the values are used, then the recursive element will never be called
			path.add(i); //choose
			used.add(i); //choose
			double temp = sum + totalRouteDistance(distance, path); //explore (returns the distance value)
			Vector<int> result = bestHelper(distance, start, path, used, temp); //explore (returns the path associated with the disctance value above)
			path.remove(path.size()-1); //unchoose
			used.remove(i); //unchoose
			if(t > temp){ //if the current distance is less than the previous, switch to this
				finalResult = result;
				t = temp;
			}
		}
	}
	return finalResult;
}
					
