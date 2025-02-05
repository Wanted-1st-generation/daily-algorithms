#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
    deque<int> deq;
    for (int i = 0; i < n; ++i)
    {
        int count = 1;
        while (!deq.empty() && deq.back() < arr[i])
        {
            deq.pop_back();
            count = count + 1;
        }
        for (int j = 0; j < count; ++j)
        {
            deq.push_back(arr[i]);            
        }
        if (deq.size() == k)
        {
            std::cout << deq.front() << " ";
            deq.pop_front();
        }
    }
    std::cout << std::endl;
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}