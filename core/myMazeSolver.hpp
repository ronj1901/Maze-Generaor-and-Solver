#ifndef MYMAZESOLVER_HPP
#define MYMAZESOLVER_HPP

#include "MazeSolver.hpp"
#include <vector>


class  MyMazeSolver : public MazeSolver{

	

	public : 

	MyMazeSolver(){};
	virtual void solveMaze(const Maze& maze, MazeSolution& mazeSolution);

	bool recurseSolver(const Maze& maze, MazeSolution& mazeSolution, std::vector<std::vector<bool>>& visited);
	void  populate_cell_false( const Maze& maze,std::vector<std::vector<bool>>& visited );


};

#endif  

