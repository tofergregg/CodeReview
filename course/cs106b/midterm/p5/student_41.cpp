Vector<int> bestRoute(Grid<double> &distance, int startCity) {
	Set<Vector<int> > possibleAnswers;
	Vector<int> route66; //because it is the best
	Set<int> cities;
	while (true) {
		if (bestRoute(distance, startCity, possibleAnswers, route66)) {
			return route66;
	}
}

		
		
		
bool bestRoute(Grid<double> &distance, int startCity, Set<Vector<int> >& possibleAnswers, Vector<int>& route66) {
	Set<int> cities;
	if (!(cities.contains('0') && cities.contains('1') && 			      		cities.contains('2') && cities.contains('3')) ||	!(route66[route66.size()-1] == startCity) {
		return true;
	}
	else {
		if (!possibleAnswers.contain(distance[r+1][c]) {
			possibleAnswers.insert(r+1);
			
			
	
		
		

