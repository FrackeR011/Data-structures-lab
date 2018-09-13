#include <iostream>
#include <string>
#define MAX 100 
using namespace std ;

class stack
{
    int a[MAX] ;
    int top = -1 ;
    string name ;
    public :
    
    stack( int n , string named )
    {
        name = named ;
        cout<<n;
        while( n > 0 )
        {
            //top++ ;
            //a[ top] = n-- ; }
            this->push( n-- ) ;
        }
    
    }
    void push( int d )
    {
        //cout<<"blah";
        top++ ;
        a[ top ] = d ;
    }
    
    int pop( )
    {
        if( top < 0 )
            return -1 ;
            
        int temp = a[ top ] ;
        top-- ;
        return temp ;
    }
    
    int get_top( )
    {
        return top + 1 ;
    }
    
    void show_stack( )
    {
        cout<<"\n\n" ;
        int i , j ;
        if( top == -1 )
            cout<<"STACK EMPTY!" ;
        for( i =  top  ; i >= 0 ; i-- )
        {    
            for( j = 0 ;j < a[i] ; j++ )
                cout<<"*" ;
            cout<<"\n" ;
        }
        cout<<"\n" ;    
    }


    string get_name()
    {
        return name ;
    }
    
} ;



void moveDisk( stack &A , stack &B )
{
    static int count = 1 ;
    cout<<"Moving disk from "<<A.get_name()<<" to "<<B.get_name()<<"\n" ;
    int temo = A.pop() ;
    B.push( temo  ) ;
    A.show_stack( ) ;
    B.show_stack( ) ;
    
}

void moveTower( stack &A , stack &B , stack &C , int n )
{

    if( n==1 ) 
       moveDisk( A , C ) ;
    
    else if( n > 1 )
    {
            
        moveTower( A , C , B , n - 1 ) ;
        moveTower( A , B , C , 1 ) ;
        moveTower( B , A , C , n - 1 ) ;
    }
        
}

int main()
{
    stack a( 3 , "A" ) ;
    stack b( 0 , "B" ) , c( 0 , "C" ) ;
    moveTower( a , b , c , 3 ) ;
    
    return 0 ;
}

    
