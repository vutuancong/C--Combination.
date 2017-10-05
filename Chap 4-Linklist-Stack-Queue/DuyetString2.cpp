#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct node
{
	string word;
	int solan;
	struct node *next;
}*start;

node *create_node(string a, int x)
{
	node *temp;
	temp = new node;
	if (temp == NULL)
	{
		cout << "Khong du khong gian nho: " << endl;
		return 0;
	}
	else
	{
		temp->word = a;
		temp->solan = x;
		temp->next = NULL;
	}
	return temp;
}
void Insert_value(string a, int x, int &OK,int flag)
{
	node *temp, *s, *ptr;
	temp = create_node(a, x);
	if (start == NULL)
	{
		start = temp;
		temp->next = NULL;
	}
	else if(OK == 1 )
	{
		s = start;
		while (s->next != NULL)
		{
			s = s->next;
		}
		s->next = temp;
		temp->next = NULL;
	}
	else if(OK == 2)
	{
		s = start;
		if(flag == 0)
		{
			start = temp;
			temp->next = start;
		}
		else
		{
			for(int i = 1;i<flag;i++)
			{
				ptr = s; s = s->next;
			}
			ptr->next = temp;temp->next = s;
		}
	}
}

int KiemTra(string a, int &n,int &OK)
{
	int count = 0;
	node *s;
	s = start;
	while (s != NULL)
	{
		if(s->word > a) 
		{
			OK = 2;
			return count;
		}
		else if (s->word == a)
		{
			OK = 3;
			return count;
		}
		s = s->next;
		count++;
	}
	return n+1;
}

void Fix_node(int n)
{
	node *s;
	s = start;
	int count = 1;
	while (s != NULL)
	{
		if (count == n) s->solan++;
		count++;
		s = s->next;
	}

}
void Display()
{
	node *temp;
	temp = start;
	while (temp != NULL)
	{
		cout << temp->word << " " << temp->solan << endl;
		temp = temp->next;
	}
}

int main()
{
	fstream f;
	string a;
	int n = 0,flag = 0;
	f.open("vanban.txt", ios::in);
	while (!f.eof())
	{
		int OK = 1;
		f >> a;
		flag = KiemTra(a, n, OK);
		cout<<"\n flag: "<<flag<<endl;
		cout<<"\n OK : "<<OK<<endl;
		if (OK == 1)
		{
			n = flag;
			Insert_value(a, 1,OK,n);//OK = 1;Chen vao vi tri cuoi;
		}
		else if(OK == 3) //  Sua vi tri trung;
			Fix_node(flag);
		else if(OK == 2 ) // vi tri bat ky; 
		{
			Insert_value(a,1,OK,flag);
			n++;
		}
	}
	Display();
}
