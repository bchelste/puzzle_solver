/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Puzzle.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 20:19:47 by bchelste          #+#    #+#             */
/*   Updated: 2022/09/15 19:50:03 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Puzzle.hpp"

Puzzle::Puzzle(PuzzleData &newPuzzle, std::string &heuristicType, std::string &searchType) : 
	heuristic(heuristicType), search(searchType), puzzle(newPuzzle)
{
	
}

Puzzle::~Puzzle()
{
	
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