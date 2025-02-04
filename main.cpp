//  Mars Exploration

#include <bits/stdc++.h>
#include <string.h>
#include <cmath>
using namespace std;

int main() 
{
   string s ;
   cin>>s;
   int count = 0;
   
   int str_length = 0;
   for(int i=0 ;  s[i] != '\0' ;i++)
   {
     str_length ++;
   }
   
   string st = "SOS";
   for(int j=0 ; j < (str_length/3) - 1; j++)
   {
     st += "SOS";
     
   }
   
   for(int i=0 ; i<str_length; i++)
   {
     if(st[i] != s[i])
     {
       count++;
     }
   }
   
   
    return 0;
    
}

//----------funny string question

#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        string str;
        cin >> str;
        string rev_str = str;
        reverse(rev_str.begin(), rev_str.end());

        int flag = 1;
        for (int j = 0; j < str.length() - 1; j++) {
            int diff1 = abs(str[j] - str[j + 1]);
            int diff2 = abs(rev_str[j] - rev_str[j + 1]);
            if (diff1 != diff2) {
                flag = 0;
                break;
            }
        }

        if (flag == 1) {
            cout << "Funny" << endl;
        } else {
            cout << "Not Funny" << endl;
        }
    }
    return 0;
}


//jumping on the cloud : revisited
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int aar[n];
    int k;
    cin >> k;
    for(int i = 0; i < n; i++) {
        cin >> aar[i];
    }
    int e = 100;
    int i = 0;
    while(true) {
        e--;
        if(aar[i] == 1) {
            e -= 2;
        }
        i = (i + k) % n;
        if(i == 0) {
            break;
        }
    }
    cout << e << endl;
    return 0;
}

//append and delete

#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    cin >> str;
    string spp;
    cin >> spp;
    int k;
    cin >> k;

    int count = 0;
    for (int i = 0; i < min(str.length(), spp.length()); i++) {
        if (str[i] == spp[i]) {
            count++;
        } else {
            break;
        }
    }

    int x = str.length() - count;
    int y = spp.length() - count;

    if (x + y <= k) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

//chocolate feast 


#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;

    while (q--) {
        int n, c, m;
        cin >> n >> c >> m;

        int wrappers = n / c;
        int chocolates = wrappers;

        while (wrappers >= m) {
            int newChocolates = wrappers / m;
            chocolates += newChocolates;
            wrappers = newChocolates + (wrappers % m);
        }

        cout << chocolates << endl;
    }

    return 0;
}

// 2d array input

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n ,m;
    cin>>n>>m;
    
    int array[n][m];

    for(int i=0 ;i<n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>array[i][j];
        }
    }
    
    int transpose[m][n];

    for(int i=0 ;i<m ;i++)
    {
        for(int j=0;j<n;j++)
        {
            transpose[j][i] = array[i][j];
        }
    }
    
        for(int i=0 ;i<m ;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<transpose[i][j];
        }
    }

return 0;

}


  //drawing book

  #include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p;
    cin >> n >> p;

    int frontTurns = p / 2;
    int backTurns = (n / 2) - (p / 2);

    cout << min(frontTurns, backTurns) << endl;

    return 0;
}