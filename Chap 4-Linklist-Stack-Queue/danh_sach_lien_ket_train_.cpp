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
		void insert_end();
		void insert_pos();
		void Display();
		void delete_pos();
		void update();
		void seach();
		void sort();
		void reverse();
};

node *single_linked_list::create_node(int value)
{
	struct node *temp;
	temp = new(struct node);
	if(temp == NULL)
	{
		cout<<"Khong du khong gian nho";
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
	cout<<"Nhap gia tri node";cin>>value;
	struct node *temp, *p;
	temp = create_node(value);
	if(start == NULL)
	{
		start = temp;
		start->next;	
	}
	else
	{
		p = start;
		start = temp;
		start->next = p;
	}
}
void single_linked_list::insert_end()
{
	int value;
	cout<<"Nhap gia tri node";cin>>value;
	struct node *temp, *p;
	temp = create_node(value);
	if(start == NULL)
	{
		start = temp;
		temp->next==NULL;
	}
	p = start;
	while(p->next != NULL)
	{
		p = p->next;
	}
	temp->next = NULL;
	p->next = temp;
	cout<<"Hoan thanh them node vao cuoi"<<endl;
}

void single_linked_list::Display()
{
	struct node *temp;
	if(start == NULL)
	{
		cout<<"Danh sach rong"<<endl;
		return ;
	}
	temp = start;
	cout<<"Noi dung cua danh sach"<<endl;
	while(temp != NULL)
	{
		cout<<temp->info<<"->";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
	getch();
}

void single_linked_list::insert_pos()
{
	int value, pos,counter = 0;
	struct node *temp,*s,*ptr;
	cout<<"Nhap gia tri cua node can them: ";cin>>value;
	cout<<"Nhap vi tri node can them";cin>>pos;
	temp = create_node(value);
	s = start;
	while(s != NULL)
	{
		s = s->next;
		counter++;
	}
	if(counter == 0)
	{
		cout<<"Danh sach trong"<<endl;
		return;
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
	else if(pos > 1 && pos <= counter)
	{
		s = start;
		for(int i = 1;i<pos;i++)
		{
			ptr = s; s = s->next;
		}
		ptr->next = temp;
		temp->next =s; 
	}
	else 
	{
		cout<<"Vuot qua gioi han node"<<endl;
	}
	getch();
}

void single_linked_list::delete_pos()
{
	int pos,counter,i;
	cout<<"Nhap vi tri can loai bo";cin>>pos;
	if(start == NULL)
	{
		cout<<"Danh sach trong"<<endl;
	}
	struct node *ptr,*s;
	s = start;
	if(pos == 1)
	{
		start = s->next;
		s->next = NULL;
		delete(s);
	}
	else
	{
		while(s!=NULL)
		{
			s = s->next;
			counter++;
		}
		if(pos>1 && pos <= counter)
		{
			s = start;
			for(int i = 0 ;i<pos;i++)
			{
				ptr = s;
				s = s->next;
			}
			ptr->next = s->next;
		}
		else cout<<"Vuot qua so luong node"<<endl;
		delete s;
		cout<<"Node da bi loai bo"<<endl;
	}
}

void single_linked_list::update()
{
	int value, pos;
	struct node *s;
	
	cout<<"Nhap vi tri can sua: ";cin>>pos;
	cout<<"Nhap gia tri moi: ";cin>>value;
	s = start;
	if(pos == 1)
	{
		start->info = value; 
	}
	else
	{
		for(int i = 1;i<pos;i++)
		{
			if(s == NULL)
			{
				cout<<"Vi tri xoa khong hop le"<<endl;
			}
			s = s->next;
		}
		s->info = value;
	}
	cout<<"Hoan thanh updata"<<endl;
	getch();
}

void single_linked_list::seach()
{
	int value,flag,pos = 0;
	cout<<"Nhap gia tri tim kiem";cin>>value;
	struct node *s;
	s = start;
	if(start ==  NULL)
	{
		cout<<"Danh sach rong "<<endl;
	}
	while(s != NULL)
	{
		pos++;
		if(s->info == value)
		{
			flag = 1;
			cout<<"Tim thay gia tri "<<value<<" o vi tri "<<pos<<endl;
		}
		s = s->next;
	}
	if(flag == 0) cout<<"Khong tim thay gia tri "<<value<<" trong node "<<endl;
	getch();
}

void single_linked_list::sort()
{
	int temp;
	struct node *s, *ptr;
	if(start == NULL)
	{
		cout<<"Danh sach node rong"<<endl;
		return ;
	}
	s = start;
	while(s != NULL)
	{
		for(ptr = s->next;ptr!=NULL;ptr = ptr->next)
		{
			if(s->info > ptr->info)
			{
				temp = s->info;
				s->info = ptr->info;
				ptr->info = temp;
			}
		}
		s = s->next;
	}
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
		cout<<"Danh sach chi co 1 node"<<endl;
	}
	ptr1 = start;
	ptr2 = ptr1->next;
	ptr3 = ptr2->next;
	ptr1->next =NULL;
	ptr2->next = ptr1;
	while(ptr3!=NULL)
	{
		ptr1 = ptr2;
		ptr2 = ptr3;
		ptr3 = ptr3->next;
		ptr2->next = ptr1;		
	}
	start = ptr2;
	getch();
}

int main()
{
	int choice;
	single_linked_list X;
	start = NULL;
	while(1)
	{
		system("cls");
		cout<<"----------Danh sach lien ket----------"<<endl;
		cout<<"1.Them vao dau danh sach lien ket"<<endl;
		cout<<"2.Them node vao cuoi danh sach"<<endl;
		cout<<"3.Them node vao vi tri bat ky"<<endl;
		cout<<"4.Hien thi danh sach lien ket"<<endl;
		cout<<"5.Xoa node tai vi tri bat ky"<<endl;
		cout<<"6.Sua thong tin node"<<endl;
		cout<<"7.Tim kiem tren node"<<endl;
		cout<<"8.Sap xep tren node"<<endl;
		cout<<"9.Dao nguoc cac node trong danh sach"<<endl;
		cout<<"Nhap lua chon"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Them node vao dau danh sach"<<endl;
				X.insert_begin();cout<<endl;break;
			case 4:
				cout<<"Hien thi danh sach"<<endl;
				X.Display();cout<<endl;break;
			case 2:
				cout<<"Them node vao cuoi danh sach"<<endl;
				X.insert_end();cout<<endl;break;
			case 3:
				cout<<"Them node vao vi tri bat ky"<<endl;
				X.insert_pos();cout<<endl;break;
			case 5:
				cout<<"Xoa node tai vi tri bat ky"<<endl;
				X.delete_pos();break;
			case 6:
				cout<<"Sua thong tin node"<<endl;
				X.update();cout<<endl;break;
			case 7:
				cout<<"Tim kiem thong tin tren node"<<endl;
				X.seach();cout<<endl;break;
			case 8:
				cout<<"Sap xep tren node"<<endl;
				X.sort();break;
			case 9:
				cout<<"Dao nguoc node"<<endl;
				X.reverse();cout<<endl;break;
			default:
				cout<<"Lua chon sai"<<endl;break;
		}
	}
}
