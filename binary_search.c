//Binary Search
//Condition : Array MUST be SORTED, either ascending or descending, mujhe nahi maalum but SORTED HONA CHAHIYE.
//Isme, low and high (mid bhi) variable lete hai, then low = 0 and high = n - 1 (n = elements present in the array, -1 isliye, cause array starts from 0th index)
//If ham yaha loop tab tak chlate hai, jab tak mid = target nhi ho jata, cause binary search hi aisa hota hai.
//(ik smjh nhi aya hoga, you can refer to w3schools website ya youtube)

//anyways, muude par aate hai
//Worst case scenario = O(log n) [better than linear search, cause you don't need to check for each and every element]


#include <stdio.h>
#include <stdlib.h>


int binary_search(int arr[], int size, int target){
    int low = 0, high = size - 1, mid;

    //low <= high, cause low kabhi bhi jada nhi jaa sakta, agar yeh condition nhi lagaoge toh, duniya khatam ho jayegi
    while (low <= high){
        mid = (high + low) / 2;

        //ham mid ke through target nikaalenge
        if (arr[mid] == target){
            
            //mid ko return kardo, hame target mil gya hai (pwease TwT)
            return mid;
        }

        //why this condition? cause agar target chota hai, from arr[mid], toh mid ke aage jaane ka koi faida nahi hai
        //finding sun in midnight? lol, woh toh kal aya tha TwT
        else if (target < arr[mid]){
            high = mid - 1;
        }

        //agar target chota nahi hai mid se (line 31-33), toh ofc bada hi hoga
        else {
            low = mid + 1;
        }
    }

    //represents absence of value
    return -1;
}

int main(){
    //isse explain karne ki zarurat nhi hai ig
    int arr[5], target, result;
    printf("Binary Search.\n");
    printf("Array MUST be SORTED!\n\n");
    printf("Enter 5 elements.\n");

    //yaha par, we are creating the array (array ke elements add kar rhe hai, to a predefined array)
    for (int i = 0; i < 5; i++){
        scanf("%d",&arr[i]);
    }

    //what value to find? 
    printf("Enter value to find : \n");
    scanf("%d",&target);


    result = binary_search(arr, 5, target);
    
    //result -1 aaya? matlab element not found
    if (result == -1){
        printf("Element not found.");
    }

    //remember? hamne "return mid;" (line XX) karwaya tha function mai? so uski value ab yaha show hoyegi 
    else {
        printf("Element found at index : %d",result);
    }

    //bery bery important TwT
    return 0;
}