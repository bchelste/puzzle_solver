/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Puzzle.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 20:19:47 by bchelste          #+#    #+#             */
/*   Updated: 2022/09/17 20:25:15 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Puzzle.hpp"

Puzzle::Puzzle()
{
	this->heuristic = "";
	this->search = "";
	this->puzzle = PuzzleData();
	this->parser = Parser();
}

Puzzle::Puzzle(PuzzleData &newPuzzle, std::string &heuristicType, std::string &searchType) : 
	heuristic(heuristicType), search(searchType), puzzle(newPuzzle)
{
	this->parser = Parser();
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

void	Puzzle::parseData(int argc, char **argv)
{
	PuzzlePack tmp;
	tmp = this->parser.cmdParser(argc, argv);
	
	this->heuristic = tmp.currentHeuristic;
	this->search = tmp.currentSearch;
	this->puzzle = tmp.puzzleData;
	
}

// bool Puzzle::isSolvable() const
// {
	
// }