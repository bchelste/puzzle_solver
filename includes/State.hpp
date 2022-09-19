/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   State.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 21:50:15 by bchelste          #+#    #+#             */
/*   Updated: 2022/09/19 18:11:51 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>

struct State
{
		std::map<int, int>		state;

		int						f;
		int						g;
		int						h;

		State					*father;
		int						movedTile;
	
};

struct CompareStates
{
	
	// std::string		heuristic;
	std::string		search;

	// CompareStates(std::string &initH, std::string initS) : heuristic(initH), search(initS) {}
	CompareStates() : search("default") {};
	CompareStates(std::string initS) : search(initS) {}
	
	bool 			operator()(State *a, State *b)
	{
		int aValue = 0;
		int bValue = 0;

		if (search == "greedy")
		{
			aValue = a->g;
			bValue = b->g;
		}
		else if (search == "uniform")
		{
			aValue = a->h;
			bValue = b->h;
		}
		else // default
		{
			aValue = a->f;
			bValue = b->f;
		}

		return (aValue > bValue);
	}
	
};

