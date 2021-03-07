
#include <iostream>

using namespace std;
bool canBeKilled(int x,int y,int king_x,int king_y,int queen_x,int queen_y)
{
    // checkmate
    //  if(isCheck( x, y, king_x, king_y, queen_x,queen_y) &&
    //     (x+1<8 || isCheck( x+1, y, king_x, king_y, queen_x,queen_y)) &&
    //     (x-1>=0 ||isCheck( x-1, y, king_x, king_y, queen_x, queen_y)) &&
    //     (y+1<8 ||isCheck( x, y+1, king_x, king_y, queen_x, queen_y))&&
    //     (y-1>=0 || isCheck( x, y-1, king_x, king_y, queen_x, queen_y))&&
    //     ((x+1<8 && y+1<8) ||isCheck( x+1, y+1, king_x, king_y, queen_x, queen_y))&&
    //     ((x-1>=0 && y-1>=0) ||isCheck( x-1, y-1, king_x, king_y, queen_x, queen_y))&&
    //     ((x+1<8 && y-1>=0) || isCheck( x+1, y-1, king_x, king_y, queen_x, queen_y))&&
    //     ((x-1>=0 && y+1<8) ||isCheck( x-1, y+1, king_x, king_y, queen_x, queen_y))){
    //         return 1;
    //     }
    bool horse=(queen_x+2==x && queen_y+1==y) ||
               (queen_x-2==x && queen_y+1==y) ||
               (queen_x+2==x && queen_y-1==y) ||
               (queen_x-2==x && queen_y-1==y) ||
               
               (queen_x+1==x && queen_y+2==y) ||
               (queen_x+1==x && queen_y-2==y) ||
               (queen_x-1==x && queen_y+2==y) ||
               (queen_x-1==x && queen_y-2==y);
               
    if(x==queen_x || y==queen_y || abs(x-queen_x) == abs(y-queen_y)|| horse)
    {
       if(king_x==queen_x)
            {
                if(king_y<queen_y && y<king_y)
                    return false;
                    
                if(king_y>queen_y && y>king_y)
                    return false;
            }
        if(king_y==queen_y)
            {
                if(king_x<queen_x && x<king_x)
                    return false;
                    
                if(king_x>queen_x && x>king_x)
                    return false;
            }
        if(abs(king_x-queen_x) == abs(king_y-queen_y))
            {
             
              if(king_y<queen_y && king_x<queen_x && x<king_x && y<king_y){
                  return false;
              }   
              else if(king_y<queen_y && king_x>queen_x && x>king_x && y<king_y){
                  return false;
              }   
              else if(king_y>queen_y && king_x<queen_x && x<king_x && y>king_y){
                  return false;
              }else
              if(king_y>queen_y && king_x>queen_x && x>king_x && y>king_y){
                  return false;
              }   
            }
        return true;
        
    }
        	
  
    return false;
}

bool isCheck(int x,int y,int king_x,int king_y,int queen_x,int queen_y)
{
    if(canBeKilled( x, y,king_x,king_y, queen_x, queen_y))
    {
        if(canBeKilled( x+1, y, king_x, king_y, queen_x,queen_y)==false||
        canBeKilled( x-1, y, king_x, king_y, queen_x, queen_y)==false||
        canBeKilled( x, y+1, king_x, king_y, queen_x, queen_y)==false||
        canBeKilled( x, y-1, king_x, king_y, queen_x, queen_y)==false||
        canBeKilled( x+1, y+1, king_x, king_y, queen_x, queen_y)==false||
        canBeKilled( x-1, y-1, king_x, king_y, queen_x, queen_y)==false||
        canBeKilled( x+1, y-1, king_x, king_y, queen_x, queen_y)==false||
        canBeKilled( x-1, y+1, king_x, king_y, queen_x, queen_y)==false)
        {
            return true;
        }
    }
    
    return false;
}

