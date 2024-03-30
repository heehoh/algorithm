#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int K, N;
	cin >> K >> N;
	vector<long long> vec;

	for (int i = 0; i < K; i++)
	{
		long long length;
		cin >> length;

		vec.push_back(length);
	}
	long long min = *min_element(vec.begin(), vec.end());

	long long left = 1;
	long long right = *max_element(vec.begin(), vec.end());

	long long result = 0;

	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long sum = 0;

		for (int i = 0; i < K; i++)
		{
			sum += (vec[i] / mid);
		}

		if (sum >= N)
		{
			result = mid;
			left = mid + 1;
 		}
		else
		{
			right = mid - 1;
		}
	}

	cout << result;

	return 0;
}