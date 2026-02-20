/*

**Problem Statement:**
"Given an array of integers, identify all elements that appear more than once.  
For each such element, insert the total count of that element immediately after its last occurrence."

---

**Sample Input:**
```
arr = [4, 2, 4, 3, 2, 2, 5]
```

**Output:**
```
arr = [4, 2, 4, 4, 3, 2, 2, 3, 5]
```
*/


#include<bits/stdc++.h>
using namespace std;
void insertarr(int a[], int& n, int id, int val)
{
    for(int i = n; i > id; i--)
    {
        a[i] = a[i - 1];
    }
    a[id] = val;
    n++;
}
int main()
{
    int n;
    cin >> n;
    int a[100];
    int freq[101] = {0}, cnt[101] = {0};
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++)
        freq[a[i]]++, cnt[a[i]]++;
    for(int i = 0; i < n; i++)
    {
        if(freq[a[i]] >= 2)
        {
            cnt[a[i]]--;
            if(cnt[a[i]] == 0)
            {
                insertarr(a, n, i + 1, freq[a[i]]);
            }
        }
    }

    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
}
