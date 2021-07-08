/* Link to the problem-
https://leetcode.com/problems/the-skyline-problem/
*/

// A divide and conquer based C++ program
#include <iostream>
using namespace std;
struct Building {
    // x coordinate of left side
    int left;
    // height
    int ht;
    // x coordinate of right side
    int right;
};  
class Strip {
    int left;
    int ht;
  
public:
    Strip(int l = 0, int h = 0)
    {
        left = l;
        ht = h;
    }
    friend class SkyLine;
};
class SkyLine {
    // Array of strips
    Strip* arr;
    int capacity;
    // Actual number of strips in array
    int n;
  
public:
    ~SkyLine() { delete[] arr; }
    int count() { return n; }
    //Merge function
    SkyLine* Merge(SkyLine* other);
    SkyLine(int cap)
    {
        capacity = cap;
        arr = new Strip[cap];
        n = 0;
    }
    //append function
    void append(Strip* st)
    {
        if (n > 0 && arr[n - 1].ht == st->ht)
            return;
        if (n > 0 && arr[n - 1].left == st->left) {
            arr[n - 1].ht = max(arr[n - 1].ht, st->ht);
            return;
        }
  
        arr[n] = *st;
        n++;
    }
  
    //Print function to print the values
    void print()
    {
        for (int i = 0; i < n; i++) {
            cout << " (" << arr[i].left << ", "
                 << arr[i].ht << "), ";
        }
    }
};
SkyLine* findSkyline(Building arr[], int l, int h)
{
    if (l == h) {
        SkyLine* res = new SkyLine(2);
        res->append(
            new Strip(
                arr[l].left, arr[l].ht));
        res->append(
            new Strip(
                arr[l].right, 0));
        return res;
    }
  
    int mid = (l + h) / 2;
    SkyLine* sl = findSkyline(
        arr, l, mid);
    SkyLine* sr = findSkyline(
        arr, mid + 1, h);
    SkyLine* res = sl->Merge(sr);
  
    // To avoid memory leak
    delete sl;
    delete sr;
    return res;
}

SkyLine* SkyLine::Merge(SkyLine* other)
{
   
    SkyLine* res = new SkyLine(
        this->n + other->n);
  
    // To store current heights of two skylines
    int h1 = 0, h2 = 0;
    int i = 0, j = 0;
    while (i < this->n && j < other->n) {
       
        if (this->arr[i].left < other->arr[j].left) {
            int x1 = this->arr[i].left;
            h1 = this->arr[i].ht;
            // Choose height as max of two heights
            int maxh = max(h1, h2);
  
            res->append(new Strip(x1, maxh));
            i++;
        }
        else {
            int x2 = other->arr[j].left;
            h2 = other->arr[j].ht;
            int maxh = max(h1, h2);
            res->append(new Strip(x2, maxh));
            j++;
        }
    }
    // If there are strips left in this
    // skyline or other skyline
    while (i < this->n) {
        res->append(&arr[i]);
        i++;
    }
    while (j < other->n) {
        res->append(&other->arr[j]);
        j++;
    }
    return res;
}
// Driver Function
int main()
{
    Building arr[] = {
        { 1, 11, 5 }, { 2, 6, 7 }, { 3, 13, 9 }, { 12, 7, 16 }, { 14, 3, 25 }, { 19, 18, 22 }, { 23, 13, 29 }, { 24, 4, 28 }
    };
    int n = sizeof(arr) / sizeof(arr[0]);
    SkyLine* ptr = findSkyline(arr, 0, n - 1);
    cout << " Skyline for given buildings is \n";
    ptr->print();
    return 0;
}

/*
Input-
bulidings= {{ 1, 11, 5 }, { 2, 6, 7 }, { 3, 13, 9 }, { 12, 7, 16 }, { 14, 3, 25 }, { 19, 18, 22 }, { 23, 13, 29 }, { 24, 4, 28 }}
Output-
Skyline for given buildings is 
(1, 11),  (3, 13),  (9, 0),  (12, 7),  (16, 3),  (19, 18),  (22, 3),  (23, 13),  (29, 0), 
*/
