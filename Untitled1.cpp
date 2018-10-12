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
for(i=0;i<r;i++)
{
	for(j=0;j<c;j++)
	{
		while(i==0 && j==0)//matrix[0][0]�O�̥��W�����A�u�n�ˬd�k�M�U�A�H�U�|��|�Ө����������B�z�C 
		{
			if(matrix[i+1][j]<=matrix[i][j]&&matrix[i][j+1]<=matrix[i][j])//�ˬd�k��M�U���A�p�G�����j��L���N�Opeak�C 
			{
				peaks=peaks+1;//�P�i���ƥ�+1 �C 
				peak.morecapacity();//������}�i�y�Ъ�QUEUE�ܤj�C 
				peak.push(i);peak.push(j);//�s�J�P�i���y�СA�̧Ǧsx,y�o�˳̫ᴣ�X�ӮɬO���Ӷ��Ǫ��C			
			}
		}
		while(i==0 &&j==c) //�k�W��
		{
			if(matrix[i+1][j]<=matrix[i][j] && matrix[i][j-1]<= matrix[i][j])
			{
				peaks=peaks+1;//�P�i���ƥ�+1 �C 
				peak.morecapacity();//������}�i�y�Ъ�QUEUE�ܤj�C 
				peak.push(i);peak.push(j);//�s�J�P�i���y�СA�̧Ǧsx,y�o�˳̫ᴣ�X�ӮɬO���Ӷ��Ǫ��C	
			}			
		} 
		while(i==r && j==0)//���U���C
		{
		    if(matrix[i-1][j]<=matrix[i][j] && matrix[i][j+1]<= matrix[i][j])
			{
				peaks=peaks+1;//�P�i���ƥ�+1 �C 
				peak.morecapacity();//������}�i�y�Ъ�QUEUE�ܤj�C 
				peak.push(i);peak.push(j);//�s�J�P�i���y�СA�̧Ǧsx,y�o�˳̫ᴣ�X�ӮɬO���Ӷ��Ǫ��C	
			}	
		}
		while (i==r && j==c)//�k�U���C
		{
			if(matrix[i-1][j]<=matrix[i][j] && matrix[i][j-1]<= matrix[i][j])
			{
				peaks=peaks+1;//�P�i���ƥ�+1 �C 
				peak.morecapacity();//������}�i�y�Ъ�QUEUE�ܤj�C 
				peak.push(i);peak.push(j);//�s�J�P�i���y�СA�̧Ǧsx,y�o�˳̫ᴣ�X�ӮɬO���Ӷ��Ǫ��C	
			}
		} 
		while(i=0 && j!=0 && j!=c)//�̤W��A���U�ӭn�B�z�|����C
		{
		if(matrix[i+1][j]<=matrix[i][j] && matrix[i][j-1]<= matrix[i][j] && matrix[i][j+1]<=matrix[i][j])//�䪺�n��T�ӡA�̤W��n�񥪡A�k�A�U�C 
			{
				peaks=peaks+1;//�P�i���ƥ�+1 �C 
				peak.morecapacity();//������}�i�y�Ъ�QUEUE�ܤj�C 
				peak.push(i);peak.push(j);//�s�J�P�i���y�СA�̧Ǧsx,y�o�˳̫ᴣ�X�ӮɬO���Ӷ��Ǫ��C	
			}
		} 
		while(i=r && j!=0 && j!=c)//�̤U�� 
		{
		if(matrix[i-1][j]<=matrix[i][j] && matrix[i][j-1]<= matrix[i][j] && matrix[i][j+1]<=matrix[i][j])//�W�A���A�k�C 
			{
				peaks=peaks+1;//�P�i���ƥ�+1 �C 
				peak.morecapacity();//������}�i�y�Ъ�QUEUE�ܤj�C 
				peak.push(i);peak.push(j);//�s�J�P�i���y�СA�̧Ǧsx,y�o�˳̫ᴣ�X�ӮɬO���Ӷ��Ǫ��C	
			}
		} 
		while(i!=r && j==0 && i!=0)//�̥��� 
		{
		if(matrix[i-1][j]<=matrix[i][j] && matrix[i+1][j]<= matrix[i][j] && matrix[i][j+1]<=matrix[i][j])//�W�A�U�A�k�C 
			{
				peaks=peaks+1;//�P�i���ƥ�+1 �C 
				peak.morecapacity();//������}�i�y�Ъ�QUEUE�ܤj�C 
				peak.push(i);peak.push(j);//�s�J�P�i���y�СA�̧Ǧsx,y�o�˳̫ᴣ�X�ӮɬO���Ӷ��Ǫ��C	
			}
		} 
				while(i!=r && j==c && i!=0)//�̥k�� 
		{
		if(matrix[i-1][j]<=matrix[i][j] && matrix[i+1][j]<= matrix[i][j] && matrix[i][j-1]<=matrix[i][j])//�W�A�U�A���C 
			{
				peaks=peaks+1;//�P�i���ƥ�+1 �C 
				peak.morecapacity();//������}�i�y�Ъ�QUEUE�ܤj�C 
				peak.push(i);peak.push(j);//�s�J�P�i���y�СA�̧Ǧsx,y�o�˳̫ᴣ�X�ӮɬO���Ӷ��Ǫ��C	
			}
		}
		while(i!=0&&i!=r&&j!=0&&j!=c)//������ 
		{
			if(matrix[i-1][j]<=matrix[i][j] && matrix[i+1][j]<= matrix[i][j] && matrix[i][j-1]<=matrix[i][j]&& matrix[i][j+1]<=matrix[i][j])//�W�A�U�A���A�k�C 
			{
				peaks=peaks+1;//�P�i���ƥ�+1 �C 
				peak.morecapacity();//������}�i�y�Ъ�QUEUE�ܤj�C 
				peak.push(i);peak.push(j);//�s�J�P�i���y�СA�̧Ǧsx,y�o�˳̫ᴣ�X�ӮɬO���Ӷ��Ǫ��C	
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


