#include <iostream> 
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

void printHistogram(int counts[]);
int roll();

int main()
{
    int n;
    cout << "Please enter a number:";
    cin >> n;
    int counts[21];
    
    for(int i = 0; i < 21; i++)
    {
    counts[i] = 0;
    }

    srand (time (0));
    for (int i = 0; i < n; i++)
    {
        int d1 = roll();
        int d2 = roll();
        int d3 = roll();
        int d4 = roll();

       int sum = d1 + d2 + d3 + d4;

       counts[sum-4]++;
    }   
   
    printHistogram(counts);

    return 0;
}

void printHistogram(int counts[])
{
    for(int i=0; i<=20; i++)
    {
        cout << i+4 << ":";
    
        for(int j = 0 ; j < counts[i]; j++)
        {
            cout << "x" ;
        }
      
        cout << endl;
    }

}

int roll()
{
  int d1 = rand() % 6 + 1;
  return d1;
}
