/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solver.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:54:34 by bchelste          #+#    #+#             */
/*   Updated: 2022/09/19 18:17:29 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <queue>
#include <map>
#include <set>

#include "Puzzle.hpp"
#include "PuzzleData.hpp"
#include "State.hpp"

class Puzzle;

class Solver
{

	friend class Puzzle;
	
	public:

		Solver(Puzzle *puzzle);
		virtual ~Solver();

		void	setInitialState(const std::vector<int> &puzzle, const int &size);
		void	setGoalState();
		void	findSolution(void (Puzzle::*heuristic)(State*), std::string &search);

		// std::map<int, int>		getInitialState();
		// std::map<int, int>		getGoalSate();

	private:

		std::priority_queue<State*, std::vector<State*>, CompareStates> opened;
		std::set<State*> closed;

		Puzzle					*puzzle;
		
		int						nSize;
		std::map<int, int>		goalState;
		std::map<int, int>		initialState;

		unsigned long			states;
		// int						moves;

		void					(Puzzle::*heuristicFunc)(State*);

		void					increaseNbr(int *nbr);
		int						countInversion();
		
		bool					isSolvable();
		

		// State					*generateNewStates(State *parent);

		// void					moveRight(State *state);
		// void					moveDown(State *state);
		// void					moveLeft(State *state);
		// void					moveUp(State *state);

		bool					isSolved(State *current);

};
