#include <iostream>
#include <conio.h>

using namespace std;

struct node 
{
	int info;
	struct node *pre;
	struct node *next;
}*start;

class double_linked_list
{
	public:
		node *create_node(int value);
		void insert_begin();
		void insert_end();
		void display();
		void insert_pos();
		void update();
		void sort();
		void delete_pos();
		void right_travel();
		void reverse_node();
};
node *double_linked_list::create_node(int value)
{
	struct node *temp;
	temp = new(struct node);
	if(temp == NULL)
	{
		cout<<"Khong du bo nho "<<endl;
	}
	else
	{
		temp->info = value;
		temp->next = NULL;
		temp->pre = NULL;
		return temp;
	}
}
void double_linked_list::insert_begin()
{
	int value;
	cout<<"Nhap gia tri can them: ";cin>>value;
	struct node *s, *ptr;
	s = create_node(value);
	if(start == NULL)
	{
		start = s;
		start->next = NULL;
		start->pre = NULL;
	}
	else
	{
		ptr = start;
		start = s;
		start->next = ptr;
		ptr->pre=start;
	}
	cout<<"Da them vao danh sach"<<endl;
	getch();
}
void double_linked_list::display()
{
	struct node *temp;
	temp = start;
	if(start == NULL)
	{
		cout<<"Khong co gi de hien thi "<<endl;
		return;
	}
	else
	{
		while(temp != NULL)
		{
			cout<<temp->info<<"->";
			temp = temp->next;
		}
		cout<<"NULL"<<endl;
	}
	getch();
}

void double_linked_list::insert_end()
{
	int value;
	cout<<"Nhap gia tri can them ";cin>>value;
	struct node *temp, *s;
	temp = create_node(value);
	if(start == NULL)
	{
		start = temp;
		start->next = NULL;
		start->pre = NULL;
		
	}
	else 
	{
		s = start;
		while(s->next = NULL)
		{
			s = s->next;
		}
		s->next = temp;
		temp->next = NULL;
		temp->pre = s;
	}
	cout<<"Hoan thanh them vao cuoi "<<endl;
}

void double_linked_list::insert_pos()
{
	int value,pos,counter = 0;
	cout<<"Nhap node can them ";cin>>value;
	cout<<"Nhap vi tri ";cin>>pos;
	struct node *temp, *s, *ptr;
	temp = create_node(value);
	s = start;
	while(s != NULL)
	{
		counter++;
		s = s->next;
	}
	
	cout<<counter<<endl;
	
	if(counter == 0)
	{
		if(pos > 1)
		{
			cout<<"Danh sach rong "<<endl;
		}
		if(pos == 1)
		{
			start = temp;
			start->next = NULL;
			start->pre = NULL;	
		}
	}
	else if(pos<=counter && counter >1)
	{
		s = start;
		for(int i = 1;i<pos;i++)
		{
			ptr = s;
			s = s->next;
		}
		ptr->next = temp;
		temp->next= s;
		temp->pre =ptr; 
		s->pre = temp;
	}
	else
	{
		cout<<"Vi tri chen khong hop le "<<endl;
	}
	getch();
}

void double_linked_list::update()
{
	int value,pos;
	struct node *s;
	cout<<"Nhap vi tri can sua ";cin>>pos;
	cout<<"Nhap gia tri moi can sua ";cin>>value;
	
	if(start == NULL)
	{
		cout<<"Danh sach rong "<<endl;
		return;
	}
	else
	{
		s = start;
		for(int i = 1;i<pos;i++)
		{
			s = s->next;
		}
		s->info = value;
	}
	cout<<"Hoan thanh update"<<endl;
	getch();
}

void double_linked_list::sort()
{
	if(start == NULL)
	{
		cout<<"Danh sach rong"<<endl;	
	}
	struct node *temp, *s;
	s = start;
	while(s != NULL)
	{
		for(temp = s;temp!=NULL;temp = temp->next)
		{
			if(s->info > temp->info)
			{
				int value = s->info;
				s->info = temp->info;
				temp->info = value;
			}
		}
		s = s->next;
	}
	cout<<"Hoan thanh sap xep"<<endl;
	getch();
}

