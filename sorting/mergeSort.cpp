#include "mergeSort.hpp"
#include <iostream>

MergeSort::MergeSort(std::vector<int> *nums){

    this->nums=nums;
}

MergeSort::~MergeSort(){}

void MergeSort::recursiveSort(int left,int right){

    if(left>=right){
        return;
    }
    //value of int is bound
    //to prevent integer overflow we use this formula
    int mid= left + (right-left)/2;

    recursiveSort(left,mid);
    recursiveSort(mid+1,right);

    std::vector<int> result;

    int i=left;
    int j=mid+1;

    while(i<=mid && j<=right){

        if((*nums)[i]<= (*nums)[j]){
            result.push_back((*nums)[i]);
            i++;
        }else{
            result.push_back((*nums)[j]);
            j++;
        }
    }

    while(i<=mid){
        result.push_back((*nums)[i]);
        i++;
    }
    while(j<=right){
        result.push_back((*nums)[j]);
        j++;
    }
    //now copying the resuly vector into the nums

    for(int k=0;k< result.size();k++){
        (*nums)[left+k] =result[k];
    }

    return;



}

void MergeSort::sort(){
    //if array of num size is 0 then return
    if((*nums).size()==0){
        return;
    }
    // if not then run recursive sort algo
    //pass left and right
    //left will be 0 and right will be (*nums).size() 
    recursiveSort(0,(*nums).size());

   
}

