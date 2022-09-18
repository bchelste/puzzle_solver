/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Puzzle.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 20:19:42 by bchelste          #+#    #+#             */
/*   Updated: 2022/09/18 17:24:24 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "PuzzleData.hpp"
#include "Parser.hpp"
#include "Solver.hpp"

class Solver;

class Puzzle 
{

	public:

		Puzzle();
		Puzzle(PuzzleData &newPuzzle, std::string &heuristicType, std::string &searchType);
		virtual~Puzzle();

		std::string				getHeuristic();
		std::string				getSearch();
		PuzzleData				getPuzzle();

		void					parseData(int argc, char **argv);
		void					solvePuzzle();
		
	private:

		std::string				heuristic;
		std::string				search;
		PuzzleData				puzzle;
		Parser					parser;
		Solver					*solver;

		void					printState(std::map<int, int> &state);
		void					printSolution(std::string sState);

		void					solve();
		
};