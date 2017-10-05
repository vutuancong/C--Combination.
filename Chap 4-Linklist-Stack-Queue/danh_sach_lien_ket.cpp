#include <iostream>
#include <conio.h>
using namespace std;

struct node
{
	int info;
	struct node *next;
}*start;

class single_linked_list
{
	public:
		node *create_node(int);
		void insert_begin();
		void insert_pos();
		void insert_last();
		void delete_pos();
		void sort();
		void search();
		void update();
		void reverse();
		void display();
		single_linked_list()
		{
			start = NULL;
		}
};

node *single_linked_list::create_node(int value)
{
	node *temp;
	temp = new node;
	
	if(temp == NULL)
	{
		cout<<"Khong du bo nho"<<endl;
		return 0;
	}
	else
	{
		temp->info = value;
		temp->next = NULL;
		return temp;
	}
}

void single_linked_list::insert_begin()
{
	int value;
	cout<<"Nhap gia tri node: ";cin>>value;
	node *temp, *p;
	temp = create_node(value);
	if(start == 0 )
	{
		start = temp;
		start->next = NULL;
	}
	else 
	{
		p = start;
		start = temp;
		start->next = p;
	}
	cout<<"Hoan thanh them node vao dau"<<endl;
	getch();
}
void single_linked_list::insert_last()
{
	int value;
	cout<<"Nhap gia tri cho node: ";cin>>value;
	struct node *temp, *s;
	temp = create_node(value);
	if(start == NULL)
	{
		start = temp;
		temp->next =NULL;
		return;
	}
	s = start;
	while(s->next != NULL)
	{
		s = s->next;
	}
	temp->next = NULL;
	s->next = temp;
	cout<<"Hoan thanh them node vao cuoi"<<endl;
	getch();
}
void single_linked_list::insert_pos()
{
	int value, pos, counter = 0;
	cout<<"Nhap gia tri node: ";cin>>value;
	struct node *temp, *s, *ptr;
	temp = create_node(value);
	cout<<"Vi tri can them: ";cin>>pos;
	int i;
	s = start;
	while(s!= NULL)
	{
		s = s->next;counter++;
	}
	if(counter == 0)
	{
		cout<<"Danh9 sach rong"<<endl;
	}
	if(pos == 1)
	{
		if(start == NULL)
		{
			start = temp;
			start->next = NULL;
		}
		else
		{
			ptr = start;
			start = temp;
			start->next = ptr;
		}
	}
	else if(pos > 1 && pos <=counter)
	{
		s = start;
		for(i = 1;i<pos;i++)
		{
			ptr = s;
			s = s->next;
		}
		ptr->next = temp;
		temp->next = s;
	}
	else
	{
		cout<<"Vi tri pos khong hop le "<<endl;
	}
	getch();
}

