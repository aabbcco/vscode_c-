#include<iostream>
#include<vector>

using namespace std;

template<typename T>
void mgs(size_t begin, size_t end,T &vec);

template<typename T>
void mergesort(T &vec)
{
    if(0==vec.size()||1==vec.size())
        return;
    size_t start = 0, end = vec.size()-1;
    return mgs(start, end, vec);
}

template<typename T>
void mgs(size_t begin, size_t end,T &vec)
{
    if (begin >= end)
        return;
    auto mid = (begin + end) >> 1;
    mgs(begin, mid, vec);
    mgs(mid+1, end, vec);
    T tmp(end - begin+1, 0);
    size_t frt=begin, bak=mid+1, tar=0;
    while(frt<=mid&&bak<=end)
    {
        tmp[tar++] = vec[frt] < vec[bak] ? vec[frt++] : vec[bak++];
    }
    while(frt<=mid)
    {
        tmp[tar++] = vec[frt++];
    }
        while(bak<=end)
    {
        tmp[tar++] = vec[bak++];
    }
    for (auto i = 0; i <= end - begin;i++)
    {
        vec[begin + i] = tmp[i];
    }
}


int main()
{
    vector<long> vec = { 5, 4,3,2,1};
    mergesort(vec);
    for(auto &&ele:vec)
    {
        cout << ele << ' ';
    }
    cout << "end";
    return 0;
}