#include <iostream>
#include <string>
#include <map>
#include <locale>

using namespace std;

struct Index
{
    int PNum;
    int In[100];
};

int main()
{
    //system("chcp 1251");
    setlocale(LC_ALL,"Russian");
    map<string, int> KeyValue;
    map<int, string> ValueKey;
    map<string, Index> NewWords;
    string tmp,tmp1, tmpd;
    bool Rus=false;
    char tmp2;
    int N;
    cin >> N;
    scanf("%c",&tmp2);
    for (int i = 1; i <= N; i++)
    {
        getline(cin,tmp);

        if(i==1&&(int)tmp[0]>=-64&&(int)tmp[0]<=1) Rus=true;

        if(Rus==true)
        {
            for(int o=0;o<tmp.length();o++)
            {
                  if((int)tmp[o]>=192&&(int)tmp[o]<=223)
                  {
                     tmp[o]=(char)((int)tmp[o]+32);
                  }

            }
            KeyValue[tmp] = i;
            ValueKey[i] = tmp;

            for (int j = 0; j < tmp.length() - 1; j++)
            {
                swap(tmp[j], tmp[j + 1]);
                NewWords[tmp].PNum++;
                NewWords[tmp].In[NewWords[tmp].PNum] = i;
                swap(tmp[j], tmp[j + 1]);
            }

            for (int j = 0; j < tmp.length(); j++)
            {
                tmpd = tmp.substr(0, j) + tmp.substr(j + 1, tmp.length() - 1);
                NewWords[tmpd].PNum++;
                NewWords[tmpd].In[NewWords[tmpd].PNum] = i;
            }

            for (int j = 0; j < tmp.length(); j++)
            {
                tmpd = tmp;
                for (int k = 32; k <= 47; k++)
                {
                    if ((int)tmpd[j] != k)
                    {
                        tmpd[j] = (char)k;
                        NewWords[tmpd].PNum++;
                        NewWords[tmpd].In[NewWords[tmpd].PNum] = i;
                    }
                }

                tmpd = tmp;
                for (int k = 58; k <= 64; k++)
                {
                    if ((int)tmpd[j] != k)
                    {
                        tmpd[j] = (char)k;
                        NewWords[tmpd].PNum++;
                        NewWords[tmpd].In[NewWords[tmpd].PNum] = i;
                    }
                }

                tmpd = tmp;
                for (int k = 224; k <= 255; k++)
                {
                    if ((int)tmpd[j] != k)
                    {
                        tmpd[j] = (char)k;

                        NewWords[tmpd].PNum++;
                        NewWords[tmpd].In[NewWords[tmpd].PNum] = i;
                    }
                }
            }

            for (int j = 0; j < tmp.length() + 1; j++)
            {
                if (j == 0)
                {
                    for (int k = 224; k <= 255; k++)
                    {
                        tmpd = (char)k + tmp;
                        NewWords[tmpd].PNum++;
                        NewWords[tmpd].In[NewWords[tmpd].PNum] = i;
                    }
                    for (int k = 32; k <= 47; k++)
                    {
                        tmpd = (char)k + tmp;
                        NewWords[tmpd].PNum++;
                        NewWords[tmpd].In[NewWords[tmpd].PNum] = i;
                    }
                    for (int k = 58; k <= 64; k++)
                    {
                        tmpd = (char)k + tmp;
                        NewWords[tmpd].PNum++;
                        NewWords[tmpd].In[NewWords[tmpd].PNum] = i;
                    }
                }
                else
                {
                    for (int k = 224; k <= 255; k++)
                    {
                        tmpd = tmp.substr(0, j) + (char)k + tmp.substr(j, tmp.length());
                        NewWords[tmpd].PNum++;
                        NewWords[tmpd].In[NewWords[tmpd].PNum] = i;
                    }
                    for (int k = 32; k <= 47; k++)
                    {
                        tmpd = tmp.substr(0, j) + (char)k + tmp.substr(j, tmp.length());
                        NewWords[tmpd].PNum++;
                        NewWords[tmpd].In[NewWords[tmpd].PNum] = i;
                    }
                    for (int k = 58; k <= 64; k++)
                    {
                        tmpd = tmp.substr(0, j) + (char)k + tmp.substr(j, tmp.length());
                        NewWords[tmpd].PNum++;
                        NewWords[tmpd].In[NewWords[tmpd].PNum] = i;
                    }
                }
            }
        }
        else
        {
            for(int o=0;o<tmp.length();o++)
            {
                  if((int)tmp[o]>=65&&(int)tmp[o]<=90)
                  {
                     tmp[o]=(char)((int)tmp[o]+32);
                  }

            }
            KeyValue[tmp] = i;
            ValueKey[i] = tmp;

            for (int j = 0; j < tmp.length() - 1; j++)
            {
                swap(tmp[j], tmp[j + 1]);
                NewWords[tmp].PNum++;
                NewWords[tmp].In[NewWords[tmp].PNum] = i;
                swap(tmp[j], tmp[j + 1]);
            }

            for (int j = 0; j < tmp.length(); j++)
            {
                tmpd = tmp.substr(0, j) + tmp.substr(j + 1, tmp.length() - 1);
                NewWords[tmpd].PNum++;
                NewWords[tmpd].In[NewWords[tmpd].PNum] = i;
            }

            for (int j = 0; j < tmp.length(); j++)
            {
                tmpd = tmp;
                for (int k = 32; k <= 47; k++)
                {
                    if ((int)tmpd[j] != k)
                    {
                        tmpd[j] = (char)k;
                        NewWords[tmpd].PNum++;
                        NewWords[tmpd].In[NewWords[tmpd].PNum] = i;
                    }
                }

                tmpd = tmp;
                for (int k = 58; k <= 64; k++)
                {
                    if ((int)tmpd[j] != k)
                    {
                        tmpd[j] = (char)k;
                        NewWords[tmpd].PNum++;
                        NewWords[tmpd].In[NewWords[tmpd].PNum] = i;
                    }
                }

                tmpd = tmp;
                for (int k = 91; k <= 126; k++)
                {
                    if ((int)tmpd[j] != k)
                    {
                        tmpd[j] = (char)k;
                        NewWords[tmpd].PNum++;
                        NewWords[tmpd].In[NewWords[tmpd].PNum] = i;
                    }
                }
            }

            for (int j = 0; j < tmp.length() + 1; j++)
            {
                if (j == 0)
                {
                    for (int k = 91; k <= 126; k++)
                    {
                        tmpd = (char)k + tmp;
                        NewWords[tmpd].PNum++;
                        NewWords[tmpd].In[NewWords[tmpd].PNum] = i;
                    }
                    for (int k = 32; k <= 47; k++)
                    {
                        tmpd = (char)k + tmp;
                        NewWords[tmpd].PNum++;
                        NewWords[tmpd].In[NewWords[tmpd].PNum] = i;
                    }
                    for (int k = 58; k <= 64; k++)
                    {
                        tmpd = (char)k + tmp;
                        NewWords[tmpd].PNum++;
                        NewWords[tmpd].In[NewWords[tmpd].PNum] = i;
                    }
                }
                else
                {
                    for (int k = 91; k <= 126; k++)
                    {
                        tmpd = tmp.substr(0, j) + (char)k + tmp.substr(j, tmp.length());
                        NewWords[tmpd].PNum++;
                        NewWords[tmpd].In[NewWords[tmpd].PNum] = i;
                    }
                    for (int k = 32; k <= 47; k++)
                    {
                        tmpd = tmp.substr(0, j) + (char)k + tmp.substr(j, tmp.length());
                        NewWords[tmpd].PNum++;
                        NewWords[tmpd].In[NewWords[tmpd].PNum] = i;
                    }
                    for (int k = 58; k <= 64; k++)
                    {
                        tmpd = tmp.substr(0, j) + (char)k + tmp.substr(j, tmp.length());
                        NewWords[tmpd].PNum++;
                        NewWords[tmpd].In[NewWords[tmpd].PNum] = i;
                    }
                }
            }

        }
    }
    string print0,print;
    getline(cin,tmp1);
    while(getline(cin,print0))
    {
        if(print0=="") continue;
        print=print0;
         for(int o=0;o<print.length();o++)
         {
             if((int)print[o]>=65&&(int)print[o]<=90)
             {
             print[o]=(char)((int)print[o]+32);
             }

        }
        tmpd.clear();
        if (KeyValue[print] > 0) cout << print << " - ok" << endl;
        else
        {
            if (NewWords[print].PNum == 1)
            {
                cout << print0 << " -> " << ValueKey[NewWords[print].In[NewWords[print].PNum]] << endl;
            }
            else if (NewWords[print].PNum > 1)
            {
                for(int l=1;l<=NewWords[print].PNum;l++)
                {
                    for(int p=1;p<=NewWords[print].PNum;p++)
                    {
                        if(ValueKey[NewWords[print].In[p]]>=ValueKey[NewWords[print].In[l]])
                        {
                            swap(NewWords[print].In[p],NewWords[print].In[l]);
                        }
                    }
                }

                cout << print0 << " -> " << ValueKey[NewWords[print].In[1]];
                for (int k = 2; k <= NewWords[print].PNum; k++)
                {
                    if(ValueKey[NewWords[print].In[k-1]]==ValueKey[NewWords[print].In[k]]);
                    else
                    {
                        tmpd += ", ";
                        tmpd += ValueKey[NewWords[print].In[k]];
                    }

                }
                cout << tmpd << endl;
            }
            else
                cout << print0 << " -?" << endl;
        }
    }
    cin.clear();
    cin.get();
}
