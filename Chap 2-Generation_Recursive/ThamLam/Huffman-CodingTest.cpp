#include<iostream>

using namespace std;

struct tree
{   int value;
    char ch;
    tree *left;
    tree *right;
};
 
struct input
{   int frequency;
    char character;
    tree *address;
};
 
void postorder(tree *root,int node,char *temp_bit)
{   node++;
    if(root!=0)
    {   temp_bit[node-1]='0';
        postorder(root->left,node,temp_bit);
        temp_bit[node-1]='\0';
       
        temp_bit[node-1]='1';
        postorder(root->right,node,temp_bit);
        temp_bit[node-1]='\0';
 
        if(root->ch!='\0')
            cout<<root->ch<<" : "<<temp_bit<<endl;
    }
    node--;
}
   
tree *inputTree(input num_input1,input num_input2)
{   tree *leftnode = new tree;
    tree *rightnode = new tree;
    tree *root=new tree;
   
    if(num_input1.address=='\0')
    {   leftnode->value = num_input1.frequency;
        leftnode->ch = num_input1.character;
        leftnode->left = '\0';
        leftnode->right = '\0';
    }
    else
    {   leftnode = num_input1.address;  }
   
    if(num_input2.address=='\0')
    {   rightnode->ch=num_input2.character;
        rightnode->value=num_input2.frequency;
        rightnode->left='\0';
        rightnode->right='\0';
    }
    else
    {   rightnode = num_input2.address; }
 
    root->value=num_input1.frequency+num_input2.frequency;
    root->ch='\0';
    root->left=leftnode;
    root->right=rightnode;
 
    return root;
}
 
void bubble(input *number_input,int counter)
{   for(int i=0;i<counter-1;i++)
        for(int j=i+1;j<counter;j++)
            if(number_input[i].frequency > number_input[j].frequency)
            {   input *temp = new input;
 
                temp->address = number_input[i].address;
                temp->character = number_input[i].character;
                temp->frequency = number_input[i].frequency;
                number_input[i].address = number_input[j].address;
                number_input[i].character = number_input[j].character;
                number_input[i].frequency = number_input[j].frequency;
                number_input[j].address = temp->address;
                number_input[j].character = temp->character;
                number_input[j].frequency = temp->frequency;
               
                delete temp;
            }
}
 
int main(void)
{  
        int number,node=0;
 
    cout<<"How many character will you input? ";
    cin>>number;
   
    char *temp_bit = new char[number];
    input *num_input = new input[number];
 
    for(int p=0;p<number;p++)
    {   num_input[p].address='\0';
        num_input[p].frequency=0;
        num_input[p].character='\0';
    }
   
    for(int i=0;i<number;i++)
    {   cout<<"\nEnter character: ";
        cin>>num_input[i].character;
        cout<<"Enter frequency: ";
        cin>>num_input[i].frequency;
    }
 
    for(int j=0;j<number-1;j++)
    {   bubble(num_input,number);
 
        num_input[j+1].address=inputTree(num_input[j],num_input[j+1]); 
        num_input[j+1].frequency += num_input[j].frequency;
        num_input[j+1].character = '\0';
    }
   
    cout<<endl;
    postorder(num_input[number-1].address,node,temp_bit);
    cout<<endl;
 
    delete temp_bit;
    delete num_input;
    return 0;
}
