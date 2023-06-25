#include <bits/stdc++.h>
#include<iostream>
#include <vector>
#include <set>
#include <string>
#include <fstream>
using namespace std;

set<int> intersection(set<int> set1,set<int> set2) {
    set<int> result;
    for (int x : set1) {
        if (set2.count(x)) {
            result.insert(x);
        }
    }
    return result;
}




void makenf(int state,vector<vector<set<int>>>& transs,char x,set <int>&y,vector<char> Sigma) {

    set <int> w;
    set <int> t;
    auto firsts=transs.begin();
    auto r=(*(firsts + state)).begin();
    
        auto it = find(Sigma.begin(),Sigma.end(), x);
        int jai=(it - Sigma.begin());
        auto z=(*(r+jai));
        for (const auto& elem : z) 
        {
            y.insert(elem);
            makenf(elem,transs,'$',w,Sigma);
        }

    

    auto itt = find(Sigma.begin(),Sigma.end(), '$');
    int jaii=(itt - Sigma.begin());
    auto zz=(*(r+jaii));
        for (const auto& elem : zz) 
        {

            
            makenf(elem,transs,x,t,Sigma);
        }

    y.insert(w.begin(),w.end());
    y.insert(t.begin(),t.end());
    
}



void printSet(set<int> mySet) {
  for (auto const& element: mySet) {
    cout << element << " ";
  }
  cout << std::endl;
}

void printVector(vector<char> v) {
    cout <<" ";
    for(int i=0; i<v.size(); i++) {
        cout <<" "<< v[i] << "    ";
    }
    cout << endl;
}


void makeDf(set<int> statess,vector<vector<set<int>>>& transs,char x,set <int>&y,vector<char> Sigma) {

    for (const auto& state : statess)
    {
    auto firsts=transs.begin();
    auto r=(*(firsts + state)).begin();
    
    auto it = find(Sigma.begin(),Sigma.end(), x);
    int jai=(it - Sigma.begin());
    auto z=(*(r+jai));
    for (const auto& elem : z) 
    {
    y.insert(elem);
    }
    }
    
    
}













void printTrans(const vector<vector<set<int>>>& transs) {
    for (const auto& row : transs){
        for (const auto& col : row) {
            cout << "{ ";
            for (const auto& elem : col) {
                cout << elem << " ";
            }
            cout << "} ";
        }
        cout << "\n";
    }
}



