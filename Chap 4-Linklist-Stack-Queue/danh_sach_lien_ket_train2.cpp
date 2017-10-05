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
		node *create_node(int value);
		void insert_begin();
		void insert_end();
		void insert_pos();
		void sort();
		void display();
};

node *single_linked_list::create_node(int value)
{
	struct node *temp;
	temp = new(struct node);
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
	struct node *s,*temp;
	cout<<"Nhap gia tri can them: ";cin>>value;
	temp = create_node(value);
	if(start == NULL)
	{
		start = temp;
		start->next = NULL;
	}
	else
	{
		s = start;
		start = temp;
		start->next = s;
	}
	cout<<"Hoan thanh them vao dau"<<endl;
	getch();
}
void single_linked_list::display()
{
	struct node *temp;
	temp = start;
	if(start == NULL)
	{
		cout<<"Danh sach rong"<<endl;
	}
	else
	{
		while(temp != NULL)
		{
			cout<<temp->info<<"->";
			temp= temp->next;
		}
		cout<<"NULL"<<endl;
	}
	getch();
}

void single_linked_list::insert_end()
{
	int value;
	cout<<"Nhap gia tri can them: ";cin>>value;
	struct node *temp,*s;
	temp = create_node(value);
	if(start == NULL)
	{
		start = temp;
		start->next = NULL;	
	}	
	else
	{
		s = start;
		while(s->next!=NULL)
		{
			s = s->next; 
		}
		temp->next =NULL;
		s->next = temp;
	}
}
void single_linked_list::insert_pos()
{
	int value,pos,counter = 0;
	struct node *temp, *s, *ptr;
	cout<<"Nhap gia tri can them: ";cin>>value;
	cout<<"Nhap vi tri can them: ";cin>>pos;
	temp = create_node(value);
	s = start; 
	while(s != NULL)
	{
		s = s->next;
		counter++;
	}
	if(counter == 0)
	{
		cout<<"Danh sach rong"<<endl;
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
			s = start;
			start = temp;
			temp->next = s;
		}
	}
	else if(pos > 1 && pos <= counter)
	{
		s = start;
		for(int i = 1;i<pos;i++)
		{
			ptr = s;s = s->next;
		}
		ptr->next = temp;
		temp->next = s;
	}
	else cout<<"Vi tri khong hop le"<<endl;
}
void single_linked_list::sort()
{
	struct node *ptr,*s, *temp;
	if(start == NULL)
	{
		cout<<"Danh sach rong"<<endl;
	}
	else
	{
		s = start;
		while(s != NULL)
		{
			for(ptr = s;ptr!=NULL;ptr= ptr->next)
			{
				if(s->info > ptr->info)
				{
					int val = s->info;
					s->info = ptr->info;
					ptr->info = val;
				}
			}
			s = s->next;
		}
	}
}
int main()
{
	while(1)
	{
		system("cls");
		int n;
		single_linked_list X;
		cout<<"------------Danh sach lien ket---------------"<<endl;
		cout<<"1.Them vao dau"<<endl;
		cout<<"2.Hien thi danh sach"<<endl;
		cout<<"3.Them vao cuoi danh sach"<<endl;
		cout<<"4.Them vao vi tri bat ky"<<endl;
		cout<<"5.Sap xep trong node"<<endl;
		cout<<"Nhap chuc nang: ";cin>>n;
		switch(n)
		{
			case 1:
				cout<<"Them vao dau danh sach"<<endl;
				X.insert_begin();cout<<endl;break;
			case 2:
				cout<<"Hien thi danh sach"<<endl;
				X.display();cout<<endl;break;
			case 3:
				cout<<"Them vao cuoi danh sach"<<endl;
				X.insert_end();cout<<endl;break;
			case 4:
				cout<<"Them vao vi tri bat ky"<<endl;
				X.insert_pos();cout<<endl;break;
			case 5:
				cout<<"Sap xep node"<<endl;
				X.sort();cout<<endl;break;
		}		
	}
}
