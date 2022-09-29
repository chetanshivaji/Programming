
#include<bits/stdc++.h>
using namespace std;
class MedianFinder {
public:
    priority_queue<long>small, large;

    MedianFinder() {
        
    }
    
    void addNum(int num)
     {
        small.push(num);
	    large.push(small.top()*-1);
	    small.pop();
	    if(small.size()<large.size())
	    {
	    	small.push(-large.top());
	    	large.pop();
	    }
    }
    
    double findMedian() {
        if(small.size()>large.size())
	    	return small.top();
	    else
	    {
	    	return (small.top()-large.top())/2.0;
	    }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
int main()
{
    MedianFinder* obj = new MedianFinder();
    int x[]={1,2,3};
    for(auto num:x)
    {
        obj->addNum(num);
        double param_2 = obj->findMedian();
        cout<<param_2<<endl;
    }
    
    return 0;
}
/**
 * Your MedianFinder object will be instantiated and called as such:
 * */
