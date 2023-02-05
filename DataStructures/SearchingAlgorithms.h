/*-- SearchingAlgorithms.h -------------------------------------------------------------

 This header file defines a SearchingAlgorithms functions.
 Basic operations:

 depthFirstSearch:		preform deapth first search on an undirected unweighted graph 
 breadthFirstSearch:	preform breadth first search on an undirected unweighted graph
 dijkstraSearch:		preform dijkstra search on an undirected weighted graph
 ---------------------------------------------------------------------------*/
#pragma once
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

void depthFirstSearch(vector<int> graph[] ,int nVerticies ,int start);
/*-----------------------------------------------------------------------
traverse through graph using depth first algo.
 -----------------------------------------------------------------------*/

void breadthFirstSearch(vector<int> graph[], int nVerticies ,int start);
/*-----------------------------------------------------------------------
traverse through graph using breadth first algo.
 -----------------------------------------------------------------------*/

void dijsktraSearch(vector<pair<int,int>> graph[], int nVerticies);
/*-----------------------------------------------------------------------
apply breadth first algo. to find the distance with least cost to all
nodes.
 -----------------------------------------------------------------------*/

