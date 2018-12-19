int main() 
{ 
    int n = 10,i; 
    int arr[n]; 
  
    // Fill whole array with 0. 
    memset(arr,'0', n*sizeof(arr[0])); 
    printf("Array after memset()\n"); 
    for(i=0;i<n;i++)
    printf("%d\n",arr[i]);

  
    return 0; 
} 
