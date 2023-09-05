#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cmath>
#include<map>
#include<sstream>
#include<tuple>
#include <unistd.h>

using namespace std;
vector<tuple<int,int>> source_ad;
vector<tuple<int,int>> dest_ad;
vector<tuple<int,int>> obstacles_ad;
vector<tuple<int,int>> iterating_ad,iterating_ad1,maze_route_path;
tuple<int,int> temp_ad,current_source_ad,current_dest_ad,temp_iterating_ad;

int grid_size;

void openinputfile(ifstream& inFile)
{
    string filename;
    cout<<"Enter the file name: ";
    cin>>filename;
    inFile.open(filename);
    while(!inFile)
    {
        cout<<"File doesnt exist or unable to open file"<<endl;
        cout<<"Enter the file name: ";
        cin>>filename;
        inFile.clear();
        inFile.open(filename);
    }
}
int main()
{
    int arr1[4]={0,-1,0,1};
    int arr2[4]={-1,0,1,0};
    int arr[15][15];
    int x1,x2,y1,y2;
    string str,str1;
    string temp1,temp2,temp3,temp4;
    ifstream inFile;
    int temp;
    cout<<"Please input the routing test files : "<<endl<<endl;
    openinputfile(inFile);
    while (!inFile.eof())
    {
        getline(inFile,str);
        if(str.find("obstruction")==0)
        {
            int row_ad,col_ad;
            temp = str.rfind(" ");
            temp1= str.substr(temp-2,temp);
            temp2= str.substr(temp,str.size());
            row_ad= stoi(temp1);
            col_ad= stoi(temp2);
            temp_ad=make_tuple(row_ad,col_ad);
            obstacles_ad.push_back(temp_ad);
        }
        else if(str.rfind("net")==0)
        {
            temp = str.rfind(" ");

            temp4 = str.substr(temp+1,str.length());

            str1 = str.substr(0,temp);
            str = str1;
    
            temp = str.rfind(" ");
            temp3 = str.substr(temp+1,str.length());

            str1 = str.substr(0,temp);
            str = str1;

            temp = str.rfind(" ");
            temp1 = str.substr(temp-2,temp);
            temp2 = str.substr(temp+1,str.length());

            x1 = stoi(temp1);
            y1 = stoi(temp2);
            x2 = stoi(temp3);
            y2 = stoi(temp4);
            temp_ad=make_tuple(x1,y1);
            source_ad.push_back(temp_ad);
            temp_ad=make_tuple(x2,y2);
            dest_ad.push_back(temp_ad);
        }
    }
    inFile.close();
    cout<<"Extraction of list of Obstacles, Source addresses and corresponding destinations is successful: "<<endl;
    cout<<endl<<"The Grid size is 15"<<endl;

    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            arr[i][j]=0;
        }
    }

    for(int i=0;i<obstacles_ad.size();i++)
    {
        arr[get<0>(obstacles_ad[i])][get<1>(obstacles_ad[i])]= -1;
    }
    for(int i=0;i<source_ad.size();i++)
    {
        arr[get<0>(source_ad[i])][get<1>(source_ad[i])]= -1;
    }
    for(int i=0;i<dest_ad.size();i++)
    {
        arr[get<0>(dest_ad[i])][get<1>(dest_ad[i])]= -1;
    }
    cout<<endl<<"The initial grid "<<endl<<endl;
    for(int i=0; i<15; i++)
    {
        for(int j=0; j <15; j++)
        {
            if(arr[i][j]<0 || arr[i][j]>9)
                cout<<"  "<<arr[i][j];
            else
                cout<<"   "<<arr[i][j];
        }
        cout<<"\n";
    }
    bool flag1=true;
    cout<<endl<<"source    destinations"<<endl<<endl;//
    for(int i=0; i<source_ad.size() ;i++)//
    {//
        temp_ad=source_ad[i];//
        cout<<(get<0>(temp_ad))<<" "<<(get<1>(temp_ad))<<"   ";//
        temp_ad=dest_ad[i];//
        cout<<(get<0>(temp_ad))<<" "<<(get<1>(temp_ad))<<endl;//
    }//
    cout<<endl<<endl<<endl;
    while(flag1)
    {
        iterating_ad.clear();
        iterating_ad1.clear();
        current_source_ad=source_ad.back();
        current_dest_ad=dest_ad.back();
        cout<<endl<<endl<<"Roouting for below mentioned source to destination"<<endl;
        cout<<"("<<get<0>(current_source_ad)<<","<<get<1>(current_source_ad)<<")"<<"  ("<<get<0>(current_dest_ad)<<","<<get<1>(current_dest_ad)<<")"<<endl;
        x1=get<0>(current_source_ad);
        x2=get<0>(current_dest_ad);
        y1=get<1>(current_source_ad);
        y2=get<1>(current_dest_ad);
        int i1,i2,j1,j2;
        i1=x1;i2=x2;j1=y1;j2=y2;
        source_ad.pop_back();
        dest_ad.pop_back();
        arr[x1][y1]= -2;
        arr[x2][y2]= -3;
        int maze_counter=1;
        temp=0;
        iterating_ad.push_back(current_source_ad);
        while(true)
        {
            for(int i=0;i<iterating_ad.size();i++)
            {
                temp_ad=iterating_ad[i];
                x1=get<0>(temp_ad);
                x2=get<1>(temp_ad);

                for(int j=0;j<4;j++)
                {
                    int a1,b1;
                    a1= x1+arr1[j];
                    b1= x2+arr2[j];
                    if(a1>=0 && a1<=14 && b1>=0 && b1<= 14)
                    {
                        temp= arr[a1][b1];
                        if(temp==0)
                        {
                            temp_iterating_ad=make_tuple(a1,b1);
                            iterating_ad1.push_back(temp_iterating_ad);
                        }
                        else if(temp== -3)
                        {
                            break;
                        }
                    }
                }
                if(temp==-3)
                {
                    break;
                }
            }
            if(temp==-3)
            {
                break;
            }
            else
            {
                for(int i=0;i<iterating_ad1.size();i++)
                {
                    temp_ad=iterating_ad1[i];
                    x1=get<0>(temp_ad);
                    y1=get<1>(temp_ad);
                    arr[x1][y1]=maze_counter;
                }
                iterating_ad.clear();
                iterating_ad=iterating_ad1;
                iterating_ad1.clear();
                maze_counter++;
            }
        }
        cout<<endl<<endl;
        for(int i=0; i<15; i++)
        {
            for(int j=0; j <15; j++)
            {
                if(arr[i][j]<0 || arr[i][j]>9)
                    cout<<"  "<<arr[i][j];
                else
                    cout<<"   "<<arr[i][j];
            }
            cout<<"\n";
        }
        while(true)
        {
            x1=get<0>(current_dest_ad);
            y1=get<1>(current_dest_ad);
            maze_route_path.push_back(current_dest_ad);
            if(arr[x1][y1]==-2)
            {
                break;
            }
            int arr3[4]={225,225,225,225};
            for(int i=0;i<4;i++)
            {
                int a1,b1;
                a1= x1+arr1[i];
                b1= y1+arr2[i];
                if(a1>=0 && a1<=14 && b1>=0 && b1<= 14)
                {
                    if(arr[a1][b1] != -1 && arr[a1][b1] != -3 && arr[a1][b1] != 0)
                        arr3[i]=arr[a1][b1];        
                }
            }
            if(arr3[0]<=arr3[1] && arr3[0]<=arr3[2] && arr3[0]<=arr3[3])
            {
                temp_ad=make_tuple(x1+arr1[0],y1+arr2[0]);
                current_dest_ad= temp_ad;
            }
            else if(arr3[1]<=arr3[0] && arr3[1]<=arr3[2] && arr3[1]<=arr3[3])
            {
                temp_ad=make_tuple(x1+arr1[1],y1+arr2[1]);
                current_dest_ad= temp_ad;
            }
            else if(arr3[2]<=arr3[1] && arr3[2]<=arr3[0] && arr3[2]<=arr3[3])
            {
                temp_ad=make_tuple(x1+arr1[2],y1+arr2[2]);
                current_dest_ad= temp_ad;
            }
            else if(arr3[3]<=arr3[1] && arr3[3]<=arr3[2] && arr3[3]<=arr3[0])
            {
                temp_ad=make_tuple(x1+arr1[3],y1+arr2[3]);
                current_dest_ad= temp_ad;
            }    
        }
        for(int i=0;i<maze_route_path.size();i++)
        {
            temp_ad=maze_route_path[i];
            arr[get<0>(temp_ad)][get<1>(temp_ad)]= -1;
        }
        cout<<endl<<"Length of route between ("<<i1<<","<<j1<<") and ("<<i2<<","<<j2<<") is "<<(maze_route_path.size()-1)<<endl;
        cout<<endl<<"The traversing path is Given Below"<<endl;//
        for(int i=0; i< maze_route_path.size()-1;i++)//
        {//
            temp_ad=maze_route_path[i];//
            x1=get<0>(temp_ad);//
            y1=get<1>(temp_ad);//
            cout<<"("<<x1<<","<<y1<<")"<<"->";//
        }//
        cout<<"("<<get<0>(current_source_ad)<<","<<get<1>(current_source_ad)<<")"<<endl<<endl;//
        cout<<endl<<"The Updated grid "<<endl<<endl;
        for(int i=0; i<15; i++)
        {
            for(int j=0; j <15; j++)
            {
                if(arr[i][j]>0)
                {
                    arr[i][j]=0;
                }
            }
        }
        for(int i=0; i<15; i++)
        {
            for(int j=0; j <15; j++)
            {
                if(arr[i][j]<0 || arr[i][j]>9)
                    cout<<"  "<<arr[i][j];
                else
                    cout<<"   "<<arr[i][j];
            }
            cout<<"\n";
        }
        maze_route_path.clear();
        if(source_ad.size() == 0)
        {
            flag1 = false;
            cout<<endl<<"-------- END OF ROUTING ---------"<<endl;
        }
    }
    return 0;
}