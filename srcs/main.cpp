/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:29:03 by bchelste          #+#    #+#             */
/*   Updated: 2022/09/17 21:21:17 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include <fcntl.h>
#include <vector>
#include <string>
#include <ctime>
#include <unistd.h>

#include "Parser.hpp"
#include "PuzzleData.hpp"
#include "Puzzle.hpp"

int main(int argc, char **argv)
{
	Puzzle puzzle = Puzzle();
	try
	{
		puzzle.parseData(argc, argv);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		exit(1);
	}

	std::cout << "--data from input--" << std::endl;
	std::cout << "heuristic type: " << (puzzle).getHeuristic() << std::endl;
	std::cout << "search type: " << (puzzle).getSearch() << std::endl;
	std::cout << "puzzle data: \n" << (puzzle).getPuzzle() << std::endl;
	
	
	
}