/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PuzzleData.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:04:35 by bchelste          #+#    #+#             */
/*   Updated: 2022/09/15 00:39:43 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <string>

class PuzzleData 
{
	public:
		
		PuzzleData(int &newSize, std::string &newHeuristic, std::vector<int> &newTiles);
		virtual ~PuzzleData();

		bool					isSolvable();
		std::pair<int, int>		findTile(int tile);
		void					swapTiles(std::pair<int, int> p1, std::pair<int, int> p2);

	private:
	
		int						puzzleSize;
		std::string				heuristic;
		std::vector<int>		tiles;

};

std::ostream& operator<<(std::ostream& stream, PuzzleData &puzzle);