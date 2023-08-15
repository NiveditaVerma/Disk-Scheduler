#include <iostream>
#include <cstdlib>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
int disk_size = 200;
void pass(std::vector<int>& data, int size, int head)
{
    std::string dataStr;
    for (int i = 0; i < size; ++i) {
        dataStr += std::to_string(data[i]);
        if (i != size - 1) {
            dataStr += ",";
        }
    }

    std::string command = "python graph.py \"" + dataStr + "\"";
    std::cout << "Executing command: " << command << std::endl;

    int exitStatus = std::system(command.c_str());
    std::cout << "Exit status: " << exitStatus << std::endl;
}



//C-LOOK
void CLOOK(int arr[], int size, int head)
{
    int seek_count = 0;
    int distance, cur_track;
    vector<int> left, right;
    vector<int> seek_sequence;

    
    for (int i = 0; i < size; i++) {
        if (arr[i] < head)
            left.push_back(arr[i]);
        if (arr[i] > head)
            right.push_back(arr[i]);
    }

   
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    
    for (int i = 0; i < right.size(); i++) {
        cur_track = right[i];

        
        seek_sequence.push_back(cur_track);

       
        distance = abs(cur_track - head);

        
        seek_count += distance;

        
        head = cur_track;
    }

  
    seek_count += abs(head - left[0]);
    head = left[0];

    
    seek_sequence.insert(seek_sequence.begin(), head);

    
    for (int i = 0; i < left.size(); i++) {
        cur_track = left[i];

        
        seek_sequence.push_back(cur_track);

        
        distance = abs(cur_track - head);

        
        seek_count += distance;

        
        head = cur_track;
    }

    cout << "Total number of seek operations = "
         << seek_count << endl;

    cout << "Seek Sequence is" << endl;

    for (int i = 0; i < seek_sequence.size(); i++) {
        cout << seek_sequence[i] << endl;
    }

    pass(seek_sequence, seek_sequence.size(), head);
}

void call_CLOOK()
{
    cout<<"Enter the number of requests: ";
    int size;
    cin>>size;
    int arr[size];
    cout<<"Enter the requests:\n";
    for (int i=0;i<size;i++)
        cin>>arr[i];
    int head;
    cout<<"Enter the head: ";
    cin>>head;
    CLOOK(arr, size, head);
}
//LOOK
void LOOK(int arr[], int size, int head, string direction)
{
    int seek_count = 0;
    int distance, cur_track;
    vector<int> left, right;
    vector<int> seek_sequence;

    for (int i = 0; i < size; i++) {
        if (arr[i] < head)
            left.push_back(arr[i]);
        if (arr[i] > head)
            right.push_back(arr[i]);
    }

    
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    
    int run = 2;
    while (run--) {
        if (direction == "left") {
            for (int i = left.size() - 1; i >= 0; i--) {
                cur_track = left[i];

                
                seek_sequence.push_back(cur_track);

                
                distance = abs(cur_track - head);

                
                seek_count += distance;

                
                head = cur_track;
            }
            
            direction = "right";
        }
        else if (direction == "right") {
            for (int i = 0; i < right.size(); i++) {
                cur_track = right[i];
                
                seek_sequence.push_back(cur_track);

                
                distance = abs(cur_track - head);

                
                seek_count += distance;

                
                head = cur_track;
            }
            
            direction = "left";
        }
    }

    
    seek_sequence.insert(seek_sequence.begin(), head);

    cout << "Total number of seek operations = "
         << seek_count << endl;

    cout << "Seek Sequence is" << endl;

    for (int i = 0; i < seek_sequence.size(); i++) {
        cout << seek_sequence[i] << endl;
    }

    pass(seek_sequence, seek_sequence.size(), head);
}

void call_LOOK()
{
    int size;
    cout<<"Enter number of requests: ";
    cin>>size;
    int arr[size];
    cout<<"Enter the requests:\n";
    for(int i=0;i<size;i++)
        cin>>arr[i];
    int head;
    cout<<"Enter initial head position: ";
    cin>>head;
    string direction = "right";
    LOOK(arr, size, head, direction);
}
//C-SCAN
void CSCAN(int arr[], int head, int size)
{
    int seek_count = 0;
    int distance, cur_track;
    vector<int> left, right;
    vector<int> seek_sequence;

    
    left.push_back(0);
    right.push_back(disk_size - 1);

    
    for (int i = 0; i < size; i++) {
        if (arr[i] < head)
            left.push_back(arr[i]);
        if (arr[i] > head)
            right.push_back(arr[i]);
    }

    
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    
    for (int i = 0; i < right.size(); i++) {
        cur_track = right[i];
        
        seek_sequence.push_back(cur_track);

        
        distance = abs(cur_track - head);

        
        seek_count += distance;

        
        head = cur_track;
    }

    
    head = 0;

    
    seek_count += (disk_size - 1);

    
    for (int i = 0; i < left.size(); i++) {
        cur_track = left[i];

        
        seek_sequence.push_back(cur_track);

        distance = abs(cur_track - head);

        
        seek_count += distance;

        
        head = cur_track;
    }

    
    seek_sequence.insert(seek_sequence.begin(), head);

    cout << "Total number of seek operations = " << seek_count << endl;
    cout << "Seek Sequence is:" << endl;

    for (int i = 0; i < seek_sequence.size(); i++) {
        cout << seek_sequence[i] << endl;
    }

    pass(seek_sequence, seek_sequence.size(), head);
}