void single_linked_list::sort()
{
	struct node *ptr, *s;
	int value;
	if(start == NULL)
	{
		cout<<"KHong phai lam gi"<<endl;
		return;
	}
	ptr = start;
	while(ptr != NULL)
	{
		for( s= ptr->next;s!=NULL;s = s->next)
		{
			value = ptr->info;
			ptr->info = s->info;
			s->info = value;
		}
	}
	ptr = ptr->next;
}
void single_linked_list::delete_pos()
{
	int pos, i, counter = 0;
	if(start == NULL)
	{
		cout<<"Danh sach rong"<<endl;
		return;
	}
	cout<<"Vi tri can loai: ";cin>>pos;
	struct node *s, *ptr;
	s = start;
	if(pos == 1)
	{
		start = s->next;
		delete(s);
		return;
	}
	else
	{
		while(s!=NULL)
		{
			s = s->next;
			counter++;
		}
		if(pos >0 && pos <= counter)
		{
			s =start;
			for(i  = 1;i <pos;i++)
			{
				ptr = s;
				s = s->next;
			}
			ptr->next = s->next;
			delete(s);
		}
		else
		{
			cout<<"Neu vi tri khong hop le"<<endl;
		}
	}
	getch();
}
void single_linked_list::update()
{
	int value, pos, i;
	if(start == NULL)
	{
		cout<<"Danh sach rong"<<endl;
		return ;
	}
	cout<<"Vi tri node can cap nhat:";cin>>pos;
	cout<<"Gia tri moi cua node: ";cin>>value;
	struct node *s, *ptr;
	s = start;
	if(pos == 1)
	{
		start->info = value;
	}
	else 
	{
		for(i = 0;i<pos -1;i++)
		{
			if(s == NULL)
			{
				cout<<"Vi tri "<<pos<<"Khong hop le";return;
			}
			s = s->next;
		}
		s->info = value;
	}
	cout<<"Cap nhat thanh cong"<<endl;
	getch();
}
void single_linked_list::search()
{
	int value, pos = 0;
	bool flag = false;
	if(start == NULL)
	{
		cout<<"Danh sach rong"<<endl;
		return;
	}
	cout<<"Gia tri can tim: ";cin>>value;
	struct node *s; s = start;
	while(s != NULL)
	{
		pos++;
		if(s->info == value)
		{
			flag = true;
			cout<<"Gia tri "<<value<<"tai vi tri"<<pos<<endl;
		}
		s = s->next;
	}
	if(!flag) cout<<"Gia tri"<<value<<"khong ton tai trong danh sach"<<endl;
	getch();
}
void single_linked_list::reverse()
{
	struct node *ptr1, *ptr2, *ptr3;
	if(start == NULL)
	{
		cout<<"Danh sach rong"<<endl;
		return;
	}
	if(start->next == NULL)
	{
		return;
	}
	ptr1 = start;
	ptr2 = ptr1->next;
	ptr3 = ptr2->next;
	ptr1->next = NULL;
	ptr2->next = ptr1;
	while(ptr3!= NULL)
	{
		ptr1 = ptr2;
		ptr2 = ptr3;
		ptr3 = ptr3->next;
		ptr2->next = ptr1;
	}
	start = ptr2;
}
void single_linked_list::display()
{
	node *temp;
	if(start == 0)
	{
		cout<<"Danh sach rong"<<endl;
		return;
	}
	temp = start;
	cout<<"Noi dung danh sach"<<endl;
	while(temp!=0)
	{
		cout<<temp->info<<"->";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
	getch();
}
int main()
{
	int choice;
	single_linked_list X;
	start = NULL;
	while(1)
	{
		cout<<endl<<"------------------------"<<endl;
		cout<<endl<<"Cac thao tac tren DSLKD"<<endl;
		cout<<endl<<"------------------------"<<endl;
		cout<<"1.Them node vao dau danh sach"<<endl;
		cout<<"2.Them node vao cuoi danh sach"<<endl;
		cout<<"3.Them node vao vi tri bat ki"<<endl;
		cout<<"4.Sap xep theo cac gia tri cua node"<<endl;
		cout<<"5.Loai bo node o vi tri bat ky"<<endl;
		cout<<"6.Cap nhat noi dung node"<<endl;
		cout<<"7.Tim kiem node theo gia tri"<<endl;
		cout<<"8.Duyet danh sach"<<endl;
		cout<<"9.Dao nguoc danh sach"<<endl;
		cout<<"0.Thoat"<<endl;
		cout<<"Lua chon chuc nang";cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Them node vao dau danh sach: "<<endl;
				X.insert_begin();cout<<endl;break;
			case 2:
				cout<<"Them node vao cuoi danh sach: "<<endl;
				X.insert_last();cout<<endl;break;
			case 3:
				cout<<"Them node vao vi tri bat ky: "<<endl;
				X.insert_pos();cout<<endl;break;
			case 4:
				cout<<"Sap xep noi dung node: "<<endl;
				X.sort();cout<<endl;break;
			case 5:
				cout<<"Loai bo node: "<<endl;
				X.delete_pos();cout<<endl;break;
			case 6:
				cout<<"Cap nhat gia tri node"<<endl;
				X.update();cout<<endl;break;
			case 7:
				cout<<"Tim kiem node"<<endl;
				X.search();cout<<endl;break;
			case 8:
				cout<<"Duyet danh sach"<<endl;
				X.display();cout<<endl;break;
			case 9:
				cout<<"Dao nguoc danh sach"<<endl;
				X.reverse();cout<<endl;break;
			case 0:
				cout<<"Thoat..."<<endl;
				exit(1);break;
			default:
				cout<<"Lua chon sai"<<endl;break;
		}
	}
}
