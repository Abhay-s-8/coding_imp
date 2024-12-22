//  Mars Exploration

// #include <bits/stdc++.h>
// #include <string.h>
// #include <cmath>
// using namespace std;

// int main() 
// {
//    string s ;
//    cin>>s;
//    int count = 0;
   
//    int str_length = 0;
//    for(int i=0 ;  s[i] != '\0' ;i++)
//    {
//      str_length ++;
//    }
   
//   string st = "SOS";
//    for(int j=0 ; j < (str_length/3) - 1; j++)
//    {
//      st += "SOS";
     
//    }
   
//    for(int i=0 ; i<str_length; i++)
//    {
//      if(st[i] != s[i])
//      {
//        count++;
//      }
//    }
   
//    cout<<count;
//     return 0;
    
// }

//----------funny string question

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int q;
//     cin >> q;
//     for (int i = 0; i < q; i++) {
//         string str;
//         cin >> str;
//         string rev_str = str;
//         reverse(rev_str.begin(), rev_str.end());

//         int flag = 1;
//         for (int j = 0; j < str.length() - 1; j++) {
//             int diff1 = abs(str[j] - str[j + 1]);
//             int diff2 = abs(rev_str[j] - rev_str[j + 1]);
//             if (diff1 != diff2) {
//                 flag = 0;
//                 break;
//             }
//         }

//         if (flag == 1) {
//             cout << "Funny" << endl;
//         } else {
//             cout << "Not Funny" << endl;
//         }
//     }
//     return 0;
// }

