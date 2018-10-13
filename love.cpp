#include<iostream> 
#include<fstream>
#include<string.h>
using namespace std;
class Queuearray
{
	public:		
		Queuearray():capacity(1000000),front(-1),back(-1)
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
int main(int argc,char*argv[])
{
    int peaks=0;
	int check=0;
    Queuearray peak;
    int r,c,i,j;
	fstream fin;
	string folderin;
    string folderout;
    string pathin,pathout;
    string start;
    folderin = "/matrix.data";
    folderout = "/final.peak";
    start ="./";
    pathin = start+argv[1] + folderin;
    pathout = start+argv[1] + folderout;
    fin.open(pathin,ios::in);
    if(fin.is_open()){cout<<"opened";}else{cerr<<"defail";}
    fin>>r;fin>>c;
    int matrix[r][c];
    for(i=0;i<r;i++) //??稿??????  (???技?????????? 
	{
		for(j=0;j<c;j++)
		{
			fin>>matrix[i][j];
		}
	}
    
  

    i=0;j=0;
for(i=0;i<r;i++)
{
	for(j=0;j<c;j++)
	{  
	 	if(r>1&&c>1){
	    if(i==0 && j==0){
		
		if(matrix[i][j]>=matrix[i+1][j]&&matrix[i][j]>=matrix[i][j+1])//??㈡????????????????????ф柤??栭偅??????peak??
			{
				peaks=peaks+1;//?㈠彲???暩??1 ??
			//	peak.morecapacity();//???????????骇?????QUEUE???????
				peak.push(i+1);peak.push(j+1);//??樺??㈠彲???骇????????????榵,y?欐??????屾?????傛?????収??????�?		
			}}
			else if(i==0 && j==c-1) //?????
		{
			if(matrix[i][j]>=matrix[i+1][j] && matrix[i][j]>= matrix[i][j-1])
			{
				peaks=peaks+1;//?㈠彲???暩??1 ??
			//	peak.morecapacity();//???????????骇?????QUEUE???????
				peak.push(i+1);peak.push(j+1);//??樺??㈠彲???骇????????????榵,y?欐??????屾?????傛?????収??????�?
			}			
		} 
		else if(i==r-1 && j==0)//??︿???????
		{
		    if(matrix[i][j]>=matrix[i-1][j] && matrix[i][j]>= matrix[i][j+1])
			{
				peaks=peaks+1;//?㈠彲???暩??1 ??
			//	peak.morecapacity();//???????????骇?????QUEUE???????
				peak.push(i+1);peak.push(j+1);//??樺??㈠彲???骇????????????榵,y?欐??????屾?????傛?????収??????�?
			}	
		}
		else if (i==r-1 && j==c-1)//?????????
		{
			if(matrix[i][j]>=matrix[i-1][j] && matrix[i][j]>= matrix[i][j-1])
			{
				peaks=peaks+1;//?㈠彲???暩??1 ??
		//	peak.morecapacity();//???????????骇?????QUEUE???????
				peak.push(i+1);peak.push(j+1);//??樺??㈠彲???骇????????????榵,y?欐??????屾?????傛?????収??????�?
			}
		} 
		else if(i==0 && j!=0 && j!=c-1)//?????????屾????????佽?????????
		{
		if(matrix[i][j]>=matrix[i+1][j] && matrix[i][j]>= matrix[i][j-1] && matrix[i][j]>=matrix[i][j+1])//?????佹???夊????????????佹???????????????
			{
				peaks=peaks+1;//?㈠彲???暩??1 ??
			//	peak.morecapacity();//???????????骇?????QUEUE???????
				peak.push(i+1);peak.push(j+1);//??樺??㈠彲???骇????????????榵,y?欐??????屾?????傛?????収??????�?
			}
		} 
		else if(i==r-1 && j!=0 && j!=c-1)//????嬮? 
		{
		if(matrix[i][j]>=matrix[i-1][j] && matrix[i][j]>= matrix[i][j-1] && matrix[i][j]>=matrix[i][j+1])//?????????????�?
			{
				peaks=peaks+1;//?㈠彲???暩??1 ??
			//	peak.morecapacity();//???????????骇?????QUEUE???????
				peak.push(i+1);peak.push(j+1);//??樺??㈠彲???骇????????????榵,y?欐??????屾?????傛?????収??????�?
			}
		} 
		else if(i!=r-1 && j==0 && i!=0)//????﹂? 
		{
		if(matrix[i][j]>=matrix[i-1][j] && matrix[i][j]>= matrix[i+1][j] && matrix[i][j]>=matrix[i][j+1])//???????嬶????�?
			{
				peaks=peaks+1;//?㈠彲???暩??1 ??
			//	peak.morecapacity();//???????????骇?????QUEUE???????
				peak.push(i+1);peak.push(j+1);//??樺??㈠彲???骇????????????榵,y?欐??????屾?????傛?????収??????�?
			}
		} 
				else if(i!=r-1 && j==c-1 && i!=0)//????? 
		{
		if(matrix[i][j]>=matrix[i-1][j] && matrix[i][j]>= matrix[i+1][j] && matrix[i][j]>=matrix[i][j-1])//???????嬶???︺??
			{
				peaks=peaks+1;//?㈠彲???暩??1 ??
		//	peak.morecapacity();//???????????骇?????QUEUE???????
				peak.push(i+1);peak.push(j+1);//??樺??㈠彲???骇????????????榵,y?欐??????屾?????傛?????収??????�?
			}
		}
		else if(i!=0&&i!=r-1&&j!=0&&j!=c-1)//???????
		{
			if(matrix[i][j]>=matrix[i-1][j] && matrix[i][j]>= matrix[i+1][j] && matrix[i][j]>=matrix[i][j-1]&& matrix[i][j]>=matrix[i][j+1])//???????嬶?????????�?
			{
				peaks=peaks+1;//?㈠彲???暩??1 ??
			//	peak.morecapacity();//???????????骇?????QUEUE???????
				peak.push(i+1);peak.push(j+1);//??樺??㈠彲???骇????????????榵,y?欐??????屾?????傛?????収??????�?
			}
		}
	}
	else
	{
    if(c==1)//Τ︽ぃノ蛤娩ゑ
	   {
         if(i==0)
		 {
			 if(matrix[i][j]>=matrix[i+1][j])
			 {
				peaks=peaks+1;//?㈠彲???暩??1 ??
			//	peak.morecapacity();//???????????骇?????QUEUE???????
				peak.push(i+1);peak.push(j+1);//??樺??㈠彲???骇????????????榵,y?欐??????屾?????傛?????収??????�?
			 }
		 }
		 else if(i==r)
		 {
			 if(matrix[i][j]>=matrix[i-1][j])
			 {
				peaks=peaks+1;//?㈠彲???暩??1 ??
			//	peak.morecapacity();//???????????骇?????QUEUE???????
				peak.push(i+1);peak.push(j+1);//??樺??㈠彲???骇????????????榵,y?欐??????屾?????傛?????収??????�?
			 }
		 }
		 else
		 {
			 	 if(matrix[i][j]>=matrix[i-1][j]&&matrix[i][j]>=matrix[i+1][j])
			 {
				peaks=peaks+1;//?㈠彲???暩??1 ??
			//	peak.morecapacity();//???????????骇?????QUEUE???????
				peak.push(i+1);peak.push(j+1);//??樺??㈠彲???骇????????????榵,y?欐??????屾?????傛?????収??????�?
			 }

		 }
	   }
	else if(r==1)
	{
		if(j==0)
		{
			if(matrix[i][j]>=matrix[i][j+1])
			 {
				peaks=peaks+1;//?㈠彲???暩??1 ??
			//	peak.morecapacity();//???????????骇?????QUEUE???????
				peak.push(i+1);peak.push(j+1);//??樺??㈠彲???骇????????????榵,y?欐??????屾?????傛?????収??????�?
			 }
		}
		else if(j==c)
		{
			if(matrix[i][j]>=matrix[i][j-1])
			 {
				peaks=peaks+1;//?㈠彲???暩??1 ??
			//	peak.morecapacity();//???????????骇?????QUEUE???????
				peak.push(i+1);peak.push(j+1);//??樺??㈠彲???骇????????????榵,y?欐??????屾?????傛?????収??????�?
			 }
		}
		else
		{
			if(matrix[i][j]>=matrix[i][j+1]&& matrix[i][j]>=matrix[i][j-1])
			 {
				peaks=peaks+1;//?㈠彲???暩??1 ??
			//	peak.morecapacity();//???????????骇?????QUEUE???????
				peak.push(i+1);peak.push(j+1);//??樺??㈠彲???骇????????????榵,y?欐??????屾?????傛?????収??????�?
			 }

		}
	}
	}
	}
}

ofstream result;
result.open(pathout,ios::out);
if(result.is_open()){cout<<"success";}else{cout<<"defail";}
result<<peaks<<endl;
   for(i=0;i<peaks;i++)
     {
     	result<<peak.getFront()<<" ";peak.pop();
     	result<<peak.getFront()<<endl;peak.pop();
	 }
   
     return 0;
}


