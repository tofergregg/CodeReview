
Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	int n = 0;
	Vector<double> bestRouteHelperVector;
	Vector bestRoute = bestRouteHelper(distance,startCity,n,BestRouteHelperVector);
	
Void bestRouteHelper(Grid<double> &distance,int& n, Vector<double> &bestRouteHelperVector) {
	for (int r = n+1; r < distance.numRows()- 2; r++) {
		for (int c = 2+n; c = distance.numCols() - 1; c++) {
			double currentCity = distance[r][c];
			if (currentCity > 0 & currentCity < currentBestRowScore) {
				double currentBestRowScore = currentCity;
				bestRouteHelperVector.add(currentBestRowScore);
			}
		}
	}
	if (n < (distance.numCols()-2) {
		bestRouteHelper(distance,n+1,bestRouteHelperVector);
	} else {
		return bestRouteHelperVector;
	
