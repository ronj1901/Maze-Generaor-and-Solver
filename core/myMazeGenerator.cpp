
#include <ics46/factory/DynamicFactory.hpp>
#include <iostream>
#include <vector>
#include "Maze.hpp"
#include "Direction.hpp"
#include "myMazeGenerator.hpp"
#include <random>


ICS46_DYNAMIC_FACTORY_REGISTER(MazeGenerator, MyMazeGenerator, "SAM's Maze Generator (Required)");


//bool** visited;   // using vectors of vector as professor recommended



void  MyMazeGenerator:: populate_cell(Maze& maze,std::vector<std::vector<bool>>& visited){

	

	for (int i = 0; i < maze.getWidth(); ++i)
	{	
   		 for (int j = 0; j < maze.getHeight(); ++j)
    	{
       		 visited[i][j] = false;
    	}
	}

}




void MyMazeGenerator :: generateMaze(Maze& maze){

	maze.addAllWalls();	

	int width = maze.getWidth();
	int height =  maze.getHeight();				

	std::vector<std::vector<bool>> visited(width, std::vector<bool>(height));

	populate_cell(maze, visited);

	recursiveGenerate(maze, 0, 0, visited);


}



void MyMazeGenerator :: recursiveGenerate(Maze& maze, int x, int y, std::vector<std::vector<bool>>& visited){

    std::vector<Direction> validDirections;
   
    visited[x][y] = true;


    while( (validDirections = findValidDirections(x, y, maze, visited)).size() > 0 ){
   

    	int numberOfDirections  = validDirections.size();   
 

		int rand = generateRandomNumber(numberOfDirections);

		Direction currentDirection = validDirections.at(rand);

		if(currentDirection == Direction::right){

			maze.removeWall(x, y, Direction::right);
			recursiveGenerate(maze, x+1, y, visited);
		}

		if(currentDirection == Direction::down){

			maze.removeWall(x, y, Direction::down);
			recursiveGenerate(maze, x, y+1,visited);
		}



		if(currentDirection == Direction::left){

			maze.removeWall(x, y, Direction::left);
			recursiveGenerate(maze, x-1, y,visited);
		}


		if(currentDirection == Direction::up){

			maze.removeWall(x, y, Direction::up);
			recursiveGenerate(maze, x, y-1,visited);
		}
		
    }

    return;

}

std::vector<Direction> MyMazeGenerator :: findValidDirections(int x, int y, const Maze& maze,  std::vector<std::vector<bool>>& visited){

 	std::vector<Direction> directions;

 	if( x+1 < maze.getWidth()  && !visited[x+1][y]){						
 		directions.push_back(Direction::right);
 	}

 	if( y-1 > 0 && !visited[x][y-1]){									
 		directions.push_back(Direction::up);							
 	}

 	if(x-1 > 0 && !visited[x-1][y]) { 									
 		directions.push_back(Direction::left);
 	}
 	

 	if(y+1 < maze.getHeight()  && !visited[x][y+1]){									
 		directions.push_back(Direction::down);
 	}

	return directions;

}


int MyMazeGenerator:: generateRandomNumber(int sizeOfVector){
	std::random_device device;
	std::default_random_engine myEngine{device()};			  // Random device to generate random direction
	std::uniform_int_distribution<int> distribution{1, sizeOfVector};
	int randomNumber =  distribution(myEngine) - 1;   // 

	return randomNumber;
}






