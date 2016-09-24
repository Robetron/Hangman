#include<iostream>
#include<iomanip>
#include<stdlib.h>

using namespace std;

struct element
		{
		char data;
		struct element *next;
		};
typedef struct element node;

class hangman
	{
	int j,n,miss,h,u,p1,p2;
	char name1[15],name2[15];
	node *a,*b,*r;
	void display();
	void game();
	void result();
	void deadman();
	void clue();
public:	hangman()
		{a=NULL;b=NULL;r=NULL;u=0;h=0;}
	void creation();
	};


void hangman::creation()
{
a=NULL;
b=NULL;
r=NULL;
int o;
system("CLS");
cout<<"\nPlayer 1 will put up the word for Player 2 to solve.";
cout<<"\nPlayer 1 enter your name: ";
cin>>name1;
cout<<"\nPlayer 2 enter your name: ";
cin>>name2;
system("CLS");
cout<<"\n"<<name1<<" enter the number of alphabets in your word: ";
cin>>n;
if(a==NULL)	{
		a=new node;
		a->next=NULL;
		cout<<"\nEnter the word in lower case (for space character enter '_').\n ";
		cin>>a->data;
		}
if(b==NULL)	{
		b=new node;
		b->next=NULL;
		b->data='_';
		}
node *p=a,*temp,*q=b,*t;
for(int i=1;i<=n-1;i++)
{
temp=new node;
temp->next=NULL;
cin>>temp->data;
p->next=temp;
p=temp;
t=new node;
t->next=NULL;
t->data='_';
q->next=t;
q=t;
if(temp->data=='_'){t->data='/';u++;}
}
cout<<endl<<"\n\n"<<name1<<" do you want show some alphabets as a clue?\n1:Yes 2:No:";
cin>>o;
if(o==1)clue();
game();
}


void hangman::game()
{
system("CLS");
int correct;
miss=0;
correct=0;
cout<<"\n\t\t\t\tHaNgMaN BeGiNs";
int w,l,c=1;
char x;
node *p=a,*q=b,*p1,*q1,*p3=r,*e;
cout<<"\nCharacter '/' seperates two words.";
display();
while(miss!=10)
{
cout<<"\n\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
cout<<"\n\n\n"<<name2<<" guess the character (1 character in lower case only): ";
cin>>x;
cout<<endl<<endl;
p=a;
l=0;
c=1;
w=0;
while(p!=NULL)
{
q=b;
if(p->data==x)	{
				w=1;
				if(l==0){
		 				 cout<<x<<" was correct.\n\nMistakes: "<<miss;
		 				 l++;
						 }
			 if(c==1){q->data=x;}
			 else	{
			 		for(int i=1;i<=c-1;i++)
					q=q->next;
					q->data=x;
					}
				}
c++;
p=p->next;
}
p1=a;
q1=b;
correct=0;
for(int k=1;k<=n;k++)
{
if(p1->data==q1->data)correct++;
p1=p1->next;
q1=q1->next;
}
if(w==0){
		 miss++;
		 cout<<x<<" was incorrect.\n\nMistakes: "<<miss;
		 if(r==NULL){
   		 r=new node;
   		 r->next=NULL;
   		 r->data=x;
			p3=r;
		    }
	else
		{
		e=new node;
		e->next=NULL;
		e->data=x;
		p3->next=e;
		p3=e;
		}
	}
display();
deadman();
if((correct+u)==n) {h=1;break;}
if(miss==10) {h=2;break;}
}
result();
}


void hangman::result()
{
if(h==1){
	system("CLS");
	cout<<endl<<"\n\t\t\t\tYOU WON.";
	cout<<"\nThe word was ";
	node *temp;
	temp=a;
	while(temp!=NULL)
	{
	cout<<temp->data;
	temp=temp->next;
	}
	cout<<".";
	cout<<endl<<name2<<" you made "<<miss<<" mistakes."<<endl<<"\nCONGRACTS.";
	if(miss<=3)cout<<endl<<name2<<" you are a LEGEND at HANGMAN.";
	else if(miss>3 && miss<=5)cout<<endl<<name2<<" you are a PRO at HANGMAN.";
	else if(miss>5 && miss<=7)cout<<endl<<name2<<" you are a BEGGINER at HANGMAN.";
	else if(miss>7 && miss<=10)cout<<endl<<name2<<" you are a DISGRACE at HANGMAN.";
	}
if(h==2){
	int g;
	system("CLS");
	cout<<endl<<"\n\t\t\t\tYOU LOST."<<endl;
	cout<<"_________"<<endl<<"|       |"<<endl<<"|      _0_"<<endl<<"|     | | |"<<endl<<"|     _/|_ "<<endl<<"|________ ";
	cout<<endl<<endl<<name2<<" do you want to see the word?\n\t\t1:YES\t2:NO"<<endl;
	cin>>g;
	if(g==1){cout<<"\nThe word or phrase was ";
	node *temp;
	temp=a;
	while(temp!=NULL)
	{
	cout<<temp->data;
	temp=temp->next;
	}
	cout<<".";
	}
	cout<<"\nBetter Luck Next Time.";
	}
}


