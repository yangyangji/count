#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

struct Str{      //����ṹ��
	int count;
	char *p;
};

Str test[100];

void lwr(char x[])     //��дתСд
{   int k = 0;
    while (x[k] != '\0')
    {
        if (x[k] >= 'A'&&x[k] <= 'Z')
            x[k] = x[k] + 32;
        k++;
    }
}

int identify(char a[])    //�ж��Ƿ���ϵ��ʵĶ���
{   int m=(strlen(a)>=4)?1:0;
    int n=(a[0]>='a'&&a[0]<='z')?1:0;
	if(!m||!n)
		return 0;
	else
		while(a)
		{   for(int i=1;;i++)
		{      if(!(a[i]>='a'&&a[i]<='z')||!(a[i]>='0'&&a[i]<='9'))
			            return 0;
		       else
					    return 1;
		}
		}
}



int counting(char b[],int num)    //���ִ�������
{   for(int j=0;j<num;j++)
        if(!strcmp(b,test[j].p))
			test[j].count++;
		else
			return 0;
}

  

int main()
{   char c[200];
    ifstream fin("D:/data.txt");   //���ĵ��л�ȡ�ַ���
	for(int f=0;;f++)
		fin>>c[f];
	fin.close();
    cin.get();
    lwr(c);
    const char *delim = " ,����.''����!?";      //�ָ��ַ���
	char *q;
    int n=0;
	q = strtok(c, delim);
	while (q)
    {
        if (identify(q))
        {
            
                strcpy(test[n].p,q);
                n++;
            
        }
        cout << test[n].p << "��" << test[n].count << '\n';
		q=strtok(NULL,delim);
       
    }
    
	return 0;
}


    

