#include<iostream> 
using namespace std;
class Queuearray
{
	public:		
		Queuearray():capacity(0),front(-1),back(-1)
		{
        queue = new int[capacity];
    };
		void push(int x);
		void pop();
		int getFront();
		void morecapacity();
	private:
	    int capacity, front, back;
        int *queue;	
};
int Queuearray::getFront()
{
	return queue[front+1];
}
void Queuearray::pop()
{
	front++;
}
void Queuearray::push(int x)
{
	
	queue[++back]=x;
}

void Queuearray::morecapacity()
{
    capacity=capacity+2;
}

int main()
{
	int r,c,i,j;
	int peaks=0;
	cin>>r>>c;
	Queuearray peak;
int matrix[r][c];
for(i=0;i<r;i++)
{
	for(j=0;j<c;j++)
	{
		cin>>matrix[i][j];
	}
}
i=0;j=0;
for(i=0;i<r;i++)
{
	for(j=0;j<c;j++)
	{
	
	    if(i==0 && j==0){
		
		if(matrix[i][j]>=matrix[i+1][j]&&matrix[i][j]>=matrix[i][j+1])//�ˬd�k��M�U���A�p�G�����j��L���N�Opeak�C 
			{
				peaks=peaks+1;//�P�i���ƥ�+1 �C 
				peak.morecapacity();//������}�i�y�Ъ�QUEUE�ܤj�C 
				peak.push(i+1);peak.push(j+1);//�s�J�P�i���y�СA�̧Ǧsx,y�o�˳̫ᴣ�X�ӮɬO���Ӷ��Ǫ��C			
			}}
			else if(i==0 && j==c-1) //�k�W��
		{
			if(matrix[i][j]>=matrix[i+1][j] && matrix[i][j]>= matrix[i][j-1])
			{
				peaks=peaks+1;//�P�i���ƥ�+1 �C 
				peak.morecapacity();//������}�i�y�Ъ�QUEUE�ܤj�C 
				peak.push(i+1);peak.push(j+1);//�s�J�P�i���y�СA�̧Ǧsx,y�o�˳̫ᴣ�X�ӮɬO���Ӷ��Ǫ��C	
			}			
		} 
		else if(i==r-1 && j==0)//���U���C
		{
		    if(matrix[i][j]>=matrix[i-1][j] && matrix[i][j]>= matrix[i][j+1])
			{
				peaks=peaks+1;//�P�i���ƥ�+1 �C 
				peak.morecapacity();//������}�i�y�Ъ�QUEUE�ܤj�C 
				peak.push(i+1);peak.push(j+1);//�s�J�P�i���y�СA�̧Ǧsx,y�o�˳̫ᴣ�X�ӮɬO���Ӷ��Ǫ��C	
			}	
		}
		else if (i==r-1 && j==c-1)//�k�U���C
		{
			if(matrix[i][j]>=matrix[i-1][j] && matrix[i][j]>= matrix[i][j-1])
			{
				peaks=peaks+1;//�P�i���ƥ�+1 �C 
				peak.morecapacity();//������}�i�y�Ъ�QUEUE�ܤj�C 
				peak.push(i+1);peak.push(j+1);//�s�J�P�i���y�СA�̧Ǧsx,y�o�˳̫ᴣ�X�ӮɬO���Ӷ��Ǫ��C	
			}
		} 
		else if(i==0 && j!=0 && j!=c-1)//�̤W��A���U�ӭn�B�z�|����C
		{
		if(matrix[i][j]>=matrix[i+1][j] && matrix[i][j]>= matrix[i][j-1] && matrix[i][j]>=matrix[i][j+1])//�䪺�n��T�ӡA�̤W��n�񥪡A�k�A�U�C 
			{
				peaks=peaks+1;//�P�i���ƥ�+1 �C 
				peak.morecapacity();//������}�i�y�Ъ�QUEUE�ܤj�C 
				peak.push(i+1);peak.push(j+1);//�s�J�P�i���y�СA�̧Ǧsx,y�o�˳̫ᴣ�X�ӮɬO���Ӷ��Ǫ��C	
			}
		} 
		else if(i==r-1 && j!=0 && j!=c-1)//�̤U�� 
		{
		if(matrix[i][j]>=matrix[i-1][j] && matrix[i][j]>= matrix[i][j-1] && matrix[i][j]>=matrix[i][j+1])//�W�A���A�k�C 
			{
				peaks=peaks+1;//�P�i���ƥ�+1 �C 
				peak.morecapacity();//������}�i�y�Ъ�QUEUE�ܤj�C 
				peak.push(i+1);peak.push(j+1);//�s�J�P�i���y�СA�̧Ǧsx,y�o�˳̫ᴣ�X�ӮɬO���Ӷ��Ǫ��C	
			}
		} 
		else if(i!=r-1 && j==0 && i!=0)//�̥��� 
		{
		if(matrix[i][j]>=matrix[i-1][j] && matrix[i][j]>= matrix[i+1][j] && matrix[i][j]>=matrix[i][j+1])//�W�A�U�A�k�C 
			{
				peaks=peaks+1;//�P�i���ƥ�+1 �C 
				peak.morecapacity();//������}�i�y�Ъ�QUEUE�ܤj�C 
				peak.push(i+1);peak.push(j+1);//�s�J�P�i���y�СA�̧Ǧsx,y�o�˳̫ᴣ�X�ӮɬO���Ӷ��Ǫ��C	
			}
		} 
				else if(i!=r-1 && j==c-1 && i!=0)//�̥k�� 
		{
		if(matrix[i][j]>=matrix[i-1][j] && matrix[i][j]>= matrix[i+1][j] && matrix[i][j]>=matrix[i][j-1])//�W�A�U�A���C 
			{
				peaks=peaks+1;//�P�i���ƥ�+1 �C 
				peak.morecapacity();//������}�i�y�Ъ�QUEUE�ܤj�C 
				peak.push(i+1);peak.push(j+1);//�s�J�P�i���y�СA�̧Ǧsx,y�o�˳̫ᴣ�X�ӮɬO���Ӷ��Ǫ��C	
			}
		}
		else if(i!=0&&i!=r-1&&j!=0&&j!=c-1)//������ 
		{
			if(matrix[i][j]>=matrix[i-1][j] && matrix[i][j]>= matrix[i+1][j] && matrix[i][j]>=matrix[i][j-1]&& matrix[i][j]>=matrix[i][j+1])//�W�A�U�A���A�k�C 
			{
				peaks=peaks+1;//�P�i���ƥ�+1 �C 
				peak.morecapacity();//������}�i�y�Ъ�QUEUE�ܤj�C 
				peak.push(i+1);peak.push(j+1);//�s�J�P�i���y�СA�̧Ǧsx,y�o�˳̫ᴣ�X�ӮɬO���Ӷ��Ǫ��C	
			}
		}
	}
	
}
     cout<<peaks<<endl;
     for(i=0;i<peaks;i++)
     {
     	cout<<peak.getFront()<<" ";peak.pop();
     	cout<<peak.getFront()<<endl;peak.pop();
	 }
	 return 0;
}

