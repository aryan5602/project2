#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
int main()
{
    int a[10];
    int s;
    int n;
    string tp[10], conv[10];
    ifstream file("input.txt");
    string str;
    int i = 0;
    while (getline(file, str))
    {
        string b = str.substr(0, 3);
        string c = str.substr(4, 4);
        c = c.substr(0, 3);
        string d = str.substr(8, 12);
        s = stoi(b);
        a[i] = s;
        tp[i] = c;
        conv[i] = d;
        i++;
    }
    for (int j = 0; j < i; j++)
    {
        for (int k = j + 1; k < i; k++)
        {
            if (a[j] == a[k])
            {
                string p = tp[j] + ">" + tp[k];
                tp[k] = "";
                tp[j] = p;
                a[k] = 9956;
            }
        }
    }
    ofstream f;
    string q;
    f.open("output.txt");
    for (int l = 0; l < 5; l++)
    {
        if (a[l] != 9956)
        {
            q = to_string(a[l]) + "-start>" + tp[l] + ">" + conv[l];
            f << q;
            f << endl;
        }
    }
    cout << "Data converted and inserted to output.txt file\n";
    f.close();
    cout << "Press any key and then press enter to quit\n";
    cin >> n;
}