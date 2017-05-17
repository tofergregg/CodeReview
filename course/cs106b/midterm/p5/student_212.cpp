void bestRouteHelper(Grid<double& distance, int min, int r, 
					 int c, Vector<int>& route);

Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	int r = distance.numRows();
	int c = distance.numCols();
	Vector<int> route;
	if (r == 0 && c == 0) { //base case; grid is 1x1
		route.add(startCity);
		route.add(startCity);
		return route;
	} else {
		r = startCity;
		c = c - 1;
		route.add(startCity);
		int min = distance[r][(r % c) + 1];
		bestRouteHelper(distance, min, r, c, route);
	}
	return route;
}

void bestRouteHelper(Grid<double& distance, int min, int r, 
					 int c, Vector<int>& route) {
	//trying to ensure that you never start where r == c
	c = (r % c) + 1;	
	int curr = distance[r][c];
	if (curr == 0) {
		//ideally, if distance[r][c] is 0 (meaning r == c), this will
		//increase the value of c by 1 while keeping r the same, to check
		//the next column
		bestRouteHelper(distance, min, r, c + 1, route); 
	} else {
		route.add(c);
		double total = totalRouteDistance(distance, route);
		if (total < min) {
			min = total;
			//minimum distance for this row has been found, so moves on
			//to the next row
			bestRouteHelper(distance, min, r + 1, c, route);
		} else {
			//removes the last value from route (the value that is not
			//the minimum value thus far) and then calls bestRouteHelper
			//again
			int s = route.size();
			route.remove(s - 1);
			bestRouteHelper(distance, min, r, c + 1, route);
		}
	}
}

/* Pseudocode for bestRouteHelper:
	start at the row given and row != col 
	get the value at this point on the grid
	if this value is 0:
		stay in the same row, but col + 1
		perform bestRouteHelper on this new location
	else:
		add the column number to route
		check the distance between startCity and this new city
		if this distance is less than the min value:
			store it as new min value
			perform bestRouteHelper on row + 1
		else:
			remove this value from route;
			perform bestRouteHelper on col + 1 (plus same row)
		
	Trying to check each combination for min distance. With the example (startCity = 0, r = 4, c = 4) I would check:
	- 0 to 1, 0 to 2, 0 to 3: check each distance, add the shortest distance to route, and use the city with the shortest distance (in this case, 1) to call bestRouteHelper again
	- 1 to 2, 1 to 3: check each distance, add the shortest distance to route, and use the city with the shortest distance (in this case, 3) to call bestRouteHelper again
	- 3 to 2 (only city that has not yet been checked)
	- 2 to 0 (return to start)
*/


