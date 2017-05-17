Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	double min = DBL_max;
	Vector<int> minDist = //pseudo code for now, a vector of all possible cities 0 through n - 1;
	Vector<int> tempVec;
	n = distance.numCols();
	next = 0;
	Vector<int> = minDist = bestRoute(distance, startCity, minDist, min, tempVec, n, next);
}
	
	
Vector<int> bestRoute(Grid<double> &distance, int startCity, Vector<int> minDist, double min, Vector<int> tempVec, int n, int next) {
	if (n == 0) {
		if (totalRouteDistance(distance, tempVec) < totalRouteDistance(distance, minDist)){
			return tempVec;
		}else{
			return minDist;
		}
		
		return minDist;
	} else if (next >= n - 1){
		return minDist
	} else if (n == 1){
		return minDist
	}
		
	next += 1;
	Vector <int> tempVec1 = bestRoute(distance, startCity, minDist, min, tempVec, n - 1, next);
	next -= 1;
	tempVec.append(next); //for recursive function
	Vector<int> tempVec2 = bestRoute(distance, startCity, minDist, min, tempVec, n, next);
	if (totalRouteDistancce(distance, tempVec1) < totalRouteDistance(distance, tempVec2)) {
		return tempVec1;
	} else {
		return tempVec2;
	}
}
	//Running out of time, think logic is right but code is very wrong. idea: advance to next item in first recursive call, attempt original call in second call. this should proceed through all possible choices. compare in both 

