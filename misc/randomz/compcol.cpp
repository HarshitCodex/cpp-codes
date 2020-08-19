#include<bits/stdc++.h>
#define int long long
#define vi vector<long long>
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAX 500 
#define FORN(start,end) for(int i=start; i<=end; i++)
// #define cout cout<<setprecision(15)
 
using namespace std;
 
// bool primes[100005];
// vector<int> prime;
 
// void sieve(int n) {
 
//     primes[2] = false;
//     for (int i = 2; i * i <= 100000; i++) {
//         if (primes[i] == false) {
//             for (int p = i * i; p <= 100000; p += i) {
//                 primes[p] = true;
//             }
//         }
//     }
//     for (int i = 2; i <= 100000; i++) {
//         if (primes[i] == false)
//             prime.push_back(i);
//     }
// }
 
void dfs(vi adj[],vector<bool>& isVisited,int start, vi& result) {
    
    if(isVisited[start]) {
        return;
    }
 
    isVisited[start]=true;
    result.push_back(start);
 
    for(int i=0; i<adj[start].size(); i++) {
        dfs(adj,isVisited,adj[start][i],result);
    }
 
}
 
void printVector(vi a) {
    cout<<"\n*********DEBUG**********\n";
    FORN(0,a.size()-1) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
 
void printArray(int a[], int n) {
    cout<<"\n*********DEBUG**********\n";
    FORN(0,n-1) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
 
int log22(int b) {
 
    int cnt = 0;
    while (b != 1) {
        cnt++;
        b /= 2;
    }
    return cnt;
}
 
void inVec(vi &vec, int n) {
    int temp;
    for(int i=0; i<n; i++) {
        cin>>temp;
        vec.push_back(temp);
    }
}
 
void solve() {
 
    int n;
    int a,b,c,d;
    int temp;
    int temp2;
    int temp3;
    string str;
    string res="";
    vi vec;
    int k;

    cin>>n;
    inVec(vec,n);
    map<int,int> primes;
    int cunt=1;

    for(int i=2; i<200; i++) {
        int fu=1;
        for(int j=2; j*j<=i; j++) {
            if(i%j==0) {
                fu=-1;
                break;
            }
        }
        if(fu==1) {
            primes[i]=cunt++;
        }
    }

    map<int,int> mmap;
    
    int start=1;
    int mx=LONG_LONG_MIN;
    cunt=1;
    map<int,int> finalmapffs;

    for(int i=0; i<vec.size(); i++) {   
        for(int p=2; p*p<=vec[i]; p++) {
            if(vec[i]%p==0 && primes.find(p)!=primes.end()) {
                mmap[vec[i]]=p;
//                mx=max(mx,p);
                if(finalmapffs.find(p)==finalmapffs.end()) {
                //    mx=max(mx,cunt);
                    finalmapffs[p]=cunt++;
                }
                break;
            }
        }
    }

    cout<<cunt-1<<endl;
    for(int i=0; i<n; i++) {
        cout<<finalmapffs[mmap[vec[i]]]<<" ";
    }
    cout<<endl;

}
 
int32_t main() {
    fastio;
 
    int t=1;
    cin>>t;
 
    while(t--) {
        solve();
    }
    return 0;
}