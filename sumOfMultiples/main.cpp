//find all solutions to a^2 + b^2 = c^2 + d^2
//0<a<b<c<d<1000

#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
#include <chrono>


using namespace std;

int main(int argc, const char * argv[]) {

    auto start = chrono::steady_clock::now();
    
    multimap<int, vector<int>> data;
    
    int N = 1000;
    for(int i=0; i<N; i++)
    {
        for(int j=i+1; j<N; j++)
        {
            data.insert({(i*i*i)+(j*j*j),{i,j}});
        }
    }
    
    multimap<int, vector<int>>::iterator itr;
    
    int num,count=0;
    for(itr=data.begin(); itr!=data.end(); itr++)
    {
        num = data.count(itr->first);
        
        if(num > 1)
        {
            count += 1;
            auto range = data.equal_range(itr->first);
            
            multimap<int, vector<int>>::iterator itr2=range.first;
            cout << "a: " << itr2->second[0] << " b: " << itr2->second[1] << " ";
            itr2++;
            cout << "c: " << itr2->second[0] << " d: " << itr2->second[1] << " ";
            
            if(num > 2)
            {
                itr2++;
                cout << "e: " << itr2->second[0] << " f: " << itr2->second[1] << " ";
            }
            cout << " Sum of cubes = " << itr->first << endl;
        }
    }
    
    cout << "Total Number of  multipair solutions a,b / c,d / e,f pairs: " << count << endl;

    auto end = chrono::steady_clock::now();
    
    auto diff = end-start;
    cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;


    cout << setprecision(5);
    return 0;
}
