/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solver.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:54:34 by bchelste          #+#    #+#             */
/*   Updated: 2022/09/18 14:24:18 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <queue>
#include <map>

#include "Puzzle.hpp"
#include "PuzzleData.hpp"

class Solver
{

	friend class Puzzle;
	
	public:

		Solver();
		virtual ~Solver();

		void	setInitialState(const std::vector<int> &puzzle, const int &size);
		void	setGoalState();

		void	findSolution(std::string &heuristic, std::string &search);

	private:

		int						nSize;
		std::map<int, int>		goalState;
		std::map<int, int>		initialState;

		unsigned long			states;
		// int						moves;

		void					increaseNbr(int *nbr);
		int						countInversion();
		
		// bool					isSolvable();

};
