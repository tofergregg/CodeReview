Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	return bestRouteHelper(distance, startCity, 0);
{
	
Vector<int> bestRouteHelper(Grid<double> &distance, int & previousCity, int bestScore) {
	double columnBestScore;
	// traverse from one city to the next 
	for(int r = 0; r < distance.numRows(); r++) {
		for(int c = 0; c <distance.numCols(); c++) {
			//recurively check within columns
			int traverseColumns = distance[previousCity][c];
			Vector<int> columnRoute = bestRouteHelper(distance, c, bestScore);
			double columnRouteSoFar = totalRouteDistance(distance, columnRoute);
			columnBestScore = DBL_MAX - columnRoutesoFar; 
			//recursively check within rows 
			int traverseRows = distance[r][previousCity];
			Vector<int> rowRoute = bestRouteHelper(distance, r, bestScore);
			double rowRouteSoFar = totalRouteDistance(distance, rowRoute); 
			rowBestScore = DBL_MAX - rowRouteSoFar; 
		{
	{	
	if(rowBestScore < columnBestScore) {
		return rowBestScore); 
	{ else {
		return columnBestScore);
{
			
	
		

			 
			 		 
		 
			
			
	

