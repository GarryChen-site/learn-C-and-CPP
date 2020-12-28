
#include <array>
#include <iostream>

struct list {

    std::array<int,50> data{};
    int top = 0;
    
    int BinarySearch(const std::array<int,50>& dataArr, int first, int last,int x)
    {
        if(last < first)
        {
            return -1;
        }
        int mid = (first + last) / 2;
        if(dataArr[mid] == x)
        {
            return mid;
        }else if (x < dataArr[mid])
        {
            return (BinarySearch(dataArr, first, mid-1, x));
        }else if(x > dataArr[mid])
        {
            return (BinarySearch(dataArr, mid + 1, last, x));
        }
         std::cerr << __func__ << ":" << __LINE__ << ": Undefined condition\n";
         return -1;
    }
    

    int Search(int x)
    {
        int pos = 0;

        return pos;
    }

}