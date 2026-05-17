//Linear Search in C
//So, what is Linear search? 
//Basically, values find karni hai aapko, but just with loop. [Simple hai, hai na? :) ]
//aapka loop chalega, from 0th index to nth index, to find the target (value). 

// Worst Case Scenario = O(n) [Cause what if, agar target value array ke last index par ho? loop then toh pura chlega na.]

#include <stdio.h>
#include <stdlib.h>

//You need to pass three parameters
int linear_search(int arr[], int size, int target){

    //iteration from 0th index to size (yaha par size = 'total elements of the array')
    for (int i = 0; i < size; i++){
        
        //condition to find target
        if (arr[i] == target){

            //return kardo i (i.e the index number of the array)
            return i; 
        }  
    }

    //what if element (target) mila hi nahi? so uske liye ham -1 return karenge, to represent the absence of value 
    return -1;
}

int main(){
    //isse explain karne ki zarurat nhi hai ig
    int arr[5], target, result;
    printf("Linear Search.\n");
    printf("Enter 5 elements.\n");

    //yaha par, we are creating the array (array ke elements add kar rhe hai, to a predefined array)
    for (int i = 0; i < 5; i++){
        scanf("%d",&arr[i]);
    }

    //what value to find? 
    printf("Enter value to find : \n");
    scanf("%d",&target);


    result = linear_search(arr, 5, target);
    
    //result -1 aaya? matlab element not found
    if (result == -1){
        printf("Element not found.");
    }

    //remember? hamne "return i;" (line 21) karwaya tha function mai? so uski value ab yaha show hoyegi 
    else {
        printf("Element found at index : %d",result);
    }

    //bery bery important TwT
    return 0;
}