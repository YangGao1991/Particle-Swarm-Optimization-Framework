#include "binTreeNetwork.h"

//construct a bintree of 80 nodes (6 piles)
network binTreeConstruct()
{
	network binTree;
	
	//******Warning!****** Only the parent node is its neighbor
	for (int i=0;i!=nodeNum;++i)
	{
		if (0==i)
			binTree[i].lvl=6;
		else if(i>=1 && i<=2)
			binTree[i].lvl=5;
		else if(i>=3 && i<=6)
			binTree[i].lvl=4;
		else if(i>=7 && i<=14)
			binTree[i].lvl=3;
		else if(i>=15 && i<=30)
			binTree[i].lvl=2;
		else if(i>=31 && i<=62)
			binTree[i].lvl=1;
		else
			binTree[i].lvl=0;
	}
	for (int i=1;i!=nodeNum;++i)
	{
		if (i%2==0)
		{
			binTree[i].upperNeighborsID.push_back((i-2)/2);
		}
		else
		{
			binTree[i].upperNeighborsID.push_back((i-1)/2);
		}
	}
	for (int i=0;i!=nodeNum;++i)
	{
		for (auto it=binTree[i].upperNeighborsID.begin();it!=binTree[i].upperNeighborsID.end();++it)
		{
			binTree[*it].lowerNeighborsID.push_back(i);
		}
	}
	return binTree;
}