int main (){

    int q,s,a,m,n;
    cin>>q;
    cin>>s;
    cin>>a;
    cin>>m;
    cin>>n;
    vector<char> Sigma;
    set<int> Accepting_State;
    vector<set<int>> satrtrans;
    vector <vector<set<int>>> trans;

    for (size_t i = 0; i < s; i++)
    {
        char x;
        cin>>x;
        Sigma.push_back(x);
    }
    
    int q0;
    cin>>q0;
        for (size_t i = 0; i < a; i++)
    {
        int x;
        cin>>x;
        Accepting_State.insert(x);
    }

    for (size_t j = 0; j < s+1; j++)
    {
        set<int> x;
        satrtrans.push_back(x);
    }

    for (size_t i = 0; i < q; i++)
    {
        trans.push_back(satrtrans);
    }

    auto firsts=trans.begin();
    for (size_t j = 0; j < m; j++)
    {
        int f,e;
        char x;
        cin>>f;
        cin>>x;
        cin>>e;
        auto it = std::find(Sigma.begin(),Sigma.end(), x);
        int jai=(it - Sigma.begin());
        auto r=(*(firsts + f)).begin();
        (*(r+jai)).insert(e);

    }

/*
cout<<"lambda NFA :\n";
printTrans(trans);
cout<<endl;
*/


for (size_t i = 0; i < q; i++)
{
    set<int> y;
    makenf(i,trans,'$',y,Sigma);
    if((intersection(Accepting_State,y)).size()!=0)
    {
        Accepting_State.insert(i);
    }
        
}








vector <vector<set<int>>> newtrans;
auto sss=Sigma.begin();


 for (size_t i = 0; i < q; i++)
 {  
    vector<set<int>> satrtranss;
    for (size_t j = 0; j < s; j++)
    {
    set<int> y;
    makenf(i,trans,*(sss+j),y,Sigma);

    satrtranss.push_back(y);
    }
    newtrans.push_back(satrtranss);
 }








/*
cout<<" NFA without lambda :\n";
printTrans(newtrans);
cout<<endl;
*/

vector <vector<set<int>>> newDFAtrans;
vector<set<int>> QQ;
set<int>q00;
q00.insert(q0);
QQ.push_back(q00);
auto it=QQ.begin();
int sizq=QQ.size();
for (int ii=0; ii<sizq; ii++)
{
    it=QQ.begin();
    it=it+ii;

    int kk=it-QQ.begin();
    vector<set<int>> sartrdfa;
    auto sss=Sigma.begin();
    for (size_t j = 0; j < s; j++)
    {


    set<int> y;
    makeDf(*it,newtrans,*(sss+j),y,Sigma);

    if(y.size()!=0)
    {
    auto dd=find(QQ.begin(),QQ.end(), y);
    if(dd==QQ.end())   
    {    
        QQ.push_back(y);
        sizq=QQ.size();
    }
    }
    sartrdfa.push_back(y);
    it=QQ.begin();
    it=it+ii;
    }
    newDFAtrans.push_back(sartrdfa);
}

int sizeqq =QQ.size();
vector<set<int>> sartrdfa;
set<int> y;
y.insert(sizeqq);
for (size_t j = 0; j < s; j++)
{
    sartrdfa.push_back(y);
}
newDFAtrans.push_back(sartrdfa);


for (auto& row : newDFAtrans){
    for (auto& col : row) {
        if(col.empty())
        {
            col.insert(sizeqq);
        }
        }
    }


/*
cout<<" DFA :\n";
printTrans(newDFAtrans);
cout<<endl;
*/

set<int> ADFA;

for (auto row=QQ.begin();row!=QQ.end();row++){
    int w=row-QQ.begin();
    for (auto& elem : *row) {
        int p=0;
        for (auto& ax : Accepting_State)
        {
            if(ax==elem)
            {
                p=1;
                int e=row-QQ.begin();
                ADFA.insert(e);
                break;
            }
            
        }
        if (p==1)
        {
            break;
        }
        }
    row=QQ.begin()+w;


    }




vector <vector<set<int>>> ADFtrans;
sss=Sigma.begin();
auto asa=newDFAtrans.begin();

 for (size_t i = 0; i < sizeqq+1; i++)
 {  
    asa=asa+i;
    vector<set<int>> satrtranss;
    for (size_t j = 0; j < s; j++)
    {

    auto x=*((*asa).begin()+j);
    set<int> y;
    int q=(find(QQ.begin(),QQ.end(), x))-QQ.begin();
    y.insert(q);
    
    satrtranss.push_back(y);
    }
    ADFtrans.push_back(satrtranss);
    asa=newDFAtrans.begin();
 }


cout<<" DFA final :\n";
cout<<" number of states :"<<sizeqq+1<<endl;
cout<<" number of Accepting State :"<< ADFA.size()<<" -> ";
printSet(ADFA);
cout<<" first state : 0"<<endl;
cout<<endl;
printVector(Sigma);
printTrans(ADFtrans);
cout<<endl;



string sn[n];

for (size_t i = 0; i < n; i++)
{
    string x;
    cin >>x;
    sn[i]=x;
}



for (size_t i = 0; i < n; i++)
{
    int qnow=0;
    int qnext;

    string x;
    x=sn[i];
            if(sn[i]=="$")
        {
            if(find(ADFA.begin(),ADFA.end(), 0)!=ADFA.end())
            {
                cout<<"YES \n";
                
            }
            else
            {
              cout<<"NO \n";
                
            }
        }
    else
    {
        for (size_t i = 0; i < x.size(); i++)
        {
            char alpabet=x[i];
            auto it = find(Sigma.begin(),Sigma.end(), alpabet);
            int jai=(it - Sigma.begin());
            qnext=*((*((*(ADFtrans.begin()+qnow)).begin()+jai)).begin());
            qnow=qnext;

            
        }
        auto u=find(ADFA.begin(),ADFA.end(), qnow);
        if (u==ADFA.end())
        {
            cout<<"NO \n";
        }
        else
        {
            cout<<"YES \n";
        }

    }
}




    return 0;



}