int status(int x,int y,int king_x,int king_y,int queen_x,int queen_y){

     // checkmate
     if(canBeKilled( x, y, king_x, king_y, queen_x,queen_y) &&
        canBeKilled( x+1, y, king_x, king_y, queen_x,queen_y) &&
        canBeKilled( x-1, y, king_x, king_y, queen_x, queen_y) &&
        canBeKilled( x, y+1, king_x, king_y, queen_x, queen_y)&&
        canBeKilled( x, y-1, king_x, king_y, queen_x, queen_y)&&
        canBeKilled( x+1, y+1, king_x, king_y, queen_x, queen_y)&&
        canBeKilled( x-1, y-1, king_x, king_y, queen_x, queen_y)&&
        canBeKilled( x+1, y-1, king_x, king_y, queen_x, queen_y)&&
        canBeKilled( x-1, y+1, king_x, king_y, queen_x, queen_y)){
            return 1;
        }
       
       
     // safe 
     
     if(!isCheck( x, y, king_x, king_y, queen_x,queen_y) &&
        (!isCheck( x+1, y, king_x, king_y, queen_x,queen_y) ||
        !isCheck( x-1, y, king_x, king_y, queen_x, queen_y) ||
        !isCheck( x, y+1, king_x, king_y, queen_x, queen_y)||
        !isCheck( x, y-1, king_x, king_y, queen_x, queen_y)||
        !isCheck( x+1, y+1, king_x, king_y, queen_x, queen_y)||
        !isCheck( x-1, y-1, king_x, king_y, queen_x, queen_y)||
        !isCheck( x+1, y-1, king_x, king_y, queen_x, queen_y)||
        !isCheck( x-1, y+1, king_x, king_y, queen_x, queen_y))){
            return 4;
        }
        
    // stalemate
    
     if(!isCheck( x, y, king_x, king_y, queen_x,queen_y) &&
        isCheck( x+1, y, king_x, king_y, queen_x,queen_y) &&
        isCheck( x-1, y, king_x, king_y, queen_x, queen_y) &&
        isCheck( x, y+1, king_x, king_y, queen_x, queen_y)&&
        isCheck( x, y-1, king_x, king_y, queen_x, queen_y)&&
        isCheck( x+1, y+1, king_x, king_y, queen_x, queen_y)&&
        isCheck( x-1, y-1, king_x, king_y, queen_x, queen_y)&&
        isCheck( x+1, y-1, king_x, king_y, queen_x, queen_y)&&
        isCheck( x-1, y+1, king_x, king_y, queen_x, queen_y)){
            return 3;
        }
        
       return 2;
        
}


int main()
{
       /// 1 -> checkmate  ,2 -> check, 3 -> stalemate, 4 -> Safe
	int x=3,y= 0;
       string king="a1";
       string queen="g5";
       
       int king_x=8-stoi(king.substr(1,1));
	   int king_y=(int)(king[0]-'a');
	   int queen_x=8-stoi(queen.substr(1,1));
	   int queen_y=(int)queen[0]-'a';
	   
	   cout<<king_x<<" "<<king_y;
	   cout<<endl;
	   cout<<queen_x<<" "<<queen_y;
	   cout<<endl;
	   //cout<<isCheck(x,y, king_x, king_y,queen_x,queen_y);
	   
	   
	   int arr[8][8];
	   int res[4];
	   
	   for(int i=0;i<8;i++){
	       for(int j=0;j<8;j++){
	           arr[i][j]=status(i,j,king_x,king_y,queen_x,queen_y);
	       }
	   }
	   
	   arr[king_x][king_y]=0;
	   
	   arr[king_x+1][king_y+1]=0;
	   arr[king_x+1][king_y-1]=0;
	   arr[king_x-1][king_y-1]=0;
	   arr[king_x-1][king_y+1]=0;
	   arr[king_x+1][king_y]=0;
	   arr[king_x-1][king_y]=0;
	   arr[king_x][king_y+1]=0;
	   arr[king_x][king_y-1]=0;
	   
	   arr[queen_x][queen_y]=0;
	   
	   int count0=0,count1=0,count2=0,count3=0;
	   
	   for(int i=0;i<8;i++){
	       for(int j=0;j<8;j++){
	           if(arr[i][j]==1){
	               count0++;
	           }else if(arr[i][j]==2){
	               count1++;
	           }else if(arr[i][j]==3){
	               count2++;
	           }else if(arr[i][j]==4){
	               count3++;
	           }
	           cout<<arr[i][j]<<" ";
	       }
	       cout<<endl;
	   }
	   
	 res[0]=count0;
	 res[1]=count1;
	 res[2]=count2;
	 res[3]=count3;
     //return res;
	 
}
