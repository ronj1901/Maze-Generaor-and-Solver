#ifndef MYMAZEGENERATOR_HPP
#define MYMAZEGENERATOR_HPP

#include "MazeGenerator.hpp"
// #include "Maze.hpp"
//#include <vector>



class  MyMazeGenerator : public MazeGenerator {

	public:

		virtual void generateMaze(Maze& maze);
		std::vector<Direction> findValidDirections(int x, int y, const Maze& maze, std::vector<std::vector<bool>>& visited);
		void recursiveGenerate(Maze& maze, int x, int y, std::vector<std::vector<bool>>& visited);
		void  populate_cell(Maze& maze,std::vector<std::vector<bool>>& visited );
		int generateRandomNumber(int size);

};

#endif