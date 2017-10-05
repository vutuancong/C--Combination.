#include <queue>
#include <conio.h>
#include <iostream>

using namespace std;

int main()
{
	queue<int> q;
	int choice,item;
	do
	{
		system("cls");
		cout<<"-------------------"<<endl;
		cout<<"CAI DAT HANG DOI"<<endl;
		cout<<"1.Them phan tu "<<endl;
		cout<<"2.Loai phan tu "<<endl;
		cout<<"3.Kich thuoc"<<endl;
		cout<<"4.Phan tu dau tien"<<endl;
		cout<<"5.Phan tu cuoi cung"<<endl;
		cout<<"6.Trang thai cua "<<endl;
		cout<<"0.Thoat"<<endl;
		cout<<"Dua vao lua chon: ";cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Phan tu can them: ";
				cin>>item;q.push(item);getch();break;
			case 2:
				if(!q.empty())
				{
					item = q.front();
					q.pop();
					cout<<"Phan tu "<<item<<" da bi loai"<<endl;
					
				}
				else cout<<"Queue rong"<<endl;
				getch();
				break;
			case 3:
				cout<<"Kick co cua Queue: "<<q.size()<<endl;
				getch();
				break;
			case 4:
				if(!q.empty())
				{
					cout<<"Phan tu dau hang doi: "<<q.front()<<endl;
				}
				getch();
				break;
			case 5:
				if(!q.empty())
					cout<<"Phan tu cuoi Queue: "<<q.back()<<endl;
				getch();
				break;
				
			case 6:
				cout<<"Trang thai Queue: "<<q.empty()<<endl;
				getch();
				break;
			case 0:
				break;
		}
	}while(choice!=0);
}
