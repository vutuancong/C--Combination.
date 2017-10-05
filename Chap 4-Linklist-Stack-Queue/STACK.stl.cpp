#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int> st;
	int choice, item;
	do
	{
		cout<<"----------------"<<endl;
		cout<<"CAI DAI DANH SACH BANG STL"<<endl;
		cout<<"1.Them phan tu vao stack"<<endl;
		cout<<"2.Loai bo phan tu khoi stack"<<endl;
		cout<<"3.Kich thuoc cua stack"<<endl;
		cout<<"4.Phan tu dau cua stack"<<endl;
		cout<<"5.Kiem tra tinh rong cua stack"<<endl;
		cout<<"0.Thoat"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Phan tu can them vao stack"<<endl;
				cin>>item;st.push(item);break;
			case 2:
				if(!st.empty())
				{
					item = st.top();
					st.pop();
					cout<<"Phan tu "<<item<<" da bi loai"<<endl;
				}
				else cout<<"Stack rong"<<endl;
				break;
			case 3:
				cout<<"Kich co stack: ";
				cout<<st.size()<<endl;break;
			case 4:
				if(!st.empty())
				{
					cout<<"Phan tu dau tien cua stack"<<endl;
					cout<<st.top()<<endl;
				}
				else cout<<"Stack rong"<<endl;
				break;
			case 5:
				cout<<"Trang thai Stack: "<<st.empty();
				break;
			case 0: break;
		}
	}while(choice!= 0);
}
