#include<iostream>
#include<vector>
using namespace std;
void bubble_sort(vector<int>& li)
{
int tmp;
for(int i=0;i<=li.size()-2;i++)
{
for(int j=i+1;j<=li.size()-1;j++)
{
if(li[i]>li[j])
{
tmp=li[i];
li[i]=li[j];
li[j]=tmp;
}
}
}
}
int main()
{
int siz,ele;
vector<int> arr;
cout<<"Do enter the total count of elements:"<<endl;
cin>>siz;
cout<<"Enter the elements: "<<endl;
for(int i=0;i<siz;i++)
{
cin>>ele;
arr.push_back(ele);
}
cout<<endl;
bubble_sort(arr);
for(auto& vr: arr)
cout<<vr<<endl;
return 0;
}
