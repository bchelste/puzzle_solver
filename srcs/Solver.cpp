/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solver.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:54:39 by bchelste          #+#    #+#             */
/*   Updated: 2022/09/19 18:19:02 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solver.hpp"

Solver::Solver(Puzzle *_puzzle) : puzzle(_puzzle), nSize(0), states(0), heuristicFunc(NULL)
{
	
}

Solver::~Solver()
{
	
}

void Solver::setInitialState(const std::vector<int> &puzzle, const int &size)
{
	nSize = size;
	std::vector<int>::const_iterator it = puzzle.begin();
	for (int i = 0; it != puzzle.end(); ++it, ++i)
		initialState.emplace(*it, i);

	states += 1;
	
}

void Solver::setGoalState()
{
	int nbr = 1;
	int finish = (nSize % 2 == 0) ? (nSize / 2) : (nSize / 2 + 1);
	
	for (int i = 0; i < finish; ++i)
	{
		for (int j = i; j < (nSize - i); ++j)
		{
			goalState.emplace(nbr , ((nSize * i) + j));
			increaseNbr(&nbr);
		}
		for (int j = (i + 1); j < (nSize - i); ++j)
		{
			goalState.emplace( nbr, ((j * nSize) + (nSize - i - 1)));
			increaseNbr(&nbr);
		}
		for (int j = (i + 1); j < (nSize - i); ++j)
		{
			goalState.emplace(nbr, (((nSize - i - 1) * nSize) + (nSize - j - 1)));
			increaseNbr(&nbr);
		}
		for (int j = (i + 1); j < (nSize -i - 1); ++j)
		{
			goalState.emplace(nbr, (((nSize - j - 1) * nSize) + i));
			increaseNbr(&nbr);
		}	
	}
	states += 1;
	
}

void Solver::findSolution(void (Puzzle::*heuristic)(State*), std::string &search)
{	
	CompareStates comp = CompareStates(search);
	heuristicFunc = heuristic;
	opened = std::priority_queue<State*, std::vector<State*>, CompareStates>(comp);
	closed.clear();
	State *start = new State();
	start->state = initialState;
	start->father = NULL;
	start->g = 0;
	start->h = 0;
	(puzzle->*heuristicFunc)(start);
	start->movedTile = -1;
	opened.push(start);
	

	std::cout << "Hello" << std::endl;
	
	std::cout << opened.top()->h << std::endl;
	std::cout << opened.top()->state.size() << std::endl;
	
}

// private methods ************************************************************

void Solver::increaseNbr(int *nbr)
{
	*nbr += 1;
	if (*nbr == (nSize * nSize))
		*nbr = 0;
}

int Solver::countInversion()
{
	int missplaced = 0;
	unsigned long totalSize = nSize * nSize;

	// std::map<int, int>::iterator it;
	
	for(unsigned long i = 1; i < totalSize; ++i)
	{
		// std::cout << std::endl;
		// std::cout << i << "| " << initialState.at(i) << "   " << goalState.at(i) << std::endl;
		// std::cout << std::endl;
		for (unsigned long j =  1; j < totalSize; ++j)
		{
			// std::cout << "i = " << i << " j = " << j << std::endl;
			// std::cout << "initial: " << initialState[i] << " < " << initialState[j] << std::endl;
			// std::cout << "   goal: " << goalState[i] << " > " << goalState[j] << std::endl;
			
			if ((initialState[i] < initialState[j]) && (goalState[i] > goalState[j]))
			{
				// std::cout << "+" << std::endl;
				missplaced += 1;
			}
				
		}
		// std::cout << "----------" << std::endl;
		
	}
	
	return (missplaced);
}

bool Solver::isSolvable()
{
	int inversions = countInversion();
	bool result = false;

	if (nSize % 2 == 1)
	{
		result = inversions % 2 == 0;
	}
	else if (nSize % 2 == 0)
	{
		int tmp = initialState[0] % nSize;
		// std::cout << "initialState[0] = " << initialState[0] << std::endl;
		// std::cout << "tmp = " << tmp << std::endl;
		// std::cout << "inversions = " << inversions << std::endl;
		// std::cout << "(tmp % 2) = " << (tmp % 2) << std::endl;
		if ((tmp % 2) == 0)
		{
			result = inversions % 2 != 0;
		}
		else
		{
			result = inversions % 2 == 0;
		}
		
	}
	
	return (result);
}

// State *Solver::generateNewStates(State *parent)
// {
	
// }

// moves **********************************************************************

// void Solver::moveRight(State *state)
// {
// 	std::cout << "move right" << std::endl;
// }

// void Solver::moveDown(State *state)
// {
	
// }

// void Solver::moveLeft(State *state)
// {
	
// }

// void Solver::moveUp(State *state)
// {
	
// }

bool Solver::isSolved(State *current)
{
	if (current->state == goalState)
		return (true);
	return (false);
}