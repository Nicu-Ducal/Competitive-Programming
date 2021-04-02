#include <fstream>
#include <iostrea
using namespace std;
//ifstream cin("ceas.in");
//ofstream cout("ceas.out");
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==12)
        a=0;
    int st=a*60+b;
    int past=c*60+d;
    int day=12*60;
    if(st%65==0)
        past-=5;
    while(past>0)
    {
        st=(st+1)%day;
        --past;
        if(st%65==0)
            past-=5;
    }
    if(st/60==0)
        cout<<12<<' ';
    else cout<<st/60<<' ';
    cout<<st%60<<'\n';
    return 0;
}
