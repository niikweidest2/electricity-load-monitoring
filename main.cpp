#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

const string APPLIANCES_FILE = "appliances.txt";
const string BILLING_FILE = "billing_summary.txt";
const int MAX_APPLIANCES = 100;

struct Appliance { string name; double watts; double hours; };

void flushIn(){ cin.clear(); cin.ignore(numeric_limits<streamsize>::max(),'\n'); }

string trim(string s){
    while(!s.empty() && (s[0]==' '||s[0]=='\t'||s[0]=='\r'||s[0]=='\n')) s.erase(0,1);
    while(!s.empty() && (s.back()==' '||s.back()=='\t'||s.back()=='\r'||s.back()=='\n')) s.pop_back();
    return s;
}
string lowerStr(string s){
    for(int i=0;i<(int)s.size();i++) if(s[i]>='A'&&s[i]<='Z') s[i]=char(s[i]-'A'+'a');
    return s;
}
int readInt(const string& p){
    int v;
    while(true){
        cout<<p;
        if(cin>>v){ flushIn(); return v; }
        cout<<"Invalid number. Try again.\n";
        flushIn();
    }
}
double readD(const string& p){
    double v;
    while(true){
        cout<<p;
        if(cin>>v){ flushIn(); return v; }
        cout<<"Invalid number. Try again.\n";
        flushIn();
    }
}
string readLineNZ(const string& p){
    while(true){
        cout<<p;
        string s; getline(cin,s);
        s=trim(s);
        if(!s.empty()) return s;
        cout<<"Input must not be empty.\n";
    }
}

void menu(){
    cout<<"\n1. Register appliance\n"
        <<"2. View appliances\n"
        <<"3. Search appliance\n"
        <<"4. Billing\n"
        <<"5. Save to file\n"
        <<"6. Exit\n";
}

double kwhDay(const Appliance& x){ return (x.watts/1000.0)*x.hours; }
double totalDay(const Appliance a[], int c){
    double t=0; for(int i=0;i<c;i++) t+=kwhDay(a[i]); return t;
}

void addAppliance(Appliance a[], int& c){
    if(c>=MAX_APPLIANCES){ cout<<"Limit reached.\n"; return; }
    Appliance x;
    x.name = readLineNZ("Name: ");
    do{ x.watts = readD("Watts (>0): "); }while(x.watts<=0);
    do{ x.hours = readD("Hours/day (0-24): "); }while(x.hours<0||x.hours>24);
    a[c++] = x;
    cout<<"Registered (in memory).\n";
}

int main(){
    Appliance a[MAX_APPLIANCES]; int count=0;
    cout<<"Electrical Load Monitoring & Billing System\n";
    cout<<"Loaded appliances: "<<count<<"\n";

    while(true){
        menu();
        int ch = readInt("Choose (1-6): ");
        if(ch==1) addAppliance(a,count);
        else if(ch==2) cout<<"[Part 3] View (coming)\n";
        else if(ch==3) cout<<"[Part 3] Search (coming)\n";
        else if(ch==4) cout<<"[Part 3] Billing (coming)\n";
        else if(ch==5) cout<<"[Part 3] Save (coming)\n";
        else if(ch==6){ cout<<"Goodbye!\n"; break; }
        else cout<<"Invalid choice.\n";
    }
    return 0;
}