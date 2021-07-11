#include<iostream>
#include<conio.h>
#include<iomanip>
using namespace std;
class Node{
	public:
	 int reg_no;
	  char name[20];
	 char Father_name[20];
	 char sec;
	 float cgpa;
	 Node  *left;
	 Node  *right;
};

class Tree{
	public:
			Node *root=NULL;

	Node  *ADD(Node *temp,int n,char na[],char fn[],char s, float gpa)
	{
			if(temp==NULL)
	{
		
		
	Node *Newnode=new Node();
	Newnode->reg_no=n;
	Newnode->sec=s;
	Newnode->cgpa=gpa;
	
	for(int i=0; i<20; i++)
	{
		Newnode->name[i]=na[i];
		
	}
	
	for(int i=0; i<20; i++)
	{
		Newnode->Father_name[i]=fn[i];
	}
	Newnode->left=NULL;
	Newnode->right=NULL;
	temp=Newnode;
	if(root==NULL)
	root=Newnode;
	return Newnode;
	}
	else if(n>temp->reg_no)
	{
		temp->right=ADD(temp->right,n,na,fn,s,gpa);
	}
	else
	{
		temp->left=ADD(temp->left,n,na,fn,s,gpa);
	}
	

	}
	
	
	Node  *ADDbyGpa(Node *temp2,int n,char na[],char fn[],char s, float gpa)
	{
			if(temp2==NULL)
	{
		
		
	Node *Newnode=new Node();
	Newnode->reg_no=n;
	Newnode->sec=s;
	Newnode->cgpa=gpa;
	
	for(int i=0; i<20; i++)
	{
		Newnode->name[i]=na[i];
		
	}
	for(int i=0; i<20; i++)
	{
		Newnode->Father_name[i]=fn[i];
	}
	Newnode->left=NULL;
	Newnode->right=NULL;
	temp2=Newnode;
	if(root==NULL)
	root=Newnode;
	return Newnode;
	}
	else if(gpa>temp2->cgpa)
	{
		temp2->right=ADDbyGpa(temp2->right,n,na,fn,s,gpa);
	}
	else
	{
		temp2->left=ADDbyGpa(temp2->left,n,na,fn,s,gpa);
	}
	

	}
	bool Find(int reg)
	{  
	     
	     
		Node *temp=root;
		while(temp!=NULL)
		{
			if(temp->reg_no==reg)
			{
					cout<<"Registered"<<endl;
					cout<<setw(10)<<left;
					cout<<"RollNo";
					cout<<setw(20)<<left;
					cout<<"Name";
					cout<<setw(20)<<left;
					cout<<"Father Name";
					cout<<setw(10)<<left;
					cout<<"Section";
					cout<<setw(10)<<left;
					cout<<"CGPA"<<endl;
				cout<<setw(10)<<left;
				cout<<temp->reg_no;
				cout<<setw(20)<<left;
				cout<<temp->name;
				cout<<setw(20)<<left;
				cout<<temp->Father_name;
				cout<<setw(10)<<left;
				cout<<temp->sec;
				cout<<setw(10)<<left;
				cout<<temp->cgpa<<endl;
				return true;
			}
			else if(temp->reg_no<reg)
			{
				temp=temp->right;
			}
			else if(temp->reg_no>reg)
			{
				temp=temp->left;
			}
		}
		if(temp==NULL)
		{
			cout<<"Not Registered"<<endl;
			return false;
		}
	}
	Node* FindMin(Node* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}
 
