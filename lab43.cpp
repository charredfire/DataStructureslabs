//Charles Dunlap
// CS 2315
// lab43

#include <cmath>
#include <iostream>
#include <d_matrix.h>
#include <queue>
#include <vector>

void bucketSort(vector<uint>& v, uint numDigits)
{

	vector<queue<uint> > bucket;
	bucket.resize(10);
	uint size = v.size();
	for(uint i=0; i < numDigits; i++)
	{	
		for(uint j =0 ; j < size; j++)
		{
			bucket[(v.at(j) / static_cast<uint>(pow(10,i))) % 10].emplace(v.at(j));
		}
		v.clear();
	
	
		for(uint H =0; H < 10; H++)
		{
			/*for(uint k=0; k < bucket[H].size(); k++)
			{
				v.emplace_back(bucket[H][k]);
			}*/
			while(!bucket[H].empty())
			{
				v.emplace_back(bucket[H].front());
				bucket[H].pop();
			}
		
		}
	}
}