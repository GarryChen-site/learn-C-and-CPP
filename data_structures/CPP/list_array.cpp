
#include <array>
#include <iostream>

struct list {

    std::array<int,50> data{};
    int top = 0;
    bool isSorted = false;
    
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

    int LinerSearch(const std::array<int,50>& dataArr, int x) const
    {
        for(int i = 0; i < top; i++)
        {
            if(dataArr[i] == x)
            {
                return i;
            }
        }

        return -1;
    }
    

    int Search(int x)
    {
        int pos = 0;
        if(isSorted)
        {
            pos = BinarySearch(data,0,top - 1, x);

        }else
        {
            pos = LinerSearch(data,x);
        }
        
        if(pos != -1)
        {
            std::cout << "\nElement found at position : " << pos;
        } else
        {
            std::cout << "\nElement not found";
        }
        
        return pos;
    }

    void Sort()
    {
        
    }

};