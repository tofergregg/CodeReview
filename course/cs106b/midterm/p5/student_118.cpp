/* Pseudocode: (Non-recursive method)
* Find a method that finds all the different routes. Could use a loop.
* Create a vector to store all vectors of the different routes.
* Use a for loop to iterate over all the different routes to calculate 
* the total distance between routes.
* Add a condition, in which it keeps track of the smallest route.
* Store the smallest route as best route.
* Return the best route.
* Can use the rec.rsive backtracking.
*/

/* Pseudocode: Recursion
* Create a helper function for best route that includes the minimum 
* distance.
* Iterate through different routes and calculate the total distance.
* If route's total distance is below the minimum distance, store that
* new distance as minimum distance. 
* Iterate recursively until all routes are completed.
*/

// Given constants and helper functions.
const double DBL_MAX;
double totalRouteDistance(Grid<double> &distance, Vector<int> &route);

// Original city must be the first and last elements.
// Probably do not need smallest route variable, but used for security/stability.
Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	int nPossibleRoutes = factorial(distance.size()-2);
	Vector<int> smallestRoute = bestRoute(distance, startCity, DBL_MAX; nPossibleRoutes);
	return smallestRoute;
}	

Vector <int> bestRoute(Grid<double> &distance, int startCity, double &minDistance, int &nPossibleRoutes){
	Vector<int> route;
	route[0] = startCity;
	Vector<int> bestRoute;

	while (n >= 0){
		// Base case.
		if (route[0] == route[route.size() - 1] && route.size() > 1) {
			// Checks the distance of the route
			if (checkDistance(distance, route, minDistance)){
				bestRoute = route;
			}
			bestRoute(distance, startCity, minDistance, n-1);
		} else {
			for (int i = 0; i < distance.size(); i++) {
				route[0] = startCity;
			}
			// Insert code to find each route.
	}
	// Returns the best saved route after iterating through all routes.
	return bestRoute;
}	

// Calculates the distance of a route and checks if it is below the 
// current minimum. Returns true and updates the minimum if it is below
// the current minimum.
bool checkDistance(Grid<double> &distance, Vector<int> route, double minDistance) {
	double distance = totalRouteDistance(distance, route);
	if (distance <= minDistance) {
		minDistance = distance;
		return true;
	} else {
		return false;
}	
		
int factorial(int n) {
	if (n <= 0) {
		return 1;
	} else {
		return n*factorial(n-1);
}	
				  
