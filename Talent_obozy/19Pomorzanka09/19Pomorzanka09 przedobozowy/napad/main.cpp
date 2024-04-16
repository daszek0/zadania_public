#include <iostream>

using namespace std;

int minvaluefromarray(int a[], int b, bool c, bool d[],bool e)
{
    int result, place, ei=0;
    for(int i=0;i<b;i++)
    {
        if(d[i]==e)
            ei++;
    }
    if(ei==0 && c==true)
        return 0;
    else if(ei==0 && c==false)
        return -1;
    for(int i=0;i<b;i++)
    {
        if (a[i]<result && d[i]==e)
        {
            result=a[i];
            place=i;
        }
    }
    if (c==true)
        return result;
    else if (c==false)
        return place;
}

int main()
{
	int n, k;
	cin>>n>>k;
	int w[n], c[n], j[k], cj[k], wj[k];
	bool usedn[n];
	for(int i=0;i<n;i++)
    {
        cin>>w[i]>>c[i];
    }
    for(int i=0;i<k;i++)while(wj[i]<j[i])
    {
        j[i]=i+1;
    }

    for(int i=0;i<k;i++)
    {
        cj[i]=0;
        wj[i]=0;
        for(int ii=0;ii<n;ii++)
        {
            cj[i]+=c[ii];
            wj[i]+=w[ii];
            usedn[ii]=true;
        }
        do
        {
            while(wj[i]>j[i])
            {
                cj[i]-=minvaluefromarray(c,n,true,usedn,true);
                if(minvaluefromarray(c,n,false,usedn,true)>-1)
                {
                    wj[i]-=w[minvaluefromarray(c,n,false,usedn,true)];
                    usedn[minvaluefromarray(c,n,false,usedn,true)]=false;
                }
                else
                    break;
            }
            while(wj[i]<j[i])
            {
                cj[i]+=minvaluefromarray(c,n,true,usedn,false);
                if(minvaluefromarray(c,n,false,usedn,false)>-1)
                {
                    wj[i]+=w[minvaluefromarray(c,n,false,usedn,false)];
                    usedn[minvaluefromarray(c,n,false,usedn,false)]=true;
                }
                else
                    break;
            }
        } while(wj[i]<j[i] && minvaluefromarray(c,n,false,usedn,false)>-1);
    }

    for(int i=0;i<k;i++)
    {
        cout<<cj[i]<<" ";
    }
    return 0;
}
