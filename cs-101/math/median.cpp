#include <iostream>
#include <memory.h>

using namespace std;

int* merge(int* l, int v, int* r, int w)
{
    int len = v + w;
    int* o = new int[len];
    int* p = o;

    // copy array 1
    for (int i = 0; i < v; i++)
    {
        *p++ = l[i];
    } 

    // copy array 2.
    for (int j = 0; j < w; j++)
    {
        *p++ = r[j];
    }

    return o;
}

void sort(int* p, int len)
{
    bool swapped = true;

    // sort
    while (swapped)
    {
        swapped = false;
        
        for (int x = 0; x < len; x++)
        {
            for (int y = x; y < len; y++)
            {
                if (y != x)
                {
                    if (p[x] > p[y]) 
                    {
                        int tmp = p[y];
                        p[x] = p[y];
                        p[y] = tmp;

                        swapped = true;
                        break;
                    }
                }
            }
        }
    }
}

int merge_sort(int* l, int v, int *r, int w, int** o)
{
    int len = v + w;

    *o = merge(l, v, r, w);

    sort(*o, len);

    return len;
}

int main(int args, char* argv[])
{
    int set1[2] = {1, 2};
    int set2[2] = {3, 4};

    int* set = 0;

    int len = merge_sort(set1, sizeof(set1)/sizeof(set1[0]), 
            set2, sizeof(set2)/sizeof(set2[0]), &set); 

    float median = 0;
    int i = len / 2;

    cout << "len: " << i << "=" <<  len << endl;

    if (len % 2 == 0)
    {
        median = (float)(set[i-1] + set[i]) / 2;
    }
    else 
    {
       median = set[i + 1];
    }
    
    for (int i = 0; i < len; i++)
        cout << set[i] << " ";
    cout << endl;

    cout << "median: " << median << endl;

    if (set) delete set;

    return 0;
}
