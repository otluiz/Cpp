#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void checkNum(vector<int> &v);

int main()
{
    vector<int> numbers;
    cout << "Please enter numbers, 0 to quit: " << endl;
    bool more = true;
    while (more)
    {
        int num;
        cin >> num;
        if (num == 0)
            more = false;
        else
            numbers.push_back(num);
    }
    sort(numbers.begin(),numbers.end());
    cout << "The sorted values are: " << endl;
    
    for (int i = 0; i < numbers.size(); i++)
        cout << numbers[i] << " ";

    void checkNum(vector<int> &v)
    {
      int i, j = 0;
      while (i < v.size() - 1)
      {
	j = j + 1;
	while (j < v.size())
	{
	  if (v[i] == v[j])
	    v.erase(v.begin() + j);
	  else
	    j +=1;
	}
	i += 1;
      }
      vector<int>::iterator it = v.begin();
      while (it == v.end() - 1)
      {
	cout << "After duplicate removal pass:" << endl;
	for (int k=0; k< v.size(); k++)
	  cout << v[k] << " ";
      }
    }

    checkNum(numbers);

    system("pause");
    return 0;
}
