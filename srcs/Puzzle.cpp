/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Puzzle.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 20:19:47 by bchelste          #+#    #+#             */
/*   Updated: 2022/09/20 23:32:04 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Puzzle.hpp"

Puzzle::Puzzle()
{
	this->heuristic = "";
	this->search = "";
	this->puzzle = PuzzleData();
	this->parser = Parser();
	this->solver = new Solver(this);
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
	
	// std::cout << "initialState" << std::endl;
	// printState(solver->initialState);
	
	solver->setGoalState();
	
	// std::cout << "-------" << std::endl;
	// std::cout << "goalState" << std::endl;
	// printState(solver->goalState);

	// std::cout << solver->countInversion() << std::endl;
	
	solve();
}

void Puzzle::solve()
{
	if (solver->isSolvable() == false)
	{
		printSolution("unsolvable");
		return ;
	}
	
	void (Puzzle::*heuristicFunc)(State *state);
	if (heuristic == "manhtn")
		heuristicFunc = &Puzzle::manhattanHeuristic;
	else if (heuristic == "euclid")
		heuristicFunc = &Puzzle::euclidianHeuristic;
	else
		heuristicFunc = &Puzzle::hammingHeuristic;	
	solver->findSolution(heuristicFunc, search);
	printSolution("solvable");
}

void Puzzle::printState(std::map<int, int> &state)
{
	int size = solver->nSize;
	int cntr = 0;
	int i = 0;
	int tmp;

	std::map<int, int>::iterator it;
	
	for (; i < (size * size); ++i)
	{
		// tmp = state.at(i);
		
		it = state.begin();
		for (; it != state.end(); ++it)
		{
			if (i == it->second)
				tmp = it->first;
		}
		
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

void Puzzle::printSolution(std::string sStatus)
{
	std::vector<std::map<int, int> > result;
	int steps = 0;
	std::cout << "----- N-PUZZLE -----" << std::endl;
	std::cout << "initial State:" << std::endl;
	printState(solver->initialState);
	std::cout << std::endl;
	std::cout << "goal State:" << std::endl;
	printState(solver->goalState);
	std::cout << std::endl;
	std::cout << "|" << sStatus << "|" << std::endl;
	
	State *solution = solver->solution;
	State tmp;
	while (solution->father != NULL)
	{
		tmp = *solution;
		std::cout << solution->h << "|" << solution->g << std::endl;
		result.push_back(solution->state);
		solution = solution->father;
		
		std::cout << "--" << std::endl;
		tmp.father = NULL;
		manhattanHeuristic(&tmp);
		std::cout << tmp.h << std::endl;
		std::cout << "---------" << std::endl;
	}
	std::cout << "____________________________________________________" << std::endl;
	printState(solver->initialState);
	std::cout << std::endl;
	while (result.empty() == false)
	{
		printState(*(result.rbegin()));
		std::cout << std::endl;
		result.pop_back();
		++steps;
	}
	std::cout << "____________________________________________________" << std::endl;
	std::cout << "Total steps to solution = " << steps <<std::endl;
	std::cout << "Time complexity (total states selected for OPENED queue): " << 0 <<std::endl;
	std::cout << "Size complexity (max number of states in memory at the same time: " << 0 << std::endl;

}

// heuristic funcs ************************************************************

void	Puzzle::manhattanHeuristic(State *state)
{
	int heuristic = 0; 
	int current = 0;
	unsigned long i = 1; 
	unsigned long size = puzzle.getPuzzleSize();
	if(state->father == NULL)
	{
		for (; i < (size * size); ++i)
		{
			// std::cout << "i = " << i << std::endl;
			// std::cout << "current pos = " << state->state.at(i) << std::endl;
			// std::cout << "goal pos = " << solver->goalState.at(i) << std::endl;
			current = abs(state->state.at(i) - solver->goalState.at(i));
			// std::cout << current << std::endl;
			// std::cout << (current / size) << "+" << (current % size) << std::endl;
			heuristic += ((current / size) + (current % size));
			// std::cout << "--------------"<< std::endl;
			state->h = heuristic;
			state->f = heuristic;
		}
	}
	else 
	{
		heuristic = state->h;
		state->f -= heuristic;
		current = abs(state->father->state.at(state->movedTile) - solver->goalState.at(state->movedTile));
		heuristic -= ((current / size) + (current % size));
		current = abs(state->state.at(state->movedTile) - solver->goalState.at(state->movedTile));
		heuristic += ((current / size) + (current % size));
		state->h = heuristic;
		state->f += heuristic;
	}
	
}

void Puzzle::euclidianHeuristic(State *state)
{
	std::cout << state->f << "euclid" << std::endl;
}

void	Puzzle::hammingHeuristic(State *state)
{
	std::cout << state->f << "hamming" << std::endl;
}
