//I would write a helper function that can also get passed in an additional two vectors, meant to act as the best route and an auxillary route. I would then recursively, the base case being when distance [r][c] == distance [startCity][startCity] and the recursive case being otherwise, check every single possible combination of routes. Each indvidual route is then added to a cue. The first vector is assigned to the best route and from then on, with the help of another helper function made to find the sum of each vector, while the queue is not empty every subsequent vector's sum is compared to the best route's sum. If the sum of a given auxillary vector is less than that of the best route, it is then assigned to be the best route. When the queue is finally empty the best route is returned and the tasked is accomplished.


//I know I shouldn't make excuse, but I couldn't make it happen. I had too vague of a sense of direction. Forgive me!!