void double_linked_list::delete_pos()
{
	if(start == NULL)
	{
		cout<<"Danh sach rong"<<endl;
	}
	else
	{
		int pos, counter = 0;
		cout<<"Vi tri can loai bo: ";cin>>pos;
		struct node *temp, *s;
		s = start;
		while(s!=NULL)
		{
			counter++;
			s = s->next;
		}
		if(pos == 1)
		{
			temp = start;
			start = temp->next;
			delete temp;
		}
		else if(pos > 1 && pos <= counter)
		{
			s = start;
			for(int i = 1;i<pos;i++)
			{
				temp = s;
				s = s->next;
			}
			if(s == NULL)
			{
				temp->next = NULL;
				s->pre = NULL;
				delete s;
			}
			else
			{
				temp->next = s->next;
				(s->next)->pre = temp;
			}
		}
		else cout<<"Vi tri khong hop le "<<endl;
	}
	cout<<"Hoan thanh loai bo"<<endl;
	getch();
}

void double_linked_list::right_travel()
{
	struct node *temp;
	temp = start;
	if(start == NULL)
	{
		cout<<"Khong co gi de hien thi"<<endl;
	}
	while(temp->next!= NULL)
	{
		temp = temp->next;
	}
	while(temp!=NULL)
	{
		cout<<temp->info<<"->";
		temp = temp->pre;
	}
	cout<<"NULL"<<endl;
	cout<<"Hoan thanh "<<endl;
	getch();
}

void double_linked_list::reverse_node()
{
	struct node *ptr1, *ptr2, *ptr3;
	if(start == NULL)
	{
		cout<<"Danh sach rong"<<endl;
	}
	else
	{
		ptr1 = start;
		ptr2 = ptr1->next;
		ptr3 = ptr2->next;
		ptr1->next =NULL;
		ptr2->next = ptr1;
		ptr1->pre = ptr2;
		while(ptr3!=NULL)
		{
			ptr1 = ptr2;
			ptr2 = ptr3;
			ptr3 = ptr3->next;
			ptr2->next = ptr1;
			ptr1->pre =ptr2;
		}
		start = ptr2;
	}
	cout<<"Hoan thanh dao nguoc"<<endl;
	
}

int main()
{
	int n;
	while(1)
	{
		system("cls");
		double_linked_list X;
		cout<<"----Danh sach lien ket kep----"<<endl;
		cout<<"1.Them vao dau danh sach"<<endl;
		cout<<"2.Them vao cuoi danh sach"<<endl;
		cout<<"3.Them vao vi tri bat ky"<<endl;
		cout<<"4.Sua node trong danh sach"<<endl;
		cout<<"5.Sap xep danh sach"<<endl;
		cout<<"6.Loai bo node"<<endl;
		cout<<"7.Duyet mang trai"<<endl;
		cout<<"9.Duyet mang phai"<<endl;
		cin>>n;
		switch(n)
		{
			case 1:
				cout<<"Them vao dau danh sach "<<endl;
				X.insert_begin();cout<<endl;break;
			case 2:
				cout<<"Them vao cuoi danh sach "<<endl;
				X.insert_end();cout<<endl;break;
			case 3:
				cout<<"Them vao vi tri bat ky"<<endl;
				X.insert_pos();cout<<endl;break;
			case 4:
				cout<<"Sua node trong danh sach"<<endl;
				X.update();cout<<endl;break;
			case 5:
				cout<<"Sap xep danh sach"<<endl;
				X.sort();cout<<endl;break;
			case 6:
				cout<<"Loai bo node trong danh sach"<<endl;
				X.delete_pos();cout<<endl;break;
			case 7:
				cout<<"Duyet mang phai trong danh sach"<<endl;
				X.right_travel();cout<<endl;break;
			case 8:
				cout<<"Dao nguoc node"<<endl;
				X.reverse_node();cout<<endl;break;
			case 9:
				cout<<"Hien thi danh sach "<<endl;
				X.display();cout<<endl;break;
		}	
	}
}
