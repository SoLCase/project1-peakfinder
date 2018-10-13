#include<iostream> 
#include<fstream>
#include<string>
#include <vector>
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

int main(int argc, char* argv[])
{
	
	int peaks=0;
	int r,c,i,j;
	char folder[10];
	Queuearray peak;
	//cin>>folder;
	char*filePath;
	
	freopen(".\\1234\\matrix.data","r",stdin);//使用這檔案的內容cin。 
	cin>>r>>c; // 輸入行、列，成功 。.
	int matrix[r][c]; 
	for(i=0;i<r;i++) //輸入矩陣  (疑似在此失敗。) 
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
		
		if(matrix[i][j]>=matrix[i+1][j]&&matrix[i][j]>=matrix[i][j+1])//檢查右邊和下面，如果都不大於他那就是peak。 
			{
				peaks=peaks+1;//闢可的數目+1 。 
				peak.morecapacity();//先把裝癖可座標的QUEUE變大。 
				peak.push(i+1);peak.push(j+1);//存入闢可的座標，依序存x,y這樣最後提出來時是按照順序的。			
			}}
			else if(i==0 && j==c-1) //右上角
		{
			if(matrix[i][j]>=matrix[i+1][j] && matrix[i][j]>= matrix[i][j-1])
			{
				peaks=peaks+1;//闢可的數目+1 。 
				peak.morecapacity();//先把裝癖可座標的QUEUE變大。 
				peak.push(i+1);peak.push(j+1);//存入闢可的座標，依序存x,y這樣最後提出來時是按照順序的。	
			}			
		} 
		else if(i==r-1 && j==0)//左下角。
		{
		    if(matrix[i][j]>=matrix[i-1][j] && matrix[i][j]>= matrix[i][j+1])
			{
				peaks=peaks+1;//闢可的數目+1 。 
				peak.morecapacity();//先把裝癖可座標的QUEUE變大。 
				peak.push(i+1);peak.push(j+1);//存入闢可的座標，依序存x,y這樣最後提出來時是按照順序的。	
			}	
		}
		else if (i==r-1 && j==c-1)//右下角。
		{
			if(matrix[i][j]>=matrix[i-1][j] && matrix[i][j]>= matrix[i][j-1])
			{
				peaks=peaks+1;//闢可的數目+1 。 
				peak.morecapacity();//先把裝癖可座標的QUEUE變大。 
				peak.push(i+1);peak.push(j+1);//存入闢可的座標，依序存x,y這樣最後提出來時是按照順序的。	
			}
		} 
		else if(i==0 && j!=0 && j!=c-1)//最上邊，接下來要處理四個邊。
		{
		if(matrix[i][j]>=matrix[i+1][j] && matrix[i][j]>= matrix[i][j-1] && matrix[i][j]>=matrix[i][j+1])//邊的要比三個，最上邊要比左，右，下。 
			{
				peaks=peaks+1;//闢可的數目+1 。 
				peak.morecapacity();//先把裝癖可座標的QUEUE變大。 
				peak.push(i+1);peak.push(j+1);//存入闢可的座標，依序存x,y這樣最後提出來時是按照順序的。	
			}
		} 
		else if(i==r-1 && j!=0 && j!=c-1)//最下邊 
		{
		if(matrix[i][j]>=matrix[i-1][j] && matrix[i][j]>= matrix[i][j-1] && matrix[i][j]>=matrix[i][j+1])//上，左，右。 
			{
				peaks=peaks+1;//闢可的數目+1 。 
				peak.morecapacity();//先把裝癖可座標的QUEUE變大。 
				peak.push(i+1);peak.push(j+1);//存入闢可的座標，依序存x,y這樣最後提出來時是按照順序的。	
			}
		} 
		else if(i!=r-1 && j==0 && i!=0)//最左邊 
		{
		if(matrix[i][j]>=matrix[i-1][j] && matrix[i][j]>= matrix[i+1][j] && matrix[i][j]>=matrix[i][j+1])//上，下，右。 
			{
				peaks=peaks+1;//闢可的數目+1 。 
				peak.morecapacity();//先把裝癖可座標的QUEUE變大。 
				peak.push(i+1);peak.push(j+1);//存入闢可的座標，依序存x,y這樣最後提出來時是按照順序的。	
			}
		} 
				else if(i!=r-1 && j==c-1 && i!=0)//最右邊 
		{
		if(matrix[i][j]>=matrix[i-1][j] && matrix[i][j]>= matrix[i+1][j] && matrix[i][j]>=matrix[i][j-1])//上，下，左。 
			{
				peaks=peaks+1;//闢可的數目+1 。 
				peak.morecapacity();//先把裝癖可座標的QUEUE變大。 
				peak.push(i+1);peak.push(j+1);//存入闢可的座標，依序存x,y這樣最後提出來時是按照順序的。	
			}
		}
		else if(i!=0&&i!=r-1&&j!=0&&j!=c-1)//中間的 
		{
			if(matrix[i][j]>=matrix[i-1][j] && matrix[i][j]>= matrix[i+1][j] && matrix[i][j]>=matrix[i][j-1]&& matrix[i][j]>=matrix[i][j+1])//上，下，左，右。 
			{
				peaks=peaks+1;//闢可的數目+1 。 
				peak.morecapacity();//先把裝癖可座標的QUEUE變大。 
				peak.push(i+1);peak.push(j+1);//存入闢可的座標，依序存x,y這樣最後提出來時是按照順序的。	
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
