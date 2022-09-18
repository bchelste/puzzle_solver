/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Puzzle.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 20:19:47 by bchelste          #+#    #+#             */
/*   Updated: 2022/09/18 13:33:22 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Puzzle.hpp"

Puzzle::Puzzle()
{
	this->heuristic = "";
	this->search = "";
	this->puzzle = PuzzleData();
	this->parser = Parser();
	this->solver = new Solver();
}

Puzzle::Puzzle(PuzzleData &newPuzzle, std::string &heuristicType, std::string &searchType) : 
	heuristic(heuristicType), search(searchType), puzzle(newPuzzle)
{
	this->parser = Parser();
}

Puzzle::~Puzzle()
{
	delete this->solver;
}

std::string	Puzzle::getHeuristic()
{
	return (this->heuristic);
}

std::string Puzzle::getSearch()
{
	return (this->search);
}

PuzzleData Puzzle::getPuzzle()
{
	return (this->puzzle);	
}

void	Puzzle::parseData(int argc, char **argv)
{
	PuzzlePack tmp;
	tmp = this->parser.cmdParser(argc, argv);
	
	this->heuristic = tmp.currentHeuristic;
	this->search = tmp.currentSearch;
	this->puzzle = tmp.puzzleData;
	
}

void Puzzle::solvePuzzle()
{
	solver->setInitialState(this->puzzle.getTiles(), this->puzzle.getPuzzleSize());
	
	std::cout << "initialState" << std::endl;
	printState(solver->initialState);
	
	solver->setGoalState();
	
	std::cout << "-------" << std::endl;
	std::cout << "goalState" << std::endl;
	printState(solver->goalState);
	// solver->findSolution(this->heuristic, this->search);
}

void Puzzle::printState(std::map<int, int> &state)
{
	int size = solver->nSize;
	int cntr = 0;
	int i = 0;
	int tmp;
	for (; i < (size * size); ++i)
	{
		tmp = state.at(i);
		std::cout << tmp;
		cntr += 1;
		if (cntr == size)
		{
			if (i == ((size * size) - 1))
				break ;
			std::cout << std::endl;
			cntr = 0;
		}
		else
		{
			if (tmp < 10)
				std::cout << "   ";
			else if ((tmp > 9) &&  (tmp < 100))
				std::cout << "  ";
			else
				std::cout << " ";
		}
		
	}
	std::cout << std::endl;
}

// void Puzzle::printSolution()
// {
			
// }
