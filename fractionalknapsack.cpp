//fractional knapsack
#include<iostream>
#include<algorithm>
using namespace std;

class item
{ 
	public:
		
	int profit,weight;
	//constructor
	item(int p,int w):profit(p),weight(w){}
	//profit by weight ratio
	double getratio() 
	{
		return (double)profit/weight;
	}
	
};
bool comparebyratio(item &a,item &b)
{
	return a.getratio()>b.getratio();
}
class fractionalknapsack
{
	public:
		//to get maximum profit for the knapsack with given capacity
		static double getmaxprofit(int capacity, item &item1,item &item2,item &item3)
		{
			if(!comparebyratio(item1,item2)) 
			swap(item1,item2);
			if(!comparebyratio(item1,item3))
			swap(item1,item3);
			if(!comparebyratio(item2,item3));
			swap(item2,item3);
			double totalprofit=0.0;
		
		if(item1.weight<=capacity)
		{
			capacity=capacity-item1.weight;	
			totalprofit=totalprofit+item1.profit;
		} 
		else
		{
			totalprofit=totalprofit+item1.profit*((double)capacity/item1.weight);
			return totalprofit;
		}
		if(item2.weight<=capacity)
		{
			capacity=capacity-item2.weight;	
			totalprofit=totalprofit+item2.profit;
		} 
		else
		{
			totalprofit=totalprofit+item2.profit*((double)capacity/item2.weight);
			return totalprofit;
		}
		if(item3.weight<=capacity)
		{
			capacity=capacity-item3.weight;	
			totalprofit=totalprofit+item1.profit;
		} 
		else
		{
			totalprofit=totalprofit+item3.profit*((double)capacity/item3.weight);
	    }
		
		return totalprofit;
	}
};

int main()
{
	int capacity=50;
	item item1(60,10);
	item item2(100,20);
	item item3(120,30);
	
	double maxprofit=fractionalknapsack::getmaxprofit(capacity,item1,item2,item3);
	cout<<"MAXIMUM PROFIT IN KNAPSACK = "<<maxprofit<<endl;
	return 0;
}
