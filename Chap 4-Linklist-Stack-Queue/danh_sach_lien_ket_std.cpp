#include <iostream>
#include <list>
#include <conio.h>

using namespace std;

int main()
{
	int myints[] = {5,6,3,2,7};
	list<int> l,ll(myints, myints + sizeof(myints)/sizeof(int));
	list<int>::iterator it;
	int choice, item;
	do
	{
		system("cls");
		cout<<"\n------------------"<<endl;
		cout<<"CAI DAT DANH SACH LIEN KET BANG STL"<<endl;
		cout<<"\n------------------"<<endl;
		cout<<"1.Them phan tu vao dau"<<endl;
		cout<<"2.Them phan tu vao cuoi"<<endl;
		cout<<"3.Loai bo phan tu o dau"<<endl;
		cout<<"4.Loai bo phan tu o cuoi"<<endl;
		cout<<"5.Phan tu o dau danh sach"<<endl;
		cout<<"6.Phan tu o cuoi danh sach"<<endl;
		cout<<"7.Kich co cua danh sach"<<endl;
		cout<<"9.Loai bo phan tu co gia tri Value"<<endl;
		cout<<"10.Loai bo phan tu trung lap"<<endl;
		cout<<"11.Dao nguoc cac phan tu"<<endl;
		cout<<"12.Sap xep cac phan tu"<<endl;
		cout<<"13.Hoa nhap cac phan tu"<<endl;
		cout<<"14.Hien thi cac phan tu"<<endl;
		cout<<"0.Thoat"<<endl;
		cout<<"Nhap vao lua chon";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Node can them vao dau: ";cin>>item;
				l.push_front(item);getch();break;
			case 2:
				cout<<"Node can them vao cuoi: ";cin>>item;
				l.push_back(item);getch();break;
			case 3:
				cout<<"Loai bo phan tu o dau";
				item = l.front();
				l.pop_front();
				cout<<"Phan tu "<<item<<"da bi loai"<<endl;
				getch();break;
			case 4:
				cout<<"Loai bo phan tu o cuoi";
				item = l.back();
				l.pop_back();
				cout<<"Phan tu "<<item<<"da bi loai."<<endl;
				getch();
				break;
			case 5:
				cout<<"Phan tu o dau danh sach:"<<l.front()<<endl;
				getch();
				break;
			case 6:
				cout<<"Phan tu o cuoi danh sach: "<<l.back()<<endl;
				getch();
				break;
			case 7:
				cout<<"Kich co cua danh sach: "<<l.size()<<endl;
				getch();
				break;
			case 8:
				cout<<"Kich co moi cua danh sach: ";cin>>item;
				if(item<=l.size())
					l.resize(item);
				else
					l.resize(item,0);
				break;
			case 9:
				cout<<"Nhap noi dung node can loai: ";cin>>item;
				l.remove(item);break;
				getch();
			case 10:
				l.unique();
				cout<<"Phan tu giong nhau da bi loai"<<endl;
				getch();
				break;
			case 11:
				l.reverse();
				cout<<"Da dao nguoc node"<<endl;
				getch();
				break;
			case 12:
				l.sort();
				cout<<"Da sap xep node"<<endl;
				getch();
				break;
			case 13:
				ll.sort();
				l.sort();
				l.merge(ll);
				cout<<"Cac danh sach hoa da hoa nhap"<<endl;
				getch();
				break;
			case 14:
				cout<<"Duyet danh sach: ";
				for(it = l.begin();it!=l.end();it++)
					cout<<*it<<" ";
				cout<<endl;
				getch();
				break;
			case 0:
				break;
		}
	}while(choice !=  0);
}
