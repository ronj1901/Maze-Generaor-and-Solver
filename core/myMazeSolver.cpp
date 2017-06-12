#include <ics46/factory/DynamicFactory.hpp>
#include <iostream>
#include <vector>
#include "Maze.hpp"
#include "myMazeSolver.hpp"
#include <random>
#include "MazeSolution.hpp"
#include <map>
#include <utility>





ICS46_DYNAMIC_FACTORY_REGISTER(MazeSolver, MyMazeSolver, "SAM's Maze Solver (Required)");



std::map<Direction, std::pair<int, int>> directionMap { 
														{ Direction::right, std::pair<int, int>(1,0)},
													 	{ Direction::down, std::pair<int, int>(0,1)} ,
													 	{ Direction::left, std::pair<int, int>(-1,0)} ,
													 	{ Direction::up, std::pair<int, int>(0,-1)} 
													};

std::vector<Direction> dirVector{Direction::right, Direction::down, Direction::left, Direction::up};


bool MyMazeSolver:: recurseSolver(const Maze& maze, MazeSolution& mazeSolution, std::vector<std::vector<bool>>&  visited){

	if(mazeSolution.isComplete()){
		
		return true;

	}
 
	// keep tracking of current cell
	int x =  mazeSolution.getCurrentCell().first;
	int y =  mazeSolution.getCurrentCell().second;


	visited[x][y] = true;
	for(auto k: dirVector){

		if(!maze.wallExists(x,y, k) && !visited[x + directionMap[k].first][y + directionMap[k].second]){
			mazeSolution.extend(k);
			if(recurseSolver(maze, mazeSolution, visited) && mazeSolution.isComplete())
			{
				return true;
			}
			mazeSolution.backUp();

		}
	}

	return true;
}



void MyMazeSolver:: solveMaze(const Maze& maze, MazeSolution& mazeSolution){

	std::vector<std::vector<bool>> visited(maze.getWidth(), std::vector<bool>(maze.getHeight()));

	populate_cell_false(maze, visited);
	recurseSolver(maze, mazeSolution, visited);

}


void  MyMazeSolver:: populate_cell_false(const Maze& maze,std::vector<std::vector<bool>>& visited){

	

	for (int i = 0; i < maze.getWidth(); ++i)
	{	
   		 for (int j = 0; j < maze.getHeight(); ++j)
    	{
       		 visited[i][j] = false;
    	}
	}

}



