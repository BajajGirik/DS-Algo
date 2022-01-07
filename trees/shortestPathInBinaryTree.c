/* Consider an infinite full binary tree (each node has two children except the
 * leaf nodes) defined as follows. For a node labelled v its left child will be
 * labelled 2*v and its right child will be labelled 2*v+1. The root is
 * labelled as 1.
 * You are given N queries of the form i j. For each query, you have to print the
 * length of the shortest path between node labelled i and node labelled j.
 */

#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#define ll long long int

int relLevelOfNode(ll index, ll rootIndex) {
	int level = -1;
	while(index >= rootIndex)
	{
		index /= 2;
		level++;
	}

	return level;
}

bool isLeft(ll index, ll rootIndex, int relLevel) {
	ll noOfElements = pow(2, relLevel);
	ll startIndex = rootIndex * noOfElements;

	if(index >= startIndex && index < startIndex + noOfElements/2)
		return true;

	return false;
}

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		ll i,j;
		scanf("%lld %lld",&i,&j);

		ll index = 1;
		ll shortestPath = 0;
		while(true)
		{
			int relLevelOfI = relLevelOfNode(i, index);
			int relLevelOfJ = relLevelOfNode(j, index);

			bool isILeft = isLeft(i, index, relLevelOfI);
			bool isJLeft = isLeft(j, index, relLevelOfJ);

			if(isILeft != isJLeft || relLevelOfI == 0 || relLevelOfJ == 0)
			{
				shortestPath = relLevelOfI + relLevelOfJ;
				break;
			}
			else if (isILeft)
				index = 2*index;
			else
				index = 2*index + 1;

		}

		printf("%lld\n", shortestPath);
	}
	return 0;
}

