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
		while(i==0 && j==0)//matrix[0][0]是最左上角的，只要檢查右和下，以下會把四個角落都做此處理。 
		{
			if(matrix[i+1][j]<=matrix[i][j]&&matrix[i][j+1]<=matrix[i][j])//檢查右邊和下面，如果都不大於他那就是peak。 
			{
				peaks=peaks+1;//闢可的數目+1 。 
				peak.morecapacity();//先把裝癖可座標的QUEUE變大。 
				peak.push(i);peak.push(j);//存入闢可的座標，依序存x,y這樣最後提出來時是按照順序的。			
			}
		}
		while(i==0 &&j==c) //右上角
		{
			if(matrix[i+1][j]<=matrix[i][j] && matrix[i][j-1]<= matrix[i][j])
			{
				peaks=peaks+1;//闢可的數目+1 。 
				peak.morecapacity();//先把裝癖可座標的QUEUE變大。 
				peak.push(i);peak.push(j);//存入闢可的座標，依序存x,y這樣最後提出來時是按照順序的。	
			}			
		} 
		while(i==r && j==0)//左下角。
		{
		    if(matrix[i-1][j]<=matrix[i][j] && matrix[i][j+1]<= matrix[i][j])
			{
				peaks=peaks+1;//闢可的數目+1 。 
				peak.morecapacity();//先把裝癖可座標的QUEUE變大。 
				peak.push(i);peak.push(j);//存入闢可的座標，依序存x,y這樣最後提出來時是按照順序的。	
			}	
		}
		while (i==r && j==c)//右下角。
		{
			if(matrix[i-1][j]<=matrix[i][j] && matrix[i][j-1]<= matrix[i][j])
			{
				peaks=peaks+1;//闢可的數目+1 。 
				peak.morecapacity();//先把裝癖可座標的QUEUE變大。 
				peak.push(i);peak.push(j);//存入闢可的座標，依序存x,y這樣最後提出來時是按照順序的。	
			}
		} 
		while(i=0 && j!=0 && j!=c)//最上邊，接下來要處理四個邊。
		{
		if(matrix[i+1][j]<=matrix[i][j] && matrix[i][j-1]<= matrix[i][j] && matrix[i][j+1]<=matrix[i][j])//邊的要比三個，最上邊要比左，右，下。 
			{
				peaks=peaks+1;//闢可的數目+1 。 
				peak.morecapacity();//先把裝癖可座標的QUEUE變大。 
				peak.push(i);peak.push(j);//存入闢可的座標，依序存x,y這樣最後提出來時是按照順序的。	
			}
		} 
		while(i=r && j!=0 && j!=c)//最下邊 
		{
		if(matrix[i-1][j]<=matrix[i][j] && matrix[i][j-1]<= matrix[i][j] && matrix[i][j+1]<=matrix[i][j])//上，左，右。 
			{
				peaks=peaks+1;//闢可的數目+1 。 
				peak.morecapacity();//先把裝癖可座標的QUEUE變大。 
				peak.push(i);peak.push(j);//存入闢可的座標，依序存x,y這樣最後提出來時是按照順序的。	
			}
		} 
		while(i!=r && j==0 && i!=0)//最左邊 
		{
		if(matrix[i-1][j]<=matrix[i][j] && matrix[i+1][j]<= matrix[i][j] && matrix[i][j+1]<=matrix[i][j])//上，下，右。 
			{
				peaks=peaks+1;//闢可的數目+1 。 
				peak.morecapacity();//先把裝癖可座標的QUEUE變大。 
				peak.push(i);peak.push(j);//存入闢可的座標，依序存x,y這樣最後提出來時是按照順序的。	
			}
		} 
				while(i!=r && j==c && i!=0)//最右邊 
		{
		if(matrix[i-1][j]<=matrix[i][j] && matrix[i+1][j]<= matrix[i][j] && matrix[i][j-1]<=matrix[i][j])//上，下，左。 
			{
				peaks=peaks+1;//闢可的數目+1 。 
				peak.morecapacity();//先把裝癖可座標的QUEUE變大。 
				peak.push(i);peak.push(j);//存入闢可的座標，依序存x,y這樣最後提出來時是按照順序的。	
			}
		}
		while(i!=0&&i!=r&&j!=0&&j!=c)//中間的 
		{
			if(matrix[i-1][j]<=matrix[i][j] && matrix[i+1][j]<= matrix[i][j] && matrix[i][j-1]<=matrix[i][j]&& matrix[i][j+1]<=matrix[i][j])//上，下，左，右。 
			{
				peaks=peaks+1;//闢可的數目+1 。 
				peak.morecapacity();//先把裝癖可座標的QUEUE變大。 
				peak.push(i);peak.push(j);//存入闢可的座標，依序存x,y這樣最後提出來時是按照順序的。	
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