void call_CSCAN()
{
    cout<<"Enter the number of requests:";
    int size;
    cin>>size;
    int arr[size];
    cout<<"Enter the requests:\n";
    for (int i=0;i<size;i++)
        cin>>arr[i];
    int head;
    cout<<"Enter initial head position: ";
    cin>>head;
    CSCAN(arr, head, size);
}
//SCAN
void SCAN(int arr[], int head, string direction, int size)
{
    int seek_count = 0;
    int distance, cur_track;
    vector<int> left, right;
    vector<int> seek_sequence;

    
    if (direction == "left")
        left.push_back(0);
    else if (direction == "right")
        right.push_back(disk_size - 1);

    for (int i = 0; i < size; i++) {
        if (arr[i] < head)
            left.push_back(arr[i]);
        if (arr[i] > head)
            right.push_back(arr[i]);
    }

    
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    
    int run = 2;
    while (run--) {
        if (direction == "left") {
            for (int i = left.size() - 1; i >= 0; i--) {
                cur_track = left[i];

                
                seek_sequence.push_back(cur_track);

                
                distance = abs(cur_track - head);

                
                seek_count += distance;

                
                head = cur_track;
            }
            direction = "right";
        }
        else if (direction == "right") {
            for (int i = 0; i < right.size(); i++) {
                cur_track = right[i];
                
                seek_sequence.push_back(cur_track);

                
                distance = abs(cur_track - head);

                
                seek_count += distance;

                
                head = cur_track;
            }
            direction = "left";
        }
    }

    
    seek_sequence.insert(seek_sequence.begin(), head);

    cout << "Total number of seek operations = " << seek_count << endl;
    cout << "Seek Sequence is:" << endl;

    for (int i = 0; i < seek_sequence.size(); i++) {
        cout << seek_sequence[i] << endl;
    }

    pass(seek_sequence, seek_sequence.size(), head);
}

void call_SCAN()
{
    cout<<"Enter the number of requests:";
    int size;
    cin>>size;
    int arr[size];
    cout<<"Enter the requests:\n";
    for (int i=0;i<size;i++)
        cin>>arr[i]; 
    int head;
    cout<<"Enter initial head: ";
    cin>>head;
    string direction = "left";
 
    SCAN(arr, head, direction, size);
}

void calculatedifference(int request[], int head,
                         int diff[][2], int n)
{
    for(int i = 0; i < n; i++)
    {
        diff[i][0] = abs(head - request[i]);
    }
}
 

int findMIN(int diff[][2], int n)
{
    int index = -1;
    int minimum = 1e9;
   
    for(int i = 0; i < n; i++)
    {
        if (!diff[i][1] && minimum > diff[i][0])
        {
            minimum = diff[i][0];
            index = i;
        }
    }
    return index;
}
 
void shortestSeekTimeFirst(int request[], int head, int n)
{
    if (n == 0) {
        return;
    }

    
    int diff[n][2] = { { 0, 0 } };

    
    int seekcount = 0;

    
    std::vector<int> seek_sequence;
    seek_sequence.push_back(head);  

    for (int i = 0; i < n; i++) {
        calculatedifference(request, head, diff, n);
        int index = findMIN(diff, n);
        diff[index][1] = 1;

        
        seekcount += diff[index][0];

        
        head = request[index];

        
        seek_sequence.push_back(head);
    }

    std::cout << "Total number of seek operations = " << seekcount << std::endl;
    std::cout << "Seek Sequence is:" << std::endl;
    for (int i = 0; i < seek_sequence.size(); i++) {
        std::cout << seek_sequence[i] << std::endl;
    }

    pass(seek_sequence, seek_sequence.size(), head);
}

void call_SSTF()
{
    int n;
    cout<<"Enter the number of disk requests: ";
    cin>>n;
    cout<<"Enter the requests:\n";
    int proc[n];
    for (int i=0;i<n;i++)
        cin>>proc[i];
    cout<<"Enter initial head: ";
    int head;
    cin>>head;
    shortestSeekTimeFirst(proc, head, n);
}
void FCFS(int arr[], int head, int size)
{
    int seek_count = 0;
    int distance, cur_track;

    
    std::vector<int> seek_sequence_vec;
    seek_sequence_vec.push_back(head);

    for (int i = 0; i < size; i++) {
        cur_track = arr[i];

        
        distance = abs(cur_track - head);

        
        seek_count += distance;

        
        head = cur_track;

        
        seek_sequence_vec.push_back(cur_track);
    }

    std::cout << "Total number of seek operations = " << seek_count << std::endl;
    std::cout << "Seek Sequence is:" << std::endl;
    for (int i = 0; i < seek_sequence_vec.size(); i++) {
        std::cout << seek_sequence_vec[i] << std::endl;
    }

    pass(seek_sequence_vec, seek_sequence_vec.size(), head);
}

void call_FCFS()
{
    int size;
    cout<<"Enter the number of requests: ";
    cin>>size;
    cout<<"Enter initial head position: ";
    int head;
    cin>>head;
    cout<<"Enter the requests:\n";
    int arr[size];
    for (int i=0;i<size;i++)
        cin>>arr[i];
    FCFS(arr,head,size);
}
int main() {
    cout<<"What algorithm do you need to use for disk scheduling:\n";
    int n;
    cout<<"1. FCFS\n2. SSTF\n3. SCAN\n4. C-SCAN\n5. LOOK\n6.C-LOOK\n";
    cin>>n;
    switch(n)
    {
        case 1: call_FCFS();
                break;
        case 2: call_SSTF();
                break;
        case 3: call_SCAN();
                break;
        case 4: call_CSCAN();
                break;
        case 5: call_LOOK();
                break;
        case 6: call_CLOOK();
                break;
        default: break;
    }
    return 0;
}
