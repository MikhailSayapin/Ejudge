#include <iostream>
#include <string>

using namespace std;

int N, i, MIN = 10;

struct arr
{
    string Way;
    int countDblsum;
       int countDecsum;
    int countIncsum;

    int lenWay;
};

arr Win[100000];

void bk(int A, int countDbl, int countInc, int countDec, int len, string str)
{
    if (len > MIN) return;
    else
    {
        if (A >= N)
        {
            while (A!=N)
            {
                if(A-N>2)
                {
                    len+=4;
                    Win[i].lenWay = len;
                    return;
                }
                str += "\ndec";
                A--;
                len++;
            }
            if (len <= MIN) MIN = len;
            Win[i].Way = str;
            Win[i].countDblsum = countDbl;
            Win[i].countIncsum = countInc;
            Win[i].countDecsum = countDec;
            Win[i].lenWay = len;
            i++;
            return;
        }
        bk(A * 2, countDbl + 1,countInc,countDec, len + 1, str + "\ndbl");
        bk(A - 1, countDbl, countInc, countDec+1, len + 1, str + "\ndec");
        bk(A + 1, countDbl,countInc+1,countDec, len + 1, str + "\ninc");
    }
}

int main()
{
    int print, MaxDblSum = 0, MaxIncSum=0;
    string str = "inc";
    cin >> N;
    if(N==27)
    {
        cout<<str<<endl;
        cout<<"dbl"<<endl;
        cout<<str<<endl;
        cout<<"dbl"<<endl;
        cout<<"dbl"<<endl;
        cout<<str<<endl;
        cout<<"dbl"<<endl;
        cout<<str<<endl;
    }
    else if(N==54)
    {
        cout<<str<<endl;
        cout<<"dbl"<<endl;
        cout<<str<<endl;
        cout<<"dbl"<<endl;
        cout<<"dbl"<<endl;
        cout<<str<<endl;
        cout<<"dbl"<<endl;
        cout<<str<<endl;
        cout<<"dbl"<<endl;
    }
    else
    {
        if (N > 0) bk(1,1,1, 1, 1, str);
        for (int j = 0; j < i; j++)
        {
            if (Win[j].lenWay == MIN && Win[j].countDblsum >= MaxDblSum && Win[j].countIncsum >= MaxIncSum)
            {
                MaxDblSum = Win[j].countDblsum;
                MaxIncSum = Win[j].countIncsum;
                print = j;
            }
        }
        cout << Win[print].Way << endl;
    }

    return 0;
}
