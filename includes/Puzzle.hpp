/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Puzzle.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 20:19:42 by bchelste          #+#    #+#             */
/*   Updated: 2022/09/15 20:13:56 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "PuzzleData.hpp"

class Puzzle 
{

	public:

		Puzzle(PuzzleData &newPuzzle, std::string &heuristicType, std::string &searchType);
		virtual~Puzzle();

		std::string				getHeuristic();
		std::string				getSearch();
		PuzzleData				getPuzzle();
		
		// bool					isSolvable();

	private:
	
		std::string				heuristic;
		std::string				search;
		PuzzleData				puzzle;
		
		
	
};