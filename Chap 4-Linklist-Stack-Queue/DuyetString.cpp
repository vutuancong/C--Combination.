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
void Insert_end(string a, int x, int OK,int flag)
{
	node *temp, *s, *str;
	temp = create_node(a, x);
	if (start == NULL)
	{
		start = temp;
		temp = temp->next;
	}
	else if(OK == 1)
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
		if(flag == 0)
		{
			s = start;
			start = temp;
			temp->next = s;
		}
		else
		{
			s = start;
			for(int i = 1;i<flag;i++)
			{
				str = s; s = s->next;
			}
			str->next = temp;
			temp->next = s;
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
		if (s->word == a)
		{
			OK = 3;
			break;
		}
		if(s->word > a)
		{
			OK = 2;
			return count;
		}
		count++;
		s = s->next;
	}
	return n+1;
}

void Fix_node(string a)
{
	node *s;
	s = start;
	while (s != NULL)
	{
		if (s->word == a)
		{
			s->solan++;
			break;
		}
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
	int n = 0,flag = 0, OK = 1;
	f.open("vanban.txt", ios::in);
	while (!f.eof())
	{
		f >> a;
		flag = KiemTra(a, n,OK);
		cout<<"flag: "<<flag<<" "<<endl;
		cout<<"OK: "<<OK<<" "<<endl;
		cout<<"n: "<<n<<" "<<endl;
		if (OK == 1)
		{
			Insert_end(a, 1, OK,flag);
			n = flag;	
		}
		else if(OK == 3)
			Fix_node(a);
		else if(OK == 2)
		{
			Insert_end(a,1,OK,flag);
			n++;
		}
	}
	Display();
}
