https://www.geeksforgeeks.org/maximum-number-of-overlapping-intervals/

Given N intervals of the form [A, B]. The task is to return the maximum 
number of overlap among these intervals at any time.


Input: 

6
13 13
3 7
6 12
12 17
6 14
3 13

Output:4
--------------------------------------------------------------------------
ALGO

1)The idea is to store coordinates in a new vector of pair mapped with characters ‘x’ and ‘y’, 
to identify coordinates.
2)Sort the vector.
3)Traverse the vector, if an x coordinate is encountered it means a new range is added, 
so update count and if y coordinate is encountered that means a range is subtracted.
4)Update the value of count for every new coordinate and take maximum.

// Function that print maximum
// overlap among ranges

void overlap(vector<pair<int, int> > v)
{
    // variable to store the maximum
    // count
    int ans = 0;
    int count = 0;
    vector<pair<int, char> > data;
 
    // storing the x and y
    // coordinates in data vector
    for (int i = 0; i < v.size(); i++) {
 
        // pushing the x coordinate
        data.push_back({ v[i].first, 'x' });
 
        // pushing the y coordinate
        data.push_back({ v[i].second, 'y' });
    }
 
    // sorting of ranges
    sort(data.begin(), data.end());
 
    // Traverse the data vector to
    // count number of overlaps
    for (int i = 0; i < data.size(); i++) {
 
        // if x occur it means a new range
        // is added so we increase count
        if (data[i].second == 'x')
            count++;
 
        // if y occur it means a range
        // is ended so we decrease count
        if (data[i].second == 'y')
            count--;
 
        // updating the value of ans
        // after every traversal
        ans = max(ans, count);
    }
 
    // printing the maximum value
    cout << ans << endl;
}