void hangman::display()
{
cout<<"\n\n";
node *temp;
temp=b;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
cout<<"\n\nIncorrect Alphabets: ";
temp=r;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}


void hangman::deadman()
{
cout<<endl<<endl;
if(miss==1)cout<<"_________";
if(miss==2)cout<<"_________"<<endl<<"|"<<endl<<"|"<<endl<<"|"<<endl<<"|"<<endl<<"|";
if(miss==3)cout<<"_________"<<endl<<"|"<<endl<<"|"<<endl<<"|"<<endl<<"|"<<endl<<"|________ ";
if(miss==4)cout<<"_________"<<endl<<"|       |"<<endl<<"|"<<endl<<"|"<<endl<<"|"<<endl<<"|________ ";
if(miss==5)cout<<"_________"<<endl<<"|       |"<<endl<<"|      _0_"<<endl<<"|"<<endl<<"|"<<endl<<"|________ ";
if(miss==6)cout<<"_________"<<endl<<"|       |"<<endl<<"|      _0_"<<endl<<"|       |"<<endl<<"|"<<endl<<"|________ ";
if(miss==7)cout<<"_________"<<endl<<"|       |"<<endl<<"|      _0_"<<endl<<"|     | |"<<endl<<"|"<<endl<<"|________ ";
if(miss==8)cout<<"_________"<<endl<<"|       |"<<endl<<"|      _0_"<<endl<<"|     | | |"<<endl<<"|"<<endl<<"|________ ";
if(miss==9)cout<<"_________"<<endl<<"|       |"<<endl<<"|      _0_"<<endl<<"|     | | |"<<endl<<"|     _/"<<endl<<"|________ ";
if(miss==10)cout<<"_________"<<endl<<"|       |"<<endl<<"|      _0_"<<endl<<"|     | | |"<<endl<<"|     _/|_ "<<endl<<"|________ ";
}


void hangman::clue()
{
int o;
char s;
node *t1,*t2;
do
{
system("CLS");
cout<<"\n\n\t\t\t\t1:Give Clue\n\t\t\t\t2:Continue With The Game";
cin>>o;
switch(o)
{
case 1:{
	cout<<"\n\n"<<name1<<" enter the alphabet that you want to give "<<name2<<" as a clue: ";
	cin>>s;
	t1=a;
	t2=b;
	while(t1!=NULL)
			{
			if(t1->data==s)t2->data=s;
			t1=t1->next;
			t2=t2->next;
			}
	break;
	}
}
}
while(o!=2);
}


int main()
{
int x;
system("CLS");
do
{
cout<<"\n\n\t\t\t\tMAIN MENU\n\n\t\t\t\t1:Start Game\n\t\t\t\t2:How To Play\n\t\t\t\t3:Credits\n\t\t\t\t4:Exit\n";
cin>>x;
switch(x)
{
case 1:{system("CLS");hangman z;z.creation();break;}
case 2:{system("CLS");cout<<"\n\n\t\t\t\tHow To Play Hangman\n\nOne player puts up a word for another player to guess in the less than 10 wrong guesses.";break;}
case 3:{system("CLS");cout<<endl<<"\n\n\t\t\tTHANK YOU FOR PLAYING HANGMAN.\n\t\t\t\tGOD BLESS YOU ALL.\n\n\n\n\n\n\t\tCoded & Created By Vishal Robertson & Yvens Pinto\n\n\t\t\t\tPeAcE OuT\n\n\n";}
}
}
while(x!=4);
return 0;
}
