#include <iostream>
#include<string.h>
using namespace std;
float series_branch_resistance(string s_circuit , int i);
float parallel_branch_resistance(string b_circuit, int i);
float series_mother_connection(string m_circuit);
float parallel_mother_connection(string circuit);
float parallel2_branch_resistance(string b2_circuit, int i);
float series2_branch_resistance(string s2_circuit,int i );
int main ()
{
int error= 0 ;
string circuit ;
float voltage;
getline (cin , circuit );
cin>>voltage;
//searching for error;
for(int i=0;i<circuit.length();i++)
 {
   switch(circuit[i])
   {
      case ' ':case 'e':case '0'...'9': case '.':case 'E' : case'P':case 'S':
      break;
      default: error=1 ;
   }
 }
    if(error== 1 )
    {
          cout<<" wrong circuit description ";
    }
	else
	{
		if(circuit[0]=='S')
		{
				cout<<"Circuit Resistance is : "<<"\t"<<series_mother_connection(circuit)<<" ohm"<<"\n";
				cout<<"Current = "<<"\t"<<voltage/series_mother_connection(circuit)<<" A";
		}
		if (circuit[0]=='P')
		{
				cout<<"Circuit Resistance is : "<<"\t"<<parallel_mother_connection(circuit)<<" ohm"<<"\n";
				cout<<"Current = "<<"\t"<<voltage/parallel_mother_connection(circuit)<<" A";
		}
	}
}
	float series_branch_resistance(string s_circuit,int i )
{
	//initialize total resistance by 0, because no resistors yet
	float series_total_branch_resistance = 0;
	//initialize 2 flags to store the beginning and the ending of the resistor value to cut the string by substr(index,length)
	int start = i+2; //start = index
	int length = 0;
	//start to loop on character by character
		for( i=i+2;i<s_circuit.length();i++)
		{
			//if we find E or e then break the loop, we don't need resistors any more
			if(s_circuit[i]=='E')
			break;
			if(s_circuit[i]=='P')
			{
			break;
			}
			//if not space then add length of resistor value and skip this loop
			if( s_circuit[i] != ' ')
			{
				length++;
				continue;
			}
			else
			{
			//if we find space, then start to get the resistor value before the space
			float r = stof( s_circuit.substr(start,length) );
			// update 2 flags/pointers
			start = i+1;
			length = 0;
			// cumulative sum according to circuit type
			series_total_branch_resistance += r;
			}
		}
	return series_total_branch_resistance;
}
	float parallel_branch_resistance(string b_circuit, int i)
{
	//initialize total resistance by 0, because no resistors yet
	float parallel_total_branch_resistance = 0;
	////initialize 2 flags to store the beginning and the ending of the resistor value to cut the string by substr(index,length)
	int start = i+2 ; //start = index
	int length = 0;
	//start to loop on character by character
		for( i=i;i<b_circuit.length();i++)
		{
		//if we find E or e then break the loop, we don't need resistors any more
		if(b_circuit[i]=='e')
		break;
		if(b_circuit[i]=='E')
		break;
		if(b_circuit[i]=='S')
		break;
		//if not space then add length of resistor value and skip this loop
		if( b_circuit[i] != ' ')
		{
		length++;
		continue;
		}
		else
		{
		//if we find space, then start to get the resistor value before the space
		float r = stof( b_circuit.substr(start,length) );
		// update 2 flags/pointers
		start = i+1;
		length = 0;
		// cumulative sum according to circuit type
		parallel_total_branch_resistance += 1/r;
		}
		parallel_total_branch_resistance = 1/parallel_total_branch_resistance;
		}
		return parallel_total_branch_resistance ;
		}
	float series_mother_connection(string m_circuit)
{
	float series_total_branch_resistance=0;
	float r_total = 0 ;
	float r_branch1 =0;
	float r_branch2 =0;
		for(int i =0; i<m_circuit.length();i++)
		{
		if(m_circuit[i]=='S'||m_circuit[i]=='e')
		{
		r_branch1+= series_branch_resistance(m_circuit, i );
		}
		if (m_circuit[i]=='P')
		{
		r_branch2+=parallel_branch_resistance( m_circuit, i);
		}
	}
return r_branch1+r_branch2;
}
	float parallel2_branch_resistance(string b2_circuit, int i)
{
	//initialize total resistance by 0, because no resistors yet
	float parallel_total_branch_resistance = 0;
	////initialize 2 flags to store the beginning and the ending of the resistor value to cut the string by substr(index,length)
	int start = i+2 ; //start = index
	int length = 0;
	//start to loop on character by character
	for( i=i+2;i<b2_circuit.length();i++)
	{
	//if we find E or e then break the loop, we don't need resistors any more
	if (b2_circuit[i]=='e')break;
	if(b2_circuit[i]=='E')
	break;
	if(b2_circuit[i]=='S')
	break;
	//if not space then add length of resistor value and skip this loop
	if( b2_circuit[i] != ' ')
	{
	length++;
	continue;
	}
	else
	{
	//if we find space, then start to get the resistor value before the space
	float r = stof( b2_circuit.substr(start,length) );
	// update 2 flags/pointers
	start = i+1;
	length = 0;
	// cumulative sum according to circuit type
	parallel_total_branch_resistance += 1/r;
	}
	parallel_total_branch_resistance = 1/parallel_total_branch_resistance;
	}
	return parallel_total_branch_resistance ;
}
	float series2_branch_resistance(string s2_circuit,int i )
{
	//initialize total resistance by 0, because no resistors yet
	float series_total_branch_resistance = 0;
	//initialize 2 flags to store the beginning and the ending of the resistor value to cut the string by substr(index,length)
	int start = i+2; //start = index
	int length = 0;
	//start to loop on character by character
	for( i=i+2;i<s2_circuit.length();i++)
	{
	//if we find E or e then break the loop, we don't need resistors any more
	if (s2_circuit[i]=='e')
	break;
	if(s2_circuit[i]=='E')
	break;
	if(s2_circuit[i]=='P')
	{
	break;
	}
	//if not space then add length of resistor value and skip this loop
	if( s2_circuit[i] != ' ')
	{
	length++;
	continue;
	}
	else
	{
	//if we find space, then start to get the resistor value before the space
	float r = stof( s2_circuit.substr(start,length) );
	// update 2 flags/pointers
	start = i+1;
	length = 0;
	// cumulative sum according to circuit type
	series_total_branch_resistance += r;
	}
}
 return series_total_branch_resistance;
}
	float parallel_mother_connection(string m_circuit)
{
	float paralell_total_branch_resistance=0;
	float r_total =0 ;
	float r_branch1 =0;
	float r_branch2 =0;
	for(int i =2; i<m_circuit.length();i++)
	{
	//if(m_circuit[i]=='P'||m_circuit[i]=='e')
	//{
	// r_branch1+= parallel2_branch_resistance(m_circuit, i );
	//}
	if (m_circuit[i]=='S')
		{
		r_branch2+=1/series2_branch_resistance( m_circuit, i);
		}
		else if (m_circuit[i]!='S'&&m_circuit[i]=='e') r_branch1+= parallel2_branch_resistance(m_circuit, i );
		}
		if (r_branch1!=0)
		{
		r_total=1/r_branch1+ r_branch2;
		return
		1/r_total;
		}
		if (r_branch1==0)
		{
		return 1/r_branch2;
		}
}
