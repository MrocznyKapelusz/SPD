#pragma once
#include <iostream>
#include <string>
class Job
{
public:
    //Czasy:
    // R - dostarczenia
    // P - Trwania
    // Q - stygnięcia
    int R=INT_MAX;
    int P= INT_MAX;
    int Q= INT_MAX;
    //int initialP= INT_MAX;

    int initialIndex= INT_MAX;

    Job() {};
    Job(int, int, int);
    void showJob();
};

Job::Job(int r, int p, int q)
{
    R = r;
    P = p;
    Q = q;
}

void Build_Heap(Job*,int*,char);

void SwapJobArr(Job*,int,int);

void Heapify_Min(Job*,int*,int);

void Heapify_Max(Job*, int*, int);

void Pop_Heap(Job*, int*);

int shift_right(int*& , int );

