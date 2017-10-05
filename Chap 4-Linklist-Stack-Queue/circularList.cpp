#include <iostream>

using namespace std;

struct node 
{
	int info;
	struct node *next;
}*last;

class circular_list
{
	public:
		void create_node(int value);
		void add_begin(int value);
		void add_after(int value);
		void delete_element(int value);
		void search_element(int value);
		void display_list();
		void update();
		void sort();
		circular_list()
		{
			last = NULL;
		}
}
void circular_list::create_node(int value)
{
	node *temp;
	temp = new node;
	temp->info = value;
	if(last == NULL)
	{
		last = temp;
	}
	else
	{
		temp->next = last->next;
		last->next = temp;
		last = temp;
	}
}
int main()
{
	int n;
	int m;
	circular_list X;
	cout<<"Danh sach lien ket"<<endl;
	cout<<"1.Create node"<<endl;
	cout<<"2.Add begin"<<endl;
	cout<<"3.Add end"<<endl;
	cout<<"4.Delete element"<<endl;
	cout<<"5.Search element"<<endl;
	cout<<"6.Update"<<endl;
	cout<<"7.Display"<<endl;
	cout<<"Lua chon"<<endl;
	cin>>n;
	switch(n)
	{
		case 1:
			cout<<"Nhap gia tri can tao:";cin>>m;
			X.create_node(m);
	}
}

