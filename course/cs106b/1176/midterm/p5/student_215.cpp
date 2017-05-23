Vector<int> bestRoute(Grid<double> &distance, int startCity, Vector<int> &vec int &total);
Vector<int> bestRoute(Grid<double> &distance, int startCity) {

	//helper
	Vector<int> vec;
	double mintotal = DBL_MAX;
	Vector<int> path = bestRoute(distance, startCity, vec, int DBL_MAX);
	cout<< path.tostring +" distance: " +mintotal;

}

Vector<int> bestRoute(Grid<double> &distance, int startCity, Vector<int> vec, int &total){
	

	//base
	if(vec.size()== distance.numRows()){	
		vec.add(startCity);
		if(maxtotal > total){
		maxtotal = total;
		return vec;
	}
	//recursive
	else{
		
		for(int i=0; i< distance.numRows()i++){
			if(!vec.contains(i)){
			vec = bestRoute(distance, i, vec, total);
			return;
			}
				}
				}
		
				


