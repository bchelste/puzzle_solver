/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PuzzleData.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:04:35 by bchelste          #+#    #+#             */
/*   Updated: 2022/09/15 19:36:02 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <string>
#include <iostream>

class PuzzleData 
{
	public:
		
		PuzzleData(int &newSize,  std::vector<int> &newTiles);
		virtual ~PuzzleData();

		// std::pair<int, int>		findTile(int &tile);
		// void					swapTiles(std::pair<int, int> &p1, std::pair<int, int> &p2);

		int						getPuzzleSize();
		std::vector<int>		getTiles();

	private:
	
		int						puzzleSize;
		std::vector<int>		tiles;

};

std::ostream& operator<<(std::ostream &stream, PuzzleData &puzzle);