	 Node* Delete2( int data,Node *root) {
	 
	 
	if(root == NULL) 
	{
		cout<<"Record not found"<<endl;
	} 
	else if(data < root->reg_no) root->left = Delete2(data,root->left);
	else if (data > root->reg_no) root->right = Delete2(data,root->right);
	
	else {
		// Case 1:  No child
		if(root->left == NULL && root->right == NULL) { 
			delete root;
			root = NULL;
		}
		//Case 2: One child 
		else if(root->left == NULL) {
			 Node *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
		 Node *temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else { 
			 Node *temp = FindMin(root->right);
			root->reg_no = temp->reg_no;
			root->right = Delete2(temp->reg_no,root->right);
		}
	}
	return root;
}
void Display(Node *temp)
{
	if(temp==NULL)
	{
		return;
	
	}
	else 
	{
	
				cout<<setw(10)<<left;
				cout<<temp->reg_no;
				cout<<setw(20)<<left;
				cout<<temp->name;
				cout<<setw(20)<<left;
				cout<<temp->Father_name;
				cout<<setw(10)<<left;
				cout<<temp->sec;
				cout<<setw(10)<<left;
				cout<<temp->cgpa<<endl;
				Display(temp->left);
				Display(temp->right);
	}
}
void Displaywarning(Node *temp)
{
	if(temp==NULL)
	{
		return;
	
	}
	else 
	{
	           if(temp->cgpa<2)
	           {
			   
				cout<<setw(10)<<left;
				cout<<temp->reg_no;
				cout<<setw(20)<<left;
				cout<<temp->name;
				cout<<setw(20)<<left;
				cout<<temp->Father_name;
				cout<<setw(10)<<left;
				cout<<temp->sec;
				cout<<setw(10)<<left;
				cout<<temp->cgpa<<endl;
				}
				Displaywarning(temp->left);
				Displaywarning(temp->right);
	
	}
}
void DisplayTopper(Node *temp,int &count)
{
	if(temp==NULL)
	{
		return;
	
	}
	else 
	{
	
				
				DisplayTopper(temp->right,count);
				if(count<3)
				{
				
				cout<<setw(10)<<left;
				cout<<temp->reg_no;
				cout<<setw(20)<<left;
				cout<<temp->name;
				cout<<setw(20)<<left;
				cout<<temp->Father_name;
				cout<<setw(10)<<left;
				cout<<temp->sec;
				cout<<setw(10)<<left;
				cout<<temp->cgpa<<endl;
				count++;
			}
				DisplayTopper(temp->left,count);
	}
}
Node *Delete(int data,Node *root)
 {
 	
 	if(Find(data)==false)
 	{
 		cout<<"Record not found"<<endl;
	}
	else
	{
		cout<<"Student with Roll No: "<<data<<" is Deleted."<<endl;
		return Delete2(data,root);
	}
 }
void mainpage()
{
	{
		
	
	int process=0;
  system("cls");
  cout << "\n";
  cout <<"\t\t\t\t    ----------------------------------\n";
  cout <<"\t\t\t\t    |  STUDENT MANAGEMENT SYSTEM|\n";
  cout <<"\t\t\t\t    ----------------------------------\n";
  cout <<"\n\n";
  cout <<"\t\t\t\t";
  cout <<"Prepared By    ";
  cout <<":";
  cout <<"FAWAD TAHIR " <<endl;
  cout<<"   \t\t\t\t\t\tAQIB MUNIR   "<<endl;
  cout<<"   \t\t\t\t\t\tBURHAN KHAN " <<endl;
  cout <<"\n\n";
  cout <<"\t\t\t\t";
  cout <<" Project   ";
  cout <<":";
  cout <<"  Student Mangement System";
  cout <<"\n\n";
  cout <<"\t\t\t\t";
  cout <<"\n\n";
  cout <<"\n\n";
  cout <<"\t\t\t\t";
  system("pause");
  cout <<"\n\t\t\t\tLoading";

  for(process=0;process<25;process++)
  {
    cout <<".";
  }
}
system("cls");
}
Node *updatefunction(int m)
 {
 	
	 Node *temp3=root;
	 int option,value;
	 float c;
	 char se,ft[20],n[20];
	 while(temp3!=NULL)
		{
			if(temp3->reg_no==m)
			{
				check:
				cout<<"Choose from the below Menu"<<endl;
				cout<<"1.Update Rollno:"<<endl;
				cout<<"2.Update Name:"<<endl;
				cout<<"3.Update Father name:"<<endl;
				cout<<"4.UPdate Section:"<<endl;
				cout<<"5.Update CGPA:"<<endl;
				cin>>option;
				switch(option){
					case 1:
						cout<<"Enter the new Rollno:"<<endl;
						cin>>value;
						temp3->reg_no=value;
					break;
					case 2:
						cout<<"Enter the new Name:"<<endl;
						cin>>n;
						for(int i=0; i<20; i++)
						{
							temp3->name[i]=n[i];
		
						}
					break;
					case 3:
						cout<<"Enter Father Name:"<<endl;
						cin>>ft;
							for(int i=0; i<20; i++)
						{
							temp3->Father_name[i]=ft[i];
		
						}
						break;
					case 4:
						cout<<"Enter Section:"<<endl;
						cin>>se;
						temp3->sec=se;
					break;
					case 5:
						cout<<"Enter New CGPA:"<<endl;
						cin>>c;
						temp3->cgpa=c;
					break;
					default:
						cout<<"Invalid Option: "<<endl;
						goto check;
				}
				  
				  return temp3; 
			}
			else if(temp3->reg_no<m)
			{
				temp3=temp3->right;
			}
			else if(temp3->reg_no>m)
			{
				temp3=temp3->left;
			}
		}
		if(temp3==NULL)
		{
			cout<<"Not Registered"<<endl;
			return root;
		}
 }
};
int main()
{
	
	Tree t,t2;
	int count=0;
	t.mainpage();
	int value,option;
	char na[20],Fathern[20],se;
	float g;
	int c;
	do{
		system("cls");
		cout<<"what operation do you want to perform."<<endl;
		cout<<"1.Enter a new record."<<endl;
		cout<<"2.Search a particular student record. "<<endl;
		cout<<"3.Delete a student data"<<endl;
		cout<<"4.Display all records. "<<endl;
		cout<<"5.Display all top students record. "<<endl;
		cout<<"6.Academic Warning students"<<endl;
		cout<<"7.Update the student record"<<endl;
		cout<<"8.Exit"<<endl;
		cin>>option;
		switch(option){
			case 1:
				cout<<"Enter the Roll no"<<endl;
				cin>>value;
				cout<<"Enter the name of the student"<<endl;
				cin>>na;
	            cout<<"Enter the father name"<<endl;
				cin>>Fathern;
				cout<<"Enter the section"<<endl;
				cin>>se;
				check:
				cout<<"Enter the cgpa"<<endl;
				cin>>g;
				if(g>4)
				{
					cout<<"Invalid CGPA."<<endl;
					goto check;
				}
				if(g<2)
				{
					cout<<"Student has academic warning"<<endl;
				}
				t.ADD(t.root,value,na,Fathern,se,g);
				t2.ADDbyGpa(t2.root,value,na,Fathern,se,g);
				system("pause");
			break;
			case 2:
				if(t.root==NULL)
				{
					cout<<"NO RECORD FOUND"<<endl;
				}
				else
				{
	
				
				
				cout<<"Enter the student roll no you want to find"<<endl;
				cin>>value;
				t.Find(value);
			}
			    system("pause");
			break;
			case 3:
					if(t.root==NULL)
				{
					cout<<"OOPS!No Record Found."<<endl;
				}
				else
				{
				
				cout<<"Enter the student roll no you want to delete"<<endl;
				cin>>value;
				t.Delete(value,t.root);
			}
				system("pause");
			break;
			case 4:
				if(t.root==NULL)
				{
					cout<<"OOPS!No Record Found."<<endl;
				}
				else
				{
				
					cout<<"Student record are"<<endl;
					cout<<setw(10)<<left;
					cout<<"RollNo";
					cout<<setw(20)<<left;
					cout<<"Name";
					cout<<setw(20)<<left;
					cout<<"Father Name";
					cout<<setw(10)<<left;
					cout<<"Section";
					cout<<setw(10)<<left;
					cout<<"CGPA"<<endl;
					t.Display(t.root);
				}
				system("pause");
			break;
		case 5:
				if(t2.root==NULL)
				{
					cout<<"OOPS!No Record Found."<<endl;
				}
				else
				{
				
					cout<<"Topper Students are:"<<endl;
					cout<<setw(10)<<left;
					cout<<"RollNo";
					cout<<setw(20)<<left;
					cout<<"Name";
					cout<<setw(20)<<left;
					cout<<"Father Name";
					cout<<setw(10)<<left;
					cout<<"Section";
					cout<<setw(10)<<left;
					cout<<"CGPA"<<endl;
					t2.DisplayTopper(t2.root,count);
				}
				system("pause");
			break;
			case 6:
				if(t.root==NULL)
				{
					cout<<"NO STUDENT FOUND"<<endl;
				}
				else
				{
				
				cout<<"Academic Warnings"<<endl;
					cout<<setw(10)<<left;
					cout<<"RollNo";
					cout<<setw(20)<<left;
					cout<<"Name";
					cout<<setw(20)<<left;
					cout<<"Father Name";
					cout<<setw(10)<<left;
					cout<<"Section";
					cout<<setw(10)<<left;
					cout<<"CGPA"<<endl;
				t.Displaywarning(t.root);
			}
				system("pause");
				break;
			case 7:
				if(t.root==NULL)
				{
					cout<<"NO RECORD FOUND"<<endl;
				}
				else{
				
				cout<<"Enter the student roll no:"<<endl;
				cin>>value;
				t.root=t.updatefunction(value);
			}
				system("pause");
				break;
			case 8:
				
				return 0;
			break;
			default:
				cout<<"Enter the valid option"<<endl;
				system("pause");
				
		}
		
	}while(option!=0);
	 return 0;
}


