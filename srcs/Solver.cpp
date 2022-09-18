/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solver.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:54:39 by bchelste          #+#    #+#             */
/*   Updated: 2022/09/18 14:24:25 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solver.hpp"

Solver::Solver() : nSize(0), states(0)
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
		initialState.emplace(i, *it);

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
			goalState.emplace(((nSize * i) + j), nbr);
			increaseNbr(&nbr);
		}
		for (int j = (i + 1); j < (nSize - i); ++j)
		{
			goalState.emplace(((j * nSize) + (nSize - i - 1)), nbr);
			increaseNbr(&nbr);
		}
		for (int j = (i + 1); j < (nSize - i); ++j)
		{
			goalState.emplace((((nSize - i - 1) * nSize) + (nSize - j - 1)), nbr);
			increaseNbr(&nbr);
		}
		for (int j = (i + 1); j < (nSize -i - 1); ++j)
		{
			goalState.emplace((((nSize - j - 1) * nSize) + i), nbr);
			increaseNbr(&nbr);
		}	
	}
	states += 1;
	
}

void Solver::findSolution(std::string &heuristic, std::string &search)
{
	std::cout << heuristic << search << std::endl;
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
	int inversions = 0;

	return (inversions);
}

// bool Solver::isSolvable()
// {
// 	int inversions = countInversion();

// 	if (nSize % 2 == 1)
// 		return (inversions % 2 == 0);
	
	
	
// }
