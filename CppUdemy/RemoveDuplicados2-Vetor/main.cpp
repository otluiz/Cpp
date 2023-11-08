#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void checkNum(vector<int> &v, vector<int>::iterator& it)
{
    if (it == v.end() - 1) //last element
    {
        cout << "\nAfter duplicate removal pass:" << endl;
        for (int k=0; k< v.size(); k++)
             cout << v[k] << " ";
	cout << endl;
    }
    else if (*it == *(it + 1)) //next element is equal to current one, erase current one
    {
        v.erase(it); //using 'it' after this line is normally not a good practice,
        // but we know the vector is stored sequentially and 'it' will point to another element because above we checked if this is the last element or not.
        return checkNum(v, it);
    }
    else //next element is not the same as this one
    {
        ++it;
        return checkNum(v, it);
    }
}

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
    int i;
    for (i = 0; i < numbers.size(); i++)
        cout << numbers[i] << " ";
    vector<int>::iterator elementToStart = numbers.begin();
    checkNum(numbers, elementToStart);
    //    system("pause");
    return 0;
}

